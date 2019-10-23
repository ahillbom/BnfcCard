/*
** ###################################################################
**     Version:             rev. 1.0, 2018-06-21
**     Build:               b180817
**
**     Abstract:
**         Chip specific module features.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
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

#ifndef _LPC8N04_FEATURES_H_
#define _LPC8N04_FEATURES_H_

/* SOC module features */

/* @brief CTIMER availability on the SoC. */
#define FSL_FEATURE_SOC_CTIMER_COUNT (2)
/* @brief EEPROM availability on the SoC. */
#define FSL_FEATURE_SOC_EEPROM_COUNT (1)
/* @brief FLASH availability on the SoC. */
#define FSL_FEATURE_SOC_FLASH_COUNT (1)
/* @brief GPIO availability on the SoC. */
#define FSL_FEATURE_SOC_GPIO_COUNT (1)
/* @brief IOCON availability on the SoC. */
#define FSL_FEATURE_SOC_IOCON_COUNT (1)
/* @brief PMU availability on the SoC. */
#define FSL_FEATURE_SOC_PMU_COUNT (1)
/* @brief RTC availability on the SoC. */
#define FSL_FEATURE_SOC_RTC_COUNT (1)
/* @brief SYSCON availability on the SoC. */
#define FSL_FEATURE_SOC_SYSCON_COUNT (1)

/* CTIMER module features */

/* @brief CIMER bit size. */
#define FSL_FEATURE_CTIMER_BIT_SIZEn(x) ((x) == CTIMER0 ? (16) : ((x) == CTIMER1 ? (32) : 0))
/* @brief CIMER has no capture. */
#define FSL_FEATURE_CTIMER_HAS_NO_INPUT_CAPTURE (1)
/* @brief CTIMER has no reset register. */
#define FSL_FEATURE_CTIMER_HAS_NO_RESET (1)

/* EEPROM module features */

/* @brief Base address of the EEPROM */
#define FSL_FEATURE_EEPROM_BASE_ADDRESS (0x30000000)
/* @brief EEPROM internal clock frequency */
#define FSL_FEATURE_EEPROM_INTERNAL_FREQ (375000)
/* @brief The EEPROM is organized in rows, this is the row size (in bytes) */
#define FSL_FEATURE_EEPROM_ROW_SIZE (64)
/* @brief Complete EEPROM area is readable */
#define FSL_FEATURE_EEPROM_NR_OF_R_ROWS (64)
/* @brief Last 4 rows (256 bytes) are read-only, so we only publish 60 rows */
#define FSL_FEATURE_EEPROM_NR_OF_RW_ROWS (60)
/* @brief EEPROM size */
#define FSL_FEATURE_EEPROM_SIZE (4096)
/* @brief Command number for eeprom program */
#define FSL_FEATURE_EEPROM_PROGRAM_CMD (6)
/* @brief Indicate the EEPROM memory aligned by two bytes */
#define FSL_FEATURE_EEPROM_TWOBYTES_ALIGNED (1)
/* @brief Page count of the EEPROM */
#define FSL_FEATURE_EEPROM_ROW_COUNT (64)

/* IOCON module features */

/* @brief Func bit field width */
#define FSL_FEATURE_IOCON_ONE_DIMENSION (0)

/* SPI0 module features */

/* @brief Has SPOL0 bitfile in CFG reigster. */
#define FSL_FEATURE_SPI0_HAS_SSEL0 (0)
/* @brief Has SPOL1 bitfile in CFG reigster. */
#define FSL_FEATURE_SPI0_HAS_SSEL1 (0)
/* @brief Has SPOL2 bitfile in CFG reigster. */
#define FSL_FEATURE_SPI0_HAS_SSEL2 (0)
/* @brief Has SPOL3 bitfile in CFG reigster. */
#define FSL_FEATURE_SPI0_HAS_SSEL3 (0)

/* SYSCON module features */

/* @brief Has PINTSEL register. */
#define FSL_FEATURE_SYSCON_HAS_PINT_SEL_REGISTER (0)
/* @brief Pointer to ROM IAP entry functions. */
#define FSL_FEATURE_SYSCON_IAP_ENTRY_LOCATION (0x1FFF1FF1)
/* @brief Flash page size in bytes. */
#define FSL_FEATURE_SYSCON_FLASH_PAGE_SIZE_BYTES (64)
/* @brief Flash sector size in bytes. */
#define FSL_FEATURE_SYSCON_FLASH_SECTOR_SIZE_BYTES (1024)
/* @brief Flash size in bytes. */
#define FSL_FEATURE_SYSCON_FLASH_SIZE_BYTES (32768)
/* @brief IAP has Flash read & write function. */
#define FSL_FEATURE_IAP_HAS_FLASH_FUNCTION (1)
/* @brief IAP has Read factory settings function. */
#define FSL_FEATURE_IAP_HAS_READ_FACTORY_SETTINGS_FUNCTION (1)
/* @brief Doesn't have STARTER. */
#define FSL_FEATURE_SYSCON_STARTER_DISCONTINUOUS (1)
/* @brief Only has ERP0. */
#define FSL_FEATURE_SYSCON_ERP0_REGISTER (1)

/* WDT module features */

/* No feature definitions */

#endif /* _LPC8N04_FEATURES_H_ */
