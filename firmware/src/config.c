/*
 * Controller Config and Runtime Data
 * WHowe <github.com/whowechina>
 * 
 * Config is a global data structure that stores all the configuration
 * Runtime is something to share between files.
 */

#include "config.h"
#include "save.h"

arcade_cfg_t *arcade_cfg;

static arcade_cfg_t default_cfg = {
    .trigger = {
        .on = { 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24 },
        .off = { 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28 },
    },
    .light = {
        .level = 128,
    },
};

arcade_runtime_t arcade_runtime;

static void config_loaded()
{
    for (int i = 0; i < 6; i++) {
        if (arcade_cfg->trigger.on[i] > 35) {
            arcade_cfg->trigger.on[i] = 35;
        }
        if (arcade_cfg->trigger.off[i] > 35) {
            arcade_cfg->trigger.off[i] = 35;
        }
    }

    config_changed();
}

void config_changed()
{
    save_request(false);
}

void config_factory_reset()
{
    *arcade_cfg = default_cfg;
    save_request(true);
}

void config_init()
{
    arcade_cfg = (arcade_cfg_t *)save_alloc(sizeof(*arcade_cfg), &default_cfg, config_loaded);
}
