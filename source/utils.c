#include "utils.h"

void utils_byte_to_hex(uint8_t byte, uint8_t hex[])
{
	if ( (byte & 0x0f) < 10 )
		hex[1] = (byte & 0x0f) + '0';
	else
		hex[1] = (byte & 0x0f) - 10 + 'A';

	if (((byte & 0xf0) >> 4) < 10)
		hex[0] = ((byte & 0xf0) >> 4) + '0';
	else
		hex[0] = ((byte & 0xf0) >> 4) - 10 + 'A';

	return;
}

void utils_word_to_hex(uint32_t word, uint8_t hex[])
{
	utils_byte_to_hex((uint8_t)(word >> 24), &hex[0]);
	utils_byte_to_hex((uint8_t)(word >> 16), &hex[2]);
	utils_byte_to_hex((uint8_t)(word >> 8), &hex[4]);
	utils_byte_to_hex((uint8_t)word, &hex[6]);
}

void utils_delay(uint32_t delay)
{
    volatile uint32_t i = 0;
    for (i = 0; i < delay; ++i) __asm("NOP");
}
