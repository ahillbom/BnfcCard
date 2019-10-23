/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_clock.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.clock"
#endif


/** System Free-Running Oscillator(SFRO) rate in Hz */
volatile uint32_t g_Sfro_Osc_Freq = 8000000U;

/** Timer Free-Running Oscillator(Tfro) rate in Hz */
volatile uint32_t g_Tfro_Osc_Freq = 32768U;

/** Timer NFC clock rate in Hz */
volatile uint32_t g_Nfc_Clk_Freq = 1695000U;
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*

*/


/*! brief   enable wdt clock Update
* param  sel: 1=update 0=no update
* return  Nothing
*/
void CLOCK_WdtClkSelect(bool sel)
{
	if(sel)
	{
		CLOCK_Select(kWDT_Clk_From_Sfro);
                CLOCK_UpdateWdtClk();            
	}
	else
	{
		CLOCK_Select(kWDT_Clk_From_Disable);
                CLOCK_UpdateWdtClk();
	}
}


/*! brief  Return Frequency of ClockOut
 *  return Frequency of ClockOut
 */
uint32_t CLOCK_GetClockOutClkFreq(void)
{
    uint32_t freq = 0U;

    switch (((SYSCON->CLKOUTEN) >> 1) & 0xfU)
    {
        case 0U:
            freq = g_Sfro_Osc_Freq;
            break;

        case 1U:
            freq = CLOCK_GetSysClkFreq();
            break;

        case 2U:
            freq = g_Tfro_Osc_Freq;
            break;

        case 3U:
            freq = g_Nfc_Clk_Freq;
            break;

        default:
            break;
    }

    return freq;
}

/*! brief	Return Frequency of selected clock
 *  return	Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName)
{
    uint32_t freq;

    switch (clockName)
    {
        case kCLOCK_SysClk:
            freq = CLOCK_GetSysClkFreq();
            break;
        case kCLOCK_Sfro:
            freq = g_Sfro_Osc_Freq;
            break;
        case kCLOCK_Tfro:
            freq = g_Tfro_Osc_Freq;
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

