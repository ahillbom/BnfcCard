/*
** ###################################################################
**     Processor:           LPC8N04FHI24
**     Compilers:           Keil ARM C/C++ Compiler
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC8N04 User manual Rev.1.0  24 Jan 2018
**     Version:             rev. 1.0, 2018-06-21
**     Build:               b180817
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC8N04
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2018 NXP
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-06-21)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file LPC8N04.h
 * @version 1.0
 * @date 2018-06-21
 * @brief CMSIS Peripheral Access Layer for LPC8N04
 *
 * CMSIS Peripheral Access Layer for LPC8N04
 */

#ifndef _LPC8N04_H_
#define _LPC8N04_H_                              /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  PIO0_0_IRQn                  = 0,                /**< PIO0_0 Start Logic Interrupt */
  PIO0_1_IRQn                  = 1,                /**< PIO0_1 Start Logic Interrupt */
  PIO0_2_IRQn                  = 2,                /**< PIO0_2 Start Logic Interrupt */
  PIO0_3_IRQn                  = 3,                /**< PIO0_3 Start Logic Interrupt */
  PIO0_4_IRQn                  = 4,                /**< PIO0_4 Start Logic Interrupt */
  PIO0_5_IRQn                  = 5,                /**< PIO0_5 Start Logic Interrupt */
  PIO0_6_IRQn                  = 6,                /**< PIO0_6 Start Logic Interrupt */
  PIO0_7_IRQn                  = 7,                /**< PIO0_7 Start Logic Interrupt */
  PIO0_8_IRQn                  = 8,                /**< PIO0_8 Start Logic Interrupt */
  PIO0_9_IRQn                  = 9,                /**< PIO0_9 Start Logic Interrupt */
  PIO0_10_IRQn                 = 10,               /**< PIO0_10 Start Logic Interrupt */
  RFFIELD_IRQn                 = 11,               /**< NFC Access Start Logic Interrupt */
  RTCPWREQ_IRQn                = 12,               /**< RTC Wakeup Request Start Logic Interrupt */
  NFC_IRQn                     = 13,               /**< NFC Read/Write Interrupt */
  RTC_IRQn                     = 14,               /**< RTC Wakeup Interrupt */
  I2C0_IRQn                    = 15,               /**< I2C0 Interrupt */
  CTIMER0_IRQn                 = 16,               /**< 16-bit Timer 0 Interrupt */
  PMUFLD_IRQn                  = 17,               /**< RF Power Detection Interrupt */
  CTIMER1_IRQn                 = 18,               /**< 32-bit Timer 0 Interrupt */
  PMUBOD_IRQn                  = 19,               /**< Brown Out Detection Interrupt */
  SSP0_IRQn                    = 20,               /**< SSP0 Interrupt */
  TSEN_IRQn                    = 21,               /**< Temperature Sensor Interrupt */
  C2D_IRQn                     = 22,               /**< Capacitance-to-Digital converter Interrupt */
  Reserved39_IRQn              = 23,               /**< Reserved interrupt */
  I2D_IRQn                     = 24,               /**< Current-to-Digital converter Interrupt */
  ADCDAC_IRQn                  = 25,               /**< Analog-to-Digital/Digital-to-Analog converter Interrupt */
  WDT_IRQn                     = 26,               /**< Watchdog Timer Interrupt */
  FLASH_IRQn                   = 27,               /**< FLASH memory Interrupt */
  EEPROM_IRQn                  = 28,               /**< EEPROM memory Interrupt */
  Reserved45_IRQn              = 29,               /**< Reserved interrupt */
  Reserved46_IRQn              = 30,               /**< Reserved interrupt */
  PIO0_IRQn                    = 31                /**< GPIO Port 0 Interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0PLUS_REV                  0x0000    /**< Core revision r0p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"              /* Core Peripheral Access Layer */
#include "system_LPC8N04.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- CTIMER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTIMER_Peripheral_Access_Layer CTIMER Peripheral Access Layer
 * @{
 */

/** CTIMER - Register Layout Typedef */
typedef struct {
  __IO uint32_t IR;                                /**< Interrupt register. The IR can be written to clear interrupts, and can be read to identify which of the five possible interrupt sources are pending., offset: 0x0 */
  __IO uint32_t TCR;                               /**< Timer control register. The TCR is used to control the timer counter functions. The TC can be disabled or reset through the TCR, offset: 0x4 */
  __IO uint32_t TC;                                /**< Timer Counter (TC). The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR., offset: 0x8 */
  __IO uint32_t PR;                                /**< Prescale register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC., offset: 0xC */
  __IO uint32_t PC;                                /**< Prescale Counter (PC). The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface., offset: 0x10 */
  __IO uint32_t MCR;                               /**< Match Control Register (MCR). The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs., offset: 0x14 */
  __IO uint32_t MR[4];                             /**< Match Register 0 (MR0). MR0 can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC., array offset: 0x18, array step: 0x4 */
       uint8_t RESERVED_0[20];
  __IO uint32_t EMR;                               /**< External Match Register (EMR). The EMR controls the match function and the external match pins CT32B_MAT[1:0]., offset: 0x3C */
       uint8_t RESERVED_1[52];
  __IO uint32_t PWMC;                              /**< PWM Control Register (PWMCON). The PWMCON enables PWM mode for the external match pins CT32B_MAT[1:0]., offset: 0x74 */
} CTIMER_Type;

/* ----------------------------------------------------------------------------
   -- CTIMER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTIMER_Register_Masks CTIMER Register Masks
 * @{
 */

/*! @name IR - Interrupt register. The IR can be written to clear interrupts, and can be read to identify which of the five possible interrupt sources are pending. */
/*! @{ */
#define CTIMER_IR_MR0INT_MASK                    (0x1U)
#define CTIMER_IR_MR0INT_SHIFT                   (0U)
#define CTIMER_IR_MR0INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_MR0INT_SHIFT)) & CTIMER_IR_MR0INT_MASK)
#define CTIMER_IR_MR1INT_MASK                    (0x2U)
#define CTIMER_IR_MR1INT_SHIFT                   (1U)
#define CTIMER_IR_MR1INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_MR1INT_SHIFT)) & CTIMER_IR_MR1INT_MASK)
#define CTIMER_IR_MR2INT_MASK                    (0x4U)
#define CTIMER_IR_MR2INT_SHIFT                   (2U)
#define CTIMER_IR_MR2INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_MR2INT_SHIFT)) & CTIMER_IR_MR2INT_MASK)
#define CTIMER_IR_MR3INT_MASK                    (0x8U)
#define CTIMER_IR_MR3INT_SHIFT                   (3U)
#define CTIMER_IR_MR3INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_MR3INT_SHIFT)) & CTIMER_IR_MR3INT_MASK)
/*! @} */

/*! @name TCR - Timer control register. The TCR is used to control the timer counter functions. The TC can be disabled or reset through the TCR */
/*! @{ */
#define CTIMER_TCR_CEN_MASK                      (0x1U)
#define CTIMER_TCR_CEN_SHIFT                     (0U)
#define CTIMER_TCR_CEN(x)                        (((uint32_t)(((uint32_t)(x)) << CTIMER_TCR_CEN_SHIFT)) & CTIMER_TCR_CEN_MASK)
#define CTIMER_TCR_CRST_MASK                     (0x2U)
#define CTIMER_TCR_CRST_SHIFT                    (1U)
#define CTIMER_TCR_CRST(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_TCR_CRST_SHIFT)) & CTIMER_TCR_CRST_MASK)
/*! @} */

/*! @name TC - Timer Counter (TC). The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR. */
/*! @{ */
#define CTIMER_TC_TC_MASK                        (0xFFFFU)
#define CTIMER_TC_TC_SHIFT                       (0U)
#define CTIMER_TC_TC(x)                          (((uint32_t)(((uint32_t)(x)) << CTIMER_TC_TC_SHIFT)) & CTIMER_TC_TC_MASK)
/*! @} */

/*! @name PR - Prescale register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC. */
/*! @{ */
#define CTIMER_PR_PRVAL_MASK                     (0xFFFFFFFFU)
#define CTIMER_PR_PRVAL_SHIFT                    (0U)
#define CTIMER_PR_PRVAL(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_PR_PRVAL_SHIFT)) & CTIMER_PR_PRVAL_MASK)
/*! @} */

/*! @name PC - Prescale Counter (PC). The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface. */
/*! @{ */
#define CTIMER_PC_PC_MASK                        (0xFFFFFFFFU)
#define CTIMER_PC_PC_SHIFT                       (0U)
#define CTIMER_PC_PC(x)                          (((uint32_t)(((uint32_t)(x)) << CTIMER_PC_PC_SHIFT)) & CTIMER_PC_PC_MASK)
/*! @} */

/*! @name MCR - Match Control Register (MCR). The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs. */
/*! @{ */
#define CTIMER_MCR_MR0I_MASK                     (0x1U)
#define CTIMER_MCR_MR0I_SHIFT                    (0U)
/*! MR0I - Interrupt on MR0: an interrupt is generated when MR0 matches the value in the TC
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR0I(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR0I_SHIFT)) & CTIMER_MCR_MR0I_MASK)
#define CTIMER_MCR_MR0R_MASK                     (0x2U)
#define CTIMER_MCR_MR0R_SHIFT                    (1U)
/*! MR0R - Reset on MR0: the TC will be reset if MR0 matches it
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR0R(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR0R_SHIFT)) & CTIMER_MCR_MR0R_MASK)
#define CTIMER_MCR_MR0S_MASK                     (0x4U)
#define CTIMER_MCR_MR0S_SHIFT                    (2U)
/*! MR0S - Stop on MR0: the TC and PC will be stopped and TCR[0] will be set to 0 if MR0 matches the TC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR0S(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR0S_SHIFT)) & CTIMER_MCR_MR0S_MASK)
#define CTIMER_MCR_MR1I_MASK                     (0x8U)
#define CTIMER_MCR_MR1I_SHIFT                    (3U)
/*! MR1I - Interrupt on MR1: an interrupt is generated when MR1 matches the value in the TC
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR1I(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR1I_SHIFT)) & CTIMER_MCR_MR1I_MASK)
#define CTIMER_MCR_MR1R_MASK                     (0x10U)
#define CTIMER_MCR_MR1R_SHIFT                    (4U)
/*! MR1R - Reset on MR1: the TC will be reset if MR1 matches it
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR1R(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR1R_SHIFT)) & CTIMER_MCR_MR1R_MASK)
#define CTIMER_MCR_MR1S_MASK                     (0x20U)
#define CTIMER_MCR_MR1S_SHIFT                    (5U)
/*! MR1S - Stop on MR1: the TC and PC will be stopped and TCR[0] will be set to 0 if MR1 matches the TC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR1S(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR1S_SHIFT)) & CTIMER_MCR_MR1S_MASK)
#define CTIMER_MCR_MR2I_MASK                     (0x40U)
#define CTIMER_MCR_MR2I_SHIFT                    (6U)
/*! MR2I - Interrupt on MR2: an interrupt is generated when MR2 matches the value in the TC
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR2I(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR2I_SHIFT)) & CTIMER_MCR_MR2I_MASK)
#define CTIMER_MCR_MR2R_MASK                     (0x80U)
#define CTIMER_MCR_MR2R_SHIFT                    (7U)
/*! MR2R - Reset on MR2: the TC will be reset if MR2 matches it
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR2R(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR2R_SHIFT)) & CTIMER_MCR_MR2R_MASK)
#define CTIMER_MCR_MR2S_MASK                     (0x100U)
#define CTIMER_MCR_MR2S_SHIFT                    (8U)
/*! MR2S - Stop on MR2: the TC and PC will be stopped and TCR[0] will be set to 0 if MR2 matches the TC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR2S(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR2S_SHIFT)) & CTIMER_MCR_MR2S_MASK)
#define CTIMER_MCR_MR3I_MASK                     (0x200U)
#define CTIMER_MCR_MR3I_SHIFT                    (9U)
/*! MR3I - Interrupt on MR3: an interrupt is generated when MR3 matches the value in the TC
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR3I(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR3I_SHIFT)) & CTIMER_MCR_MR3I_MASK)
#define CTIMER_MCR_MR3R_MASK                     (0x400U)
#define CTIMER_MCR_MR3R_SHIFT                    (10U)
/*! MR3R - Reset on MR3: the TC will be reset if MR3 matches it
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR3R(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR3R_SHIFT)) & CTIMER_MCR_MR3R_MASK)
#define CTIMER_MCR_MR3S_MASK                     (0x800U)
#define CTIMER_MCR_MR3S_SHIFT                    (11U)
/*! MR3S - Stop on MR3: the TC and PC will be stopped and TCR[0] will be set to 0 if MR3 matches the TC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define CTIMER_MCR_MR3S(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR3S_SHIFT)) & CTIMER_MCR_MR3S_MASK)
/*! @} */

/*! @name MR - Match Register 0 (MR0). MR0 can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC. */
/*! @{ */
#define CTIMER_MR_MATCH_MASK                     (0xFFFFFFFFU)
#define CTIMER_MR_MATCH_SHIFT                    (0U)
#define CTIMER_MR_MATCH(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MR_MATCH_SHIFT)) & CTIMER_MR_MATCH_MASK)
/*! @} */

/* The count of CTIMER_MR */
#define CTIMER_MR_COUNT                          (4U)

/*! @name EMR - External Match Register (EMR). The EMR controls the match function and the external match pins CT32B_MAT[1:0]. */
/*! @{ */
#define CTIMER_EMR_EM0_MASK                      (0x1U)
#define CTIMER_EMR_EM0_SHIFT                     (0U)
#define CTIMER_EMR_EM0(x)                        (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EM0_SHIFT)) & CTIMER_EMR_EM0_MASK)
#define CTIMER_EMR_EM1_MASK                      (0x2U)
#define CTIMER_EMR_EM1_SHIFT                     (1U)
#define CTIMER_EMR_EM1(x)                        (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EM1_SHIFT)) & CTIMER_EMR_EM1_MASK)
#define CTIMER_EMR_EMC0_MASK                     (0x30U)
#define CTIMER_EMR_EMC0_SHIFT                    (4U)
/*! EMC0 - External match control 0
 *  0b00..Do Nothing
 *  0b01..Clear the corresponding External Match bit/output to 0 (CT32B_MAT0 pin is LOW if pinned out).
 *  0b10..Set the corresponding External Match bit/output to 1 (CT32B_MAT0 pin is HIGH if pinned out).
 *  0b11..Toggle the corresponding External Match bit/output.
 */
#define CTIMER_EMR_EMC0(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EMC0_SHIFT)) & CTIMER_EMR_EMC0_MASK)
#define CTIMER_EMR_EMC1_MASK                     (0xC0U)
#define CTIMER_EMR_EMC1_SHIFT                    (6U)
/*! EMC1 - External match control 1
 *  0b00..Do Nothing
 *  0b01..Clear the corresponding External Match bit/output to 0 (CT32B_MAT1 pin is LOW if pinned out).
 *  0b10..Set the corresponding External Match bit/output to 1 (CT32B_MAT1 pin is HIGH if pinned out).
 *  0b11..Toggle the corresponding External Match bit/output.
 */
#define CTIMER_EMR_EMC1(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EMC1_SHIFT)) & CTIMER_EMR_EMC1_MASK)
/*! @} */

/*! @name PWMC - PWM Control Register (PWMCON). The PWMCON enables PWM mode for the external match pins CT32B_MAT[1:0]. */
/*! @{ */
#define CTIMER_PWMC_PWMEN0_MASK                  (0x1U)
#define CTIMER_PWMC_PWMEN0_SHIFT                 (0U)
/*! PWMEN0 - PWM channel0 enable
 *  0b0..CT32B_MAT0 is controlled by EM0
 *  0b1..PWM mode is enabled for CT32B_MAT0
 */
#define CTIMER_PWMC_PWMEN0(x)                    (((uint32_t)(((uint32_t)(x)) << CTIMER_PWMC_PWMEN0_SHIFT)) & CTIMER_PWMC_PWMEN0_MASK)
#define CTIMER_PWMC_PWMEN1_MASK                  (0x2U)
#define CTIMER_PWMC_PWMEN1_SHIFT                 (1U)
/*! PWMEN1 - PWM channel1 enable
 *  0b0..CT32B_MAT1 is controlled by EM1
 *  0b1..PWM mode is enabled for CT32B_MAT1
 */
#define CTIMER_PWMC_PWMEN1(x)                    (((uint32_t)(((uint32_t)(x)) << CTIMER_PWMC_PWMEN1_SHIFT)) & CTIMER_PWMC_PWMEN1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CTIMER_Register_Masks */


/* CTIMER - Peripheral instance base addresses */
/** Peripheral CTIMER0 base address */
#define CTIMER0_BASE                             (0x4000C000u)
/** Peripheral CTIMER0 base pointer */
#define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
/** Peripheral CTIMER1 base address */
#define CTIMER1_BASE                             (0x40014000u)
/** Peripheral CTIMER1 base pointer */
#define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
/** Array initializer of CTIMER peripheral base addresses */
#define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE }
/** Array initializer of CTIMER peripheral base pointers */
#define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1 }
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn }

/*!
 * @}
 */ /* end of group CTIMER_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- EEPROM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EEPROM_Peripheral_Access_Layer EEPROM Peripheral Access Layer
 * @{
 */

/** EEPROM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CMD;                               /**< EEPROM command register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t RWSTATE;                           /**< EEPROM read wait state register, offset: 0x8 */
  __IO uint32_t AUTOPROG;                          /**< EEPROM auto programming register, offset: 0xC */
  __IO uint32_t WSTATE;                            /**< EEPROM wait state register, offset: 0x10 */
  __IO uint32_t CLKDIV;                            /**< EEPROM clock divider register, offset: 0x14 */
  __IO uint32_t PWRDWN;                            /**< EEPROM power-down register, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MSSTART;                           /**< EEPROM checksum start address register, offset: 0x20 */
  __IO uint32_t MSSTOP;                            /**< EEPROM checksum stop address register, offset: 0x24 */
  __I  uint32_t MSDATASIG;                         /**< EEPROM Data signature register, offset: 0x28 */
  __I  uint32_t MSPARSIG;                          /**< EEPROM parity signature register, offset: 0x2C */
       uint8_t RESERVED_2[4];
  __I  uint32_t STATUS;                            /**< EEPROM device status register, offset: 0x34 */
  __IO uint32_t ECCRSTERRCNT;                      /**< Invalid flag and error corrected counter reset, offset: 0x38 */
  __IO uint32_t ECCERRCNT;                         /**< ECC status information, offset: 0x3C */
       uint8_t RESERVED_3[20];
  __IO uint32_t CLKDIV1;                           /**< EEPROM initial clock divider register, offset: 0x54 */
  __IO uint32_t CLKDIV2;                           /**< EEPROM clock ramp duration register, offset: 0x58 */
       uint8_t RESERVED_4[3964];
  __O  uint32_t INTENCLR;                          /**< EEPROM interrupt enable clear, offset: 0xFD8 */
  __O  uint32_t INTENSET;                          /**< EEPROM interrupt enable set, offset: 0xFDC */
  __I  uint32_t INTSTAT;                           /**< EEPROM interrupt status, offset: 0xFE0 */
  __I  uint32_t INTEN;                             /**< EEPROM interrupt enable, offset: 0xFE4 */
  __O  uint32_t INTSTATCLR;                        /**< EEPROM interrupt status clear, offset: 0xFE8 */
  __O  uint32_t INTSTATSET;                        /**< EEPROM interrupt status set, offset: 0xFEC */
       uint8_t RESERVED_5[12];
  __I  uint32_t MODULE_ID;                         /**< Controller memory module identification, offset: 0xFFC */
} EEPROM_Type;

/* ----------------------------------------------------------------------------
   -- EEPROM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EEPROM_Register_Masks EEPROM Register Masks
 * @{
 */

/*! @name CMD - EEPROM command register */
/*! @{ */
#define EEPROM_CMD_CMD_MASK                      (0x7U)
#define EEPROM_CMD_CMD_SHIFT                     (0U)
#define EEPROM_CMD_CMD(x)                        (((uint32_t)(((uint32_t)(x)) << EEPROM_CMD_CMD_SHIFT)) & EEPROM_CMD_CMD_MASK)
/*! @} */

/*! @name RWSTATE - EEPROM read wait state register */
/*! @{ */
#define EEPROM_RWSTATE_RPHASE2_MASK              (0xFFU)
#define EEPROM_RWSTATE_RPHASE2_SHIFT             (0U)
#define EEPROM_RWSTATE_RPHASE2(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_RWSTATE_RPHASE2_SHIFT)) & EEPROM_RWSTATE_RPHASE2_MASK)
#define EEPROM_RWSTATE_RPHASE1_MASK              (0xFF00U)
#define EEPROM_RWSTATE_RPHASE1_SHIFT             (8U)
#define EEPROM_RWSTATE_RPHASE1(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_RWSTATE_RPHASE1_SHIFT)) & EEPROM_RWSTATE_RPHASE1_MASK)
/*! @} */

/*! @name AUTOPROG - EEPROM auto programming register */
/*! @{ */
#define EEPROM_AUTOPROG_AUTOPROG_MASK            (0x3U)
#define EEPROM_AUTOPROG_AUTOPROG_SHIFT           (0U)
/*! AUTOPROG - Set auto programming mode
 *  0b00..auto programming switched off
 *  0b01..erase/program cycle is triggered after 1 word is written
 *  0b10..erase/program cycle is triggered after a write to the last word of a page
 *  0b11..(reserved)
 */
#define EEPROM_AUTOPROG_AUTOPROG(x)              (((uint32_t)(((uint32_t)(x)) << EEPROM_AUTOPROG_AUTOPROG_SHIFT)) & EEPROM_AUTOPROG_AUTOPROG_MASK)
/*! @} */

/*! @name WSTATE - EEPROM wait state register */
/*! @{ */
#define EEPROM_WSTATE_PHASE3_MASK                (0xFFU)
#define EEPROM_WSTATE_PHASE3_SHIFT               (0U)
#define EEPROM_WSTATE_PHASE3(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_WSTATE_PHASE3_SHIFT)) & EEPROM_WSTATE_PHASE3_MASK)
#define EEPROM_WSTATE_PHASE2_MASK                (0xFF00U)
#define EEPROM_WSTATE_PHASE2_SHIFT               (8U)
#define EEPROM_WSTATE_PHASE2(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_WSTATE_PHASE2_SHIFT)) & EEPROM_WSTATE_PHASE2_MASK)
#define EEPROM_WSTATE_PHASE1_MASK                (0xFF0000U)
#define EEPROM_WSTATE_PHASE1_SHIFT               (16U)
#define EEPROM_WSTATE_PHASE1(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_WSTATE_PHASE1_SHIFT)) & EEPROM_WSTATE_PHASE1_MASK)
#define EEPROM_WSTATE_LCK_PARWEP_MASK            (0x80000000U)
#define EEPROM_WSTATE_LCK_PARWEP_SHIFT           (31U)
#define EEPROM_WSTATE_LCK_PARWEP(x)              (((uint32_t)(((uint32_t)(x)) << EEPROM_WSTATE_LCK_PARWEP_SHIFT)) & EEPROM_WSTATE_LCK_PARWEP_MASK)
/*! @} */

/*! @name CLKDIV - EEPROM clock divider register */
/*! @{ */
#define EEPROM_CLKDIV_CLKDIV_MASK                (0xFFFFU)
#define EEPROM_CLKDIV_CLKDIV_SHIFT               (0U)
#define EEPROM_CLKDIV_CLKDIV(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_CLKDIV_CLKDIV_SHIFT)) & EEPROM_CLKDIV_CLKDIV_MASK)
#define EEPROM_CLKDIV_CLKMOD_MASK                (0xC0000000U)
#define EEPROM_CLKDIV_CLKMOD_SHIFT               (30U)
#define EEPROM_CLKDIV_CLKMOD(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_CLKDIV_CLKMOD_SHIFT)) & EEPROM_CLKDIV_CLKMOD_MASK)
/*! @} */

/*! @name PWRDWN - EEPROM power-down register */
/*! @{ */
#define EEPROM_PWRDWN_PWRDWN_MASK                (0x1U)
#define EEPROM_PWRDWN_PWRDWN_SHIFT               (0U)
#define EEPROM_PWRDWN_PWRDWN(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_PWRDWN_PWRDWN_SHIFT)) & EEPROM_PWRDWN_PWRDWN_MASK)
/*! @} */

/*! @name MSSTART - EEPROM checksum start address register */
/*! @{ */
#define EEPROM_MSSTART_STARTA_MASK               (0xFFFFU)
#define EEPROM_MSSTART_STARTA_SHIFT              (0U)
#define EEPROM_MSSTART_STARTA(x)                 (((uint32_t)(((uint32_t)(x)) << EEPROM_MSSTART_STARTA_SHIFT)) & EEPROM_MSSTART_STARTA_MASK)
/*! @} */

/*! @name MSSTOP - EEPROM checksum stop address register */
/*! @{ */
#define EEPROM_MSSTOP_STOPA_MASK                 (0xFFFFU)
#define EEPROM_MSSTOP_STOPA_SHIFT                (0U)
#define EEPROM_MSSTOP_STOPA(x)                   (((uint32_t)(((uint32_t)(x)) << EEPROM_MSSTOP_STOPA_SHIFT)) & EEPROM_MSSTOP_STOPA_MASK)
#define EEPROM_MSSTOP_STRTBIST_MASK              (0x80000000U)
#define EEPROM_MSSTOP_STRTBIST_SHIFT             (31U)
#define EEPROM_MSSTOP_STRTBIST(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_MSSTOP_STRTBIST_SHIFT)) & EEPROM_MSSTOP_STRTBIST_MASK)
/*! @} */

/*! @name MSDATASIG - EEPROM Data signature register */
/*! @{ */
#define EEPROM_MSDATASIG_DATA_SIG_MASK           (0xFFFFFFFFU)
#define EEPROM_MSDATASIG_DATA_SIG_SHIFT          (0U)
#define EEPROM_MSDATASIG_DATA_SIG(x)             (((uint32_t)(((uint32_t)(x)) << EEPROM_MSDATASIG_DATA_SIG_SHIFT)) & EEPROM_MSDATASIG_DATA_SIG_MASK)
/*! @} */

/*! @name MSPARSIG - EEPROM parity signature register */
/*! @{ */
#define EEPROM_MSPARSIG_PARITY_SIG_MASK          (0x1U)
#define EEPROM_MSPARSIG_PARITY_SIG_SHIFT         (0U)
#define EEPROM_MSPARSIG_PARITY_SIG(x)            (((uint32_t)(((uint32_t)(x)) << EEPROM_MSPARSIG_PARITY_SIG_SHIFT)) & EEPROM_MSPARSIG_PARITY_SIG_MASK)
/*! @} */

/*! @name STATUS - EEPROM device status register */
/*! @{ */
#define EEPROM_STATUS_HVTRIM_E_MASK              (0xFU)
#define EEPROM_STATUS_HVTRIM_E_SHIFT             (0U)
#define EEPROM_STATUS_HVTRIM_E(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_HVTRIM_E_SHIFT)) & EEPROM_STATUS_HVTRIM_E_MASK)
#define EEPROM_STATUS_HVTRIM_P_MASK              (0xF0U)
#define EEPROM_STATUS_HVTRIM_P_SHIFT             (4U)
#define EEPROM_STATUS_HVTRIM_P(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_HVTRIM_P_SHIFT)) & EEPROM_STATUS_HVTRIM_P_MASK)
#define EEPROM_STATUS_CORRECTED_MASK             (0x100U)
#define EEPROM_STATUS_CORRECTED_SHIFT            (8U)
#define EEPROM_STATUS_CORRECTED(x)               (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_CORRECTED_SHIFT)) & EEPROM_STATUS_CORRECTED_MASK)
#define EEPROM_STATUS_INVALID_MASK               (0x200U)
#define EEPROM_STATUS_INVALID_SHIFT              (9U)
#define EEPROM_STATUS_INVALID(x)                 (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_INVALID_SHIFT)) & EEPROM_STATUS_INVALID_MASK)
#define EEPROM_STATUS_ALL1_MASK                  (0x400U)
#define EEPROM_STATUS_ALL1_SHIFT                 (10U)
#define EEPROM_STATUS_ALL1(x)                    (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_ALL1_SHIFT)) & EEPROM_STATUS_ALL1_MASK)
#define EEPROM_STATUS_ALL0_MASK                  (0x800U)
#define EEPROM_STATUS_ALL0_SHIFT                 (11U)
#define EEPROM_STATUS_ALL0(x)                    (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_ALL0_SHIFT)) & EEPROM_STATUS_ALL0_MASK)
#define EEPROM_STATUS_HVERR_MASK                 (0x1000U)
#define EEPROM_STATUS_HVERR_SHIFT                (12U)
#define EEPROM_STATUS_HVERR(x)                   (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_HVERR_SHIFT)) & EEPROM_STATUS_HVERR_MASK)
#define EEPROM_STATUS_TMANALOG_MASK              (0x2000U)
#define EEPROM_STATUS_TMANALOG_SHIFT             (13U)
#define EEPROM_STATUS_TMANALOG(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_TMANALOG_SHIFT)) & EEPROM_STATUS_TMANALOG_MASK)
#define EEPROM_STATUS_VMPOK_MASK                 (0x4000U)
#define EEPROM_STATUS_VMPOK_SHIFT                (14U)
#define EEPROM_STATUS_VMPOK(x)                   (((uint32_t)(((uint32_t)(x)) << EEPROM_STATUS_VMPOK_SHIFT)) & EEPROM_STATUS_VMPOK_MASK)
/*! @} */

/*! @name ECCRSTERRCNT - Invalid flag and error corrected counter reset */
/*! @{ */
#define EEPROM_ECCRSTERRCNT_ECCRSTERRCNT_MASK    (0x1U)
#define EEPROM_ECCRSTERRCNT_ECCRSTERRCNT_SHIFT   (0U)
#define EEPROM_ECCRSTERRCNT_ECCRSTERRCNT(x)      (((uint32_t)(((uint32_t)(x)) << EEPROM_ECCRSTERRCNT_ECCRSTERRCNT_SHIFT)) & EEPROM_ECCRSTERRCNT_ECCRSTERRCNT_MASK)
/*! @} */

/*! @name ECCERRCNT - ECC status information */
/*! @{ */
#define EEPROM_ECCERRCNT_INVALID_FLAG_MASK       (0x1U)
#define EEPROM_ECCERRCNT_INVALID_FLAG_SHIFT      (0U)
#define EEPROM_ECCERRCNT_INVALID_FLAG(x)         (((uint32_t)(((uint32_t)(x)) << EEPROM_ECCERRCNT_INVALID_FLAG_SHIFT)) & EEPROM_ECCERRCNT_INVALID_FLAG_MASK)
#define EEPROM_ECCERRCNT_ERRCOUNTER_MASK         (0x1EU)
#define EEPROM_ECCERRCNT_ERRCOUNTER_SHIFT        (1U)
#define EEPROM_ECCERRCNT_ERRCOUNTER(x)           (((uint32_t)(((uint32_t)(x)) << EEPROM_ECCERRCNT_ERRCOUNTER_SHIFT)) & EEPROM_ECCERRCNT_ERRCOUNTER_MASK)
#define EEPROM_ECCERRCNT_ERR_PAGE_MASK           (0x3FFE0U)
#define EEPROM_ECCERRCNT_ERR_PAGE_SHIFT          (5U)
#define EEPROM_ECCERRCNT_ERR_PAGE(x)             (((uint32_t)(((uint32_t)(x)) << EEPROM_ECCERRCNT_ERR_PAGE_SHIFT)) & EEPROM_ECCERRCNT_ERR_PAGE_MASK)
/*! @} */

/*! @name CLKDIV1 - EEPROM initial clock divider register */
/*! @{ */
#define EEPROM_CLKDIV1_CLKDIV1_MASK              (0xFFFFU)
#define EEPROM_CLKDIV1_CLKDIV1_SHIFT             (0U)
#define EEPROM_CLKDIV1_CLKDIV1(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_CLKDIV1_CLKDIV1_SHIFT)) & EEPROM_CLKDIV1_CLKDIV1_MASK)
#define EEPROM_CLKDIV1_CLKMOD_MASK               (0xFFFF0000U)
#define EEPROM_CLKDIV1_CLKMOD_SHIFT              (16U)
#define EEPROM_CLKDIV1_CLKMOD(x)                 (((uint32_t)(((uint32_t)(x)) << EEPROM_CLKDIV1_CLKMOD_SHIFT)) & EEPROM_CLKDIV1_CLKMOD_MASK)
/*! @} */

/*! @name CLKDIV2 - EEPROM clock ramp duration register */
/*! @{ */
#define EEPROM_CLKDIV2_CLKDIV2_MASK              (0xFFFFU)
#define EEPROM_CLKDIV2_CLKDIV2_SHIFT             (0U)
#define EEPROM_CLKDIV2_CLKDIV2(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_CLKDIV2_CLKDIV2_SHIFT)) & EEPROM_CLKDIV2_CLKDIV2_MASK)
/*! @} */

/*! @name INTENCLR - EEPROM interrupt enable clear */
/*! @{ */
#define EEPROM_INTENCLR_PROG_CLR_EN_MASK         (0x4U)
#define EEPROM_INTENCLR_PROG_CLR_EN_SHIFT        (2U)
#define EEPROM_INTENCLR_PROG_CLR_EN(x)           (((uint32_t)(((uint32_t)(x)) << EEPROM_INTENCLR_PROG_CLR_EN_SHIFT)) & EEPROM_INTENCLR_PROG_CLR_EN_MASK)
/*! @} */

/*! @name INTENSET - EEPROM interrupt enable set */
/*! @{ */
#define EEPROM_INTENSET_PROG_SET_EN_MASK         (0x4U)
#define EEPROM_INTENSET_PROG_SET_EN_SHIFT        (2U)
#define EEPROM_INTENSET_PROG_SET_EN(x)           (((uint32_t)(((uint32_t)(x)) << EEPROM_INTENSET_PROG_SET_EN_SHIFT)) & EEPROM_INTENSET_PROG_SET_EN_MASK)
/*! @} */

/*! @name INTSTAT - EEPROM interrupt status */
/*! @{ */
#define EEPROM_INTSTAT_END_OF_PROG_MASK          (0x4U)
#define EEPROM_INTSTAT_END_OF_PROG_SHIFT         (2U)
#define EEPROM_INTSTAT_END_OF_PROG(x)            (((uint32_t)(((uint32_t)(x)) << EEPROM_INTSTAT_END_OF_PROG_SHIFT)) & EEPROM_INTSTAT_END_OF_PROG_MASK)
/*! @} */

/*! @name INTEN - EEPROM interrupt enable */
/*! @{ */
#define EEPROM_INTEN_EE_PROG_DONE_MASK           (0x4U)
#define EEPROM_INTEN_EE_PROG_DONE_SHIFT          (2U)
#define EEPROM_INTEN_EE_PROG_DONE(x)             (((uint32_t)(((uint32_t)(x)) << EEPROM_INTEN_EE_PROG_DONE_SHIFT)) & EEPROM_INTEN_EE_PROG_DONE_MASK)
/*! @} */

/*! @name INTSTATCLR - EEPROM interrupt status clear */
/*! @{ */
#define EEPROM_INTSTATCLR_PROG_CLR_ST_MASK       (0x4U)
#define EEPROM_INTSTATCLR_PROG_CLR_ST_SHIFT      (2U)
#define EEPROM_INTSTATCLR_PROG_CLR_ST(x)         (((uint32_t)(((uint32_t)(x)) << EEPROM_INTSTATCLR_PROG_CLR_ST_SHIFT)) & EEPROM_INTSTATCLR_PROG_CLR_ST_MASK)
/*! @} */

/*! @name INTSTATSET - EEPROM interrupt status set */
/*! @{ */
#define EEPROM_INTSTATSET_PROG_SET_ST_MASK       (0x4U)
#define EEPROM_INTSTATSET_PROG_SET_ST_SHIFT      (2U)
#define EEPROM_INTSTATSET_PROG_SET_ST(x)         (((uint32_t)(((uint32_t)(x)) << EEPROM_INTSTATSET_PROG_SET_ST_SHIFT)) & EEPROM_INTSTATSET_PROG_SET_ST_MASK)
/*! @} */

/*! @name MODULE_ID - Controller memory module identification */
/*! @{ */
#define EEPROM_MODULE_ID_APERTURE_MASK           (0xFFU)
#define EEPROM_MODULE_ID_APERTURE_SHIFT          (0U)
#define EEPROM_MODULE_ID_APERTURE(x)             (((uint32_t)(((uint32_t)(x)) << EEPROM_MODULE_ID_APERTURE_SHIFT)) & EEPROM_MODULE_ID_APERTURE_MASK)
#define EEPROM_MODULE_ID_MINOR_REV_MASK          (0xF00U)
#define EEPROM_MODULE_ID_MINOR_REV_SHIFT         (8U)
#define EEPROM_MODULE_ID_MINOR_REV(x)            (((uint32_t)(((uint32_t)(x)) << EEPROM_MODULE_ID_MINOR_REV_SHIFT)) & EEPROM_MODULE_ID_MINOR_REV_MASK)
#define EEPROM_MODULE_ID_MAJOR_REV_MASK          (0xF000U)
#define EEPROM_MODULE_ID_MAJOR_REV_SHIFT         (12U)
#define EEPROM_MODULE_ID_MAJOR_REV(x)            (((uint32_t)(((uint32_t)(x)) << EEPROM_MODULE_ID_MAJOR_REV_SHIFT)) & EEPROM_MODULE_ID_MAJOR_REV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EEPROM_Register_Masks */


/* EEPROM - Peripheral instance base addresses */
/** Peripheral EEPROM base address */
#define EEPROM_BASE                              (0x40034000u)
/** Peripheral EEPROM base pointer */
#define EEPROM                                   ((EEPROM_Type *)EEPROM_BASE)
/** Array initializer of EEPROM peripheral base addresses */
#define EEPROM_BASE_ADDRS                        { EEPROM_BASE }
/** Array initializer of EEPROM peripheral base pointers */
#define EEPROM_BASE_PTRS                         { EEPROM }
/** Interrupt vectors for the EEPROM peripheral type */
#define EEPROM_IRQS                              { EEPROM_IRQn }

/*!
 * @}
 */ /* end of group EEPROM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FLASH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_Peripheral_Access_Layer FLASH Peripheral Access Layer
 * @{
 */

/** FLASH - Register Layout Typedef */
typedef struct {
  __IO uint32_t FCTR;                              /**< Flash Control register, offset: 0x0 */
  __I  uint32_t FSTAT;                             /**< Flash status register, offset: 0x4 */
  __IO uint32_t FPTR;                              /**< Flash program-time register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t FBWST;                             /**< Flash wait state register, offset: 0x10 */
       uint8_t RESERVED_1[8];
  __IO uint32_t FCRA;                              /**< Flash program clock divider, offset: 0x1C */
  __IO uint32_t FMSSTART;                          /**< Flash checksum start address register, offset: 0x20 */
  __IO uint32_t FMSSTOP;                           /**< Flash checksum stop address register, offset: 0x24 */
  __I  uint32_t FMS16;                             /**< Flash parity signature register, offset: 0x28 */
  __I  uint32_t FMSW0;                             /**< Flash data signature register, offset: 0x2C */
       uint8_t RESERVED_2[32];
  __IO uint32_t ECCRSTERRCNT;                      /**< Invalid flag and error corrected counter reset, offset: 0x50 */
  __IO uint32_t ECCERRCNT;                         /**< ECC status information, offset: 0x54 */
       uint8_t RESERVED_3[3968];
  __IO uint32_t INT_CLR_ENABLE;                    /**< Clear interrupt enable bits, offset: 0xFD8 */
  __IO uint32_t INT_SET_ENABLE;                    /**< Set interrupt enable bits, offset: 0xFDC */
  __I  uint32_t INT_STATUS;                        /**< Interrupt status bits, offset: 0xFE0 */
  __I  uint32_t INT_ENABLE;                        /**< Interrupt enable bits, offset: 0xFE4 */
  __IO uint32_t INT_CLR_STATUS;                    /**< Clear interrupt status bits, offset: 0xFE8 */
  __IO uint32_t INT_SET_STATUS;                    /**< Set interrupt status bits, offset: 0xFEC */
       uint8_t RESERVED_4[12];
  __I  uint32_t MODULE_ID;                         /**< Controller memory module identification, offset: 0xFFC */
} FLASH_Type;

/* ----------------------------------------------------------------------------
   -- FLASH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_Register_Masks FLASH Register Masks
 * @{
 */

/*! @name FCTR - Flash Control register */
/*! @{ */
#define FLASH_FCTR_CS_MASK                       (0x1U)
#define FLASH_FCTR_CS_SHIFT                      (0U)
#define FLASH_FCTR_CS(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_CS_SHIFT)) & FLASH_FCTR_CS_MASK)
#define FLASH_FCTR_WRE_MASK                      (0x2U)
#define FLASH_FCTR_WRE_SHIFT                     (1U)
#define FLASH_FCTR_WRE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_WRE_SHIFT)) & FLASH_FCTR_WRE_MASK)
#define FLASH_FCTR_WEB_MASK                      (0x4U)
#define FLASH_FCTR_WEB_SHIFT                     (2U)
#define FLASH_FCTR_WEB(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_WEB_SHIFT)) & FLASH_FCTR_WEB_MASK)
#define FLASH_FCTR_DCR_MASK                      (0x10U)
#define FLASH_FCTR_DCR_SHIFT                     (4U)
#define FLASH_FCTR_DCR(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_DCR_SHIFT)) & FLASH_FCTR_DCR_MASK)
#define FLASH_FCTR_RLD_MASK                      (0x20U)
#define FLASH_FCTR_RLD_SHIFT                     (5U)
#define FLASH_FCTR_RLD(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_RLD_SHIFT)) & FLASH_FCTR_RLD_MASK)
#define FLASH_FCTR_ISS_MASK                      (0x40U)
#define FLASH_FCTR_ISS_SHIFT                     (6U)
#define FLASH_FCTR_ISS(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_ISS_SHIFT)) & FLASH_FCTR_ISS_MASK)
#define FLASH_FCTR_WPB_MASK                      (0x80U)
#define FLASH_FCTR_WPB_SHIFT                     (7U)
#define FLASH_FCTR_WPB(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_WPB_SHIFT)) & FLASH_FCTR_WPB_MASK)
#define FLASH_FCTR_ERSP_MASK                     (0x100U)
#define FLASH_FCTR_ERSP_SHIFT                    (8U)
#define FLASH_FCTR_ERSP(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_ERSP_SHIFT)) & FLASH_FCTR_ERSP_MASK)
#define FLASH_FCTR_PD_MASK                       (0x200U)
#define FLASH_FCTR_PD_SHIFT                      (9U)
#define FLASH_FCTR_PD(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_PD_SHIFT)) & FLASH_FCTR_PD_MASK)
#define FLASH_FCTR_PDL_MASK                      (0x400U)
#define FLASH_FCTR_PDL_SHIFT                     (10U)
#define FLASH_FCTR_PDL(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_PDL_SHIFT)) & FLASH_FCTR_PDL_MASK)
#define FLASH_FCTR_RLS_MASK                      (0x800U)
#define FLASH_FCTR_RLS_SHIFT                     (11U)
#define FLASH_FCTR_RLS(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_RLS_SHIFT)) & FLASH_FCTR_RLS_MASK)
#define FLASH_FCTR_PROGREQ_MASK                  (0x1000U)
#define FLASH_FCTR_PROGREQ_SHIFT                 (12U)
#define FLASH_FCTR_PROGREQ(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_PROGREQ_SHIFT)) & FLASH_FCTR_PROGREQ_MASK)
#define FLASH_FCTR_LOADREQ_MASK                  (0x8000U)
#define FLASH_FCTR_LOADREQ_SHIFT                 (15U)
#define FLASH_FCTR_LOADREQ(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_LOADREQ_SHIFT)) & FLASH_FCTR_LOADREQ_MASK)
#define FLASH_FCTR_REMAP_MASK                    (0x10000U)
#define FLASH_FCTR_REMAP_SHIFT                   (16U)
#define FLASH_FCTR_REMAP(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_REMAP_SHIFT)) & FLASH_FCTR_REMAP_MASK)
#define FLASH_FCTR_INIT_WR_MASK                  (0x20000U)
#define FLASH_FCTR_INIT_WR_SHIFT                 (17U)
#define FLASH_FCTR_INIT_WR(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_INIT_WR_SHIFT)) & FLASH_FCTR_INIT_WR_MASK)
#define FLASH_FCTR_LPM_MASK                      (0x40000U)
#define FLASH_FCTR_LPM_SHIFT                     (18U)
#define FLASH_FCTR_LPM(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_LPM_SHIFT)) & FLASH_FCTR_LPM_MASK)
#define FLASH_FCTR_PDBG_MASK                     (0x80000U)
#define FLASH_FCTR_PDBG_SHIFT                    (19U)
#define FLASH_FCTR_PDBG(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_FCTR_PDBG_SHIFT)) & FLASH_FCTR_PDBG_MASK)
/*! @} */

/*! @name FSTAT - Flash status register */
/*! @{ */
#define FLASH_FSTAT_RY_MASK                      (0x4U)
#define FLASH_FSTAT_RY_SHIFT                     (2U)
#define FLASH_FSTAT_RY(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FSTAT_RY_SHIFT)) & FLASH_FSTAT_RY_MASK)
#define FLASH_FSTAT_SL_MASK                      (0xE0U)
#define FLASH_FSTAT_SL_SHIFT                     (5U)
#define FLASH_FSTAT_SL(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_FSTAT_SL_SHIFT)) & FLASH_FSTAT_SL_MASK)
#define FLASH_FSTAT_CORRECTED_MASK               (0x100U)
#define FLASH_FSTAT_CORRECTED_SHIFT              (8U)
#define FLASH_FSTAT_CORRECTED(x)                 (((uint32_t)(((uint32_t)(x)) << FLASH_FSTAT_CORRECTED_SHIFT)) & FLASH_FSTAT_CORRECTED_MASK)
/*! @} */

/*! @name FPTR - Flash program-time register */
/*! @{ */
#define FLASH_FPTR_EN_T_MASK                     (0x1U)
#define FLASH_FPTR_EN_T_SHIFT                    (0U)
#define FLASH_FPTR_EN_T(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_FPTR_EN_T_SHIFT)) & FLASH_FPTR_EN_T_MASK)
#define FLASH_FPTR_TR_MASK                       (0x1FFFFFFEU)
#define FLASH_FPTR_TR_SHIFT                      (1U)
#define FLASH_FPTR_TR(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_FPTR_TR_SHIFT)) & FLASH_FPTR_TR_MASK)
/*! @} */

/*! @name FBWST - Flash wait state register */
/*! @{ */
#define FLASH_FBWST_WST_MASK                     (0xFFU)
#define FLASH_FBWST_WST_SHIFT                    (0U)
#define FLASH_FBWST_WST(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_FBWST_WST_SHIFT)) & FLASH_FBWST_WST_MASK)
#define FLASH_FBWST_SPECALWAYS_MASK              (0x4000U)
#define FLASH_FBWST_SPECALWAYS_SHIFT             (14U)
#define FLASH_FBWST_SPECALWAYS(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_FBWST_SPECALWAYS_SHIFT)) & FLASH_FBWST_SPECALWAYS_MASK)
#define FLASH_FBWST_CACHE2EN_MASK                (0x8000U)
#define FLASH_FBWST_CACHE2EN_SHIFT               (15U)
#define FLASH_FBWST_CACHE2EN(x)                  (((uint32_t)(((uint32_t)(x)) << FLASH_FBWST_CACHE2EN_SHIFT)) & FLASH_FBWST_CACHE2EN_MASK)
/*! @} */

/*! @name FCRA - Flash program clock divider */
/*! @{ */
#define FLASH_FCRA_FCRA_MASK                     (0xFFFU)
#define FLASH_FCRA_FCRA_SHIFT                    (0U)
#define FLASH_FCRA_FCRA(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_FCRA_FCRA_SHIFT)) & FLASH_FCRA_FCRA_MASK)
/*! @} */

/*! @name FMSSTART - Flash checksum start address register */
/*! @{ */
#define FLASH_FMSSTART_STARTA_MASK               (0x1FFFFU)
#define FLASH_FMSSTART_STARTA_SHIFT              (0U)
#define FLASH_FMSSTART_STARTA(x)                 (((uint32_t)(((uint32_t)(x)) << FLASH_FMSSTART_STARTA_SHIFT)) & FLASH_FMSSTART_STARTA_MASK)
/*! @} */

/*! @name FMSSTOP - Flash checksum stop address register */
/*! @{ */
#define FLASH_FMSSTOP_STOPA_MASK                 (0x1FFFFU)
#define FLASH_FMSSTOP_STOPA_SHIFT                (0U)
#define FLASH_FMSSTOP_STOPA(x)                   (((uint32_t)(((uint32_t)(x)) << FLASH_FMSSTOP_STOPA_SHIFT)) & FLASH_FMSSTOP_STOPA_MASK)
#define FLASH_FMSSTOP_STRTBIST_MASK              (0x80000000U)
#define FLASH_FMSSTOP_STRTBIST_SHIFT             (31U)
#define FLASH_FMSSTOP_STRTBIST(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_FMSSTOP_STRTBIST_SHIFT)) & FLASH_FMSSTOP_STRTBIST_MASK)
/*! @} */

/*! @name FMS16 - Flash parity signature register */
/*! @{ */
#define FLASH_FMS16_FMS16_MASK                   (0xFFFFU)
#define FLASH_FMS16_FMS16_SHIFT                  (0U)
#define FLASH_FMS16_FMS16(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_FMS16_FMS16_SHIFT)) & FLASH_FMS16_FMS16_MASK)
/*! @} */

/*! @name FMSW0 - Flash data signature register */
/*! @{ */
#define FLASH_FMSW0_FMSW0_MASK                   (0xFFFFFFFFU)
#define FLASH_FMSW0_FMSW0_SHIFT                  (0U)
#define FLASH_FMSW0_FMSW0(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_FMSW0_FMSW0_SHIFT)) & FLASH_FMSW0_FMSW0_MASK)
/*! @} */

/*! @name ECCRSTERRCNT - Invalid flag and error corrected counter reset */
/*! @{ */
#define FLASH_ECCRSTERRCNT_ECCRSTERRCNT_MASK     (0x1U)
#define FLASH_ECCRSTERRCNT_ECCRSTERRCNT_SHIFT    (0U)
#define FLASH_ECCRSTERRCNT_ECCRSTERRCNT(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_ECCRSTERRCNT_ECCRSTERRCNT_SHIFT)) & FLASH_ECCRSTERRCNT_ECCRSTERRCNT_MASK)
/*! @} */

/*! @name ECCERRCNT - ECC status information */
/*! @{ */
#define FLASH_ECCERRCNT_INVALID_FLAG_MASK        (0x1U)
#define FLASH_ECCERRCNT_INVALID_FLAG_SHIFT       (0U)
#define FLASH_ECCERRCNT_INVALID_FLAG(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_ECCERRCNT_INVALID_FLAG_SHIFT)) & FLASH_ECCERRCNT_INVALID_FLAG_MASK)
#define FLASH_ECCERRCNT_ERRCOUNTER_MASK          (0x1EU)
#define FLASH_ECCERRCNT_ERRCOUNTER_SHIFT         (1U)
#define FLASH_ECCERRCNT_ERRCOUNTER(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_ECCERRCNT_ERRCOUNTER_SHIFT)) & FLASH_ECCERRCNT_ERRCOUNTER_MASK)
#define FLASH_ECCERRCNT_ERR_PAGE_MASK            (0x3FFE0U)
#define FLASH_ECCERRCNT_ERR_PAGE_SHIFT           (5U)
#define FLASH_ECCERRCNT_ERR_PAGE(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_ECCERRCNT_ERR_PAGE_SHIFT)) & FLASH_ECCERRCNT_ERR_PAGE_MASK)
/*! @} */

/*! @name INT_CLR_ENABLE - Clear interrupt enable bits */
/*! @{ */
#define FLASH_INT_CLR_ENABLE_CLR_ENABLE_MASK     (0xFFFFFFFFU)
#define FLASH_INT_CLR_ENABLE_CLR_ENABLE_SHIFT    (0U)
#define FLASH_INT_CLR_ENABLE_CLR_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_INT_CLR_ENABLE_CLR_ENABLE_SHIFT)) & FLASH_INT_CLR_ENABLE_CLR_ENABLE_MASK)
/*! @} */

/*! @name INT_SET_ENABLE - Set interrupt enable bits */
/*! @{ */
#define FLASH_INT_SET_ENABLE_SET_ENABLE_MASK     (0xFFFFFFFFU)
#define FLASH_INT_SET_ENABLE_SET_ENABLE_SHIFT    (0U)
#define FLASH_INT_SET_ENABLE_SET_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_INT_SET_ENABLE_SET_ENABLE_SHIFT)) & FLASH_INT_SET_ENABLE_SET_ENABLE_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt status bits */
/*! @{ */
#define FLASH_INT_STATUS_SIG_DONE_MASK           (0x2U)
#define FLASH_INT_STATUS_SIG_DONE_SHIFT          (1U)
#define FLASH_INT_STATUS_SIG_DONE(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_INT_STATUS_SIG_DONE_SHIFT)) & FLASH_INT_STATUS_SIG_DONE_MASK)
#define FLASH_INT_STATUS_PROG_DONE_MASK          (0x4U)
#define FLASH_INT_STATUS_PROG_DONE_SHIFT         (2U)
#define FLASH_INT_STATUS_PROG_DONE(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_INT_STATUS_PROG_DONE_SHIFT)) & FLASH_INT_STATUS_PROG_DONE_MASK)
#define FLASH_INT_STATUS_ECC_ERR_MASK            (0x8U)
#define FLASH_INT_STATUS_ECC_ERR_SHIFT           (3U)
#define FLASH_INT_STATUS_ECC_ERR(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_INT_STATUS_ECC_ERR_SHIFT)) & FLASH_INT_STATUS_ECC_ERR_MASK)
/*! @} */

/*! @name INT_ENABLE - Interrupt enable bits */
/*! @{ */
#define FLASH_INT_ENABLE_INT_ENABLE_MASK         (0xFFFFFFFFU)
#define FLASH_INT_ENABLE_INT_ENABLE_SHIFT        (0U)
#define FLASH_INT_ENABLE_INT_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_INT_ENABLE_INT_ENABLE_SHIFT)) & FLASH_INT_ENABLE_INT_ENABLE_MASK)
/*! @} */

/*! @name INT_CLR_STATUS - Clear interrupt status bits */
/*! @{ */
#define FLASH_INT_CLR_STATUS_CLR_STATUS_MASK     (0xFFFFFFFFU)
#define FLASH_INT_CLR_STATUS_CLR_STATUS_SHIFT    (0U)
#define FLASH_INT_CLR_STATUS_CLR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_INT_CLR_STATUS_CLR_STATUS_SHIFT)) & FLASH_INT_CLR_STATUS_CLR_STATUS_MASK)
/*! @} */

/*! @name INT_SET_STATUS - Set interrupt status bits */
/*! @{ */
#define FLASH_INT_SET_STATUS_SET_STATUS_MASK     (0xFFFFFFFFU)
#define FLASH_INT_SET_STATUS_SET_STATUS_SHIFT    (0U)
#define FLASH_INT_SET_STATUS_SET_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_INT_SET_STATUS_SET_STATUS_SHIFT)) & FLASH_INT_SET_STATUS_SET_STATUS_MASK)
/*! @} */

/*! @name MODULE_ID - Controller memory module identification */
/*! @{ */
#define FLASH_MODULE_ID_APERTURE_MASK            (0xFFU)
#define FLASH_MODULE_ID_APERTURE_SHIFT           (0U)
#define FLASH_MODULE_ID_APERTURE(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_MODULE_ID_APERTURE_SHIFT)) & FLASH_MODULE_ID_APERTURE_MASK)
#define FLASH_MODULE_ID_MINOR_REV_MASK           (0xF00U)
#define FLASH_MODULE_ID_MINOR_REV_SHIFT          (8U)
#define FLASH_MODULE_ID_MINOR_REV(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_MODULE_ID_MINOR_REV_SHIFT)) & FLASH_MODULE_ID_MINOR_REV_MASK)
#define FLASH_MODULE_ID_MAJOR_REV_MASK           (0xF000U)
#define FLASH_MODULE_ID_MAJOR_REV_SHIFT          (12U)
#define FLASH_MODULE_ID_MAJOR_REV(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_MODULE_ID_MAJOR_REV_SHIFT)) & FLASH_MODULE_ID_MAJOR_REV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_Register_Masks */


/* FLASH - Peripheral instance base addresses */
/** Peripheral FLASH base address */
#define FLASH_BASE                               (0x4003C000u)
/** Peripheral FLASH base pointer */
#define FLASH                                    ((FLASH_Type *)FLASH_BASE)
/** Array initializer of FLASH peripheral base addresses */
#define FLASH_BASE_ADDRS                         { FLASH_BASE }
/** Array initializer of FLASH peripheral base pointers */
#define FLASH_BASE_PTRS                          { FLASH }

/*!
 * @}
 */ /* end of group FLASH_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPIODATA[4096];                    /**< data address masking register locations for pins PIO0_0 to PIO0_11, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[16384];
  __IO uint32_t DIR;                               /**< Data direction register, offset: 0x8000 */
  __IO uint32_t IS;                                /**< Interrupt sense register, offset: 0x8004 */
  __IO uint32_t IBE;                               /**< Interrupt both edges register, offset: 0x8008 */
  __IO uint32_t IEV;                               /**< Interrupt event register, offset: 0x800C */
  __IO uint32_t IMSC;                              /**< Interrupt mask register, offset: 0x8010 */
  __I  uint32_t RIS;                               /**< Raw Interrupt status register, offset: 0x8014 */
  __I  uint32_t MIS;                               /**< Masked interrupt status register, offset: 0x8018 */
  __O  uint32_t IC;                                /**< Interrupt clear register, offset: 0x801C */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name GPIODATA - data address masking register locations for pins PIO0_0 to PIO0_11 */
/*! @{ */
#define GPIO_GPIODATA_DATA_MASK                  (0xFFFU)
#define GPIO_GPIODATA_DATA_SHIFT                 (0U)
#define GPIO_GPIODATA_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << GPIO_GPIODATA_DATA_SHIFT)) & GPIO_GPIODATA_DATA_MASK)
/*! @} */

/* The count of GPIO_GPIODATA */
#define GPIO_GPIODATA_COUNT                      (4096U)

/*! @name DIR - Data direction register */
/*! @{ */
#define GPIO_DIR_IO_MASK                         (0xFFFU)
#define GPIO_DIR_IO_SHIFT                        (0U)
#define GPIO_DIR_IO(x)                           (((uint32_t)(((uint32_t)(x)) << GPIO_DIR_IO_SHIFT)) & GPIO_DIR_IO_MASK)
/*! @} */

/*! @name IS - Interrupt sense register */
/*! @{ */
#define GPIO_IS_ISENSE_MASK                      (0xFFFU)
#define GPIO_IS_ISENSE_SHIFT                     (0U)
#define GPIO_IS_ISENSE(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_IS_ISENSE_SHIFT)) & GPIO_IS_ISENSE_MASK)
/*! @} */

/*! @name IBE - Interrupt both edges register */
/*! @{ */
#define GPIO_IBE_IBE_MASK                        (0xFFFU)
#define GPIO_IBE_IBE_SHIFT                       (0U)
#define GPIO_IBE_IBE(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_IBE_IBE_SHIFT)) & GPIO_IBE_IBE_MASK)
/*! @} */

/*! @name IEV - Interrupt event register */
/*! @{ */
#define GPIO_IEV_IEV_MASK                        (0xFFFU)
#define GPIO_IEV_IEV_SHIFT                       (0U)
#define GPIO_IEV_IEV(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_IEV_IEV_SHIFT)) & GPIO_IEV_IEV_MASK)
/*! @} */

/*! @name IMSC - Interrupt mask register */
/*! @{ */
#define GPIO_IMSC_MASK_MASK                      (0xFFFU)
#define GPIO_IMSC_MASK_SHIFT                     (0U)
#define GPIO_IMSC_MASK(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_IMSC_MASK_SHIFT)) & GPIO_IMSC_MASK_MASK)
/*! @} */

/*! @name RIS - Raw Interrupt status register */
/*! @{ */
#define GPIO_RIS_RAWST_MASK                      (0xFFFU)
#define GPIO_RIS_RAWST_SHIFT                     (0U)
#define GPIO_RIS_RAWST(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_RIS_RAWST_SHIFT)) & GPIO_RIS_RAWST_MASK)
/*! @} */

/*! @name MIS - Masked interrupt status register */
/*! @{ */
#define GPIO_MIS_MASK_MASK                       (0xFFFU)
#define GPIO_MIS_MASK_SHIFT                      (0U)
#define GPIO_MIS_MASK(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_MIS_MASK_SHIFT)) & GPIO_MIS_MASK_MASK)
/*! @} */

/*! @name IC - Interrupt clear register */
/*! @{ */
#define GPIO_IC_CLR_MASK                         (0xFFFU)
#define GPIO_IC_CLR_SHIFT                        (0U)
#define GPIO_IC_CLR(x)                           (((uint32_t)(((uint32_t)(x)) << GPIO_IC_CLR_SHIFT)) & GPIO_IC_CLR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO base address */
#define GPIO_BASE                                (0x50000000u)
/** Peripheral GPIO base pointer */
#define GPIO                                     ((GPIO_Type *)GPIO_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO }

/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- I2C0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C0_Peripheral_Access_Layer I2C0 Peripheral Access Layer
 * @{
 */

/** I2C0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONSET;                            /**< I2C Control Set Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is set. Writing a zero has no effect on the corresponding bit in the I2C control register., offset: 0x0 */
  __I  uint32_t STAT;                              /**< I2C Status Register. During I2C operation, this register provides detailed status codes that allow software to determine the next action needed., offset: 0x4 */
  __IO uint32_t DAT;                               /**< I2C Data Register. During master or slave transmit mode, data to be transmitted is written to this register. During master or slave receive mode, data that has been received may be read from this register., offset: 0x8 */
  __IO uint32_t ADR0;                              /**< I2C Slave Address Register 0. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address. This address is also used for device wakeup., offset: 0xC */
  __IO uint32_t SCLH;                              /**< SCH Duty Cycle Register High Half Word. Determines the high time of the I2C clock., offset: 0x10 */
  __IO uint32_t SCLL;                              /**< SCL Duty Cycle Register Low Half Word. Determines the low time of the I2C clock. I2nSCLL and I2nSCLH together determine the clock frequency generated by an I2C master and certain times used in slave mode., offset: 0x14 */
  __IO uint32_t CONCLR;                            /**< I2C Control Clear Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is cleared. Writing a zero has no effect on the corresponding bit in the I2C control register, offset: 0x18 */
  __IO uint32_t MMCTRL;                            /**< Monitor mode control register, offset: 0x1C */
  __IO uint32_t ADR1;                              /**< I2C Slave Address Register 1. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address., offset: 0x20 */
  __IO uint32_t ADR2;                              /**< I2C Slave Address Register 2. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address, offset: 0x24 */
  __IO uint32_t ADR3;                              /**< I2C Slave Address Register 3. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address, offset: 0x28 */
  __I  uint32_t DATA_BUFFER;                       /**< Data buffer register. The contents of the 8 MSBs of the DAT shift register will be transferred to the DATA_BUFFER automatically after every nine bits (8 bits of data plus ACK or NACK) has been received on the bus., offset: 0x2C */
  __IO uint32_t MASK0;                             /**< I2C Slave address mask register 0. This mask register is associated with ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (0x0000000)., offset: 0x30 */
  __IO uint32_t MASK1;                             /**< I2C Slave address mask register 1. This mask register is associated with ADR1 to determine an address match. The mask register has no effect when comparing to the General Call address (0x0000000)., offset: 0x34 */
  __IO uint32_t MASK2;                             /**< I2C Slave address mask register 2. This mask register is associated with ADR2 to determine an address match. The mask register has no effect when comparing to the General Call address (0x0000000)., offset: 0x38 */
  __IO uint32_t MASK3;                             /**< I2C Slave address mask register 3. This mask register is associated with ADR3 to determine an address match. The mask register has no effect when comparing to the General Call address (0x0000000)., offset: 0x3C */
} I2C0_Type;

/* ----------------------------------------------------------------------------
   -- I2C0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C0_Register_Masks I2C0 Register Masks
 * @{
 */

/*! @name CONSET - I2C Control Set Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is set. Writing a zero has no effect on the corresponding bit in the I2C control register. */
/*! @{ */
#define I2C0_CONSET_AA_MASK                      (0x4U)
#define I2C0_CONSET_AA_SHIFT                     (2U)
#define I2C0_CONSET_AA(x)                        (((uint32_t)(((uint32_t)(x)) << I2C0_CONSET_AA_SHIFT)) & I2C0_CONSET_AA_MASK)
#define I2C0_CONSET_SI_MASK                      (0x8U)
#define I2C0_CONSET_SI_SHIFT                     (3U)
#define I2C0_CONSET_SI(x)                        (((uint32_t)(((uint32_t)(x)) << I2C0_CONSET_SI_SHIFT)) & I2C0_CONSET_SI_MASK)
#define I2C0_CONSET_STO_MASK                     (0x10U)
#define I2C0_CONSET_STO_SHIFT                    (4U)
#define I2C0_CONSET_STO(x)                       (((uint32_t)(((uint32_t)(x)) << I2C0_CONSET_STO_SHIFT)) & I2C0_CONSET_STO_MASK)
#define I2C0_CONSET_STA_MASK                     (0x20U)
#define I2C0_CONSET_STA_SHIFT                    (5U)
#define I2C0_CONSET_STA(x)                       (((uint32_t)(((uint32_t)(x)) << I2C0_CONSET_STA_SHIFT)) & I2C0_CONSET_STA_MASK)
#define I2C0_CONSET_I2EN_MASK                    (0x40U)
#define I2C0_CONSET_I2EN_SHIFT                   (6U)
#define I2C0_CONSET_I2EN(x)                      (((uint32_t)(((uint32_t)(x)) << I2C0_CONSET_I2EN_SHIFT)) & I2C0_CONSET_I2EN_MASK)
/*! @} */

/*! @name STAT - I2C Status Register. During I2C operation, this register provides detailed status codes that allow software to determine the next action needed. */
/*! @{ */
#define I2C0_STAT_Status_MASK                    (0xF8U)
#define I2C0_STAT_Status_SHIFT                   (3U)
#define I2C0_STAT_Status(x)                      (((uint32_t)(((uint32_t)(x)) << I2C0_STAT_Status_SHIFT)) & I2C0_STAT_Status_MASK)
/*! @} */

/*! @name DAT - I2C Data Register. During master or slave transmit mode, data to be transmitted is written to this register. During master or slave receive mode, data that has been received may be read from this register. */
/*! @{ */
#define I2C0_DAT_DATA_MASK                       (0xFFU)
#define I2C0_DAT_DATA_SHIFT                      (0U)
#define I2C0_DAT_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << I2C0_DAT_DATA_SHIFT)) & I2C0_DAT_DATA_MASK)
/*! @} */

/*! @name ADR0 - I2C Slave Address Register 0. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address. This address is also used for device wakeup. */
/*! @{ */
#define I2C0_ADR0_GC_MASK                        (0x1U)
#define I2C0_ADR0_GC_SHIFT                       (0U)
#define I2C0_ADR0_GC(x)                          (((uint32_t)(((uint32_t)(x)) << I2C0_ADR0_GC_SHIFT)) & I2C0_ADR0_GC_MASK)
#define I2C0_ADR0_ADDRESS_MASK                   (0xFEU)
#define I2C0_ADR0_ADDRESS_SHIFT                  (1U)
#define I2C0_ADR0_ADDRESS(x)                     (((uint32_t)(((uint32_t)(x)) << I2C0_ADR0_ADDRESS_SHIFT)) & I2C0_ADR0_ADDRESS_MASK)
/*! @} */

/*! @name SCLH - SCH Duty Cycle Register High Half Word. Determines the high time of the I2C clock. */
/*! @{ */
#define I2C0_SCLH_SCLH_MASK                      (0xFFFFU)
#define I2C0_SCLH_SCLH_SHIFT                     (0U)
#define I2C0_SCLH_SCLH(x)                        (((uint32_t)(((uint32_t)(x)) << I2C0_SCLH_SCLH_SHIFT)) & I2C0_SCLH_SCLH_MASK)
/*! @} */

/*! @name SCLL - SCL Duty Cycle Register Low Half Word. Determines the low time of the I2C clock. I2nSCLL and I2nSCLH together determine the clock frequency generated by an I2C master and certain times used in slave mode. */
/*! @{ */
#define I2C0_SCLL_SCLL_MASK                      (0xFFFFU)
#define I2C0_SCLL_SCLL_SHIFT                     (0U)
#define I2C0_SCLL_SCLL(x)                        (((uint32_t)(((uint32_t)(x)) << I2C0_SCLL_SCLL_SHIFT)) & I2C0_SCLL_SCLL_MASK)
/*! @} */

/*! @name CONCLR - I2C Control Clear Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is cleared. Writing a zero has no effect on the corresponding bit in the I2C control register */
/*! @{ */
#define I2C0_CONCLR_AAC_MASK                     (0x4U)
#define I2C0_CONCLR_AAC_SHIFT                    (2U)
#define I2C0_CONCLR_AAC(x)                       (((uint32_t)(((uint32_t)(x)) << I2C0_CONCLR_AAC_SHIFT)) & I2C0_CONCLR_AAC_MASK)
#define I2C0_CONCLR_SIC_MASK                     (0x8U)
#define I2C0_CONCLR_SIC_SHIFT                    (3U)
#define I2C0_CONCLR_SIC(x)                       (((uint32_t)(((uint32_t)(x)) << I2C0_CONCLR_SIC_SHIFT)) & I2C0_CONCLR_SIC_MASK)
#define I2C0_CONCLR_STAC_MASK                    (0x20U)
#define I2C0_CONCLR_STAC_SHIFT                   (5U)
#define I2C0_CONCLR_STAC(x)                      (((uint32_t)(((uint32_t)(x)) << I2C0_CONCLR_STAC_SHIFT)) & I2C0_CONCLR_STAC_MASK)
#define I2C0_CONCLR_I2ENC_MASK                   (0x40U)
#define I2C0_CONCLR_I2ENC_SHIFT                  (6U)
#define I2C0_CONCLR_I2ENC(x)                     (((uint32_t)(((uint32_t)(x)) << I2C0_CONCLR_I2ENC_SHIFT)) & I2C0_CONCLR_I2ENC_MASK)
/*! @} */

/*! @name MMCTRL - Monitor mode control register */
/*! @{ */
#define I2C0_MMCTRL_MM_ENA_MASK                  (0x1U)
#define I2C0_MMCTRL_MM_ENA_SHIFT                 (0U)
/*! MM_ENA - Monitor mode enable
 *  0b0..Monitor mode disabled
 *  0b1..The I2C module will enter monitor mode. In this mode the SDA output will be forced high. This will prevent the I2C module from outputting data of any kind (including ACK) onto the I2C data bus. Depending on the state of the ENA_SCL bit, the output may be also forced high, preventing the module from having control over the I2C clock line.
 */
#define I2C0_MMCTRL_MM_ENA(x)                    (((uint32_t)(((uint32_t)(x)) << I2C0_MMCTRL_MM_ENA_SHIFT)) & I2C0_MMCTRL_MM_ENA_MASK)
#define I2C0_MMCTRL_ENA_SCL_MASK                 (0x2U)
#define I2C0_MMCTRL_ENA_SCL_SHIFT                (1U)
/*! ENA_SCL - SCL output enable
 *  0b0..When this bit is cleared to 0, the SCL output will be forced high when the module is in monitor mode. As described above, this will prevent the module from having any control over the I2C clock line.
 *  0b1..When this bit is set, the I2C module may exercise the same control over the clock line that it would in normal operation. This means that, acting as a slave peripheral, the I2C module can stretch the clock line (hold it low) until it has had time to respond to an I2C interrupt
 */
#define I2C0_MMCTRL_ENA_SCL(x)                   (((uint32_t)(((uint32_t)(x)) << I2C0_MMCTRL_ENA_SCL_SHIFT)) & I2C0_MMCTRL_ENA_SCL_MASK)
#define I2C0_MMCTRL_MATCH_ALL_MASK               (0x4U)
#define I2C0_MMCTRL_MATCH_ALL_SHIFT              (2U)
/*! MATCH_ALL - Select interrupt register match
 *  0b0..When this bit is cleared, an interrupt will only be generated when a match occurs to one of the (up-to) four address registers described above. That is, the module will respond as a normal slave as far as address-recognition is concerned.
 *  0b1..When this bit is set to 1 and the I2C is in monitor mode, an interrupt will be generated on ANY address received. This will enable the part to monitor all traffic on the bus.
 */
#define I2C0_MMCTRL_MATCH_ALL(x)                 (((uint32_t)(((uint32_t)(x)) << I2C0_MMCTRL_MATCH_ALL_SHIFT)) & I2C0_MMCTRL_MATCH_ALL_MASK)
/*! @} */

/*! @name ADR1 - I2C Slave Address Register 1. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address. */
/*! @{ */
#define I2C0_ADR1_GC_MASK                        (0x1U)
#define I2C0_ADR1_GC_SHIFT                       (0U)
#define I2C0_ADR1_GC(x)                          (((uint32_t)(((uint32_t)(x)) << I2C0_ADR1_GC_SHIFT)) & I2C0_ADR1_GC_MASK)
#define I2C0_ADR1_ADDRESS_MASK                   (0xFEU)
#define I2C0_ADR1_ADDRESS_SHIFT                  (1U)
#define I2C0_ADR1_ADDRESS(x)                     (((uint32_t)(((uint32_t)(x)) << I2C0_ADR1_ADDRESS_SHIFT)) & I2C0_ADR1_ADDRESS_MASK)
/*! @} */

/*! @name ADR2 - I2C Slave Address Register 2. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
/*! @{ */
#define I2C0_ADR2_GC_MASK                        (0x1U)
#define I2C0_ADR2_GC_SHIFT                       (0U)
#define I2C0_ADR2_GC(x)                          (((uint32_t)(((uint32_t)(x)) << I2C0_ADR2_GC_SHIFT)) & I2C0_ADR2_GC_MASK)
#define I2C0_ADR2_ADDRESS_MASK                   (0xFEU)
#define I2C0_ADR2_ADDRESS_SHIFT                  (1U)
#define I2C0_ADR2_ADDRESS(x)                     (((uint32_t)(((uint32_t)(x)) << I2C0_ADR2_ADDRESS_SHIFT)) & I2C0_ADR2_ADDRESS_MASK)
/*! @} */

/*! @name ADR3 - I2C Slave Address Register 3. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
/*! @{ */
#define I2C0_ADR3_GC_MASK                        (0x1U)
#define I2C0_ADR3_GC_SHIFT                       (0U)
#define I2C0_ADR3_GC(x)                          (((uint32_t)(((uint32_t)(x)) << I2C0_ADR3_GC_SHIFT)) & I2C0_ADR3_GC_MASK)
#define I2C0_ADR3_ADDRESS_MASK                   (0xFEU)
#define I2C0_ADR3_ADDRESS_SHIFT                  (1U)
#define I2C0_ADR3_ADDRESS(x)                     (((uint32_t)(((uint32_t)(x)) << I2C0_ADR3_ADDRESS_SHIFT)) & I2C0_ADR3_ADDRESS_MASK)
/*! @} */

/*! @name DATA_BUFFER - Data buffer register. The contents of the 8 MSBs of the DAT shift register will be transferred to the DATA_BUFFER automatically after every nine bits (8 bits of data plus ACK or NACK) has been received on the bus. */
/*! @{ */
#define I2C0_DATA_BUFFER_DATA_MASK               (0xFFU)
#define I2C0_DATA_BUFFER_DATA_SHIFT              (0U)
#define I2C0_DATA_BUFFER_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << I2C0_DATA_BUFFER_DATA_SHIFT)) & I2C0_DATA_BUFFER_DATA_MASK)
/*! @} */

/*! @name MASK0 - I2C Slave address mask register 0. This mask register is associated with ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (0x0000000). */
/*! @{ */
#define I2C0_MASK0_DATA_MASK                     (0xFEU)
#define I2C0_MASK0_DATA_SHIFT                    (1U)
#define I2C0_MASK0_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << I2C0_MASK0_DATA_SHIFT)) & I2C0_MASK0_DATA_MASK)
/*! @} */

/*! @name MASK1 - I2C Slave address mask register 1. This mask register is associated with ADR1 to determine an address match. The mask register has no effect when comparing to the General Call address (0x0000000). */
/*! @{ */
#define I2C0_MASK1_DATA_MASK                     (0xFEU)
#define I2C0_MASK1_DATA_SHIFT                    (1U)
#define I2C0_MASK1_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << I2C0_MASK1_DATA_SHIFT)) & I2C0_MASK1_DATA_MASK)
/*! @} */

/*! @name MASK2 - I2C Slave address mask register 2. This mask register is associated with ADR2 to determine an address match. The mask register has no effect when comparing to the General Call address (0x0000000). */
/*! @{ */
#define I2C0_MASK2_DATA_MASK                     (0xFEU)
#define I2C0_MASK2_DATA_SHIFT                    (1U)
#define I2C0_MASK2_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << I2C0_MASK2_DATA_SHIFT)) & I2C0_MASK2_DATA_MASK)
/*! @} */

/*! @name MASK3 - I2C Slave address mask register 3. This mask register is associated with ADR3 to determine an address match. The mask register has no effect when comparing to the General Call address (0x0000000). */
/*! @{ */
#define I2C0_MASK3_DATA_MASK                     (0xFEU)
#define I2C0_MASK3_DATA_SHIFT                    (1U)
#define I2C0_MASK3_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << I2C0_MASK3_DATA_SHIFT)) & I2C0_MASK3_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group I2C0_Register_Masks */


/* I2C0 - Peripheral instance base addresses */
/** Peripheral I2C0 base address */
#define I2C0_BASE                                (0x40000000u)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C0_Type *)I2C0_BASE)
/** Array initializer of I2C0 peripheral base addresses */
#define I2C0_BASE_ADDRS                          { I2C0_BASE }
/** Array initializer of I2C0 peripheral base pointers */
#define I2C0_BASE_PTRS                           { I2C0 }

/*!
 * @}
 */ /* end of group I2C0_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IOCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Peripheral_Access_Layer IOCON Peripheral Access Layer
 * @{
 */

/** IOCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[1][12];                        /**< Digital I/O control for port 0 pins PIO_0..Digital I/O control for port 0 pins PIO_11, array offset: 0x0, array step: index*0x30, index2*0x4 */
} IOCON_Type;

/* ----------------------------------------------------------------------------
   -- IOCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Register_Masks IOCON Register Masks
 * @{
 */

/*! @name PIO - Digital I/O control for port 0 pins PIO_0..Digital I/O control for port 0 pins PIO_11 */
/*! @{ */
#define IOCON_PIO_FUNC_MASK                      (0x7U)
#define IOCON_PIO_FUNC_SHIFT                     (0U)
/*! FUNC - Selects pin function.
 *  0b000..Alternative connection 0.
 *  0b001..Alternative connection 1.
 *  0b010..Alternative connection 2.
 *  0b011..Alternative connection 3.
 *  0b100..Alternative connection 4.
 *  0b101..Alternative connection 5.
 *  0b110..Alternative connection 6.
 *  0b111..Alternative connection 7.
 */
#define IOCON_PIO_FUNC(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_FUNC_SHIFT)) & IOCON_PIO_FUNC_MASK)
#define IOCON_PIO_MODE_MASK                      (0x18U)
#define IOCON_PIO_MODE_SHIFT                     (3U)
/*! MODE - Selects function mode (on-chip pull-up/pull-down resistor
                control).
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define IOCON_PIO_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_MODE_SHIFT)) & IOCON_PIO_MODE_MASK)
#define IOCON_PIO_LPF_MASK                       (0x20U)
#define IOCON_PIO_LPF_SHIFT                      (5U)
/*! LPF - Low-pass filter
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOCON_PIO_LPF(x)                         (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_LPF_SHIFT)) & IOCON_PIO_LPF_MASK)
#define IOCON_PIO_CDRIVE_MASK                    (0x40U)
#define IOCON_PIO_CDRIVE_SHIFT                   (6U)
/*! CDRIVE - Select pin output driver
 *  0b0..Fixed voltage driver
 *  0b1..Programmable current driver
 */
#define IOCON_PIO_CDRIVE(x)                      (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_CDRIVE_SHIFT)) & IOCON_PIO_CDRIVE_MASK)
#define IOCON_PIO_DDRIVE_MASK                    (0x80U)
#define IOCON_PIO_DDRIVE_SHIFT                   (7U)
/*! DDRIVE - Digital drive strength
 *  0b0..High Drive (pad EHD0=0,EHD1=1)
 *  0b1..Ultra high Drive (pad EHD0=1,EHD1=1)
 */
#define IOCON_PIO_DDRIVE(x)                      (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_DDRIVE_SHIFT)) & IOCON_PIO_DDRIVE_MASK)
#define IOCON_PIO_I2CMODE_MASK                   (0x300U)
#define IOCON_PIO_I2CMODE_SHIFT                  (8U)
/*! I2CMODE - Selects I2C mode. Select I2C-bus standard/fast-mode I2CMODE = 00, default) or open-drain GPIO (4 mA) functionality (I2CMODE = 01) if the pin function is GPIO (FUNC = 000).
 *  0b00..I2C-bus standard/fast-mode
 *  0b01..open-drain GPIO (4 mA) functionality
 */
#define IOCON_PIO_I2CMODE(x)                     (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_I2CMODE_SHIFT)) & IOCON_PIO_I2CMODE_MASK)
#define IOCON_PIO_ILO_MASK                       (0xFF00U)
#define IOCON_PIO_ILO_SHIFT                      (8U)
#define IOCON_PIO_ILO(x)                         (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_ILO_SHIFT)) & IOCON_PIO_ILO_MASK)
#define IOCON_PIO_IHI_MASK                       (0xFF0000U)
#define IOCON_PIO_IHI_SHIFT                      (16U)
#define IOCON_PIO_IHI(x)                         (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_IHI_SHIFT)) & IOCON_PIO_IHI_MASK)
/*! @} */

/* The count of IOCON_PIO */
#define IOCON_PIO_COUNT                          (1U)

/* The count of IOCON_PIO */
#define IOCON_PIO_COUNT2                         (12U)


/*!
 * @}
 */ /* end of group IOCON_Register_Masks */


/* IOCON - Peripheral instance base addresses */
/** Peripheral IOCON base address */
#define IOCON_BASE                               (0x40044000u)
/** Peripheral IOCON base pointer */
#define IOCON                                    ((IOCON_Type *)IOCON_BASE)
/** Array initializer of IOCON peripheral base addresses */
#define IOCON_BASE_ADDRS                         { IOCON_BASE }
/** Array initializer of IOCON peripheral base pointers */
#define IOCON_BASE_PTRS                          { IOCON }

/*!
 * @}
 */ /* end of group IOCON_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Peripheral_Access_Layer PMU Peripheral Access Layer
 * @{
 */

/** PMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCON;                              /**< Power control register, offset: 0x0 */
  __IO uint32_t GPREG[5];                          /**< General purpose register 0..General purpose register 4, array offset: 0x4, array step: 0x4 */
  __I  uint32_t PSTAT;                             /**< Power management unit status register, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __I  uint32_t ACCSTAT;                           /**< Access status register, offset: 0x20 */
  __IO uint32_t LDO1V6;                            /**< Analog 1.6 V LDO trimming, offset: 0x24 */
       uint8_t RESERVED_1[4];
  __IO uint32_t TMRCLKCTRL;                        /**< Timer clock control register, offset: 0x2C */
  __IO uint32_t IMSC;                              /**< interrupt mask set and clear Register, offset: 0x30 */
  __I  uint32_t RIS;                               /**< raw interrupt status register, offset: 0x34 */
  __I  uint32_t MIS;                               /**< masked interrupt status register, offset: 0x38 */
  __O  uint32_t ICR;                               /**< interrupt clear register, offset: 0x3C */
} PMU_Type;

/* ----------------------------------------------------------------------------
   -- PMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Register_Masks PMU Register Masks
 * @{
 */

/*! @name PCON - Power control register */
/*! @{ */
#define PMU_PCON_DPEN_MASK                       (0x2U)
#define PMU_PCON_DPEN_SHIFT                      (1U)
/*! DPEN - Deep power-down mode enable
 *  0b0..ARM WFI will enter Sleep or Deep-sleep mode (clock to ARM Cortex M0+ core turned off)
 *  0b1..ARM WFI will enter Deep-power down mode (ARM Cortex M0+ core powered down)
 */
#define PMU_PCON_DPEN(x)                         (((uint32_t)(((uint32_t)(x)) << PMU_PCON_DPEN_SHIFT)) & PMU_PCON_DPEN_MASK)
#define PMU_PCON_SLEEPFLAG_MASK                  (0x100U)
#define PMU_PCON_SLEEPFLAG_SHIFT                 (8U)
/*! SLEEPFLAG - Sleep mode flag
 *  0b0..read: No power-down mode entered / write: no effect
 *  0b1..read: sleep/deep-sleep mode entered / write: write 1 to clear SLEEPFLAG
 */
#define PMU_PCON_SLEEPFLAG(x)                    (((uint32_t)(((uint32_t)(x)) << PMU_PCON_SLEEPFLAG_SHIFT)) & PMU_PCON_SLEEPFLAG_MASK)
#define PMU_PCON_DPDFLAG_MASK                    (0x800U)
#define PMU_PCON_DPDFLAG_SHIFT                   (11U)
/*! DPDFLAG - Deep power-down flag
 *  0b0..read: No power-down mode entered / write: no effect
 *  0b1..read:deep power-down mode entered / write: clear the deep power-down flag
 */
#define PMU_PCON_DPDFLAG(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_PCON_DPDFLAG_SHIFT)) & PMU_PCON_DPDFLAG_MASK)
#define PMU_PCON_PMULPM_MASK                     (0x2000U)
#define PMU_PCON_PMULPM_SHIFT                    (13U)
/*! PMULPM - PMU ultra-low-power mod
 *  0b0..power switches are in automatic mode
 *  0b1..disable automatic switching (default to external power).
 */
#define PMU_PCON_PMULPM(x)                       (((uint32_t)(((uint32_t)(x)) << PMU_PCON_PMULPM_SHIFT)) & PMU_PCON_PMULPM_MASK)
#define PMU_PCON_VBAT_MASK                       (0x4000U)
#define PMU_PCON_VBAT_SHIFT                      (14U)
/*! VBAT - This bit enables the connection of the VBAT pin to VDD, effectively connecting the system to the battery.
 *  0b0..VBAT not connected to VDD
 *  0b1..VBAT connected to VDD
 */
#define PMU_PCON_VBAT(x)                         (((uint32_t)(((uint32_t)(x)) << PMU_PCON_VBAT_SHIFT)) & PMU_PCON_VBAT_MASK)
#define PMU_PCON_BODEN_MASK                      (0x8000U)
#define PMU_PCON_BODEN_SHIFT                     (15U)
/*! BODEN - Brown-out detector enable
 *  0b0..BOD disabled
 *  0b1..BOD enabled
 */
#define PMU_PCON_BODEN(x)                        (((uint32_t)(((uint32_t)(x)) << PMU_PCON_BODEN_SHIFT)) & PMU_PCON_BODEN_MASK)
#define PMU_PCON_FORCEVBAT_FORCEVNFC_MASK        (0x60000U)
#define PMU_PCON_FORCEVBAT_FORCEVNFC_SHIFT       (17U)
/*! FORCEVBAT_FORCEVNFC - force the power source selection
 *  0b01..force to VBAT/external power
 *  0b10..force to NFC power
 *  0b11..autoswitching if PMULPM is 0
 */
#define PMU_PCON_FORCEVBAT_FORCEVNFC(x)          (((uint32_t)(((uint32_t)(x)) << PMU_PCON_FORCEVBAT_FORCEVNFC_SHIFT)) & PMU_PCON_FORCEVBAT_FORCEVNFC_MASK)
#define PMU_PCON_WAKEUP_MASK                     (0x80000U)
#define PMU_PCON_WAKEUP_SHIFT                    (19U)
/*! WAKEUP - enable the WAKEUP function on pin PIO0_0
 *  0b0..WAKEUP function not enabled
 *  0b1..WAKEUP function assigned to PIO0_0. When selecting this option, PIO0_0 has a weak pull-up to VDD_ALON when in Deep power-down.
 */
#define PMU_PCON_WAKEUP(x)                       (((uint32_t)(((uint32_t)(x)) << PMU_PCON_WAKEUP_SHIFT)) & PMU_PCON_WAKEUP_MASK)
/*! @} */

/*! @name GPREG - General purpose register 0..General purpose register 4 */
/*! @{ */
#define PMU_GPREG_GPDATA_MASK                    (0xFFFFFFFFU)
#define PMU_GPREG_GPDATA_SHIFT                   (0U)
#define PMU_GPREG_GPDATA(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_GPREG_GPDATA_SHIFT)) & PMU_GPREG_GPDATA_MASK)
/*! @} */

/* The count of PMU_GPREG */
#define PMU_GPREG_COUNT                          (5U)

/*! @name PSTAT - Power management unit status register */
/*! @{ */
#define PMU_PSTAT_PSWNFC_MASK                    (0x1U)
#define PMU_PSTAT_PSWNFC_SHIFT                   (0U)
/*! PSWNFC - Status of NFC power selection switch
 *  0b0..Switch disabled (not conducting)
 *  0b1..Switch enabled (conducting)
 */
#define PMU_PSTAT_PSWNFC(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_PSTAT_PSWNFC_SHIFT)) & PMU_PSTAT_PSWNFC_MASK)
#define PMU_PSTAT_PSWBAT_MASK                    (0x2U)
#define PMU_PSTAT_PSWBAT_SHIFT                   (1U)
/*! PSWBAT - status of battery power selection switch
 *  0b0..Switch disabled (not conducting)
 *  0b1..Switch enabled (conducting)
 */
#define PMU_PSTAT_PSWBAT(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_PSTAT_PSWBAT_SHIFT)) & PMU_PSTAT_PSWBAT_MASK)
#define PMU_PSTAT_DPDEXIT_MASK                   (0x18U)
#define PMU_PSTAT_DPDEXIT_SHIFT                  (3U)
/*! DPDEXIT - reason for exit from Deep-Power Down. Only valid when the DPDFLAG in the PCON register is asserted (1)
 *  0b00..POR or RESETN pin asserted
 *  0b01..LDO enabled
 *  0b10..RTC timer event
 *  0b11..WAKEUP pin negative edge detected
 */
#define PMU_PSTAT_DPDEXIT(x)                     (((uint32_t)(((uint32_t)(x)) << PMU_PSTAT_DPDEXIT_SHIFT)) & PMU_PSTAT_DPDEXIT_MASK)
#define PMU_PSTAT_BOD1V8_MASK                    (0x20U)
#define PMU_PSTAT_BOD1V8_SHIFT                   (5U)
/*! BOD1V8 - BOD detected (VDD less 1.8 V)
 *  0b0..VDD larger 1.8 V
 *  0b1..VDD less 1.8 V
 */
#define PMU_PSTAT_BOD1V8(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_PSTAT_BOD1V8_SHIFT)) & PMU_PSTAT_BOD1V8_MASK)
#define PMU_PSTAT_RFPOW_MASK                     (0x80U)
#define PMU_PSTAT_RFPOW_SHIFT                    (7U)
/*! RFPOW - RF field detected
 *  0b0..No field
 *  0b1..RF field
 */
#define PMU_PSTAT_RFPOW(x)                       (((uint32_t)(((uint32_t)(x)) << PMU_PSTAT_RFPOW_SHIFT)) & PMU_PSTAT_RFPOW_MASK)
/*! @} */

/*! @name ACCSTAT - Access status register */
/*! @{ */
#define PMU_ACCSTAT_PMU_READY_MASK               (0x1U)
#define PMU_ACCSTAT_PMU_READY_SHIFT              (0U)
#define PMU_ACCSTAT_PMU_READY(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_ACCSTAT_PMU_READY_SHIFT)) & PMU_ACCSTAT_PMU_READY_MASK)
/*! @} */

/*! @name LDO1V6 - Analog 1.6 V LDO trimming */
/*! @{ */
#define PMU_LDO1V6_TRIM1V6_MASK                  (0xFU)
#define PMU_LDO1V6_TRIM1V6_SHIFT                 (0U)
#define PMU_LDO1V6_TRIM1V6(x)                    (((uint32_t)(((uint32_t)(x)) << PMU_LDO1V6_TRIM1V6_SHIFT)) & PMU_LDO1V6_TRIM1V6_MASK)
/*! @} */

/*! @name TMRCLKCTRL - Timer clock control register */
/*! @{ */
#define PMU_TMRCLKCTRL_TMREN_MASK                (0x1U)
#define PMU_TMRCLKCTRL_TMREN_SHIFT               (0U)
/*! TMREN - RTC clock source.
 *  0b0..No clock
 *  0b1..32kHz FRO
 */
#define PMU_TMRCLKCTRL_TMREN(x)                  (((uint32_t)(((uint32_t)(x)) << PMU_TMRCLKCTRL_TMREN_SHIFT)) & PMU_TMRCLKCTRL_TMREN_MASK)
#define PMU_TMRCLKCTRL_TMRCLKTRIM_MASK           (0x3F0000U)
#define PMU_TMRCLKCTRL_TMRCLKTRIM_SHIFT          (16U)
#define PMU_TMRCLKCTRL_TMRCLKTRIM(x)             (((uint32_t)(((uint32_t)(x)) << PMU_TMRCLKCTRL_TMRCLKTRIM_SHIFT)) & PMU_TMRCLKCTRL_TMRCLKTRIM_MASK)
#define PMU_TMRCLKCTRL_TMRCURRLVL_MASK           (0xC00000U)
#define PMU_TMRCLKCTRL_TMRCURRLVL_SHIFT          (22U)
#define PMU_TMRCLKCTRL_TMRCURRLVL(x)             (((uint32_t)(((uint32_t)(x)) << PMU_TMRCLKCTRL_TMRCURRLVL_SHIFT)) & PMU_TMRCLKCTRL_TMRCURRLVL_MASK)
/*! @} */

/*! @name IMSC - interrupt mask set and clear Register */
/*! @{ */
#define PMU_IMSC_BODI_MASK                       (0x1U)
#define PMU_IMSC_BODI_SHIFT                      (0U)
#define PMU_IMSC_BODI(x)                         (((uint32_t)(((uint32_t)(x)) << PMU_IMSC_BODI_SHIFT)) & PMU_IMSC_BODI_MASK)
#define PMU_IMSC_RFPOWI_MASK                     (0x2U)
#define PMU_IMSC_RFPOWI_SHIFT                    (1U)
#define PMU_IMSC_RFPOWI(x)                       (((uint32_t)(((uint32_t)(x)) << PMU_IMSC_RFPOWI_SHIFT)) & PMU_IMSC_RFPOWI_MASK)
/*! @} */

/*! @name RIS - raw interrupt status register */
/*! @{ */
#define PMU_RIS_BODRI_MASK                       (0x1U)
#define PMU_RIS_BODRI_SHIFT                      (0U)
#define PMU_RIS_BODRI(x)                         (((uint32_t)(((uint32_t)(x)) << PMU_RIS_BODRI_SHIFT)) & PMU_RIS_BODRI_MASK)
#define PMU_RIS_RFPOWRI_MASK                     (0x2U)
#define PMU_RIS_RFPOWRI_SHIFT                    (1U)
#define PMU_RIS_RFPOWRI(x)                       (((uint32_t)(((uint32_t)(x)) << PMU_RIS_RFPOWRI_SHIFT)) & PMU_RIS_RFPOWRI_MASK)
/*! @} */

/*! @name MIS - masked interrupt status register */
/*! @{ */
#define PMU_MIS_BODRI_MASK                       (0x1U)
#define PMU_MIS_BODRI_SHIFT                      (0U)
#define PMU_MIS_BODRI(x)                         (((uint32_t)(((uint32_t)(x)) << PMU_MIS_BODRI_SHIFT)) & PMU_MIS_BODRI_MASK)
#define PMU_MIS_RFPOWRI_MASK                     (0x2U)
#define PMU_MIS_RFPOWRI_SHIFT                    (1U)
#define PMU_MIS_RFPOWRI(x)                       (((uint32_t)(((uint32_t)(x)) << PMU_MIS_RFPOWRI_SHIFT)) & PMU_MIS_RFPOWRI_MASK)
/*! @} */

/*! @name ICR - interrupt clear register */
/*! @{ */
#define PMU_ICR_BODC_MASK                        (0x1U)
#define PMU_ICR_BODC_SHIFT                       (0U)
#define PMU_ICR_BODC(x)                          (((uint32_t)(((uint32_t)(x)) << PMU_ICR_BODC_SHIFT)) & PMU_ICR_BODC_MASK)
#define PMU_ICR_RFPOWC_MASK                      (0x2U)
#define PMU_ICR_RFPOWC_SHIFT                     (1U)
#define PMU_ICR_RFPOWC(x)                        (((uint32_t)(((uint32_t)(x)) << PMU_ICR_RFPOWC_SHIFT)) & PMU_ICR_RFPOWC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMU_Register_Masks */


/* PMU - Peripheral instance base addresses */
/** Peripheral PMU base address */
#define PMU_BASE                                 (0x40038000u)
/** Peripheral PMU base pointer */
#define PMU                                      ((PMU_Type *)PMU_BASE)
/** Array initializer of PMU peripheral base addresses */
#define PMU_BASE_ADDRS                           { PMU_BASE }
/** Array initializer of PMU peripheral base pointers */
#define PMU_BASE_PTRS                            { PMU }

/*!
 * @}
 */ /* end of group PMU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RFIDNFC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RFIDNFC_Peripheral_Access_Layer RFIDNFC Peripheral Access Layer
 * @{
 */

/** RFIDNFC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG;                               /**< RFID/NFC configuration register, offset: 0x0 */
  __I  uint32_t SR;                                /**< RFID/NFC status register, offset: 0x4 */
  __I  uint32_t CMDIN;                             /**< RFID/NFC incoming command, offset: 0x8 */
  __IO uint32_t CMDOUT;                            /**< RFID/NFC outgoing command, offset: 0xC */
  __IO uint32_t TARGET;                            /**< RFID/NFC target page address register, offset: 0x10 */
  __I  uint32_t LAST_ACCESS;                       /**< raw Interrupt status register, offset: 0x14 */
  __IO uint32_t IMIS;                              /**< Interrupt mask register, offset: 0x18 */
  __I  uint32_t RIS;                               /**< Raw Interrupt status register, offset: 0x1C */
  __I  uint32_t MIS;                               /**< Masked interrupt status register, offset: 0x20 */
  __O  uint32_t ICR;                               /**< Interrupt clear register, offset: 0x24 */
       uint8_t RESERVED_0[216];
  __IO uint32_t SHARED_MEM[128];                   /**< POR captured value of port n, array offset: 0x100, array step: 0x4 */
} RFIDNFC_Type;

/* ----------------------------------------------------------------------------
   -- RFIDNFC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RFIDNFC_Register_Masks RFIDNFC Register Masks
 * @{
 */

/*! @name CFG - RFID/NFC configuration register */
/*! @{ */
#define RFIDNFC_CFG_BYPASS_MASK                  (0x1U)
#define RFIDNFC_CFG_BYPASS_SHIFT                 (0U)
#define RFIDNFC_CFG_BYPASS(x)                    (((uint32_t)(((uint32_t)(x)) << RFIDNFC_CFG_BYPASS_SHIFT)) & RFIDNFC_CFG_BYPASS_MASK)
/*! @} */

/*! @name SR - RFID/NFC status register */
/*! @{ */
#define RFIDNFC_SR_POR_MASK                      (0x1U)
#define RFIDNFC_SR_POR_SHIFT                     (0U)
#define RFIDNFC_SR_POR(x)                        (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SR_POR_SHIFT)) & RFIDNFC_SR_POR_MASK)
#define RFIDNFC_SR_R1V2_MASK                     (0x2U)
#define RFIDNFC_SR_R1V2_SHIFT                    (1U)
#define RFIDNFC_SR_R1V2(x)                       (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SR_R1V2_SHIFT)) & RFIDNFC_SR_R1V2_MASK)
#define RFIDNFC_SR_R1V5_MASK                     (0x4U)
#define RFIDNFC_SR_R1V5_SHIFT                    (2U)
#define RFIDNFC_SR_R1V5(x)                       (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SR_R1V5_SHIFT)) & RFIDNFC_SR_R1V5_MASK)
#define RFIDNFC_SR_PLL_MASK                      (0x8U)
#define RFIDNFC_SR_PLL_SHIFT                     (3U)
#define RFIDNFC_SR_PLL(x)                        (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SR_PLL_SHIFT)) & RFIDNFC_SR_PLL_MASK)
#define RFIDNFC_SR_SEL_MASK                      (0x10U)
#define RFIDNFC_SR_SEL_SHIFT                     (4U)
#define RFIDNFC_SR_SEL(x)                        (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SR_SEL_SHIFT)) & RFIDNFC_SR_SEL_MASK)
#define RFIDNFC_SR_AUTH_MASK                     (0x20U)
#define RFIDNFC_SR_AUTH_SHIFT                    (5U)
#define RFIDNFC_SR_AUTH(x)                       (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SR_AUTH_SHIFT)) & RFIDNFC_SR_AUTH_MASK)
#define RFIDNFC_SR_BYPASS_MASK                   (0x40U)
#define RFIDNFC_SR_BYPASS_SHIFT                  (6U)
#define RFIDNFC_SR_BYPASS(x)                     (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SR_BYPASS_SHIFT)) & RFIDNFC_SR_BYPASS_MASK)
#define RFIDNFC_SR_RFID_CMD_MASK                 (0xFF00U)
#define RFIDNFC_SR_RFID_CMD_SHIFT                (8U)
/*! RFID_CMD - Last RFID command received
 *  0b00000000..REQA
 *  0b00000001..WUPA
 *  0b00000010..ANTICOLLISION
 *  0b00000011..SELECT
 *  0b00000100..HLTA
 *  0b00000101..READ
 *  0b00000110..COMP_WRITE
 *  0b00000111..WRITE
 *  0b00001000..INCR_CNT
 *  0b00001001..READ_CNT
 *  0b00001010..PWD_AUTH
 *  0b00001011..GET_VERSION
 *  0b00001100..FAST_READ
 *  0b00001101..READ_SIG
 *  0b00001111..CHECK_TEARING_EVENT
 */
#define RFIDNFC_SR_RFID_CMD(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SR_RFID_CMD_SHIFT)) & RFIDNFC_SR_RFID_CMD_MASK)
/*! @} */

/*! @name CMDIN - RFID/NFC incoming command */
/*! @{ */
#define RFIDNFC_CMDIN_CMDIN_MASK                 (0xFFFFFFFFU)
#define RFIDNFC_CMDIN_CMDIN_SHIFT                (0U)
#define RFIDNFC_CMDIN_CMDIN(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_CMDIN_CMDIN_SHIFT)) & RFIDNFC_CMDIN_CMDIN_MASK)
/*! @} */

/*! @name CMDOUT - RFID/NFC outgoing command */
/*! @{ */
#define RFIDNFC_CMDOUT_CMDOUT_MASK               (0xFFFFFFFFU)
#define RFIDNFC_CMDOUT_CMDOUT_SHIFT              (0U)
#define RFIDNFC_CMDOUT_CMDOUT(x)                 (((uint32_t)(((uint32_t)(x)) << RFIDNFC_CMDOUT_CMDOUT_SHIFT)) & RFIDNFC_CMDOUT_CMDOUT_MASK)
/*! @} */

/*! @name TARGET - RFID/NFC target page address register */
/*! @{ */
#define RFIDNFC_TARGET_PAGE_MASK                 (0xFFU)
#define RFIDNFC_TARGET_PAGE_SHIFT                (0U)
#define RFIDNFC_TARGET_PAGE(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_TARGET_PAGE_SHIFT)) & RFIDNFC_TARGET_PAGE_MASK)
/*! @} */

/*! @name LAST_ACCESS - raw Interrupt status register */
/*! @{ */
#define RFIDNFC_LAST_ACCESS_LAST_ACCESS_END_MASK (0xFFU)
#define RFIDNFC_LAST_ACCESS_LAST_ACCESS_END_SHIFT (0U)
#define RFIDNFC_LAST_ACCESS_LAST_ACCESS_END(x)   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_LAST_ACCESS_LAST_ACCESS_END_SHIFT)) & RFIDNFC_LAST_ACCESS_LAST_ACCESS_END_MASK)
#define RFIDNFC_LAST_ACCESS_LAST_ACCESS_START_MASK (0xFF00U)
#define RFIDNFC_LAST_ACCESS_LAST_ACCESS_START_SHIFT (8U)
#define RFIDNFC_LAST_ACCESS_LAST_ACCESS_START(x) (((uint32_t)(((uint32_t)(x)) << RFIDNFC_LAST_ACCESS_LAST_ACCESS_START_SHIFT)) & RFIDNFC_LAST_ACCESS_LAST_ACCESS_START_MASK)
#define RFIDNFC_LAST_ACCESS_DIR_MASK             (0x10000U)
#define RFIDNFC_LAST_ACCESS_DIR_SHIFT            (16U)
#define RFIDNFC_LAST_ACCESS_DIR(x)               (((uint32_t)(((uint32_t)(x)) << RFIDNFC_LAST_ACCESS_DIR_SHIFT)) & RFIDNFC_LAST_ACCESS_DIR_MASK)
/*! @} */

/*! @name IMIS - Interrupt mask register */
/*! @{ */
#define RFIDNFC_IMIS_RFPOWER_MASK                (0x1U)
#define RFIDNFC_IMIS_RFPOWER_SHIFT               (0U)
#define RFIDNFC_IMIS_RFPOWER(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_RFPOWER_SHIFT)) & RFIDNFC_IMIS_RFPOWER_MASK)
#define RFIDNFC_IMIS_RFSELECT_MASK               (0x2U)
#define RFIDNFC_IMIS_RFSELECT_SHIFT              (1U)
#define RFIDNFC_IMIS_RFSELECT(x)                 (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_RFSELECT_SHIFT)) & RFIDNFC_IMIS_RFSELECT_MASK)
#define RFIDNFC_IMIS_MEMREAD_MASK                (0x4U)
#define RFIDNFC_IMIS_MEMREAD_SHIFT               (2U)
#define RFIDNFC_IMIS_MEMREAD(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_MEMREAD_SHIFT)) & RFIDNFC_IMIS_MEMREAD_MASK)
#define RFIDNFC_IMIS_MEMWRITE_MASK               (0x8U)
#define RFIDNFC_IMIS_MEMWRITE_SHIFT              (3U)
#define RFIDNFC_IMIS_MEMWRITE(x)                 (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_MEMWRITE_SHIFT)) & RFIDNFC_IMIS_MEMWRITE_MASK)
#define RFIDNFC_IMIS_CMDWRITE_MASK               (0x10U)
#define RFIDNFC_IMIS_CMDWRITE_SHIFT              (4U)
#define RFIDNFC_IMIS_CMDWRITE(x)                 (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_CMDWRITE_SHIFT)) & RFIDNFC_IMIS_CMDWRITE_MASK)
#define RFIDNFC_IMIS_CMDREAD_MASK                (0x20U)
#define RFIDNFC_IMIS_CMDREAD_SHIFT               (5U)
#define RFIDNFC_IMIS_CMDREAD(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_CMDREAD_SHIFT)) & RFIDNFC_IMIS_CMDREAD_MASK)
#define RFIDNFC_IMIS_TARGETWRITE_MASK            (0x40U)
#define RFIDNFC_IMIS_TARGETWRITE_SHIFT           (6U)
#define RFIDNFC_IMIS_TARGETWRITE(x)              (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_TARGETWRITE_SHIFT)) & RFIDNFC_IMIS_TARGETWRITE_MASK)
#define RFIDNFC_IMIS_TARGETREAD_MASK             (0x80U)
#define RFIDNFC_IMIS_TARGETREAD_SHIFT            (7U)
#define RFIDNFC_IMIS_TARGETREAD(x)               (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_TARGETREAD_SHIFT)) & RFIDNFC_IMIS_TARGETREAD_MASK)
#define RFIDNFC_IMIS_NFCOFF_MASK                 (0x100U)
#define RFIDNFC_IMIS_NFCOFF_SHIFT                (8U)
#define RFIDNFC_IMIS_NFCOFF(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_IMIS_NFCOFF_SHIFT)) & RFIDNFC_IMIS_NFCOFF_MASK)
/*! @} */

/*! @name RIS - Raw Interrupt status register */
/*! @{ */
#define RFIDNFC_RIS_RFPOWER_MASK                 (0x1U)
#define RFIDNFC_RIS_RFPOWER_SHIFT                (0U)
#define RFIDNFC_RIS_RFPOWER(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_RFPOWER_SHIFT)) & RFIDNFC_RIS_RFPOWER_MASK)
#define RFIDNFC_RIS_RFSELECT_MASK                (0x2U)
#define RFIDNFC_RIS_RFSELECT_SHIFT               (1U)
#define RFIDNFC_RIS_RFSELECT(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_RFSELECT_SHIFT)) & RFIDNFC_RIS_RFSELECT_MASK)
#define RFIDNFC_RIS_MEMREAD_MASK                 (0x4U)
#define RFIDNFC_RIS_MEMREAD_SHIFT                (2U)
#define RFIDNFC_RIS_MEMREAD(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_MEMREAD_SHIFT)) & RFIDNFC_RIS_MEMREAD_MASK)
#define RFIDNFC_RIS_MEMWRITE_MASK                (0x8U)
#define RFIDNFC_RIS_MEMWRITE_SHIFT               (3U)
#define RFIDNFC_RIS_MEMWRITE(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_MEMWRITE_SHIFT)) & RFIDNFC_RIS_MEMWRITE_MASK)
#define RFIDNFC_RIS_CMDWRITE_MASK                (0x10U)
#define RFIDNFC_RIS_CMDWRITE_SHIFT               (4U)
#define RFIDNFC_RIS_CMDWRITE(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_CMDWRITE_SHIFT)) & RFIDNFC_RIS_CMDWRITE_MASK)
#define RFIDNFC_RIS_CMDREAD_MASK                 (0x20U)
#define RFIDNFC_RIS_CMDREAD_SHIFT                (5U)
#define RFIDNFC_RIS_CMDREAD(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_CMDREAD_SHIFT)) & RFIDNFC_RIS_CMDREAD_MASK)
#define RFIDNFC_RIS_TARGETWRITE_MASK             (0x40U)
#define RFIDNFC_RIS_TARGETWRITE_SHIFT            (6U)
#define RFIDNFC_RIS_TARGETWRITE(x)               (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_TARGETWRITE_SHIFT)) & RFIDNFC_RIS_TARGETWRITE_MASK)
#define RFIDNFC_RIS_TARGETREAD_MASK              (0x80U)
#define RFIDNFC_RIS_TARGETREAD_SHIFT             (7U)
#define RFIDNFC_RIS_TARGETREAD(x)                (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_TARGETREAD_SHIFT)) & RFIDNFC_RIS_TARGETREAD_MASK)
#define RFIDNFC_RIS_NFCOFF_MASK                  (0x100U)
#define RFIDNFC_RIS_NFCOFF_SHIFT                 (8U)
#define RFIDNFC_RIS_NFCOFF(x)                    (((uint32_t)(((uint32_t)(x)) << RFIDNFC_RIS_NFCOFF_SHIFT)) & RFIDNFC_RIS_NFCOFF_MASK)
/*! @} */

/*! @name MIS - Masked interrupt status register */
/*! @{ */
#define RFIDNFC_MIS_RFPOWER_MASK                 (0x1U)
#define RFIDNFC_MIS_RFPOWER_SHIFT                (0U)
#define RFIDNFC_MIS_RFPOWER(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_RFPOWER_SHIFT)) & RFIDNFC_MIS_RFPOWER_MASK)
#define RFIDNFC_MIS_RFSELECT_MASK                (0x2U)
#define RFIDNFC_MIS_RFSELECT_SHIFT               (1U)
#define RFIDNFC_MIS_RFSELECT(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_RFSELECT_SHIFT)) & RFIDNFC_MIS_RFSELECT_MASK)
#define RFIDNFC_MIS_MEMREAD_MASK                 (0x4U)
#define RFIDNFC_MIS_MEMREAD_SHIFT                (2U)
#define RFIDNFC_MIS_MEMREAD(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_MEMREAD_SHIFT)) & RFIDNFC_MIS_MEMREAD_MASK)
#define RFIDNFC_MIS_MEMWRITE_MASK                (0x8U)
#define RFIDNFC_MIS_MEMWRITE_SHIFT               (3U)
#define RFIDNFC_MIS_MEMWRITE(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_MEMWRITE_SHIFT)) & RFIDNFC_MIS_MEMWRITE_MASK)
#define RFIDNFC_MIS_CMDWRITE_MASK                (0x10U)
#define RFIDNFC_MIS_CMDWRITE_SHIFT               (4U)
#define RFIDNFC_MIS_CMDWRITE(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_CMDWRITE_SHIFT)) & RFIDNFC_MIS_CMDWRITE_MASK)
#define RFIDNFC_MIS_CMDREAD_MASK                 (0x20U)
#define RFIDNFC_MIS_CMDREAD_SHIFT                (5U)
#define RFIDNFC_MIS_CMDREAD(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_CMDREAD_SHIFT)) & RFIDNFC_MIS_CMDREAD_MASK)
#define RFIDNFC_MIS_TARGETWRITE_MASK             (0x40U)
#define RFIDNFC_MIS_TARGETWRITE_SHIFT            (6U)
#define RFIDNFC_MIS_TARGETWRITE(x)               (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_TARGETWRITE_SHIFT)) & RFIDNFC_MIS_TARGETWRITE_MASK)
#define RFIDNFC_MIS_TARGETREAD_MASK              (0x80U)
#define RFIDNFC_MIS_TARGETREAD_SHIFT             (7U)
#define RFIDNFC_MIS_TARGETREAD(x)                (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_TARGETREAD_SHIFT)) & RFIDNFC_MIS_TARGETREAD_MASK)
#define RFIDNFC_MIS_NFCOFF_MASK                  (0x100U)
#define RFIDNFC_MIS_NFCOFF_SHIFT                 (8U)
#define RFIDNFC_MIS_NFCOFF(x)                    (((uint32_t)(((uint32_t)(x)) << RFIDNFC_MIS_NFCOFF_SHIFT)) & RFIDNFC_MIS_NFCOFF_MASK)
/*! @} */

/*! @name ICR - Interrupt clear register */
/*! @{ */
#define RFIDNFC_ICR_RFPOWER_MASK                 (0x1U)
#define RFIDNFC_ICR_RFPOWER_SHIFT                (0U)
#define RFIDNFC_ICR_RFPOWER(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_RFPOWER_SHIFT)) & RFIDNFC_ICR_RFPOWER_MASK)
#define RFIDNFC_ICR_RFSELECT_MASK                (0x2U)
#define RFIDNFC_ICR_RFSELECT_SHIFT               (1U)
#define RFIDNFC_ICR_RFSELECT(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_RFSELECT_SHIFT)) & RFIDNFC_ICR_RFSELECT_MASK)
#define RFIDNFC_ICR_MEMREAD_MASK                 (0x4U)
#define RFIDNFC_ICR_MEMREAD_SHIFT                (2U)
#define RFIDNFC_ICR_MEMREAD(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_MEMREAD_SHIFT)) & RFIDNFC_ICR_MEMREAD_MASK)
#define RFIDNFC_ICR_MEMWRITE_MASK                (0x8U)
#define RFIDNFC_ICR_MEMWRITE_SHIFT               (3U)
#define RFIDNFC_ICR_MEMWRITE(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_MEMWRITE_SHIFT)) & RFIDNFC_ICR_MEMWRITE_MASK)
#define RFIDNFC_ICR_CMDWRITE_MASK                (0x10U)
#define RFIDNFC_ICR_CMDWRITE_SHIFT               (4U)
#define RFIDNFC_ICR_CMDWRITE(x)                  (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_CMDWRITE_SHIFT)) & RFIDNFC_ICR_CMDWRITE_MASK)
#define RFIDNFC_ICR_CMDREAD_MASK                 (0x20U)
#define RFIDNFC_ICR_CMDREAD_SHIFT                (5U)
#define RFIDNFC_ICR_CMDREAD(x)                   (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_CMDREAD_SHIFT)) & RFIDNFC_ICR_CMDREAD_MASK)
#define RFIDNFC_ICR_TARGETWRITE_MASK             (0x40U)
#define RFIDNFC_ICR_TARGETWRITE_SHIFT            (6U)
#define RFIDNFC_ICR_TARGETWRITE(x)               (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_TARGETWRITE_SHIFT)) & RFIDNFC_ICR_TARGETWRITE_MASK)
#define RFIDNFC_ICR_TARGETREAD_MASK              (0x80U)
#define RFIDNFC_ICR_TARGETREAD_SHIFT             (7U)
#define RFIDNFC_ICR_TARGETREAD(x)                (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_TARGETREAD_SHIFT)) & RFIDNFC_ICR_TARGETREAD_MASK)
#define RFIDNFC_ICR_NFCOFF_MASK                  (0x100U)
#define RFIDNFC_ICR_NFCOFF_SHIFT                 (8U)
#define RFIDNFC_ICR_NFCOFF(x)                    (((uint32_t)(((uint32_t)(x)) << RFIDNFC_ICR_NFCOFF_SHIFT)) & RFIDNFC_ICR_NFCOFF_MASK)
/*! @} */

/*! @name SHARED_MEM - POR captured value of port n */
/*! @{ */
#define RFIDNFC_SHARED_MEM_SHAREDMEM_MASK        (0xFFFFFFFFU)
#define RFIDNFC_SHARED_MEM_SHAREDMEM_SHIFT       (0U)
#define RFIDNFC_SHARED_MEM_SHAREDMEM(x)          (((uint32_t)(((uint32_t)(x)) << RFIDNFC_SHARED_MEM_SHAREDMEM_SHIFT)) & RFIDNFC_SHARED_MEM_SHAREDMEM_MASK)
/*! @} */

/* The count of RFIDNFC_SHARED_MEM */
#define RFIDNFC_SHARED_MEM_COUNT                 (128U)


/*!
 * @}
 */ /* end of group RFIDNFC_Register_Masks */


/* RFIDNFC - Peripheral instance base addresses */
/** Peripheral RFIDNFC base address */
#define RFIDNFC_BASE                             (0x40058000u)
/** Peripheral RFIDNFC base pointer */
#define RFIDNFC                                  ((RFIDNFC_Type *)RFIDNFC_BASE)
/** Array initializer of RFIDNFC peripheral base addresses */
#define RFIDNFC_BASE_ADDRS                       { RFIDNFC_BASE }
/** Array initializer of RFIDNFC peripheral base pointers */
#define RFIDNFC_BASE_PTRS                        { RFIDNFC }

/*!
 * @}
 */ /* end of group RFIDNFC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< RTC control register, offset: 0x0 */
  __I  uint32_t SR;                                /**< RTC status register, offset: 0x4 */
  __IO uint32_t CAL;                               /**< RTC calibration value, offset: 0x8 */
  __IO uint32_t SLEEPT;                            /**< RTC Sleep time, offset: 0xC */
  __I  uint32_t VAL;                               /**< Current RTC counter value, offset: 0x10 */
  __IO uint32_t IMIS;                              /**< Interrupt mask register, offset: 0x14 */
  __I  uint32_t RIS;                               /**< Raw Interrupt status register, offset: 0x18 */
  __I  uint32_t MIS;                               /**< Masked interrupt status register, offset: 0x1C */
  __O  uint32_t ICR;                               /**< Interrupt clear register, offset: 0x20 */
  __I  uint32_t ACCSTAT;                           /**< Access status register, offset: 0x24 */
       uint8_t RESERVED_0[8];
  __IO uint32_t TIME;                              /**< RTC Time register, offset: 0x30 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name CR - RTC control register */
/*! @{ */
#define RTC_CR_EN_MASK                           (0x1U)
#define RTC_CR_EN_SHIFT                          (0U)
#define RTC_CR_EN(x)                             (((uint32_t)(((uint32_t)(x)) << RTC_CR_EN_SHIFT)) & RTC_CR_EN_MASK)
#define RTC_CR_AUTOSTART_MASK                    (0x2U)
#define RTC_CR_AUTOSTART_SHIFT                   (1U)
#define RTC_CR_AUTOSTART(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_CR_AUTOSTART_SHIFT)) & RTC_CR_AUTOSTART_MASK)
#define RTC_CR_START_MASK                        (0x4U)
#define RTC_CR_START_SHIFT                       (2U)
#define RTC_CR_START(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_CR_START_SHIFT)) & RTC_CR_START_MASK)
/*! @} */

/*! @name SR - RTC status register */
/*! @{ */
#define RTC_SR_EN_MASK                           (0x1U)
#define RTC_SR_EN_SHIFT                          (0U)
#define RTC_SR_EN(x)                             (((uint32_t)(((uint32_t)(x)) << RTC_SR_EN_SHIFT)) & RTC_SR_EN_MASK)
#define RTC_SR_FREEZE_MASK                       (0x4U)
#define RTC_SR_FREEZE_SHIFT                      (2U)
#define RTC_SR_FREEZE(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_SR_FREEZE_SHIFT)) & RTC_SR_FREEZE_MASK)
#define RTC_SR_RUN_MASK                          (0x8U)
#define RTC_SR_RUN_SHIFT                         (3U)
#define RTC_SR_RUN(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_RUN_SHIFT)) & RTC_SR_RUN_MASK)
/*! @} */

/*! @name CAL - RTC calibration value */
/*! @{ */
#define RTC_CAL_CALIB_MASK                       (0xFFFFU)
#define RTC_CAL_CALIB_SHIFT                      (0U)
#define RTC_CAL_CALIB(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_CAL_CALIB_SHIFT)) & RTC_CAL_CALIB_MASK)
/*! @} */

/*! @name SLEEPT - RTC Sleep time */
/*! @{ */
#define RTC_SLEEPT_SLEEPTIME_MASK                (0xFFFFFFU)
#define RTC_SLEEPT_SLEEPTIME_SHIFT               (0U)
#define RTC_SLEEPT_SLEEPTIME(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_SLEEPT_SLEEPTIME_SHIFT)) & RTC_SLEEPT_SLEEPTIME_MASK)
/*! @} */

/*! @name VAL - Current RTC counter value */
/*! @{ */
#define RTC_VAL_TIMEREMAIN_MASK                  (0xFFFFFFU)
#define RTC_VAL_TIMEREMAIN_SHIFT                 (0U)
#define RTC_VAL_TIMEREMAIN(x)                    (((uint32_t)(((uint32_t)(x)) << RTC_VAL_TIMEREMAIN_SHIFT)) & RTC_VAL_TIMEREMAIN_MASK)
/*! @} */

/*! @name IMIS - Interrupt mask register */
/*! @{ */
#define RTC_IMIS_IE_MASK                         (0x1U)
#define RTC_IMIS_IE_SHIFT                        (0U)
#define RTC_IMIS_IE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_IMIS_IE_SHIFT)) & RTC_IMIS_IE_MASK)
/*! @} */

/*! @name RIS - Raw Interrupt status register */
/*! @{ */
#define RTC_RIS_RIS_MASK                         (0x1U)
#define RTC_RIS_RIS_SHIFT                        (0U)
#define RTC_RIS_RIS(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_RIS_RIS_SHIFT)) & RTC_RIS_RIS_MASK)
/*! @} */

/*! @name MIS - Masked interrupt status register */
/*! @{ */
#define RTC_MIS_MIS_MASK                         (0x1U)
#define RTC_MIS_MIS_SHIFT                        (0U)
#define RTC_MIS_MIS(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_MIS_MIS_SHIFT)) & RTC_MIS_MIS_MASK)
/*! @} */

/*! @name ICR - Interrupt clear register */
/*! @{ */
#define RTC_ICR_IC_MASK                          (0x1U)
#define RTC_ICR_IC_SHIFT                         (0U)
#define RTC_ICR_IC(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_ICR_IC_SHIFT)) & RTC_ICR_IC_MASK)
/*! @} */

/*! @name ACCSTAT - Access status register */
/*! @{ */
#define RTC_ACCSTAT_READY_MASK                   (0x1U)
#define RTC_ACCSTAT_READY_SHIFT                  (0U)
#define RTC_ACCSTAT_READY(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_ACCSTAT_READY_SHIFT)) & RTC_ACCSTAT_READY_MASK)
/*! @} */

/*! @name TIME - RTC Time register */
/*! @{ */
#define RTC_TIME_TIME_MASK                       (0xFFFFFFFFU)
#define RTC_TIME_TIME_SHIFT                      (0U)
#define RTC_TIME_TIME(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_TIME_TIME_SHIFT)) & RTC_TIME_TIME_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x40054000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTCPWREQ_IRQn }

/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SPI0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI0_Peripheral_Access_Layer SPI0 Peripheral Access Layer
 * @{
 */

/** SPI0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR0;                               /**< Control register 0. Selects the serial clock rate, bus type, and data size, offset: 0x0 */
  __IO uint32_t CR1;                               /**< Control register 1. Selects master/slave and other modes, offset: 0x4 */
  __IO uint32_t DR;                                /**< Data register. Writes fill the transmit FIFO, and reads empty the receive FIFO, offset: 0x8 */
  __I  uint32_t SR;                                /**< Status register, offset: 0xC */
  __IO uint32_t CPSR;                              /**< Clock Prescale register, offset: 0x10 */
  __IO uint32_t IMSC;                              /**< Interrupt Mask Set and Clear Register, offset: 0x14 */
  __I  uint32_t RIS;                               /**< Raw Interrupt Status Register, offset: 0x18 */
  __I  uint32_t MIS;                               /**< Masked Interrupt Status Register, offset: 0x1C */
  __O  uint32_t ICR;                               /**< Interrupt Clear Register, offset: 0x20 */
} SPI0_Type;

/* ----------------------------------------------------------------------------
   -- SPI0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI0_Register_Masks SPI0 Register Masks
 * @{
 */

/*! @name CR0 - Control register 0. Selects the serial clock rate, bus type, and data size */
/*! @{ */
#define SPI0_CR0_DSS_MASK                        (0xFU)
#define SPI0_CR0_DSS_SHIFT                       (0U)
/*! DSS - Data Size Select. This field controls the number of bits transferred in each frame. Values 0000-0010 are not supported and should not be used.
 *  0b0011..4-bit transfer
 *  0b0100..5-bit transfer
 *  0b0101..6-bit transfer
 *  0b0110..7-bit transfer
 *  0b0111..8-bit transfer
 *  0b1000..9-bit transfer
 *  0b1001..10-bit transfer
 *  0b1010..11-bit transfer
 *  0b1011..12-bit transfer
 *  0b1100..13-bit transfer
 *  0b1101..14-bit transfer
 *  0b1110..15-bit transfer
 *  0b1111..16-bit transfer
 */
#define SPI0_CR0_DSS(x)                          (((uint32_t)(((uint32_t)(x)) << SPI0_CR0_DSS_SHIFT)) & SPI0_CR0_DSS_MASK)
#define SPI0_CR0_FRF_MASK                        (0x30U)
#define SPI0_CR0_FRF_SHIFT                       (4U)
/*! FRF - Frame Format
 *  0b00..SPI
 *  0b01..TI...
 *  0b10..Microwire
 */
#define SPI0_CR0_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << SPI0_CR0_FRF_SHIFT)) & SPI0_CR0_FRF_MASK)
#define SPI0_CR0_CPOL_MASK                       (0x40U)
#define SPI0_CR0_CPOL_SHIFT                      (6U)
/*! CPOL - Clock out polarity. This bit is only used in SPI mode
 *  0b0..SPI controller maintains the bus clock low between frames
 *  0b1..SPI controller maintains the bus clock high between frames
 */
#define SPI0_CR0_CPOL(x)                         (((uint32_t)(((uint32_t)(x)) << SPI0_CR0_CPOL_SHIFT)) & SPI0_CR0_CPOL_MASK)
#define SPI0_CR0_CPHA_MASK                       (0x80U)
#define SPI0_CR0_CPHA_SHIFT                      (7U)
/*! CPHA - Clock out Phase. This bit is only used in SPI mode
 *  0b0..SPI controller captures serial data on the first clock transition of the frame, that is, the transition away from the inter-frame state of the clock line.
 *  0b1..SPI controller captures serial data on the second clock transition of the frame, that is, the transition back to the inter-frame state of the clock line.
 */
#define SPI0_CR0_CPHA(x)                         (((uint32_t)(((uint32_t)(x)) << SPI0_CR0_CPHA_SHIFT)) & SPI0_CR0_CPHA_MASK)
#define SPI0_CR0_SCR_MASK                        (0xFF00U)
#define SPI0_CR0_SCR_SHIFT                       (8U)
#define SPI0_CR0_SCR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI0_CR0_SCR_SHIFT)) & SPI0_CR0_SCR_MASK)
/*! @} */

/*! @name CR1 - Control register 1. Selects master/slave and other modes */
/*! @{ */
#define SPI0_CR1_LBM_MASK                        (0x1U)
#define SPI0_CR1_LBM_SHIFT                       (0U)
/*! LBM - Loop back mode
 *  0b0..During normal operation
 *  0b1..Serial input is taken from the serial output (MOSI or MISO) rather than the serial input pin (MISO or MOSI respectively).
 */
#define SPI0_CR1_LBM(x)                          (((uint32_t)(((uint32_t)(x)) << SPI0_CR1_LBM_SHIFT)) & SPI0_CR1_LBM_MASK)
#define SPI0_CR1_SSE_MASK                        (0x2U)
#define SPI0_CR1_SSE_SHIFT                       (1U)
/*! SSE - SPI Enable
 *  0b0..The SPI controller is enable
 *  0b1..The SPI controller will interact with other devices on the serial bus. Software should write the appropriate control information to the other SPI/SSP registers and interrupt controller registers, before setting this bit.
 */
#define SPI0_CR1_SSE(x)                          (((uint32_t)(((uint32_t)(x)) << SPI0_CR1_SSE_SHIFT)) & SPI0_CR1_SSE_MASK)
#define SPI0_CR1_MS_MASK                         (0x4U)
#define SPI0_CR1_MS_SHIFT                        (2U)
/*! MS - Master/Slave Mode.This bit can only be written when the SSE bit is 0.
 *  0b0..The SPI controller acts as a master on the bus, driving the SCLK, MOSI, and SSEL lines and receiving the MISO line.
 *  0b1..The SPI controller acts as a slave on the bus, driving MISO line and receiving SCLK, MOSI, and SSEL lines.
 */
#define SPI0_CR1_MS(x)                           (((uint32_t)(((uint32_t)(x)) << SPI0_CR1_MS_SHIFT)) & SPI0_CR1_MS_MASK)
#define SPI0_CR1_SOD_MASK                        (0x8U)
#define SPI0_CR1_SOD_SHIFT                       (3U)
#define SPI0_CR1_SOD(x)                          (((uint32_t)(((uint32_t)(x)) << SPI0_CR1_SOD_SHIFT)) & SPI0_CR1_SOD_MASK)
/*! @} */

/*! @name DR - Data register. Writes fill the transmit FIFO, and reads empty the receive FIFO */
/*! @{ */
#define SPI0_DR_DATA_MASK                        (0xFFFFU)
#define SPI0_DR_DATA_SHIFT                       (0U)
#define SPI0_DR_DATA(x)                          (((uint32_t)(((uint32_t)(x)) << SPI0_DR_DATA_SHIFT)) & SPI0_DR_DATA_MASK)
/*! @} */

/*! @name SR - Status register */
/*! @{ */
#define SPI0_SR_TFE_MASK                         (0x1U)
#define SPI0_SR_TFE_SHIFT                        (0U)
#define SPI0_SR_TFE(x)                           (((uint32_t)(((uint32_t)(x)) << SPI0_SR_TFE_SHIFT)) & SPI0_SR_TFE_MASK)
#define SPI0_SR_TNF_MASK                         (0x2U)
#define SPI0_SR_TNF_SHIFT                        (1U)
#define SPI0_SR_TNF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI0_SR_TNF_SHIFT)) & SPI0_SR_TNF_MASK)
#define SPI0_SR_RNE_MASK                         (0x4U)
#define SPI0_SR_RNE_SHIFT                        (2U)
#define SPI0_SR_RNE(x)                           (((uint32_t)(((uint32_t)(x)) << SPI0_SR_RNE_SHIFT)) & SPI0_SR_RNE_MASK)
#define SPI0_SR_RFF_MASK                         (0x8U)
#define SPI0_SR_RFF_SHIFT                        (3U)
#define SPI0_SR_RFF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI0_SR_RFF_SHIFT)) & SPI0_SR_RFF_MASK)
#define SPI0_SR_BSY_MASK                         (0x10U)
#define SPI0_SR_BSY_SHIFT                        (4U)
#define SPI0_SR_BSY(x)                           (((uint32_t)(((uint32_t)(x)) << SPI0_SR_BSY_SHIFT)) & SPI0_SR_BSY_MASK)
/*! @} */

/*! @name CPSR - Clock Prescale register */
/*! @{ */
#define SPI0_CPSR_CPSDVSR_MASK                   (0xFFU)
#define SPI0_CPSR_CPSDVSR_SHIFT                  (0U)
#define SPI0_CPSR_CPSDVSR(x)                     (((uint32_t)(((uint32_t)(x)) << SPI0_CPSR_CPSDVSR_SHIFT)) & SPI0_CPSR_CPSDVSR_MASK)
/*! @} */

/*! @name IMSC - Interrupt Mask Set and Clear Register */
/*! @{ */
#define SPI0_IMSC_RORIM_MASK                     (0x1U)
#define SPI0_IMSC_RORIM_SHIFT                    (0U)
#define SPI0_IMSC_RORIM(x)                       (((uint32_t)(((uint32_t)(x)) << SPI0_IMSC_RORIM_SHIFT)) & SPI0_IMSC_RORIM_MASK)
#define SPI0_IMSC_RTIM_MASK                      (0x2U)
#define SPI0_IMSC_RTIM_SHIFT                     (1U)
#define SPI0_IMSC_RTIM(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_IMSC_RTIM_SHIFT)) & SPI0_IMSC_RTIM_MASK)
#define SPI0_IMSC_RXIM_MASK                      (0x4U)
#define SPI0_IMSC_RXIM_SHIFT                     (2U)
#define SPI0_IMSC_RXIM(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_IMSC_RXIM_SHIFT)) & SPI0_IMSC_RXIM_MASK)
#define SPI0_IMSC_TXIM_MASK                      (0x8U)
#define SPI0_IMSC_TXIM_SHIFT                     (3U)
#define SPI0_IMSC_TXIM(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_IMSC_TXIM_SHIFT)) & SPI0_IMSC_TXIM_MASK)
/*! @} */

/*! @name RIS - Raw Interrupt Status Register */
/*! @{ */
#define SPI0_RIS_RORRIS_MASK                     (0x1U)
#define SPI0_RIS_RORRIS_SHIFT                    (0U)
#define SPI0_RIS_RORRIS(x)                       (((uint32_t)(((uint32_t)(x)) << SPI0_RIS_RORRIS_SHIFT)) & SPI0_RIS_RORRIS_MASK)
#define SPI0_RIS_RTRIS_MASK                      (0x2U)
#define SPI0_RIS_RTRIS_SHIFT                     (1U)
#define SPI0_RIS_RTRIS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_RIS_RTRIS_SHIFT)) & SPI0_RIS_RTRIS_MASK)
#define SPI0_RIS_RXRIS_MASK                      (0x4U)
#define SPI0_RIS_RXRIS_SHIFT                     (2U)
#define SPI0_RIS_RXRIS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_RIS_RXRIS_SHIFT)) & SPI0_RIS_RXRIS_MASK)
#define SPI0_RIS_TXRIS_MASK                      (0x8U)
#define SPI0_RIS_TXRIS_SHIFT                     (3U)
#define SPI0_RIS_TXRIS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_RIS_TXRIS_SHIFT)) & SPI0_RIS_TXRIS_MASK)
/*! @} */

/*! @name MIS - Masked Interrupt Status Register */
/*! @{ */
#define SPI0_MIS_RORMIS_MASK                     (0x1U)
#define SPI0_MIS_RORMIS_SHIFT                    (0U)
#define SPI0_MIS_RORMIS(x)                       (((uint32_t)(((uint32_t)(x)) << SPI0_MIS_RORMIS_SHIFT)) & SPI0_MIS_RORMIS_MASK)
#define SPI0_MIS_RTMIS_MASK                      (0x2U)
#define SPI0_MIS_RTMIS_SHIFT                     (1U)
#define SPI0_MIS_RTMIS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_MIS_RTMIS_SHIFT)) & SPI0_MIS_RTMIS_MASK)
#define SPI0_MIS_RXMIS_MASK                      (0x4U)
#define SPI0_MIS_RXMIS_SHIFT                     (2U)
#define SPI0_MIS_RXMIS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_MIS_RXMIS_SHIFT)) & SPI0_MIS_RXMIS_MASK)
#define SPI0_MIS_TXMIS_MASK                      (0x8U)
#define SPI0_MIS_TXMIS_SHIFT                     (3U)
#define SPI0_MIS_TXMIS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_MIS_TXMIS_SHIFT)) & SPI0_MIS_TXMIS_MASK)
/*! @} */

/*! @name ICR - Interrupt Clear Register */
/*! @{ */
#define SPI0_ICR_RORIC_MASK                      (0x1U)
#define SPI0_ICR_RORIC_SHIFT                     (0U)
#define SPI0_ICR_RORIC(x)                        (((uint32_t)(((uint32_t)(x)) << SPI0_ICR_RORIC_SHIFT)) & SPI0_ICR_RORIC_MASK)
#define SPI0_ICR_RTIC_MASK                       (0x2U)
#define SPI0_ICR_RTIC_SHIFT                      (1U)
#define SPI0_ICR_RTIC(x)                         (((uint32_t)(((uint32_t)(x)) << SPI0_ICR_RTIC_SHIFT)) & SPI0_ICR_RTIC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPI0_Register_Masks */


/* SPI0 - Peripheral instance base addresses */
/** Peripheral SPI0 base address */
#define SPI0_BASE                                (0x40040000u)
/** Peripheral SPI0 base pointer */
#define SPI0                                     ((SPI0_Type *)SPI0_BASE)
/** Array initializer of SPI0 peripheral base addresses */
#define SPI0_BASE_ADDRS                          { SPI0_BASE }
/** Array initializer of SPI0 peripheral base pointers */
#define SPI0_BASE_PTRS                           { SPI0 }

/*!
 * @}
 */ /* end of group SPI0_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SYSCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Peripheral_Access_Layer SYSCON Peripheral Access Layer
 * @{
 */

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSMEMREMAP;                       /**< System memory remap, offset: 0x0 */
  __IO uint32_t PRESETCTRL;                        /**< Peripheral reset control, offset: 0x4 */
       uint8_t RESERVED_0[24];
  __IO uint32_t SYSCLKCTRL;                        /**< System clock control register, offset: 0x20 */
  __IO uint32_t SYSCLKUEN;                         /**< System clock update enable, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t SYSRSTSTAT;                        /**< System reset status register, offset: 0x30 */
       uint8_t RESERVED_2[76];
  __IO uint32_t SYSAHBCLKCTRL;                     /**< AHB clock control, offset: 0x80 */
       uint8_t RESERVED_3[16];
  __IO uint32_t SSPCLKDIV;                         /**< SPI/SSP clock divider, offset: 0x94 */
       uint8_t RESERVED_4[56];
  __IO uint32_t WDTCLKSEL;                         /**< Watchdog timer clock selector, offset: 0xD0 */
  __IO uint32_t WDTCLKUEN;                         /**< Watchdog timer clock update enable, offset: 0xD4 */
  __IO uint32_t WDTCLKDIV;                         /**< Watchdog timer clock divider, offset: 0xD8 */
       uint8_t RESERVED_5[12];
  __IO uint32_t CLKOUTEN;                          /**< CLKOUT enable, offset: 0xE8 */
       uint8_t RESERVED_6[104];
  __IO uint32_t SYSTCKCAL;                         /**< System tick counter calibration, offset: 0x154 */
       uint8_t RESERVED_7[168];
  __IO uint32_t STARTAPRP0;                        /**< Start logic edge control register 0, offset: 0x200 */
  __IO uint32_t STARTERP0;                         /**< Start logic signal enable register 0, offset: 0x204 */
  __IO uint32_t STARTRSRP0CLR;                     /**< Start logic reset register 0, offset: 0x208 */
  __I  uint32_t STARTSRP0;                         /**< Start logic status register 0, offset: 0x20C */
       uint8_t RESERVED_8[36];
  __IO uint32_t PDAWAKECFG;                        /**< Power-down states after wake-up from deep-sleep mode, offset: 0x234 */
  __IO uint32_t PDRUNCFG;                          /**< power-down configuration register, offset: 0x238 */
       uint8_t RESERVED_9[440];
  __I  uint32_t DEVICE_ID;                         /**< ..., offset: 0x3F4 */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name SYSMEMREMAP - System memory remap */
/*! @{ */
#define SYSCON_SYSMEMREMAP_map_MASK              (0x1U)
#define SYSCON_SYSMEMREMAP_map_SHIFT             (0U)
/*! map - Interrupt vector remap
 *  0b0..Interrupt vectors reside in Flash
 *  0b1..Interrupt vectors reside in SRAM
 */
#define SYSCON_SYSMEMREMAP_map(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSMEMREMAP_map_SHIFT)) & SYSCON_SYSMEMREMAP_map_MASK)
#define SYSCON_SYSMEMREMAP_offset_MASK           (0x3EU)
#define SYSCON_SYSMEMREMAP_offset_SHIFT          (1U)
/*! offset - System memory remap offset
 *  0b00000..Interrupt vectors in flash or remapped to SRAM but not offset
 *  0b00001..Interrupt vectors offset in flash or SRAM to 1K word segment
 *  0b01000..Interrupt vectors offset in flash to 1K word segment 8 to 31
 */
#define SYSCON_SYSMEMREMAP_offset(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSMEMREMAP_offset_SHIFT)) & SYSCON_SYSMEMREMAP_offset_MASK)
/*! @} */

/*! @name PRESETCTRL - Peripheral reset control */
/*! @{ */
#define SYSCON_PRESETCTRL_SSP_RST_N_MASK         (0x1U)
#define SYSCON_PRESETCTRL_SSP_RST_N_SHIFT        (0U)
/*! SSP_RST_N - SPI/SSP reset control
 *  0b0..Resets the SPI peripheral
 *  0b1..SPI reset deasserted
 */
#define SYSCON_PRESETCTRL_SSP_RST_N(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SSP_RST_N_SHIFT)) & SYSCON_PRESETCTRL_SSP_RST_N_MASK)
#define SYSCON_PRESETCTRL_I2C_RST_N_MASK         (0x2U)
#define SYSCON_PRESETCTRL_I2C_RST_N_SHIFT        (1U)
/*! I2C_RST_N - I2C reset control
 *  0b0..Resets the I2C peripheral
 *  0b1..I2C reset de-asserted
 */
#define SYSCON_PRESETCTRL_I2C_RST_N(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_I2C_RST_N_SHIFT)) & SYSCON_PRESETCTRL_I2C_RST_N_MASK)
#define SYSCON_PRESETCTRL_EE_RST_N_MASK          (0x4U)
#define SYSCON_PRESETCTRL_EE_RST_N_SHIFT         (2U)
/*! EE_RST_N - EEPROM nvmc reset control
 *  0b0..Resets the EEPROM controller
 *  0b1..Reset de-asserted
 */
#define SYSCON_PRESETCTRL_EE_RST_N(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_EE_RST_N_SHIFT)) & SYSCON_PRESETCTRL_EE_RST_N_MASK)
#define SYSCON_PRESETCTRL_NFC_RST_N_MASK         (0x8U)
#define SYSCON_PRESETCTRL_NFC_RST_N_SHIFT        (3U)
/*! NFC_RST_N - NRF shared memory reset control
 *  0b0..Resets the NRF shared memory
 *  0b1..Reset de-asserted
 */
#define SYSCON_PRESETCTRL_NFC_RST_N(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_NFC_RST_N_SHIFT)) & SYSCON_PRESETCTRL_NFC_RST_N_MASK)
/*! @} */

/*! @name SYSCLKCTRL - System clock control register */
/*! @{ */
#define SYSCON_SYSCLKCTRL_SYSCLKDIV_MASK         (0xEU)
#define SYSCON_SYSCLKCTRL_SYSCLKDIV_SHIFT        (1U)
/*! SYSCLKDIV - System clock divider
 *  0b000..no division (output 8 MHz from SFRO)
 *  0b001..divide-by-2 (output 4 MHz from SFRO)
 *  0b010..divide-by-4 (output 2 MHz from SFRO)
 *  0b011..divide-by-8 (output 1 MHz from SFRO)
 *  0b100..divide-by-16 (output 500 kHz from SFRO)
 *  0b101..divide-by-32 (output 250 kHz from SFRO)
 *  0b110..divide-by-64 (output 125 kHz from SFRO)
 *  0b111..divide-by-128 (output 62.5 kHz from SFRO)
 */
#define SYSCON_SYSCLKCTRL_SYSCLKDIV(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSCLKCTRL_SYSCLKDIV_SHIFT)) & SYSCON_SYSCLKCTRL_SYSCLKDIV_MASK)
#define SYSCON_SYSCLKCTRL_SYSCLKTRIM_MASK        (0x3F0000U)
#define SYSCON_SYSCLKCTRL_SYSCLKTRIM_SHIFT       (16U)
#define SYSCON_SYSCLKCTRL_SYSCLKTRIM(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSCLKCTRL_SYSCLKTRIM_SHIFT)) & SYSCON_SYSCLKCTRL_SYSCLKTRIM_MASK)
/*! @} */

/*! @name SYSCLKUEN - System clock update enable */
/*! @{ */
#define SYSCON_SYSCLKUEN_ENA_MASK                (0x1U)
#define SYSCON_SYSCLKUEN_ENA_SHIFT               (0U)
/*! ENA - Enable system clock source update
 *  0b0..no update
 *  0b1..update clock source
 */
#define SYSCON_SYSCLKUEN_ENA(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSCLKUEN_ENA_SHIFT)) & SYSCON_SYSCLKUEN_ENA_MASK)
/*! @} */

/*! @name SYSRSTSTAT - System reset status register */
/*! @{ */
#define SYSCON_SYSRSTSTAT_POR_MASK               (0x1U)
#define SYSCON_SYSRSTSTAT_POR_SHIFT              (0U)
/*! POR - POR reset status
 *  0b0..no POR detected
 *  0b1..POR detected
 */
#define SYSCON_SYSRSTSTAT_POR(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_POR_SHIFT)) & SYSCON_SYSRSTSTAT_POR_MASK)
#define SYSCON_SYSRSTSTAT_EXTRST_MASK            (0x2U)
#define SYSCON_SYSRSTSTAT_EXTRST_SHIFT           (1U)
/*! EXTRST - Status of external RESETN pin
 *  0b0..No RESETN event detected
 *  0b1..External reset detected
 */
#define SYSCON_SYSRSTSTAT_EXTRST(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_EXTRST_SHIFT)) & SYSCON_SYSRSTSTAT_EXTRST_MASK)
#define SYSCON_SYSRSTSTAT_WDT_MASK               (0x4U)
#define SYSCON_SYSRSTSTAT_WDT_SHIFT              (2U)
/*! WDT - Status of the Watchdog reset
 *  0b0..no WDT reset detected
 *  0b1..WDT reset detected
 */
#define SYSCON_SYSRSTSTAT_WDT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_WDT_SHIFT)) & SYSCON_SYSRSTSTAT_WDT_MASK)
#define SYSCON_SYSRSTSTAT_SYSRST_MASK            (0x8U)
#define SYSCON_SYSRSTSTAT_SYSRST_SHIFT           (3U)
/*! SYSRST - Status of software system reset (ARM AIRCR register SYSRESETREQ bit was set)
 *  0b0..No software reset detected
 *  0b1..Software reset detected
 */
#define SYSCON_SYSRSTSTAT_SYSRST(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_SYSRST_SHIFT)) & SYSCON_SYSRSTSTAT_SYSRST_MASK)
/*! @} */

/*! @name SYSAHBCLKCTRL - AHB clock control */
/*! @{ */
#define SYSCON_SYSAHBCLKCTRL_RAM_MASK            (0x4U)
#define SYSCON_SYSAHBCLKCTRL_RAM_SHIFT           (2U)
/*! RAM - Enable clock for RAM
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_RAM(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_RAM_SHIFT)) & SYSCON_SYSAHBCLKCTRL_RAM_MASK)
#define SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK       (0x8U)
#define SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT      (3U)
/*! FLASHREG - Enable clock for Flash register interface
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_FLASHREG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT)) & SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK)
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK     (0x10U)
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY_SHIFT    (4U)
/*! FLASHARRAY - Enable clock for Flash array access
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_FLASHARRAY_SHIFT)) & SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK)
#define SYSCON_SYSAHBCLKCTRL_I2C_MASK            (0x20U)
#define SYSCON_SYSAHBCLKCTRL_I2C_SHIFT           (5U)
/*! I2C - Enable clock for I2C
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_I2C(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_I2C_SHIFT)) & SYSCON_SYSAHBCLKCTRL_I2C_MASK)
#define SYSCON_SYSAHBCLKCTRL_GPIO_MASK           (0x40U)
#define SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT          (6U)
/*! GPIO - Enable clock for GPIO
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_GPIO(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT)) & SYSCON_SYSAHBCLKCTRL_GPIO_MASK)
#define SYSCON_SYSAHBCLKCTRL_SPISSP_MASK         (0x80U)
#define SYSCON_SYSAHBCLKCTRL_SPISSP_SHIFT        (7U)
/*! SPISSP - Enable clock for SPI/SSP
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_SPISSP(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_SPISSP_SHIFT)) & SYSCON_SYSAHBCLKCTRL_SPISSP_MASK)
#define SYSCON_SYSAHBCLKCTRL_CT16B_MASK          (0x100U)
#define SYSCON_SYSAHBCLKCTRL_CT16B_SHIFT         (8U)
/*! CT16B - Enable clock for 16-bit counter/timer
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_CT16B(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_CT16B_SHIFT)) & SYSCON_SYSAHBCLKCTRL_CT16B_MASK)
#define SYSCON_SYSAHBCLKCTRL_CT32B_MASK          (0x200U)
#define SYSCON_SYSAHBCLKCTRL_CT32B_SHIFT         (9U)
/*! CT32B - Enable clock for 32-bit counter/timer
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_CT32B(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_CT32B_SHIFT)) & SYSCON_SYSAHBCLKCTRL_CT32B_MASK)
#define SYSCON_SYSAHBCLKCTRL_RTC_MASK            (0x400U)
#define SYSCON_SYSAHBCLKCTRL_RTC_SHIFT           (10U)
/*! RTC - Enable clock for RTC on/off timer (APB side only, timer unit is clocked by TFRO directly as set by TMRCLKCTRL register)
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_RTC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_RTC_SHIFT)) & SYSCON_SYSAHBCLKCTRL_RTC_MASK)
#define SYSCON_SYSAHBCLKCTRL_WDT_MASK            (0x800U)
#define SYSCON_SYSAHBCLKCTRL_WDT_SHIFT           (11U)
/*! WDT - Enable clock for watchdog timer
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_WDT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_WDT_SHIFT)) & SYSCON_SYSAHBCLKCTRL_WDT_MASK)
#define SYSCON_SYSAHBCLKCTRL_TSENS_MASK          (0x1000U)
#define SYSCON_SYSAHBCLKCTRL_TSENS_SHIFT         (12U)
/*! TSENS - Enable clock for temperature sensor
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_TSENS(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_TSENS_SHIFT)) & SYSCON_SYSAHBCLKCTRL_TSENS_MASK)
#define SYSCON_SYSAHBCLKCTRL_IOCON_MASK          (0x40000U)
#define SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT         (18U)
/*! IOCON - Enable clock for I/O configuration block
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_IOCON(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT)) & SYSCON_SYSAHBCLKCTRL_IOCON_MASK)
#define SYSCON_SYSAHBCLKCTRL_EEREG_MASK          (0x80000U)
#define SYSCON_SYSAHBCLKCTRL_EEREG_SHIFT         (19U)
/*! EEREG - Enable clock for EEPROM register interface
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_EEREG(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_EEREG_SHIFT)) & SYSCON_SYSAHBCLKCTRL_EEREG_MASK)
#define SYSCON_SYSAHBCLKCTRL_EEARRAY_MASK        (0x100000U)
#define SYSCON_SYSAHBCLKCTRL_EEARRAY_SHIFT       (20U)
/*! EEARRAY - Enable clock for EEPROM array access
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SYSAHBCLKCTRL_EEARRAY(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_EEARRAY_SHIFT)) & SYSCON_SYSAHBCLKCTRL_EEARRAY_MASK)
/*! @} */

/*! @name SSPCLKDIV - SPI/SSP clock divider */
/*! @{ */
#define SYSCON_SSPCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_SSPCLKDIV_DIV_SHIFT               (0U)
#define SYSCON_SSPCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SSPCLKDIV_DIV_SHIFT)) & SYSCON_SSPCLKDIV_DIV_MASK)
/*! @} */

/*! @name WDTCLKSEL - Watchdog timer clock selector */
/*! @{ */
#define SYSCON_WDTCLKSEL_SEL_MASK                (0x3U)
#define SYSCON_WDTCLKSEL_SEL_SHIFT               (0U)
/*! SEL - WDT clock source
 *  0b00..System FRO
 *  0b01..External clock pin
 *  0b10..VSS (no clock)
 */
#define SYSCON_WDTCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTCLKSEL_SEL_SHIFT)) & SYSCON_WDTCLKSEL_SEL_MASK)
/*! @} */

/*! @name WDTCLKUEN - Watchdog timer clock update enable */
/*! @{ */
#define SYSCON_WDTCLKUEN_ENA_MASK                (0x1U)
#define SYSCON_WDTCLKUEN_ENA_SHIFT               (0U)
/*! ENA - Enable WDT clock source update
 *  0b0..no update
 *  0b1..update clock source
 */
#define SYSCON_WDTCLKUEN_ENA(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTCLKUEN_ENA_SHIFT)) & SYSCON_WDTCLKUEN_ENA_MASK)
/*! @} */

/*! @name WDTCLKDIV - Watchdog timer clock divider */
/*! @{ */
#define SYSCON_WDTCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_WDTCLKDIV_DIV_SHIFT               (0U)
#define SYSCON_WDTCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTCLKDIV_DIV_SHIFT)) & SYSCON_WDTCLKDIV_DIV_MASK)
/*! @} */

/*! @name CLKOUTEN - CLKOUT enable */
/*! @{ */
#define SYSCON_CLKOUTEN_CLKOUTEN_MASK            (0x1U)
#define SYSCON_CLKOUTEN_CLKOUTEN_SHIFT           (0U)
/*! CLKOUTEN - control output clock enable or disable
 *  0b0..disable output
 *  0b1..enable output
 */
#define SYSCON_CLKOUTEN_CLKOUTEN(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTEN_CLKOUTEN_SHIFT)) & SYSCON_CLKOUTEN_CLKOUTEN_MASK)
#define SYSCON_CLKOUTEN_CLKOUTSRC_MASK           (0x6U)
#define SYSCON_CLKOUTEN_CLKOUTSRC_SHIFT          (1U)
/*! CLKOUTSRC - select output clock
 *  0b00..8MHz
 *  0b01..output system clock (62.5 kHz - 8 MHz)
 *  0b10..output TFRO (32 kHz)
 *  0b11..output NFC clock (1.695 MHz)
 */
#define SYSCON_CLKOUTEN_CLKOUTSRC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTEN_CLKOUTSRC_SHIFT)) & SYSCON_CLKOUTEN_CLKOUTSRC_MASK)
/*! @} */

/*! @name SYSTCKCAL - System tick counter calibration */
/*! @{ */
#define SYSCON_SYSTCKCAL_CAL_MASK                (0x3FFFFFFU)
#define SYSCON_SYSTCKCAL_CAL_SHIFT               (0U)
#define SYSCON_SYSTCKCAL_CAL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTCKCAL_CAL_SHIFT)) & SYSCON_SYSTCKCAL_CAL_MASK)
/*! @} */

/*! @name STARTAPRP0 - Start logic edge control register 0 */
/*! @{ */
#define SYSCON_STARTAPRP0_APRPIO_n_MASK          (0x7FFU)
#define SYSCON_STARTAPRP0_APRPIO_n_SHIFT         (0U)
#define SYSCON_STARTAPRP0_APRPIO_n(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTAPRP0_APRPIO_n_SHIFT)) & SYSCON_STARTAPRP0_APRPIO_n_MASK)
/*! @} */

/*! @name STARTERP0 - Start logic signal enable register 0 */
/*! @{ */
#define SYSCON_STARTERP0_ERPIO_n_MASK            (0x7FFU)
#define SYSCON_STARTERP0_ERPIO_n_SHIFT           (0U)
#define SYSCON_STARTERP0_ERPIO_n(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_ERPIO_n_SHIFT)) & SYSCON_STARTERP0_ERPIO_n_MASK)
#define SYSCON_STARTERP0_ERRFID_MASK             (0x800U)
#define SYSCON_STARTERP0_ERRFID_SHIFT            (11U)
/*! ERRFID - Enable start signal for start logic input RFID
 *  0b0..disabled
 *  0b1..enabled
 */
#define SYSCON_STARTERP0_ERRFID(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_ERRFID_SHIFT)) & SYSCON_STARTERP0_ERRFID_MASK)
#define SYSCON_STARTERP0_ERTMR_MASK              (0x1000U)
#define SYSCON_STARTERP0_ERTMR_SHIFT             (12U)
/*! ERTMR - Enable start signal for start logic input RTC timer
 *  0b0..disabled
 *  0b1..enabled
 */
#define SYSCON_STARTERP0_ERTMR(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_ERTMR_SHIFT)) & SYSCON_STARTERP0_ERTMR_MASK)
/*! @} */

/*! @name STARTRSRP0CLR - Start logic reset register 0 */
/*! @{ */
#define SYSCON_STARTRSRP0CLR_RSRPIO_n_MASK       (0x7FFU)
#define SYSCON_STARTRSRP0CLR_RSRPIO_n_SHIFT      (0U)
#define SYSCON_STARTRSRP0CLR_RSRPIO_n(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTRSRP0CLR_RSRPIO_n_SHIFT)) & SYSCON_STARTRSRP0CLR_RSRPIO_n_MASK)
#define SYSCON_STARTRSRP0CLR_RSRRFID_MASK        (0x800U)
#define SYSCON_STARTRSRP0CLR_RSRRFID_SHIFT       (11U)
/*! RSRRFID - Start signal reset for start logic input RFID
 *  0b0..Do nothing
 *  0b1..Writing 1 resets the start signal
 */
#define SYSCON_STARTRSRP0CLR_RSRRFID(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTRSRP0CLR_RSRRFID_SHIFT)) & SYSCON_STARTRSRP0CLR_RSRRFID_MASK)
#define SYSCON_STARTRSRP0CLR_RSRTMR_MASK         (0x1000U)
#define SYSCON_STARTRSRP0CLR_RSRTMR_SHIFT        (12U)
/*! RSRTMR - Start signal reset for start logic input wakeup timer
 *  0b0..Do nothing
 *  0b1..Writing 1 resets the start signal
 */
#define SYSCON_STARTRSRP0CLR_RSRTMR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTRSRP0CLR_RSRTMR_SHIFT)) & SYSCON_STARTRSRP0CLR_RSRTMR_MASK)
/*! @} */

/*! @name STARTSRP0 - Start logic status register 0 */
/*! @{ */
#define SYSCON_STARTSRP0_SRPIO_n_MASK            (0x7FFU)
#define SYSCON_STARTSRP0_SRPIO_n_SHIFT           (0U)
#define SYSCON_STARTSRP0_SRPIO_n(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTSRP0_SRPIO_n_SHIFT)) & SYSCON_STARTSRP0_SRPIO_n_MASK)
#define SYSCON_STARTSRP0_SRRFID_MASK             (0x800U)
#define SYSCON_STARTSRP0_SRRFID_SHIFT            (11U)
/*! SRRFID - Start signal status for start logic input RFID
 *  0b0..no start signal received
 *  0b1..start signal received
 */
#define SYSCON_STARTSRP0_SRRFID(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTSRP0_SRRFID_SHIFT)) & SYSCON_STARTSRP0_SRRFID_MASK)
#define SYSCON_STARTSRP0_SRTMR_MASK              (0x1000U)
#define SYSCON_STARTSRP0_SRTMR_SHIFT             (12U)
/*! SRTMR - Start signal status for start logic input wakeup timer
 *  0b0..no start signal received
 *  0b1..start signal received
 */
#define SYSCON_STARTSRP0_SRTMR(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTSRP0_SRTMR_SHIFT)) & SYSCON_STARTSRP0_SRTMR_MASK)
/*! @} */

/*! @name PDAWAKECFG - Power-down states after wake-up from deep-sleep mode */
/*! @{ */
#define SYSCON_PDAWAKECFG_FLASH_PD_MASK          (0x1U)
#define SYSCON_PDAWAKECFG_FLASH_PD_SHIFT         (0U)
/*! FLASH_PD - Flash wake-up configuration
 *  0b0..Powered
 *  0b1..Powered down
 */
#define SYSCON_PDAWAKECFG_FLASH_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_FLASH_PD_SHIFT)) & SYSCON_PDAWAKECFG_FLASH_PD_MASK)
/*! @} */

/*! @name PDRUNCFG - power-down configuration register */
/*! @{ */
#define SYSCON_PDRUNCFG_FLASH_PD_MASK            (0x1U)
#define SYSCON_PDRUNCFG_FLASH_PD_SHIFT           (0U)
/*! FLASH_PD - Flash power down
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_FLASH_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_FLASH_PD_SHIFT)) & SYSCON_PDRUNCFG_FLASH_PD_MASK)
#define SYSCON_PDRUNCFG_TSENS_PD_MASK            (0x2U)
#define SYSCON_PDRUNCFG_TSENS_PD_SHIFT           (1U)
/*! TSENS_PD - Temperature sensor
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_TSENS_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_TSENS_PD_SHIFT)) & SYSCON_PDRUNCFG_TSENS_PD_MASK)
#define SYSCON_PDRUNCFG_EEPROM_PD_MASK           (0x8U)
#define SYSCON_PDRUNCFG_EEPROM_PD_SHIFT          (3U)
/*! EEPROM_PD - EEPROM power down
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_EEPROM_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_EEPROM_PD_SHIFT)) & SYSCON_PDRUNCFG_EEPROM_PD_MASK)
/*! @} */

/*! @name DEVICE_ID - ... */
/*! @{ */
#define SYSCON_DEVICE_ID_DEVICEID_MASK           (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID_DEVICEID_SHIFT          (0U)
#define SYSCON_DEVICE_ID_DEVICEID(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID_DEVICEID_SHIFT)) & SYSCON_DEVICE_ID_DEVICEID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON_Register_Masks */


/* SYSCON - Peripheral instance base addresses */
/** Peripheral SYSCON base address */
#define SYSCON_BASE                              (0x40048000u)
/** Peripheral SYSCON base pointer */
#define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
/** Array initializer of SYSCON peripheral base addresses */
#define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
/** Array initializer of SYSCON peripheral base pointers */
#define SYSCON_BASE_PTRS                         { SYSCON }

/*!
 * @}
 */ /* end of group SYSCON_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TSENS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSENS_Peripheral_Access_Layer TSENS Peripheral Access Layer
 * @{
 */

/** TSENS - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control register, offset: 0x0 */
  __I  uint32_t DR;                                /**< Data register. Contains result of conversion, offset: 0x4 */
  __I  uint32_t SR;                                /**< Status register, offset: 0x8 */
  __IO uint32_t SP0;                               /**< Setup register 0: set ADC and operation modes, offset: 0xC */
  __IO uint32_t SP1;                               /**< Setup register 1: Calibration value 'A', offset: 0x10 */
  __IO uint32_t SP2;                               /**< Setup register 2: Calibration value 'B', offset: 0x14 */
  __IO uint32_t SP3;                               /**< Setup register 3: Calibration value 'alpha', offset: 0x18 */
  __IO uint32_t TLO;                               /**< Low temperature threshold register, offset: 0x1C */
  __IO uint32_t THI;                               /**< High temperature threshold register, offset: 0x20 */
  __IO uint32_t IMSC;                              /**< Interrupt Mask Set and Clear Register, offset: 0x24 */
  __I  uint32_t RIS;                               /**< Raw Interrupt Status Register, offset: 0x28 */
  __I  uint32_t MIS;                               /**< Masked Interrupt Status Register, offset: 0x2C */
  __O  uint32_t ICR;                               /**< Interrupt Clear Register, offset: 0x30 */
} TSENS_Type;

/* ----------------------------------------------------------------------------
   -- TSENS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSENS_Register_Masks TSENS Register Masks
 * @{
 */

/*! @name CR - Control register */
/*! @{ */
#define TSENS_CR_START_MASK                      (0x1U)
#define TSENS_CR_START_SHIFT                     (0U)
#define TSENS_CR_START(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_CR_START_SHIFT)) & TSENS_CR_START_MASK)
/*! @} */

/*! @name DR - Data register. Contains result of conversion */
/*! @{ */
#define TSENS_DR_DATA_MASK                       (0xFFFFU)
#define TSENS_DR_DATA_SHIFT                      (0U)
#define TSENS_DR_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << TSENS_DR_DATA_SHIFT)) & TSENS_DR_DATA_MASK)
/*! @} */

/*! @name SR - Status register */
/*! @{ */
#define TSENS_SR_TRANLOC_MASK                    (0x1U)
#define TSENS_SR_TRANLOC_SHIFT                   (0U)
#define TSENS_SR_TRANLOC(x)                      (((uint32_t)(((uint32_t)(x)) << TSENS_SR_TRANLOC_SHIFT)) & TSENS_SR_TRANLOC_MASK)
#define TSENS_SR_TRANHIC_MASK                    (0x2U)
#define TSENS_SR_TRANHIC_SHIFT                   (1U)
#define TSENS_SR_TRANHIC(x)                      (((uint32_t)(((uint32_t)(x)) << TSENS_SR_TRANHIC_SHIFT)) & TSENS_SR_TRANHIC_MASK)
#define TSENS_SR_TRANLOF_MASK                    (0x4U)
#define TSENS_SR_TRANLOF_SHIFT                   (2U)
#define TSENS_SR_TRANLOF(x)                      (((uint32_t)(((uint32_t)(x)) << TSENS_SR_TRANLOF_SHIFT)) & TSENS_SR_TRANLOF_MASK)
#define TSENS_SR_TRANHIF_MASK                    (0x8U)
#define TSENS_SR_TRANHIF_SHIFT                   (3U)
#define TSENS_SR_TRANHIF(x)                      (((uint32_t)(((uint32_t)(x)) << TSENS_SR_TRANHIF_SHIFT)) & TSENS_SR_TRANHIF_MASK)
#define TSENS_SR_TSUCC_MASK                      (0x10U)
#define TSENS_SR_TSUCC_SHIFT                     (4U)
#define TSENS_SR_TSUCC(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_SR_TSUCC_SHIFT)) & TSENS_SR_TSUCC_MASK)
#define TSENS_SR_TRESMODE_MASK                   (0xE0U)
#define TSENS_SR_TRESMODE_SHIFT                  (5U)
#define TSENS_SR_TRESMODE(x)                     (((uint32_t)(((uint32_t)(x)) << TSENS_SR_TRESMODE_SHIFT)) & TSENS_SR_TRESMODE_MASK)
#define TSENS_SR_TOUTMODE_MASK                   (0x100U)
#define TSENS_SR_TOUTMODE_SHIFT                  (8U)
#define TSENS_SR_TOUTMODE(x)                     (((uint32_t)(((uint32_t)(x)) << TSENS_SR_TOUTMODE_SHIFT)) & TSENS_SR_TOUTMODE_MASK)
/*! @} */

/*! @name SP0 - Setup register 0: set ADC and operation modes */
/*! @{ */
#define TSENS_SP0_TOUTMODE_MASK                  (0x1U)
#define TSENS_SP0_TOUTMODE_SHIFT                 (0U)
#define TSENS_SP0_TOUTMODE(x)                    (((uint32_t)(((uint32_t)(x)) << TSENS_SP0_TOUTMODE_SHIFT)) & TSENS_SP0_TOUTMODE_MASK)
#define TSENS_SP0_TRESMODE_MASK                  (0xEU)
#define TSENS_SP0_TRESMODE_SHIFT                 (1U)
#define TSENS_SP0_TRESMODE(x)                    (((uint32_t)(((uint32_t)(x)) << TSENS_SP0_TRESMODE_SHIFT)) & TSENS_SP0_TRESMODE_MASK)
#define TSENS_SP0_TVCALEN_MASK                   (0x40U)
#define TSENS_SP0_TVCALEN_SHIFT                  (6U)
#define TSENS_SP0_TVCALEN(x)                     (((uint32_t)(((uint32_t)(x)) << TSENS_SP0_TVCALEN_SHIFT)) & TSENS_SP0_TVCALEN_MASK)
/*! @} */

/*! @name SP1 - Setup register 1: Calibration value 'A' */
/*! @{ */
#define TSENS_SP1_A_MASK                         (0xFFFFU)
#define TSENS_SP1_A_SHIFT                        (0U)
#define TSENS_SP1_A(x)                           (((uint32_t)(((uint32_t)(x)) << TSENS_SP1_A_SHIFT)) & TSENS_SP1_A_MASK)
/*! @} */

/*! @name SP2 - Setup register 2: Calibration value 'B' */
/*! @{ */
#define TSENS_SP2_B_MASK                         (0xFFFFU)
#define TSENS_SP2_B_SHIFT                        (0U)
#define TSENS_SP2_B(x)                           (((uint32_t)(((uint32_t)(x)) << TSENS_SP2_B_SHIFT)) & TSENS_SP2_B_MASK)
/*! @} */

/*! @name SP3 - Setup register 3: Calibration value 'alpha' */
/*! @{ */
#define TSENS_SP3_ALPHA_MASK                     (0xFFFFU)
#define TSENS_SP3_ALPHA_SHIFT                    (0U)
#define TSENS_SP3_ALPHA(x)                       (((uint32_t)(((uint32_t)(x)) << TSENS_SP3_ALPHA_SHIFT)) & TSENS_SP3_ALPHA_MASK)
/*! @} */

/*! @name TLO - Low temperature threshold register */
/*! @{ */
#define TSENS_TLO_TLO_MASK                       (0xFFFFU)
#define TSENS_TLO_TLO_SHIFT                      (0U)
#define TSENS_TLO_TLO(x)                         (((uint32_t)(((uint32_t)(x)) << TSENS_TLO_TLO_SHIFT)) & TSENS_TLO_TLO_MASK)
/*! @} */

/*! @name THI - High temperature threshold register */
/*! @{ */
#define TSENS_THI_THI_MASK                       (0xFFFFU)
#define TSENS_THI_THI_SHIFT                      (0U)
#define TSENS_THI_THI(x)                         (((uint32_t)(((uint32_t)(x)) << TSENS_THI_THI_SHIFT)) & TSENS_THI_THI_MASK)
/*! @} */

/*! @name IMSC - Interrupt Mask Set and Clear Register */
/*! @{ */
#define TSENS_IMSC_RDYI_MASK                     (0x1U)
#define TSENS_IMSC_RDYI_SHIFT                    (0U)
#define TSENS_IMSC_RDYI(x)                       (((uint32_t)(((uint32_t)(x)) << TSENS_IMSC_RDYI_SHIFT)) & TSENS_IMSC_RDYI_MASK)
#define TSENS_IMSC_TLOE_MASK                     (0x2U)
#define TSENS_IMSC_TLOE_SHIFT                    (1U)
#define TSENS_IMSC_TLOE(x)                       (((uint32_t)(((uint32_t)(x)) << TSENS_IMSC_TLOE_SHIFT)) & TSENS_IMSC_TLOE_MASK)
#define TSENS_IMSC_THIE_MASK                     (0x4U)
#define TSENS_IMSC_THIE_SHIFT                    (2U)
#define TSENS_IMSC_THIE(x)                       (((uint32_t)(((uint32_t)(x)) << TSENS_IMSC_THIE_SHIFT)) & TSENS_IMSC_THIE_MASK)
/*! @} */

/*! @name RIS - Raw Interrupt Status Register */
/*! @{ */
#define TSENS_RIS_RDYI_MASK                      (0x1U)
#define TSENS_RIS_RDYI_SHIFT                     (0U)
#define TSENS_RIS_RDYI(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_RIS_RDYI_SHIFT)) & TSENS_RIS_RDYI_MASK)
#define TSENS_RIS_TLOI_MASK                      (0x2U)
#define TSENS_RIS_TLOI_SHIFT                     (1U)
#define TSENS_RIS_TLOI(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_RIS_TLOI_SHIFT)) & TSENS_RIS_TLOI_MASK)
#define TSENS_RIS_THII_MASK                      (0x4U)
#define TSENS_RIS_THII_SHIFT                     (2U)
#define TSENS_RIS_THII(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_RIS_THII_SHIFT)) & TSENS_RIS_THII_MASK)
/*! @} */

/*! @name MIS - Masked Interrupt Status Register */
/*! @{ */
#define TSENS_MIS_RDYI_MASK                      (0x1U)
#define TSENS_MIS_RDYI_SHIFT                     (0U)
#define TSENS_MIS_RDYI(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_MIS_RDYI_SHIFT)) & TSENS_MIS_RDYI_MASK)
#define TSENS_MIS_TLOI_MASK                      (0x2U)
#define TSENS_MIS_TLOI_SHIFT                     (1U)
#define TSENS_MIS_TLOI(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_MIS_TLOI_SHIFT)) & TSENS_MIS_TLOI_MASK)
#define TSENS_MIS_THII_MASK                      (0x4U)
#define TSENS_MIS_THII_SHIFT                     (2U)
#define TSENS_MIS_THII(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_MIS_THII_SHIFT)) & TSENS_MIS_THII_MASK)
/*! @} */

/*! @name ICR - Interrupt Clear Register */
/*! @{ */
#define TSENS_ICR_RDYC_MASK                      (0x1U)
#define TSENS_ICR_RDYC_SHIFT                     (0U)
#define TSENS_ICR_RDYC(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_ICR_RDYC_SHIFT)) & TSENS_ICR_RDYC_MASK)
#define TSENS_ICR_TLOC_MASK                      (0x2U)
#define TSENS_ICR_TLOC_SHIFT                     (1U)
#define TSENS_ICR_TLOC(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_ICR_TLOC_SHIFT)) & TSENS_ICR_TLOC_MASK)
#define TSENS_ICR_THIC_MASK                      (0x4U)
#define TSENS_ICR_THIC_SHIFT                     (2U)
#define TSENS_ICR_THIC(x)                        (((uint32_t)(((uint32_t)(x)) << TSENS_ICR_THIC_SHIFT)) & TSENS_ICR_THIC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TSENS_Register_Masks */


/* TSENS - Peripheral instance base addresses */
/** Peripheral TSENS base address */
#define TSENS_BASE                               (0x40060000u)
/** Peripheral TSENS base pointer */
#define TSENS                                    ((TSENS_Type *)TSENS_BASE)
/** Array initializer of TSENS peripheral base addresses */
#define TSENS_BASE_ADDRS                         { TSENS_BASE }
/** Array initializer of TSENS peripheral base pointers */
#define TSENS_BASE_PTRS                          { TSENS }

/*!
 * @}
 */ /* end of group TSENS_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WDT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDT_Peripheral_Access_Layer WDT Peripheral Access Layer
 * @{
 */

/** WDT - Register Layout Typedef */
typedef struct {
  __IO uint32_t WDMOD;                             /**< Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer., offset: 0x0 */
  __IO uint32_t WDTC;                              /**< Watchdog timer constant register. This register determines the time-out value., offset: 0x4 */
  __O  uint32_t WDFEED;                            /**< Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC., offset: 0x8 */
  __I  uint32_t WDTV;                              /**< Watchdog timer value register. This register reads out the current value of the Watchdog timer., offset: 0xC */
} WDT_Type;

/* ----------------------------------------------------------------------------
   -- WDT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDT_Register_Masks WDT Register Masks
 * @{
 */

/*! @name WDMOD - Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer. */
/*! @{ */
#define WDT_WDMOD_EN_MASK                        (0x1U)
#define WDT_WDMOD_EN_SHIFT                       (0U)
#define WDT_WDMOD_EN(x)                          (((uint32_t)(((uint32_t)(x)) << WDT_WDMOD_EN_SHIFT)) & WDT_WDMOD_EN_MASK)
#define WDT_WDMOD_RESET_MASK                     (0x2U)
#define WDT_WDMOD_RESET_SHIFT                    (1U)
#define WDT_WDMOD_RESET(x)                       (((uint32_t)(((uint32_t)(x)) << WDT_WDMOD_RESET_SHIFT)) & WDT_WDMOD_RESET_MASK)
#define WDT_WDMOD_TOF_MASK                       (0x4U)
#define WDT_WDMOD_TOF_SHIFT                      (2U)
#define WDT_WDMOD_TOF(x)                         (((uint32_t)(((uint32_t)(x)) << WDT_WDMOD_TOF_SHIFT)) & WDT_WDMOD_TOF_MASK)
#define WDT_WDMOD_INT_MASK                       (0x8U)
#define WDT_WDMOD_INT_SHIFT                      (3U)
#define WDT_WDMOD_INT(x)                         (((uint32_t)(((uint32_t)(x)) << WDT_WDMOD_INT_SHIFT)) & WDT_WDMOD_INT_MASK)
/*! @} */

/*! @name WDTC - Watchdog timer constant register. This register determines the time-out value. */
/*! @{ */
#define WDT_WDTC_Count_MASK                      (0xFFFFFFU)
#define WDT_WDTC_Count_SHIFT                     (0U)
#define WDT_WDTC_Count(x)                        (((uint32_t)(((uint32_t)(x)) << WDT_WDTC_Count_SHIFT)) & WDT_WDTC_Count_MASK)
/*! @} */

/*! @name WDFEED - Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC. */
/*! @{ */
#define WDT_WDFEED_Feed_MASK                     (0xFFU)
#define WDT_WDFEED_Feed_SHIFT                    (0U)
#define WDT_WDFEED_Feed(x)                       (((uint32_t)(((uint32_t)(x)) << WDT_WDFEED_Feed_SHIFT)) & WDT_WDFEED_Feed_MASK)
/*! @} */

/*! @name WDTV - Watchdog timer value register. This register reads out the current value of the Watchdog timer. */
/*! @{ */
#define WDT_WDTV_Count_MASK                      (0xFFFFFFU)
#define WDT_WDTV_Count_SHIFT                     (0U)
#define WDT_WDTV_Count(x)                        (((uint32_t)(((uint32_t)(x)) << WDT_WDTV_Count_SHIFT)) & WDT_WDTV_Count_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WDT_Register_Masks */


/* WDT - Peripheral instance base addresses */
/** Peripheral WDT base address */
#define WDT_BASE                                 (0x40004000u)
/** Peripheral WDT base pointer */
#define WDT                                      ((WDT_Type *)WDT_BASE)
/** Array initializer of WDT peripheral base addresses */
#define WDT_BASE_ADDRS                           { WDT_BASE }
/** Array initializer of WDT peripheral base pointers */
#define WDT_BASE_PTRS                            { WDT }

/*!
 * @}
 */ /* end of group WDT_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang system_header
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma system_include
#endif

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* _LPC8N04_H_ */

