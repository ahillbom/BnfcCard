#include <stdio.h>
#include "LPC8N04.h"

typedef struct
{
	uint8_t row;
	uint8_t col;
} led_pin_mux_t;

const uint8_t pin_led_rows[] = {1, 2};
const uint8_t pin_led_cols[] = {6, 8, 9, 7, 3};
const uint8_t pin_buf = 0;

const led_pin_mux_t led_pin_mux[] = {
	{2, 1}, //D6
	{2, 2}, //D7
	{2, 3}, //D8
	{2, 4}, //D9
	{1, 5}, //D5
	{1, 4}, //D4
	{1, 3}, //D3
	{1, 2}, //D2
	{1, 1}  //D1
};

void conf_pins()
{

}

void Delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 80000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}


int main(void) {
	//Enable IOCON clock
	SYSCON->SYSAHBCLKCTRL |= SYSCON_SYSAHBCLKCTRL_IOCON(1);
	//enable GPIO clock
	SYSCON->SYSAHBCLKCTRL |= SYSCON_SYSAHBCLKCTRL_GPIO(1);

	// Divide clock by 8 Mhz / 16 => 500KHz
    SYSCON->SYSCLKUEN = 0;
    SYSCON->SYSCLKCTRL |= SYSCON_SYSCLKCTRL_SYSCLKDIV(4U);
    SYSCON->SYSCLKUEN = 0;
    SYSCON->SYSCLKUEN = 1;

    // SPI/SSP clock divider => 0
	SYSCON->SSPCLKDIV |= SYSCON_SSPCLKDIV_DIV(0);
	// WDT clock source => System FRO
	SYSCON->WDTCLKSEL |= SYSCON_WDTCLKSEL_SEL(0);
	// Watchdog timer clock divider => 0
	SYSCON->WDTCLKDIV|= SYSCON_WDTCLKDIV_DIV(0);
	// Disable clockout on the pin
	SYSCON->CLKOUTEN |= SYSCON_CLKOUTEN_CLKOUTEN(0);

	IOCON->PIO[0][2] = IOCON_PIO_FUNC(0);
	IOCON->PIO[0][4] = IOCON_PIO_FUNC(0);

	GPIO->DIR |= 1U << 2;

	GPIO->DIR |= 1U << 4;

	GPIO->GPIODATA[1 << 2] = (1 << 2);
	GPIO->GPIODATA[1 << 4] = (0 << 4);

	while(1)
	{
		Delay();
	}
}
