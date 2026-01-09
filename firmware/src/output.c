/*
 * IO Output
 * WHowe <github.com/whowechina>
 * 
 */

#include "output.h"

#include <stdint.h>
#include <stdbool.h>

#include "hardware/gpio.h" 
#include "board_defs.h"

static const uint8_t output_gpio[] = OUTPUT_GPIO;
#define OUTPUT_NUM (count_of(output_gpio))

void output_init()
{
    static const bool defaults[] = OUTPUT_DEFAULT;
    static_assert(count_of(defaults) == OUTPUT_NUM, "Size mismatch");

    for (int i = 0; i < OUTPUT_NUM; i++) {
        int8_t gpio = output_gpio[i];
        gpio_init(gpio);
        gpio_set_function(gpio, GPIO_FUNC_SIO);
        gpio_put(gpio, defaults[i]);
        gpio_set_dir(gpio, GPIO_OUT);
    }
}

uint8_t output_num()
{
    return OUTPUT_NUM;
}

void output_set(uint8_t index, bool value)
{
    if (index < OUTPUT_NUM) {
        gpio_put(output_gpio[index], value);
    }
}

bool output_get(uint8_t index)
{
    if (index < OUTPUT_NUM) {
        return gpio_get(output_gpio[index]);
    }
    return false;
}
