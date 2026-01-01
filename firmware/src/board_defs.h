/*
 * Voltex Controller Board Definitions
 * WHowe <github.com/whowechina>
 */

#if defined BOARD_ARCADE_PICO

#define RGB_PIN 14

#define RGB_ORDER GRB // or RGB

#define BUTTON_DEF { 18, 16, 12, 10, 11, 13, 17, 19  }
#define BUTTON_PULL_UPDOWN { 1, 1, 1, 1, 1, 1, 1, 1 }


#define HALL_KEY_MUX_ADDRS { 20, 21, 22 }
#define HALL_KEY_MUX_MAP { 3, 2, 1, 0, 7, 6, 5, 4 }
#define HALL_KEY_MUX_EN -1
#define HALL_KEY_ADC_CHN 0

#endif
