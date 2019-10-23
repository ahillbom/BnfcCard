/*
 * Copyright 2017, NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_RESET_H_
#define _FSL_RESET_H_

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "fsl_device_registers.h"

/*!
 * @addtogroup ksdk_common
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief reset driver version 2.0.1. */
#define FSL_RESET_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*@}*/

/*!
 * @brief Enumeration for peripheral reset control bits
 *
 * Defines the enumeration for peripheral reset control bits in PRESETCTRL/ASYNCPRESETCTRL registers
 */
typedef enum _SYSCON_RSTn
{
	kSSP_RST_N_SHIFT_RSTn = 0 | 0U, 	/**< SPI/SSP reset control */
	kI2C_RST_N_SHIFT_RSTn = 0 | 1U,     /**< I2C-bus reset control */
	kEEPROM_RST_SHIFT_RSTn  = 0 | 2U,		/**< EEPROM NVMC reset control */
	kNFC_RST_N_SHIFT_RSTn = 0 | 3U,		/**< NFC shared memory reset control */

} SYSCON_RSTn_t;

/** Array initializers with peripheral reset bits **/
#define SSP_RSTS_N             \
    {                           \
        kSSP_RST_N_SHIFT_RSTn \
    } /* Reset bits for SPI/SSP peripheral */
#define I2C_RSTS_N            \
    {                         \
        kI2C_RST_N_SHIFT_RSTn \
    } /* Reset bits for I2C peripheral */
#define EE_RSTS_N            \
    {                         \
        kEEPROM_RST_SHIFT_RSTn  \
    } /* Reset bits for EEPROM NVMC peripheral */
#define NFC_RSTS_N            \
    {                         \
        kNFC_RST_N_SHIFT_RSTn \
    } /* Reset bits for NFC peripheral */

/*!
 * @brief Reset source
 */
enum _reset_source
{
    kRESET_SrcPowerOn = SYSCON_SYSRSTSTAT_POR_MASK,        /**< Power on reset */
    kRESET_SrcExternalPin = SYSCON_SYSRSTSTAT_EXTRST_MASK, /**< External pin reset */
    kRESET_SrcWatchDog = SYSCON_SYSRSTSTAT_WDT_MASK,       /**< Watch dog reset */
    kRESET_SrcCpuSoftware = SYSCON_SYSRSTSTAT_SYSRST_MASK, /**< CPU software reset */
};


typedef SYSCON_RSTn_t reset_ip_name_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif
/*!
 * @brief Assert reset to peripheral.
 *
 * Asserts reset signal to specified peripheral module.
 *
 * @param peripheral Assert reset to this peripheral. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_SetPeripheralReset(reset_ip_name_t peripheral);
/*!
 * @brief Clear reset to peripheral.
 *
 * Clears reset signal to specified peripheral module, allows it to operate.
 *
 * @param peripheral Clear reset to this peripheral. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_ClearPeripheralReset(reset_ip_name_t peripheral);
/*!
 * @brief Reset peripheral module.
 *
 * Reset peripheral module.
 *
 * @param peripheral Peripheral to reset. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_PeripheralReset(reset_ip_name_t peripheral);

/*!
 * @brief This function is used to get the CPU start up source.
 *
 * @return Reset source, use return source to AND #_reset_source to get the related status.
 */
static inline uint32_t RESET_GetResetSource(void)
{
    return SYSCON->SYSRSTSTAT;
}

/*!
 * @brief Clear the reset source
 */
static inline void RESET_ClearResetSource(void)
{
    SYSCON->SYSRSTSTAT = SYSCON->SYSRSTSTAT;
}

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* _FSL_RESET_H_ */
