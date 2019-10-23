/*
 * Copyright 2018, NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_POWER_H_
#define _FSL_POWER_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief power driver version 2.0.1. */
#define FSL_POWER_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*@}*/

/*! @brief Enable power control */
#define FSL_SDK_ENABLE_DRIVER_POWER_CONTROL (1)

/*! @brief power down configurations mask */
typedef enum pd_bits
{
    kPDRUNCFG_PD_FLASH = SYSCON_PDRUNCFG_FLASH_PD_MASK,   /*!< Flash power down */
    kPDRUNCFG_PD_TSEN = SYSCON_PDRUNCFG_TSENS_PD_MASK,    /*!< Temperature sensor power down */
    kPDRUNCFG_PD_EEPROM = SYSCON_PDRUNCFG_EEPROM_PD_MASK, /*!< Eeprom power down */

    /*
    This enum member has no practical meaning,it is used to avoid MISRA issue,
    user should not trying to use it.
    */
    kPDRUNCFG_ForceUnsigned = (int)0x80000000U,
} pd_bit_t;

/*! @brief pmu general purpose register index */
typedef enum _power_gen_reg
{
    kPmu_GenReg0 = 0U, /*!< general purpose register0 */
    kPmu_GenReg1 = 1U, /*!< general purpose register1 */
    kPmu_GenReg2 = 2U, /*!< general purpose register2 */
    kPmu_GenReg3 = 3U, /*!< general purpose register3 */
    kPmu_GenReg4 = 4U, /*!< general purpose register4 */
} power_gen_reg_t;

/* Power mode configuration API parameter */
typedef enum _power_mode_config
{
    kPmu_Sleep = 0U,
    kPmu_Deep_Sleep = 1U,
    kPmu_Deep_PowerDown = 2U,
    kPmu_MaxPowerMode = 3U,
} power_mode_cfg_t;

/*! @brief Power source selection */
typedef enum _power_src_sel
{
    kPmu_PowerSourceFromVBAT = 1U,   /*!< power source from VBAT, external power */
    kPmu_PowerSourceFromNFC = 2U,    /*!< power source from NFC */
    kPmu_PowerSourceAutoSwitch = 3U, /*!< power source is switch automatically */
} power_src_sel_t;

/*! @brief Power deep power down mode wakeup pin selection */
typedef enum _power_dpd_wakeup_pin
{
    kPmu_Dpd_WakeupPin_PIO0_0 = PMU_PCON_WAKEUP_MASK, /*!< Wake up function assign to PIO0_0 */
} power_dpd_wakeup_pin_t;

/*!< @brief power interrupt status */
enum _power_interrupt_status
{
    kPmu_StatusBOD = 1U << 0U,             /*!< BOD interrupt */
    kPmu_StatusDetectedRFPower = 1U << 1U, /*!< Detected RF power interrupt */
};

/*!< @brief power status */
enum _power_status
{
    kPmu_NFCPowerSwitchEnabled = PMU_PSTAT_PSWNFC_MASK,     /*!< NFC power switch enabled */
    kPmu_BatteryPowerSwitchEnabled = PMU_PSTAT_PSWBAT_MASK, /*!< Battery power switch enabled */
    kPmu_BodDetectVddLowerThan1V8 = PMU_PSTAT_BOD1V8_MASK,  /*!< BOD detected VDD < 1.8V */
    kPmu_RFDetected = PMU_PSTAT_RFPOW_MASK,                 /*!< RF power field detected */
};

/*!< @brief deep power down wakeup source */
enum _power_deep_power_down_wakeup_src
{
    kPmu_DeepPowerDownWakeupSrcReset = 0,     /*!< wakeup source is POR or reset pin */
    kPmu_DeepPowerDownWakeupSrcLDO = 1,       /*!< wakeup source is LDO enabled */
    kPmu_DeepPowerDownWakeupSrcRTC = 2,       /*!< wakeup source is RTC timer event */
    kPmu_DeepPowerDownWakeupSrcWakeupPin = 3, /*!< wakeup source is Wakeup pin */
};
/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
* @name SYSCON Power Configuration
* @{
*/

/*!
 * @brief API to enable PDRUNCFG bit in the Syscon. Note that enabling the bit powers down the peripheral
 *
 * @param en    peripheral for which to enable the PDRUNCFG bit
 * @return none
 */
static inline void POWER_EnablePD(pd_bit_t en)
{
    SYSCON->PDRUNCFG |= en;
}

/*!
 * @brief API to disable PDRUNCFG bit in the Syscon. Note that disabling the bit powers up the peripheral
 *
 * @param en    peripheral for which to disable the PDRUNCFG bit
 * @return none
 */
static inline void POWER_DisablePD(pd_bit_t en)
{
    SYSCON->PDRUNCFG &= ~en;
}

/*!
 * @brief API to enable flash remap feature for deep sleep mode.
 *
 * @param enable, true is enable remap feature, false is disable the feature.
 */
static inline void POWER_EnableFlashRemap(bool enable)
{
    if (enable)
    {
        SYSCON->PDAWAKECFG |= SYSCON_PDAWAKECFG_FLASH_PD_MASK;
    }
    else
    {
        SYSCON->PDAWAKECFG &= ~SYSCON_PDAWAKECFG_FLASH_PD_MASK;
    }
}
/* @} */

/*!
* @name ARM core Power Configuration
* @{
*/

/*!
 * @brief API to enable deep sleep bit in the ARM Core.
 *
 * @param none
 * @return none
 */
static inline void POWER_EnableDeepSleep(void)
{
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
}

/*!
 * @brief API to disable deep sleep bit in the ARM Core.
 *
 * @param none
 * @return none
 */
static inline void POWER_DisableDeepSleep(void)
{
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
}

/* @} */

/*!
* @name PMU functionality
* @{
*/

/*!
 * @brief API to enter sleep power mode.
 *
 * @return none
 */
void POWER_EnterSleep(void);

/*!
 * @brief API to enter deep sleep power mode.
 *
 * @param activePart , should be a single or combine value of _power_deep_sleep_active .
 * @return none
 */
void POWER_EnterDeepSleep(void);

/*!
 * @brief API to enter deep power down mode.
 *
 * @return none
 */
void POWER_EnterDeepPowerDownMode(void);

/*!
 * @brief API to read PMU register.
 *
 * @param regAddr address of PMU register.
 * @return register value.
 */
uint32_t POWER_ReadPmuReg(void *regAddr);

/*!
 * @brief API to write PMU register.
 *
 * @param regAddr address of PMU register.
 * @param regValue value to write.
 * @return none
 */
void POWER_WritePmuReg(void *regAddr, uint32_t regValue);

/*!
 * @brief API to set PMU register bit.
 *
 * @param regAddr address of PMU register.
 * @param mask bit mask.
 * @return none
 */
void POWER_SetPmuRegBit(void *regAddr, uint32_t mask);

/*!
 * @brief API to clr PMU register bit.
 *
 * @param regAddr address of PMU register.
 * @param mask bit mask.
 * @return none
 */
void POWER_ClrPmuRegBit(void *regAddr, uint32_t mask);

/*!
 * @brief API to enable PMU interrupt.
 *
 * @param mask interrupt mask.
 * @param enable true is enable, false is disable.
 * @return none
 */
static inline void POWER_EnablePmuInterrupt(uint32_t mask, bool enable)
{
    if (enable)
    {
        POWER_SetPmuRegBit((void *)&PMU->IMSC, mask);
    }
    else
    {
        POWER_ClrPmuRegBit((void *)&PMU->IMSC, mask);
    }
}

/*!
 * @brief API to retore data to general purpose register which can be retain during deep power down mode.
 * Note the kPMU_GenReg4 can retore 3 byte data only, so the general purpose register can store 19bytes data.
 * @param index, general purpose data register index.
 * @param data, data to restore.
 */
static inline void POWER_SetRetainData(power_gen_reg_t index, uint32_t data)
{
    POWER_WritePmuReg((void *)&PMU->GPREG[index], data);
}

/*!
 * @brief API to get data from general purpose register which retain during deep power down mode.
 * Note the kPMU_GenReg4 can retore 3 byte data only, so the general purpose register can store 19bytes data.
 * @param index, general purpose data register index.
 * @return data stored in the general purpose register.
 */
static inline uint32_t POWER_GetRetainData(power_gen_reg_t index)
{
    return POWER_ReadPmuReg((void *)&PMU->GPREG[index]);
}

/*!
 * @brief API to get sleep mode flag.
 *
 * @return sleep mode flag: 0 is active mode, 1 is sleep mode/deep sleep mode entered.
 */
static inline uint32_t POWER_GetSleepModeFlag(void)
{
    return (POWER_ReadPmuReg((void *)&PMU->PCON) & PMU_PCON_SLEEPFLAG_MASK) >> PMU_PCON_SLEEPFLAG_SHIFT;
}

/*!
 * @brief API to clear sleep mode flag.
 *
 */
static inline void POWER_ClrSleepModeFlag(void)
{
    POWER_SetPmuRegBit((void *)&PMU->PCON, PMU_PCON_SLEEPFLAG_MASK);
}

/*!
 * @brief API to get deep power down mode flag.
 *
 * @return sleep mode flag: 0 not deep power down, 1 is deep power down mode entered.
 */
static inline uint32_t POWER_GetDeepPowerDownModeFlag(void)
{
    return (POWER_ReadPmuReg((void *)&PMU->PCON) & PMU_PCON_DPDFLAG_MASK) >> PMU_PCON_DPDFLAG_SHIFT;
}

/*!
 * @brief API to get deep power down mode exit source.
 *
 * @return wakeup source of deep power down mode, reference _power_deep_power_down_wakeup_src.
 */
static inline uint32_t POWER_GetDeepPowerDownWakeupSrc(void)
{
    return (POWER_ReadPmuReg((void *)&PMU->PSTAT) & PMU_PSTAT_DPDEXIT_MASK) >> PMU_PSTAT_DPDEXIT_SHIFT;
}

/*!
 * @brief API to clear deep power down mode flag.
 *
 */
static inline void POWER_ClrDeepPowerDownModeFlag(void)
{
    POWER_SetPmuRegBit((void *)&PMU->PCON, PMU_PCON_DPDFLAG_MASK);
}

/*!
 * @brief API to enable auto power mode switch.
 *
 * @param enable true is enable, false is disable.
 */
static inline void POWER_EnableAutoPowerSwitch(bool enable)
{
    if (enable)
    {
        POWER_ClrPmuRegBit((void *)&PMU->PCON, PMU_PCON_PMULPM_MASK);
    }
    else
    {
        POWER_SetPmuRegBit((void *)&PMU->PCON, PMU_PCON_PMULPM_MASK);
    }
}

/*!
 * @brief API to enable auto battery switch.
 *
 * @param enable true is enable, false is disable.
 */
static inline void POWER_EnableAutoBatterySwitch(bool enable)
{
    if (enable)
    {
        POWER_ClrPmuRegBit((void *)&PMU->PCON, PMU_PCON_VBAT_MASK);
    }
    else
    {
        POWER_SetPmuRegBit((void *)&PMU->PCON, PMU_PCON_VBAT_MASK);
    }
}

/*!
 * @brief API to enable detection of VDD_ALON is falls below the threshold level(1.8v)
 *
 * @param enable true is enable, false is disable.
 */
static inline void POWER_EnableDetectBrownOut(bool enable)
{
    if (enable)
    {
        POWER_SetPmuRegBit((void *)&PMU->PCON, PMU_PCON_BODEN_MASK);
    }
    else
    {
        POWER_ClrPmuRegBit((void *)&PMU->PCON, PMU_PCON_BODEN_MASK);
    }
}

/*!
 * @brief API to enable detection of VDD_ALON is falls below the threshold level(1.8v)
 *
 * @param pin pin used as wakeup source
 * @param enable true is enable, false is disable.
 */
static inline void POWER_EnableWakeupPinForDeepPowerDown(power_dpd_wakeup_pin_t pin, bool enable)
{
    if (enable)
    {
        POWER_SetPmuRegBit((void *)&PMU->PCON, pin);
    }
    else
    {
        POWER_ClrPmuRegBit((void *)&PMU->PCON, pin);
    }
}

/*!
 * @brief API to get PMU access ready status.
 *
 * @return true is PMU ready for access, false is PMU not ready for access.
 */
static inline bool POWER_GetPmuAccessReadyStat(void)
{
    return (PMU->ACCSTAT & PMU_ACCSTAT_PMU_READY_MASK) ? true : false;
}

/*!
 * @brief API to select power source.
 *
 * @param sel power source.
 */
void POWER_SelectPowerSource(power_src_sel_t sel);

/* @} */

/*!
* @name PMU status
* @{
*/

/*!
 * @brief API to get PMU status,.
 *
 * @return PMU statue, reference _power_status.
 */
static inline uint32_t PMU_GetStatus(void)
{
    return POWER_ReadPmuReg((void *)&PMU->PSTAT);
}

/*!
 * @brief API to get PMU raw interrupt status,.
 *
 * @return status for each interrupt condition that is asserted, regardless of whether the interrupt is enabled.
 */
static inline uint32_t PMU_GetRawIntStatus(void)
{
    return POWER_ReadPmuReg((void *)&PMU->RIS);
}

/*!
 * @brief API to get PMU interrupt status.
 *
 * @return status for each interrupt that is enabled.
 */
static inline uint32_t PMU_GetIntStatus(void)
{
    return POWER_ReadPmuReg((void *)&PMU->MIS);
}

/*!
 * @brief API to clear PMU interrupt status.
 *
 * @param mask interrupt mask value to clear.
 */
static inline void PMU_ClrInterruptStatus(uint32_t mask)
{
    POWER_WritePmuReg((void *)&PMU->ICR, mask);
}

/* @} */

#ifdef __cplusplus
}
#endif

#endif /* _FSL_POWER_H_ */
