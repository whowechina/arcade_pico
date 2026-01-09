/*
 * Controller Config
 * WHowe <github.com/whowechina>
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

typedef struct __attribute__((packed)) {
    struct {
        uint16_t up[8];
        uint16_t down[8];
    } calibrated;
    struct {
        uint8_t on[8];
        uint8_t off[8];
    } trigger;
    struct {
        uint8_t level;
        uint8_t not_used[15];
        uint32_t color_on[8];
        uint32_t color_off[8];
    } light;
    struct {
        uint8_t output[8];
        uint8_t rgb[8];
    } route;
} arcade_cfg_t;

typedef struct {
    struct {
        bool hall;
        bool input;
    } debug;
} arcade_runtime_t;

extern arcade_cfg_t *arcade_cfg;
extern arcade_runtime_t arcade_runtime;

void config_init();
void config_changed(); // Notify the config has changed
void config_factory_reset(); // Reset the config to factory default

#endif
