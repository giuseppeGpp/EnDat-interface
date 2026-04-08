/****************************************************************************
*
* Copyright (c) 2022 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0098 at www.st.com.
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PLEASE NOTE THAT THIS FILE IS GENERATED FROM A CONFIGURATION FILE,
* USING com.st.stellar.pinmap.gpiocfg, Version 2.1.0.202501060949
* MODIFYING IT IMPLIES POTENTIAL LOSS OF YOUR MODIFICATIONS.
*
*****************************************************************************/
/**
 * @file    steval_ttm007a.h
 * @brief   SR5E1-STEVAL_TTM007A board header file.
 *
 * @addtogroup PLATFORM
 * @addtogroup BOARD
 * @ingroup PLATFORM
 * @addtogroup STEVAL_TTM007A
 * @ingroup BOARD
 * @{
 */

#ifndef _STEVAL_TTM007A_H_
#define _STEVAL_TTM007A_H_

#include <gpio.h>
#include <platform.h>
#include <typedefs.h>


/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

#define STEVAL_TTM007A	1

/*--------------------- GPIO pins definitions ---------------------*/
#define PIN_GPIO4_3 gpio_iopack(GPIO_PORT_E, GPIO_PIN_3) /* PE[3] */
#define PIN_GPIO4_3_CFG                             \
	(GPIO_MODE_MODER_OUTPUT |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_MEDIUM |                     \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define PIN_GPIO4_2 gpio_iopack(GPIO_PORT_E, GPIO_PIN_2) /* PE[2] */
#define PIN_GPIO4_2_CFG                             \
	(GPIO_MODE_MODER_OUTPUT |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_MEDIUM |                     \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define PIN_GPIO4_1 gpio_iopack(GPIO_PORT_E, GPIO_PIN_1) /* PE[1] */
#define PIN_GPIO4_1_CFG                             \
	(GPIO_MODE_MODER_OUTPUT |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_MEDIUM |                     \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define PIN_GPIO4_4 gpio_iopack(GPIO_PORT_E, GPIO_PIN_4) /* PE[4] */
#define PIN_GPIO4_4_CFG                             \
	(GPIO_MODE_MODER_INPUT |                        \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_MEDIUM |                     \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- CAN1 pins definitions ---------------------*/
#define CAN1_RX gpio_iopack(GPIO_PORT_A, GPIO_PIN_4) /* PA[4] */
#define CAN1_RX_CFG                                 \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(6U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define CAN1_TX gpio_iopack(GPIO_PORT_A, GPIO_PIN_5) /* PA[5] */
#define CAN1_TX_CFG                                 \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(6U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- CAN2 pins definitions ---------------------*/
#define CAN2_RX gpio_iopack(GPIO_PORT_D, GPIO_PIN_8) /* PD[8] */
#define CAN2_RX_CFG                                 \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(6U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define CAN2_TX gpio_iopack(GPIO_PORT_D, GPIO_PIN_7) /* PD[7] */
#define CAN2_TX_CFG                                 \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(6U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SDADC1 pins definitions ---------------------*/
#define SDADC1_IN0 gpio_iopack(GPIO_PORT_A, GPIO_PIN_13) /* PA[13] */
#define SDADC1_IN0_CFG                              \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(9U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- BDAC pins definitions ---------------------*/
#define B_DAC1_OUT gpio_iopack(GPIO_PORT_B, GPIO_PIN_1) /* PB[1] */
#define B_DAC1_OUT_CFG                              \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SAR1 pins definitions ---------------------*/
#define SAR1_IN1 gpio_iopack(GPIO_PORT_B, GPIO_PIN_2) /* PB[2] */
#define SAR1_IN1_CFG                                \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SAR2 pins definitions ---------------------*/
#define SAR2_IN1 gpio_iopack(GPIO_PORT_B, GPIO_PIN_7) /* PB[7] */
#define SAR2_IN1_CFG                                \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SAR3 pins definitions ---------------------*/
#define SAR3_IN2 gpio_iopack(GPIO_PORT_B, GPIO_PIN_13) /* PB[13] */
#define SAR3_IN2_CFG                                \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SAR pins definitions ---------------------*/
#define SAR_CAL1 gpio_iopack(GPIO_PORT_C, GPIO_PIN_1) /* PC[1] */
#define SAR_CAL1_CFG                                \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SAR4 pins definitions ---------------------*/
#define SAR4_IN3 gpio_iopack(GPIO_PORT_C, GPIO_PIN_6) /* PC[6] */
#define SAR4_IN3_CFG                                \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- BDAC pins definitions ---------------------*/
#define B_DAC2_OUT gpio_iopack(GPIO_PORT_C, GPIO_PIN_5) /* PC[5] */
#define B_DAC2_OUT_CFG                              \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SAR5 pins definitions ---------------------*/
#define SAR5_IN1 gpio_iopack(GPIO_PORT_C, GPIO_PIN_9) /* PC[9] */
#define SAR5_IN1_CFG                                \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define SAR5_IN2 gpio_iopack(GPIO_PORT_C, GPIO_PIN_10) /* PC[10] */
#define SAR5_IN2_CFG                                \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define SAR5_IN3 gpio_iopack(GPIO_PORT_C, GPIO_PIN_11) /* PC[11] */
#define SAR5_IN3_CFG                                \
	(GPIO_MODE_MODER_ANALOG |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(0U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- TIM1 pins definitions ---------------------*/
#define TIM1_CH1N gpio_iopack(GPIO_PORT_C, GPIO_PIN_14) /* PC[14] */
#define TIM1_CH1N_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH1 gpio_iopack(GPIO_PORT_C, GPIO_PIN_15) /* PC[15] */
#define TIM1_CH1_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH2N gpio_iopack(GPIO_PORT_D, GPIO_PIN_0) /* PD[0] */
#define TIM1_CH2N_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH2 gpio_iopack(GPIO_PORT_D, GPIO_PIN_1) /* PD[1] */
#define TIM1_CH2_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM1_BKIN gpio_iopack(GPIO_PORT_H, GPIO_PIN_0) /* PH[0] */
#define TIM1_BKIN_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM1_BKIN2 gpio_iopack(GPIO_PORT_H, GPIO_PIN_1) /* PH[1] */
#define TIM1_BKIN2_CFG                              \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH3N gpio_iopack(GPIO_PORT_D, GPIO_PIN_3) /* PD[3] */
#define TIM1_CH3N_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH3 gpio_iopack(GPIO_PORT_D, GPIO_PIN_4) /* PD[4] */
#define TIM1_CH3_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- TIM8 pins definitions ---------------------*/
#define TIM8_CH1N gpio_iopack(GPIO_PORT_I, GPIO_PIN_1) /* PI[1] */
#define TIM8_CH1N_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH1 gpio_iopack(GPIO_PORT_I, GPIO_PIN_0) /* PI[0] */
#define TIM8_CH1_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH2N gpio_iopack(GPIO_PORT_I, GPIO_PIN_3) /* PI[3] */
#define TIM8_CH2N_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH2 gpio_iopack(GPIO_PORT_I, GPIO_PIN_2) /* PI[2] */
#define TIM8_CH2_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM8_BKIN gpio_iopack(GPIO_PORT_I, GPIO_PIN_8) /* PI[8] */
#define TIM8_BKIN_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM8_BKIN2 gpio_iopack(GPIO_PORT_I, GPIO_PIN_9) /* PI[9] */
#define TIM8_BKIN2_CFG                              \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH3N gpio_iopack(GPIO_PORT_I, GPIO_PIN_5) /* PI[5] */
#define TIM8_CH3N_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH3 gpio_iopack(GPIO_PORT_I, GPIO_PIN_4) /* PI[4] */
#define TIM8_CH3_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(4U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SPI1 pins definitions ---------------------*/
#define SPI1_MOSI gpio_iopack(GPIO_PORT_E, GPIO_PIN_5) /* PE[5] */
#define SPI1_MOSI_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(5U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define SPI1_MISO gpio_iopack(GPIO_PORT_E, GPIO_PIN_6) /* PE[6] */
#define SPI1_MISO_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(5U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define SPI1_SCK gpio_iopack(GPIO_PORT_E, GPIO_PIN_7) /* PE[7] */
#define SPI1_SCK_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(5U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- SPI3 pins definitions ---------------------*/
#define SPI3_MOSI gpio_iopack(GPIO_PORT_D, GPIO_PIN_12) /* PD[12] */
#define SPI3_MOSI_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(5U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define SPI3_MISO gpio_iopack(GPIO_PORT_D, GPIO_PIN_11) /* PD[11] */
#define SPI3_MISO_CFG                               \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(5U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define SPI3_SCK gpio_iopack(GPIO_PORT_D, GPIO_PIN_10) /* PD[10] */
#define SPI3_SCK_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(5U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define SPI3_NSS gpio_iopack(GPIO_PORT_D, GPIO_PIN_13) /* PD[13] */
#define SPI3_NSS_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_HIGH |                       \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(5U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- TIM3 pins definitions ---------------------*/
#define TIM3_CH1 gpio_iopack(GPIO_PORT_G, GPIO_PIN_14) /* PG[14] */
#define TIM3_CH1_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(2U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define TIM3_CH2 gpio_iopack(GPIO_PORT_G, GPIO_PIN_15) /* PG[15] */
#define TIM3_CH2_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(2U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- TIM2 pins definitions ---------------------*/
#define TIM2_CH1 gpio_iopack(GPIO_PORT_H, GPIO_PIN_2) /* PH[2] */
#define TIM2_CH1_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(1U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- GPIO pins definitions ---------------------*/
#define USER_LED_1 gpio_iopack(GPIO_PORT_H, GPIO_PIN_12) /* PH[12] */
#define USER_LED_1_CFG                              \
	(GPIO_MODE_MODER_OUTPUT |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(12U) |                           \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define USER_LED_2 gpio_iopack(GPIO_PORT_H, GPIO_PIN_13) /* PH[13] */
#define USER_LED_2_CFG                              \
	(GPIO_MODE_MODER_OUTPUT |                       \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(12U) |                           \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)


/*--------------------- UART3 pins definitions ---------------------*/
#define UART3_RX gpio_iopack(GPIO_PORT_H, GPIO_PIN_14) /* PH[14] */
#define UART3_RX_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(7U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_ENABLED |                 \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)

#define UART3_TX gpio_iopack(GPIO_PORT_H, GPIO_PIN_15) /* PH[15] */
#define UART3_TX_CFG                                \
	(GPIO_MODE_MODER_ALTERNATE |                    \
	 GPIO_MODE_OTYPER_PUSHPULL |                    \
	 GPIO_MODE_OSPEEDR_LOW |                        \
	 GPIO_MODE_PUPDR_FLOATING |                     \
	 GPIO_MODE_AFR(7U) |                            \
	 GPIO_MODE_IHYSTR_CMOS |                        \
	 GPIO_MODE_TRIGENR_IN_DISABLED |                \
	 GPIO_MODE_SAFESELR_DISABLED |                  \
	 GPIO_MODE_SAFEVALR_LOW)



/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/


__STATIC_INLINE void steval_ttm007a_init(void) {
	
	/* GPIO */
	gpio_set_pin_mode(PIN_GPIO4_3, PIN_GPIO4_3_CFG);
	gpio_set_pin_mode(PIN_GPIO4_2, PIN_GPIO4_2_CFG);
	gpio_set_pin_mode(PIN_GPIO4_1, PIN_GPIO4_1_CFG);
	gpio_set_pin_mode(PIN_GPIO4_4, PIN_GPIO4_4_CFG);

	/* CAN1 */
	gpio_set_pin_mode(CAN1_RX, CAN1_RX_CFG);
	gpio_set_pin_mode(CAN1_TX, CAN1_TX_CFG);

	/* CAN2 */
	gpio_set_pin_mode(CAN2_RX, CAN2_RX_CFG);
	gpio_set_pin_mode(CAN2_TX, CAN2_TX_CFG);

	/* SDADC1 */
	gpio_set_pin_mode(SDADC1_IN0, SDADC1_IN0_CFG);

	/* BDAC */
	gpio_set_pin_mode(B_DAC1_OUT, B_DAC1_OUT_CFG);

	/* SAR1 */
	gpio_set_pin_mode(SAR1_IN1, SAR1_IN1_CFG);

	/* SAR2 */
	gpio_set_pin_mode(SAR2_IN1, SAR2_IN1_CFG);

	/* SAR3 */
	gpio_set_pin_mode(SAR3_IN2, SAR3_IN2_CFG);

	/* SAR */
	gpio_set_pin_mode(SAR_CAL1, SAR_CAL1_CFG);

	/* SAR4 */
	gpio_set_pin_mode(SAR4_IN3, SAR4_IN3_CFG);

	/* BDAC */
	gpio_set_pin_mode(B_DAC2_OUT, B_DAC2_OUT_CFG);

	/* SAR5 */
	gpio_set_pin_mode(SAR5_IN1, SAR5_IN1_CFG);
	gpio_set_pin_mode(SAR5_IN2, SAR5_IN2_CFG);
	gpio_set_pin_mode(SAR5_IN3, SAR5_IN3_CFG);

	/* TIM1 */
	gpio_set_pin_mode(TIM1_CH1N, TIM1_CH1N_CFG);
	gpio_set_pin_mode(TIM1_CH1, TIM1_CH1_CFG);
	gpio_set_pin_mode(TIM1_CH2N, TIM1_CH2N_CFG);
	gpio_set_pin_mode(TIM1_CH2, TIM1_CH2_CFG);
	gpio_set_pin_mode(TIM1_BKIN, TIM1_BKIN_CFG);
	gpio_set_pin_mode(TIM1_BKIN2, TIM1_BKIN2_CFG);
	gpio_set_pin_mode(TIM1_CH3N, TIM1_CH3N_CFG);
	gpio_set_pin_mode(TIM1_CH3, TIM1_CH3_CFG);

	/* TIM8 */
	gpio_set_pin_mode(TIM8_CH1N, TIM8_CH1N_CFG);
	gpio_set_pin_mode(TIM8_CH1, TIM8_CH1_CFG);
	gpio_set_pin_mode(TIM8_CH2N, TIM8_CH2N_CFG);
	gpio_set_pin_mode(TIM8_CH2, TIM8_CH2_CFG);
	gpio_set_pin_mode(TIM8_BKIN, TIM8_BKIN_CFG);
	gpio_set_pin_mode(TIM8_BKIN2, TIM8_BKIN2_CFG);
	gpio_set_pin_mode(TIM8_CH3N, TIM8_CH3N_CFG);
	gpio_set_pin_mode(TIM8_CH3, TIM8_CH3_CFG);

	/* SPI1 */
	gpio_set_pin_mode(SPI1_MOSI, SPI1_MOSI_CFG);
	gpio_set_pin_mode(SPI1_MISO, SPI1_MISO_CFG);
	gpio_set_pin_mode(SPI1_SCK, SPI1_SCK_CFG);

	/* SPI3 */
	gpio_set_pin_mode(SPI3_MOSI, SPI3_MOSI_CFG);
	gpio_set_pin_mode(SPI3_MISO, SPI3_MISO_CFG);
	gpio_set_pin_mode(SPI3_SCK, SPI3_SCK_CFG);
	gpio_set_pin_mode(SPI3_NSS, SPI3_NSS_CFG);

	/* TIM3 */
	gpio_set_pin_mode(TIM3_CH1, TIM3_CH1_CFG);
	gpio_set_pin_mode(TIM3_CH2, TIM3_CH2_CFG);

	/* TIM2 */
	gpio_set_pin_mode(TIM2_CH1, TIM2_CH1_CFG);

	/* GPIO */
	gpio_set_pin_mode(USER_LED_1, USER_LED_1_CFG);
	gpio_set_pin_mode(USER_LED_2, USER_LED_2_CFG);

	/* UART3 */
	gpio_set_pin_mode(UART3_RX, UART3_RX_CFG);
	gpio_set_pin_mode(UART3_TX, UART3_TX_CFG);

}

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _STEVAL_TTM007A_H_ */

/** @} */

