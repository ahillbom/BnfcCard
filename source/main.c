#include <stdint.h>
#include <string.h>
#include "LPC8N04.h"
#include "nfc_ndef.h"
#include "IAP.h"
#include "utils.h"

#define LED_ROWS  2
#define LED_COLS  5
#define LEDS 9

#define URL_BASE  "beastdevices.com/nfccodes/25YDZ2SCIP/?id="

typedef struct{
    uint8_t base[sizeof(URL_BASE)-1];
    uint8_t id[16];
}url_t;

uint32_t SystemClock;

//GPIOs for LEDR1, LEDR2
const uint8_t pin_led_rows[] = {1, 2};

//GPIOs for LEDC1, LEDC2, LEDC3, LEDC4, LEDC5
const uint8_t pin_led_cols[] = {6, 8, 9, 7, 3};

//GPIO with energy harvesting buffer capacitor
const uint8_t pin_buf = 0;

// All pins
const uint8_t * pin_all[] = {pin_led_rows, pin_led_cols, &pin_buf};

// -1 indicates LED doesn't exist
const int_least8_t led_pin_mux[LED_ROWS][LED_COLS] = { {0, 1, 2, 3, 4}, {3, 2, 1, 0, -1} };

// LED Double buffer
uint8_t led_prebuf[LED_ROWS][LED_COLS] = { {0,0,0,0,0},{0,0,0,0,0} };
uint8_t led_buf[LED_ROWS][LED_COLS] = { {0,0,0,0,0},{0,0,0,0,0} };

//Indicates active writing to the LED prebuffer
uint8_t led_prebuf_w = 0;

//Pointer to the active LED buffer for linear access instead or row and columns
uint8_t (*led_prebuf_lin)[LED_ROWS*LED_COLS] = (uint8_t(*)[LED_ROWS][LED_COLS])led_prebuf;

// MCU's serial number
uint32_t uid[2] = {0};

const uint8_t led_animation[][LEDS] = { {0, 0, 0, 0, 1, 0, 0, 0, 0},
                                        {0, 0, 0, 1, 0, 1, 0, 0, 0},
                                        {0, 0, 1, 0, 0, 0, 1, 0, 0},
                                        {0, 1, 0, 0, 0, 0, 0, 1, 0},
                                        {1, 0, 0, 0, 0, 0, 0, 0, 1},
                                        {0, 1, 0, 0, 0, 0, 0, 1, 0},
                                        {0, 0, 1, 0, 0, 0, 1, 0, 0},
                                        {0, 0, 0, 1, 0, 1, 0, 0, 0},
                                        {0, 0, 0, 0, 1, 0, 0, 0, 0} };

void setGPIO(uint8_t io, uint8_t state)
{
    GPIO->GPIODATA[1 << io] = (state << io);
}

void LED_prebuf_clear()
{
    for (uint8_t i = 0; i < LEDS; i++) (*led_prebuf_lin)[i] = 0;
}

void LED_refresh()
{
    static uint8_t row = 0;

    setGPIO(pin_led_rows[row], 0);
    row++;
    if (row == LED_ROWS)
    {
        row = 0;
        //swap double buffer, if not writing
        if (led_prebuf_w == 0) memcpy(led_buf, led_prebuf, sizeof(led_buf));
    }

    for (uint8_t col = 0; col < LED_COLS; col++)
    {
        if (led_buf[row][col] != -1)
            setGPIO(pin_led_cols[led_pin_mux[row][col]], ~led_buf[row][col]);
    }

    setGPIO(pin_led_rows[row], 1);
}

void NFC_write(uint32_t pageIndex, const uint32_t *data, uint32_t numPage)
{
    for (uint8_t i = 0; i < numPage; i++) RFIDNFC->SHARED_MEM[pageIndex++] = data[i];
}

void SysTick_Handler(void)
{
    LED_refresh();
}

void NFC_IRQHandler(void)
{
    // Clear the CMD READ interrupt
    if (RFIDNFC->IMIS & RFIDNFC_MIS_CMDREAD(1))
        RFIDNFC->ICR = RFIDNFC_ICR_CMDREAD(1);
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
    // Disable clock out on the pin
    SYSCON->CLKOUTEN |= SYSCON_CLKOUTEN_CLKOUTEN(0);

    SystemClock = 500000;

    // Terminator TLV (Last TLV block in the data area)
    RFIDNFC->SHARED_MEM[0] = 0x000000FE;

    // Disable NFC interrupts
    RFIDNFC->IMIS &= ~(RFIDNFC_MIS_RFPOWER_MASK | RFIDNFC_MIS_RFSELECT_MASK | RFIDNFC_MIS_MEMREAD_MASK |
            RFIDNFC_MIS_MEMWRITE_MASK | RFIDNFC_MIS_CMDWRITE_MASK | RFIDNFC_MIS_CMDREAD_MASK |
            RFIDNFC_MIS_TARGETWRITE_MASK | RFIDNFC_MIS_TARGETREAD_MASK | RFIDNFC_MIS_NFCOFF_MASK);
    // CLear pending interrupts
    RFIDNFC->ICR = RFIDNFC_MIS_RFPOWER_MASK | RFIDNFC_MIS_RFSELECT_MASK | RFIDNFC_MIS_MEMREAD_MASK |
            RFIDNFC_MIS_MEMWRITE_MASK | RFIDNFC_MIS_CMDWRITE_MASK | RFIDNFC_MIS_CMDREAD_MASK |
            RFIDNFC_MIS_TARGETWRITE_MASK | RFIDNFC_MIS_TARGETREAD_MASK | RFIDNFC_MIS_NFCOFF_MASK;

    // Enable interrupt on CMD READ
    //RFIDNFC->IMIS |= RFIDNFC_IMIS_MEMREAD(1);
    //NVIC_EnableIRQ(NFC_IRQn);

    // Disable NFC bypasss mode (direct access to EEPROM)
    RFIDNFC->CFG = 0x0;

    // Configure GPIOs
    // Set pins to output
    GPIO->DIR |= 1U << pin_led_rows[0];
    GPIO->DIR |= 1U << pin_led_rows[1];
    GPIO->DIR |= 1U << pin_led_cols[0];
    GPIO->DIR |= 1U << pin_led_cols[1];
    GPIO->DIR |= 1U << pin_led_cols[2];
    GPIO->DIR |= 1U << pin_led_cols[3];
    GPIO->DIR |= 1U << pin_led_cols[4];
    GPIO->DIR |= 1U << pin_buf;

    // No alternate function
    IOCON->PIO[0][pin_led_rows[0]] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][pin_led_rows[1]] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][pin_led_cols[0]] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][pin_led_cols[1]] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][pin_led_cols[2]] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][pin_led_cols[3]] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][pin_led_cols[4]] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][pin_buf] = IOCON_PIO_FUNC(0);

    // Turn on pin for the energy harvesting buffer capacitor
    setGPIO(pin_buf, 1);

    // Enable SysTick and set to 1 mS interval
    SysTick_Config(SystemClock/100);

    // Get MCU's serial number
    IAP_getUID(uid);

    // Prepare NDEF message
    url_t url = {   {URL_BASE},
                    {0}};

    utils_word_to_hex(uid[0], &url.id[0]);
    utils_word_to_hex(uid[1], &url.id[8]);

    // Buffer for binary NDEF message
    uint8_t msg[80] = {};
    // Binary NDEF message length
    uint8_t msg_len;

    ndef_msg_rtd_uri((uint8_t*)&url, sizeof(url), msg, &msg_len);
    NFC_write(0, (uint32_t*)msg, msg_len/(sizeof(uint32_t)));

    uint8_t i = 0;

    while(1)
    {
        utils_delay(2500);
        led_prebuf_w = 1;
        if (i == sizeof(led_animation)/LEDS) i = 0;
        memcpy(led_prebuf_lin, led_animation[i], LEDS);
        led_prebuf_w = 0;
        i++;
    }
}
