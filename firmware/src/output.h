/*
 * IO Output
 * WHowe <github.com/whowechina>
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdint.h>
#include <stdbool.h>

void output_init();
uint8_t output_num();
void output_set(uint8_t index, bool value);
bool output_get(uint8_t index);

#endif
