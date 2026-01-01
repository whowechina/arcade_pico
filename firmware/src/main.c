/*
 * Controller Main
 * WHowe <github.com/whowechina>
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "bsp/board.h"
#include "pico/multicore.h"
#include "pico/bootrom.h"

#include "hardware/gpio.h"
#include "hardware/sync.h"
#include "hardware/structs/ioqspi.h"
#include "hardware/structs/sio.h"

#include "tusb.h"
#include "usb_descriptors.h"

#include "board_defs.h"

#include "save.h"
#include "config.h"
#include "cli.h"
#include "commands.h"

#include "light.h"
#include "button.h"
#include "hebtn.h"

static void run_lights()
{
    for (int i = 0; i < 8; i++) {
        uint32_t color = rgb32_from_hsv(i * 31, 255, 255);
        light_set(i, color, false);
    }
}

static mutex_t core1_io_lock;
static void core1_loop()
{
    while (1) {
        if (mutex_try_enter(&core1_io_lock, NULL)) {
            run_lights();
            light_update();
            mutex_exit(&core1_io_lock);
        }
        cli_fps_count(1);
        sleep_us(700);
    }
}

struct __attribute__((packed)) {
    uint8_t buttons;
    uint8_t padding;
} hid_report, hid_report_sent;

static void hid_update()
{
    uint32_t buttons = button_read() ^ 0xffc; // invert the fader bits

    hid_report.buttons = buttons << 12;
    for (int i = 0; i < 12; i++) {
        if (hebtn_actuated(i)) {
            hid_report.buttons |= (1 << i);
        }
    }

    static uint64_t last_report_time = 0;
    if (tud_hid_ready()) {
        uint64_t now = time_us_64();
        if ((memcmp(&hid_report, &hid_report_sent, sizeof(hid_report)) == 0) &&
            (now - last_report_time < 10000)) {
            return;
        }
        last_report_time = now;
        if (tud_hid_report(REPORT_ID_JOYSTICK, &hid_report, sizeof(hid_report))) {
            hid_report_sent = hid_report;
        }
    }
}

static void debug_display()
{
    static uint64_t last_display = 0;
    uint64_t now = time_us_64();
    if (now - last_display < 100000) {
        return;
    }
    last_display = now;
}

static void core0_loop()
{
    uint64_t next_frame = 0;
    while(1) {
        tud_task();

        cli_run();

        save_loop();
        cli_fps_count(0);

        button_update();
        hebtn_update();

        hid_update();

        debug_display();
        sleep_until(next_frame);
        next_frame += 1000;
    }
}

/* if certain key pressed when booting, enter update mode */
static void update_check()
{
}

void init()
{
    sleep_ms(50);
    board_init();

    update_check();

    tusb_init();
    stdio_init_all();

    config_init();
    mutex_init(&core1_io_lock);
    save_init(0xca44cdb1, &core1_io_lock);

    light_init();
    button_init();
    hebtn_init(arcade_cfg->calibrated.up, arcade_cfg->calibrated.down,
               arcade_cfg->trigger.on, arcade_cfg->trigger.off);

    cli_init("arcade_pico>", "\n   << Arcade Pico Controller >>\n"
                            " https://github.com/whowechina\n\n");
    
    commands_init();
}

int main(void)
{
    init();
    multicore_launch_core1(core1_loop);
    core0_loop();
    return 0;
}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t tud_hid_get_report_cb(uint8_t itf, uint8_t report_id,
                               hid_report_type_t report_type, uint8_t *buffer,
                               uint16_t reqlen)
{
    printf("Get from USB %d-%d\n", report_id, report_type);
    return 0;
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
void tud_hid_set_report_cb(uint8_t itf, uint8_t report_id,
                           hid_report_type_t report_type, uint8_t const *buffer,
                           uint16_t bufsize)
{
    if ((report_id == REPORT_ID_LIGHTS) && (bufsize >= 24)) {
        for (int i = 0; i < 8; i++) {
            const uint8_t *rgb = &buffer[i * 3];
            uint32_t color = rgb32(rgb[0], rgb[1], rgb[2], false);
            light_set(i, color, true);
        }
    }
}
