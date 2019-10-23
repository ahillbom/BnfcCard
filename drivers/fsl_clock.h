/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 2.0.2. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*@}*/


extern volatile uint32_t g_Sfro_Osc_Freq;
extern volatile uint32_t g_Tfro_Osc_Freq;
extern volatile uint32_t g_Nfc_Clk_Freq;


	
/*! @brief Clock ip name array for SRAM. */
#define SRAM_CLOCKS \
    {               \
        kCLOCK_Ram \
    }
/*! @brief Clock ip name array for FLASH. */
#define FLASH_CLOCKS \
    {               \
        kCLOCK_Flashreg_Flasharray \
    }	
/*! @brief Clock ip name array for IOCON. */
#define IOCON_CLOCKS \
    {                \
        kCLOCK_Iocon \
    }
/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS  \
    {                \
        kCLOCK_Gpio \
    }
/*! @brief Clock ip name array for WDT. */
#define WDT_CLOCKS \
    {               \
        kCLOCK_Wdt \
    }
/*! @brief Clock ip name array for I2C. */
#define I2C_CLOCKS               \
    {                            \
        kCLOCK_I2c			 \
    }
/*! @brief Clock ip name array for SPISSP. */
#define SPISSP_CLOCKS  \
    {               \
        kCLOCK_Spissp \
    }
/*! @brief Clock ip name array for CTIMER. */
#define CTIMER_CLOCKS  \
    {                  \
        kCLOCK_Ct16b,kCLOCK_Ct32b\
    }
/*! @brief Clock ip name array for TSEN. */
#define TSEN_CLOCKS \
    {              \
        kCLOCK_Tsen \
    }
/*! @brief Clock ip name array for EEPROM. */
#define EEPROM_CLOCKS \
    {              \
        kCLOCK_Eepeg_Eearray \
    }


/*! @brief Internal used Clock definition only. */

#define CLK_GATE_DEFINE(reg, value)               ((((reg) & 0xFFU) << 24U) | ((value) & 0xFFFFFFU))
#define CLK_GATE_GET_REG(x)                     (((x) >> 24U) & 0xFFU)
#define CLK_GATE_GET_VALUE_SHIFT(x)              ((uint32_t)(x) & 0xFFFFFFU)

/* clock mux register definition */
#define CLK_MUX_DEFINE(reg, mux)    (((((uint32_t)(&((SYSCON_Type *)0U)->reg)) & 0xFFU) << 8U) | ((mux) & 0xFFU))
#define CLK_MUX_GET_REG(x) ((volatile uint32_t *)(((uint32_t)(SYSCON)) + (((x) >> 8U) & 0xFFU)))
#define CLK_MUX_GET_MUX(x) ((x) & 0xFFU)

#define CLK_DIV_DEFINE(reg) (((uint32_t)(&((SYSCON_Type *)0U)->reg)) & 0xFFFU)
#define CLK_DIV_GET_REG(x) *((volatile uint32_t *)(((uint32_t)(SYSCON)) + ((uint32_t)(x) & 0xFFFU)))

/* Fractional clock register map */

/* register offset */
#define SYS_AHB_CLK_CTRL   (0U)

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
typedef enum _clock_ip_name
{

	kCLOCK_Ram      			= CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_RAM_MASK),	
    kCLOCK_Flashreg_Flasharray  = CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK),	
    kCLOCK_I2c         			= CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_I2C_MASK),
    kCLOCK_Gpio       		    = CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_GPIO_MASK),
    kCLOCK_Spissp         		= CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_SPISSP_MASK),
    kCLOCK_Ct16b         	    = CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_CT16B_MASK),
    kCLOCK_Ct32b        		= CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_CT32B_MASK),
    kCLOCK_Rtc          		= CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_RTC_MASK),
    kCLOCK_Wdt         			= CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_WDT_MASK),
    kCLOCK_Tsen         		= CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_TSENS_MASK),
    kCLOCK_Iocon        		= CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_IOCON_MASK),
    kCLOCK_Eepeg_Eearray        = CLK_GATE_DEFINE(SYS_AHB_CLK_CTRL, SYSCON_SYSAHBCLKCTRL_EEARRAY_MASK)
	
} clock_ip_name_t;

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    kCLOCK_SysClk, 		/*!< Cpu/AHB/AHB matrix/Memories,etc */
    // kCLOCK_MainClk,    /*!< Main clock */

	kCLOCK_Sfro,        /*!< System FRO*/
	kCLOCK_Tfro        /*!< Timer FRO */
} clock_name_t;

/*! @brief Clock Mux Switches
*CLK_MUX_DEFINE(reg, mux)
*reg is used to define the mux register
*mux is used to define the mux value
*
*/
typedef enum _clock_select
{
	
	kWDT_Clk_From_Sfro = CLK_MUX_DEFINE(WDTCLKSEL, 0U),
	kWDT_Clk_From_Disable = CLK_MUX_DEFINE(WDTCLKSEL, 2U),
	
    kCLKOUT_From_Sfro = CLK_MUX_DEFINE(CLKOUTEN, 0U),
    kCLKOUT_From_SysClk = CLK_MUX_DEFINE(CLKOUTEN, 2U),
    kCLKOUT_From_Tfro = CLK_MUX_DEFINE(CLKOUTEN, 4U),
	kCLKOUT_From_NfcClk = CLK_MUX_DEFINE(CLKOUTEN, 6U)
	
} clock_select_t;

/*! @brief Clock divider
*/
typedef enum _clock_divider
{

    kCLOCK_DivSspClk = CLK_DIV_DEFINE(SSPCLKDIV),
    kCLOCK_DivWdtClk = CLK_DIV_DEFINE(WDTCLKDIV)
} clock_divider_t;


/*! @brief System clock frequency
*/
typedef enum _clock_SysClkfrequency
{
	kCLOCK_SysClkFreq8MHZ = 0U,
	kCLOCK_SysClkFreq4MHZ = 1U,
	kCLOCK_SysClkFreq2MHZ = 2U,
	kCLOCK_SysClkFreq1MHZ = 3U,
	kCLOCK_SysClkFreq500KHZ = 4U,
	kCLOCK_SysClkFreq250KHZ = 5U,
	kCLOCK_SysClkFreq125KHZ = 6U,
	kCLOCK_SysClkFreq62500HZ = 7U
}clock_SysClkfrequency_t;




/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Clock gate, mux, and divider.
 * @{
 */

 
/*
 *! @brief  CLOCKOUT enable or diable.
 *	@param  value   1=enable 0=disable 
 */
static inline void CLOCKOUT_Enable(bool value)
{
	(SYSCON->CLKOUTEN) |= (uint32_t)((value) ? (1) : (0));
}
 
/*
 *! @brief enable ip clock.
 *
 * @param clk clock ip definition.
 */
static inline void CLOCK_EnableClock(clock_ip_name_t clk)
{
		*(volatile uint32_t *)(((uint32_t)(&SYSCON->SYSAHBCLKCTRL)) + CLK_GATE_GET_REG(clk)) |= CLK_GATE_GET_VALUE_SHIFT(clk);
}

/*
 *!@brief disable ip clock.
 *
 * @param clk clock ip definition.
 */
static inline void CLOCK_DisableClock(clock_ip_name_t clk)
{
		*(volatile uint32_t *)(((uint32_t)(&SYSCON->SYSAHBCLKCTRL)) + CLK_GATE_GET_REG(clk)) &= ~CLK_GATE_GET_VALUE_SHIFT(clk);
}

/*
 * @brief Update watchdog clock source or divider.
 */
static inline void CLOCK_UpdateWdtClk(void)
{
    SYSCON->WDTCLKUEN = 0;
    SYSCON->WDTCLKUEN = 1;
    SYSCON->WDTCLKUEN = 0;    
}

/*
 *! @brief	Configure the clock selection muxes.
 * @param	mux	: Clock to be configured.
 * @return	Nothing
 */
static inline void CLOCK_Select(clock_select_t sel)
{
    *(CLK_MUX_GET_REG(sel)) = CLK_MUX_GET_MUX(sel);
}

/*
 *! @brief	Setup peripheral clock dividers.
 * @param	name	: Clock divider name
 * @param   value: Value to be divided
 * @return	Nothing
 */
static inline void CLOCK_SetClkDivider(clock_divider_t name, uint32_t value)
{
    CLK_DIV_GET_REG(name) = value & 0xFFU;
    if(name == kCLOCK_DivWdtClk){
      CLOCK_UpdateWdtClk();   
    }
}

/*
 *! @brief  Get peripheral clock dividers.
 * @param   name    : Clock divider name
 * @return  clock divider value
 */
static inline uint32_t CLOCK_GetClkDivider(clock_divider_t name)
{
    return CLK_DIV_GET_REG(name) & 0xFFU;
}

/*
 *! @brief   Setup System clock dividers.
 * @param   name: system clock frequency name
 * @return  Nothing
 */
static inline void CLOCK_SetSysClkDiv(clock_SysClkfrequency_t name)
{
    SYSCON->SYSCLKUEN = 0;
    SYSCON->SYSCLKCTRL = ((SYSCON->SYSCLKCTRL) & (~(0x7u << 1))) | SYSCON_SYSCLKCTRL_SYSCLKDIV(name);
    SYSCON->SYSCLKUEN = 0;
    SYSCON->SYSCLKUEN = 1;
}


/* @} */

/*!
 * @name Get frequency
 * @{
 */




/*! @brief  Return Frequency of system clock.
 *  @return Frequency of system clock.
 */
static inline uint32_t CLOCK_GetSysClkFreq(void)
{
	return g_Sfro_Osc_Freq / (1U << (((SYSCON->SYSCLKCTRL) >> 1U) & 0x7U));
}

/*! @brief  Return Frequency of ClockOut
 *  @return Frequency of ClockOut
 */
uint32_t CLOCK_GetClockOutClkFreq(void);

/*! @brief	Return Frequency of selected clock
 *  @return	Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);



/*! @brief   enable wdt clock Update
* @param  sel: 1=update 0=no update
* @return  Nothing
*/
void CLOCK_WdtClkSelect(bool sel);

// /* @} */


/*
 *! @brief  Get SFRO trim value.
 * @return  SFRO trim value
 */
static inline uint32_t CLOCK_GetSysclktrim(void)
{
	return (((SYSCON->SYSAHBCLKCTRL) >> 16U) & 0x3fU);
}

/*
 *! @brief  Get TFRO trim value.
 * @return  TFRO trim value
 */
static inline uint32_t CLOCK_GetTmrclktrim(void)
{
	return (((PMU->TMRCLKCTRL) >> 16U) & 0x3fU);
}
/* @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
