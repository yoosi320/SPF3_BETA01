/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#if defined(RMDO)
#define TARGET_BOARD_IDENTIFIER "RMDO"
#elif defined(ZCOREF3)
#define TARGET_BOARD_IDENTIFIER "ZCF3"
#elif defined(FLIP32F3OSD)
#define TARGET_BOARD_IDENTIFIER "FLF3"
#else
#define TARGET_BOARD_IDENTIFIER "SRF3"
#endif

#if defined(ZCOREF3)
#define CONFIG_FASTLOOP_PREFERRED_ACC ACC_DEFAULT

#define LED0                    PB8
#else
#define CONFIG_FASTLOOP_PREFERRED_ACC ACC_NONE

#define LED0                    PB3
#endif

#if defined(ZCOREF3)
#define EXTI15_10_CALLBACK_HANDLER_COUNT 1
#elif defined(FLIP32F3OSD)
#define EXTI_CALLBACK_HANDLER_COUNT 2 // MPU data ready and MAG data ready
#endif

#define BEEPER                  PC15
#define BEEPER_INVERTED

#define USE_EXTI
#define MPU_INT_EXTI            PC13
#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW

#define GYRO

#define ACC

//#define BARO
//#define USE_BARO_BMP280

#if defined(FLIP32F3OSD)
#define USE_GYRO_MPU6500
#define GYRO_MPU6500_ALIGN CW270_DEG

#define USE_ACC_MPU6500
#define ACC_MPU6500_ALIGN CW270_DEG

#elif defined(ZCOREF3)
#define GYRO
#define USE_GYRO_MPU6500
#define USE_GYRO_SPI_MPU6500
#define GYRO_MPU6500_ALIGN      CW180_DEG

#define ACC
#define USE_ACC_MPU6500
#define USE_ACC_SPI_MPU6500
#define ACC_MPU6500_ALIGN       CW180_DEG

#define USE_SPI_DEVICE_1 // PB9,3,4,5 on AF5 SPI1 (MPU)

#define SPI1_NSS_PIN            PB9
#define SPI1_SCK_PIN            PB3
#define SPI1_MISO_PIN           PB4
#define SPI1_MOSI_PIN           PB5

#define MPU6500_CS_PIN          PB9
#define MPU6500_SPI_INSTANCE    SPI1


#else
#define USE_GYRO_MPU6050
#define GYRO_MPU6050_ALIGN      CW270_DEG

#define USE_ACC_MPU6050
#define ACC_MPU6050_ALIGN       CW270_DEG
#endif

#if defined(FLIP32F3OSD)
#define SONAR
#define SONAR_TRIGGER_PIN       PB0
#define SONAR_ECHO_PIN          PB1

#elif defined(RMDO)
#undef USE_GPS

#elif defined(ZCOREF3)
#define USE_MAG_DATA_READY_SIGNAL
#define ENSURE_MAG_DATA_READY_IS_HIGH

#else //SPRACINGF3
#define USE_BARO_MS5611
#define USE_BARO_BMP085

#define MAG
#define USE_MAG_AK8975
#define USE_MAG_HMC5883
#define MAG_HMC5883_ALIGN       CW270_DEG

#define USE_MAG_DATA_READY_SIGNAL
#define ENSURE_MAG_DATA_READY_IS_HIGH
#define MAG_INT_EXTI            PC14
#endif

//#define USE_FLASHFS
//#define USE_FLASH_M25P16

#define USE_UART1
#define USE_UART2
#define USE_UART3

#if defined(ZCOREF3)
#define SERIAL_PORT_COUNT       3

#else
#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2
#define SERIAL_PORT_COUNT       5

#define SOFTSERIAL_1_TIMER      TIM3
#define SOFTSERIAL_1_TIMER_RX_HARDWARE 4 // PWM 5
#define SOFTSERIAL_1_TIMER_TX_HARDWARE 5 // PWM 6
#define SOFTSERIAL_2_TIMER TIM3
#define SOFTSERIAL_2_TIMER_RX_HARDWARE 6 // PWM 7
#define SOFTSERIAL_2_TIMER_TX_HARDWARE 7 // PWM 8
#define SONAR_SOFTSERIAL2_EXCLUSIVE
#endif

#define USE_ESCSERIAL
#define ESCSERIAL_TIMER_TX_HARDWARE 0 // PWM 1

#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define UART2_TX_PIN            PA14 // PA14 / SWCLK
#define UART2_RX_PIN            PA15

#define UART3_TX_PIN            PB10 // PB10 (AF7)
#define UART3_RX_PIN            PB11 // PB11 (AF7)

#define USE_I2C
#define I2C_DEVICE (I2CDEV_1) // PB6/SCL, PB7/SDA

#define USE_SPI
#define USE_SPI_DEVICE_2 // PB12,13,14,15 on AF5

//#define M25P16_CS_PIN           PB12
//#define M25P16_SPI_INSTANCE     SPI2



// NRF24L01 Setting
#define USE_RX_NRF24

#define USE_RX_SPI
#define RX_SPI_INSTANCE         SPI2

// Nordic Semiconductor uses 'CSN', STM uses 'NSS'
#define RX_CE_PIN               PA2//PA6//PB4
#define RX_NSS_PIN              PA3//PA7//PB5
#define RX_SCK_PIN              PB13
#define RX_MISO_PIN             PB14
#define RX_MOSI_PIN             PB15
//#define RX_IRQ_PIN              PA8
#define SPI2_NSS_PIN            RX_NSS_PIN
#define SPI2_SCK_PIN            RX_SCK_PIN
#define SPI2_MISO_PIN           RX_MISO_PIN
#define SPI2_MOSI_PIN           RX_MOSI_PIN


#define USE_RX_SYMA
#define RX_SPI_DEFAULT_PROTOCOL RX_SPI_NRF24_SYMA_X

//#define DEFAULT_RX_FEATURE      FEATURE_RX_SPI
#define DEFAULT_RX_FEATURE      FEATURE_RX_PPM

// NRF24L01 //




#define BOARD_HAS_VOLTAGE_DIVIDER
#define USE_ADC
#define ADC_INSTANCE            ADC2
#define VBAT_ADC_PIN            PA4
#define CURRENT_METER_ADC_PIN   PA5
#define RSSI_ADC_PIN            PB2

#define USE_ESC_SENSOR
#define REMAP_TIM17_DMA

// UART1 TX uses DMA1_Channel4, which is also used by dshot on motor 4
#if defined(USE_UART1_TX_DMA) && defined(USE_DSHOT)
#undef USE_UART1_TX_DMA
#endif

#define LED_STRIP

//#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT


#define DEFAULT_FEATURES        (FEATURE_TRANSPONDER | FEATURE_RSSI_ADC | FEATURE_CURRENT_METER)

//#define SPEKTRUM_BIND
// USART3,
//#define BIND_PIN                PB11

#define USE_SERIAL_4WAY_BLHELI_INTERFACE

// IO - stm32f303cc in 48pin package
#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         (BIT(13)|BIT(14)|BIT(15))
#define TARGET_IO_PORTF         (BIT(0)|BIT(1)|BIT(3)|BIT(4))

#define USABLE_TIMER_CHANNEL_COUNT 8
#define USED_TIMERS             ( TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(4) | TIM_N(15) | TIM_N(16) | TIM_N(17) )
