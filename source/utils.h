#include <stdint.h>

#ifndef _UTILS_H_
#define _UTILS_H_

void utils_byte_to_hex(uint8_t byte, uint8_t hex[]);
void utils_word_to_hex(uint32_t word, uint8_t hex[]);
void utils_delay(uint32_t delay);

#endif
