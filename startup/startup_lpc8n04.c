//*****************************************************************************
// LPC8N04 startup code for use with MCUXpresso IDE
//
// Version : 170818
//*****************************************************************************
//
// Copyright 2016-2018 NXP
//
// SPDX-License-Identifier: BSD-3-Clause
//*****************************************************************************

#if defined (DEBUG)
#pragma GCC push_options
#pragma GCC optimize ("Og")
#endif // (DEBUG)

#if defined (__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#else
//*****************************************************************************
//
// The entry point for the C++ library startup
//
//*****************************************************************************
extern "C" {
    extern void __libc_init_array(void);
}
#endif
#endif

#define WEAK __attribute__ ((weak))
#define WEAK_AV __attribute__ ((weak, section(".after_vectors")))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

//*****************************************************************************
#if defined (__cplusplus)
extern "C" {
#endif

//*****************************************************************************
// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
//*****************************************************************************
//*****************************************************************************
// Declaration of external SystemInit function
//*****************************************************************************
#if defined (__USE_CMSIS)
extern void SystemInit(void);
#endif // (__USE_CMSIS)

//*****************************************************************************
// Forward declaration of the core exception handlers.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions.
// If your application is a C++ one, then any interrupt handlers defined
// in C++ files within in your main application will need to have C linkage
// rather than C++ linkage. To do this, make sure that you are using extern "C"
// { .... } around the interrupt handler within your main application code.
//*****************************************************************************
     void ResetISR(void);
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void IntDefaultHandler(void);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void PIO0_0_IRQHandler(void);
WEAK void PIO0_1_IRQHandler(void);
WEAK void PIO0_2_IRQHandler(void);
WEAK void PIO0_3_IRQHandler(void);
WEAK void PIO0_4_IRQHandler(void);
WEAK void PIO0_5_IRQHandler(void);
WEAK void PIO0_6_IRQHandler(void);
WEAK void PIO0_7_IRQHandler(void);
WEAK void PIO0_8_IRQHandler(void);
WEAK void PIO0_9_IRQHandler(void);
WEAK void PIO0_10_IRQHandler(void);
WEAK void RFFIELD_IRQHandler(void);
WEAK void RTCPWREQ_IRQHandler(void);
WEAK void NFC_IRQHandler(void);
WEAK void RTC_IRQHandler(void);
WEAK void I2C0_IRQHandler(void);
WEAK void CTIMER0_IRQHandler(void);
WEAK void PMUFLD_IRQHandler(void);
WEAK void CTIMER1_IRQHandler(void);
WEAK void PMUBOD_IRQHandler(void);
WEAK void SSP0_IRQHandler(void);
WEAK void TSEN_IRQHandler(void);
WEAK void C2D_IRQHandler(void);
WEAK void Reserved39_IRQHandler(void);
WEAK void I2D_IRQHandler(void);
WEAK void ADCDAC_IRQHandler(void);
WEAK void WDT_IRQHandler(void);
WEAK void FLASH_IRQHandler(void);
WEAK void EEPROM_IRQHandler(void);
WEAK void Reserved45_IRQHandler(void);
WEAK void Reserved46_IRQHandler(void);
WEAK void PIO0_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the IntDefaultHandler, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void PIO0_0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_4_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_5_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_6_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_7_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_8_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_9_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_10_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RFFIELD_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTCPWREQ_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void NFC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void I2C0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CTIMER0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PMUFLD_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CTIMER1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PMUBOD_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SSP0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TSEN_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void C2D_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved39_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void I2D_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ADCDAC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void WDT_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FLASH_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void EEPROM_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved45_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved46_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIO0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);

//*****************************************************************************
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//*****************************************************************************
#if defined (__REDLIB__)
extern void __main(void);
#endif
extern int main(void);

//*****************************************************************************
// External declaration for the pointer to the stack top from the Linker Script
//*****************************************************************************
extern void _vStackTop(void);
//*****************************************************************************
// External declaration for LPC MCU vector table checksum from  Linker Script
//*****************************************************************************
WEAK extern void __valid_user_code_checksum();

//*****************************************************************************
//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif
//*****************************************************************************
// The vector table.
// This relies on the linker script to place at correct location in memory.
//*****************************************************************************
extern void (* const g_pfnVectors[])(void);
extern void * __Vectors __attribute__ ((alias ("g_pfnVectors")));

__attribute__ ((used, section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    // Core Level - CM0P
    &_vStackTop,                       // The initial stack pointer
    ResetISR,                          // The reset handler
    NMI_Handler,                       // The NMI handler
    HardFault_Handler,                 // The hard fault handler
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    __valid_user_code_checksum,        // LPC MCU checksum
    0,                                 // ECRP
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall handler
    0,                                 // Reserved
    0,                                 // Reserved
    PendSV_Handler,                    // The PendSV handler
    SysTick_Handler,                   // The SysTick handler

    // Chip Level - LPC8N04
    PIO0_0_IRQHandler,       // 16: PIO0_0 Start Logic Interrupt
    PIO0_1_IRQHandler,       // 17: PIO0_1 Start Logic Interrupt
    PIO0_2_IRQHandler,       // 18: PIO0_2 Start Logic Interrupt
    PIO0_3_IRQHandler,       // 19: PIO0_3 Start Logic Interrupt
    PIO0_4_IRQHandler,       // 20: PIO0_4 Start Logic Interrupt
    PIO0_5_IRQHandler,       // 21: PIO0_5 Start Logic Interrupt
    PIO0_6_IRQHandler,       // 22: PIO0_6 Start Logic Interrupt
    PIO0_7_IRQHandler,       // 23: PIO0_7 Start Logic Interrupt
    PIO0_8_IRQHandler,       // 24: PIO0_8 Start Logic Interrupt
    PIO0_9_IRQHandler,       // 25: PIO0_9 Start Logic Interrupt
    PIO0_10_IRQHandler,      // 26: PIO0_10 Start Logic Interrupt
    RFFIELD_IRQHandler,      // 27: NFC Access Start Logic Interrupt
    RTCPWREQ_IRQHandler,     // 28: RTC Wakeup Request Start Logic Interrupt
    NFC_IRQHandler,          // 29: NFC Read/Write Interrupt
    RTC_IRQHandler,          // 30: RTC Wakeup Interrupt
    I2C0_IRQHandler,         // 31: I2C0 Interrupt
    CTIMER0_IRQHandler,      // 32: 16-bit Timer 0 Interrupt
    PMUFLD_IRQHandler,       // 33: RF Power Detection Interrupt
    CTIMER1_IRQHandler,      // 34: 32-bit Timer 0 Interrupt
    PMUBOD_IRQHandler,       // 35: Brown Out Detection Interrupt
    SSP0_IRQHandler,         // 36: SSP0 Interrupt
    TSEN_IRQHandler,         // 37: Temperature Sensor Interrupt
    C2D_IRQHandler,          // 38: Capacitance-to-Digital converter Interrupt
    Reserved39_IRQHandler,   // 39: Reserved interrupt
    I2D_IRQHandler,          // 40: Current-to-Digital converter Interrupt
    ADCDAC_IRQHandler,       // 41: Analog-to-Digital/Digital-to-Analog converter Interrupt
    WDT_IRQHandler,          // 42: Watchdog Timer Interrupt
    FLASH_IRQHandler,        // 43: FLASH memory Interrupt
    EEPROM_IRQHandler,       // 44: EEPROM memory Interrupt
    Reserved45_IRQHandler,   // 45: Reserved interrupt
    Reserved46_IRQHandler,   // 46: Reserved interrupt
    PIO0_IRQHandler,         // 47: GPIO Port 0 Interrupt

}; /* End of g_pfnVectors */

//*****************************************************************************
// Functions to carry out the initialization of RW and BSS data sections. These
// are written as separate functions rather than being inlined within the
// ResetISR() function in order to cope with MCUs with multiple banks of
// memory.
//*****************************************************************************
__attribute__ ((section(".after_vectors.init_data")))
void data_init(unsigned int romstart, unsigned int start, unsigned int len) {
    unsigned int *pulDest = (unsigned int*) start;
    unsigned int *pulSrc = (unsigned int*) romstart;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = *pulSrc++;
}

__attribute__ ((section(".after_vectors.init_bss")))
void bss_init(unsigned int start, unsigned int len) {
    unsigned int *pulDest = (unsigned int*) start;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = 0;
}

//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Global Section Table". This table is
// created by the linker via the Code Red managed linker script mechanism. It
// contains the load address, execution address and length of each RW data
// section and the execution and length of each BSS (zero initialized) section.
//*****************************************************************************
extern unsigned int __data_section_table;
extern unsigned int __data_section_table_end;
extern unsigned int __bss_section_table;
extern unsigned int __bss_section_table_end;

//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
__attribute__ ((section(".after_vectors.reset")))
void ResetISR(void) {

    // Disable interrupts
    __asm volatile ("cpsid i");

    // Enable SRAM clock used by Stack
    __asm volatile ("LDR R0, =0x40000220\n\t"
                    "MOV R1, #56\n\t"
                    "STR R1, [R0]");

#if defined (__USE_CMSIS)
// If __USE_CMSIS defined, then call CMSIS SystemInit code
    SystemInit();

#endif // (__USE_CMSIS)

    //
    // Copy the data sections from flash to SRAM.
    //
    unsigned int LoadAddr, ExeAddr, SectionLen;
    unsigned int *SectionTableAddr;

    // Load base address of Global Section Table
    SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
    while (SectionTableAddr < &__data_section_table_end) {
        LoadAddr = *SectionTableAddr++;
        ExeAddr = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        data_init(LoadAddr, ExeAddr, SectionLen);
    }

    // At this point, SectionTableAddr = &__bss_section_table;
    // Zero fill the bss segment
    while (SectionTableAddr < &__bss_section_table_end) {
        ExeAddr = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        bss_init(ExeAddr, SectionLen);
    }

#if !defined (__USE_CMSIS)
// Assume that if __USE_CMSIS defined, then CMSIS SystemInit code
// will setup the VTOR register

    // Check to see if we are running the code from a non-zero
    // address (eg RAM, external flash), in which case we need
    // to modify the VTOR register to tell the CPU that the
    // vector table is located at a non-0x0 address.
    unsigned int * pSCB_VTOR = (unsigned int *) 0xE000ED08;
    if ((unsigned int *)g_pfnVectors!=(unsigned int *) 0x00000000) {
        *pSCB_VTOR = (unsigned int)g_pfnVectors;
    }
#endif // (__USE_CMSIS)

#if defined (__cplusplus)
    //
    // Call C++ library initialisation
    //
    __libc_init_array();
#endif

    // Reenable interrupts
    __asm volatile ("cpsie i");

#if defined (__REDLIB__)
    // Call the Redlib library, which in turn calls main()
    __main();
#else
    main();
#endif

    //
    // main() shouldn't return, but if it does, we'll just enter an infinite loop
    //
    while (1) {
        ;
    }
}

//*****************************************************************************
// Default core exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
WEAK_AV void NMI_Handler(void)
{ while(1) {}
}

WEAK_AV void HardFault_Handler(void)
{ while(1) {}
}

WEAK_AV void SVC_Handler(void)
{ while(1) {}
}

WEAK_AV void PendSV_Handler(void)
{ while(1) {}
}

WEAK_AV void SysTick_Handler(void)
{ while(1) {}
}

//*****************************************************************************
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//*****************************************************************************
WEAK_AV void IntDefaultHandler(void)
{ while(1) {}
}

//*****************************************************************************
// Default application exception handlers. Override the ones here by defining
// your own handler routines in your application code. These routines call
// driver exception handlers or IntDefaultHandler() if no driver exception
// handler is included.
//*****************************************************************************
WEAK_AV void PIO0_0_IRQHandler(void)
{   PIO0_0_DriverIRQHandler();
}

WEAK_AV void PIO0_1_IRQHandler(void)
{   PIO0_1_DriverIRQHandler();
}

WEAK_AV void PIO0_2_IRQHandler(void)
{   PIO0_2_DriverIRQHandler();
}

WEAK_AV void PIO0_3_IRQHandler(void)
{   PIO0_3_DriverIRQHandler();
}

WEAK_AV void PIO0_4_IRQHandler(void)
{   PIO0_4_DriverIRQHandler();
}

WEAK_AV void PIO0_5_IRQHandler(void)
{   PIO0_5_DriverIRQHandler();
}

WEAK_AV void PIO0_6_IRQHandler(void)
{   PIO0_6_DriverIRQHandler();
}

WEAK_AV void PIO0_7_IRQHandler(void)
{   PIO0_7_DriverIRQHandler();
}

WEAK_AV void PIO0_8_IRQHandler(void)
{   PIO0_8_DriverIRQHandler();
}

WEAK_AV void PIO0_9_IRQHandler(void)
{   PIO0_9_DriverIRQHandler();
}

WEAK_AV void PIO0_10_IRQHandler(void)
{   PIO0_10_DriverIRQHandler();
}

WEAK_AV void RFFIELD_IRQHandler(void)
{   RFFIELD_DriverIRQHandler();
}

WEAK_AV void RTCPWREQ_IRQHandler(void)
{   RTCPWREQ_DriverIRQHandler();
}

WEAK_AV void NFC_IRQHandler(void)
{   NFC_DriverIRQHandler();
}

WEAK_AV void RTC_IRQHandler(void)
{   RTC_DriverIRQHandler();
}

WEAK_AV void I2C0_IRQHandler(void)
{   I2C0_DriverIRQHandler();
}

WEAK_AV void CTIMER0_IRQHandler(void)
{   CTIMER0_DriverIRQHandler();
}

WEAK_AV void PMUFLD_IRQHandler(void)
{   PMUFLD_DriverIRQHandler();
}

WEAK_AV void CTIMER1_IRQHandler(void)
{   CTIMER1_DriverIRQHandler();
}

WEAK_AV void PMUBOD_IRQHandler(void)
{   PMUBOD_DriverIRQHandler();
}

WEAK_AV void SSP0_IRQHandler(void)
{   SSP0_DriverIRQHandler();
}

WEAK_AV void TSEN_IRQHandler(void)
{   TSEN_DriverIRQHandler();
}

WEAK_AV void C2D_IRQHandler(void)
{   C2D_DriverIRQHandler();
}

WEAK_AV void Reserved39_IRQHandler(void)
{   Reserved39_DriverIRQHandler();
}

WEAK_AV void I2D_IRQHandler(void)
{   I2D_DriverIRQHandler();
}

WEAK_AV void ADCDAC_IRQHandler(void)
{   ADCDAC_DriverIRQHandler();
}

WEAK_AV void WDT_IRQHandler(void)
{   WDT_DriverIRQHandler();
}

WEAK_AV void FLASH_IRQHandler(void)
{   FLASH_DriverIRQHandler();
}

WEAK_AV void EEPROM_IRQHandler(void)
{   EEPROM_DriverIRQHandler();
}

WEAK_AV void Reserved45_IRQHandler(void)
{   Reserved45_DriverIRQHandler();
}

WEAK_AV void Reserved46_IRQHandler(void)
{   Reserved46_DriverIRQHandler();
}

WEAK_AV void PIO0_IRQHandler(void)
{   PIO0_DriverIRQHandler();
}

//*****************************************************************************

#if defined (DEBUG)
#pragma GCC pop_options
#endif // (DEBUG)
