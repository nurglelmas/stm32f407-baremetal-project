/*
 * stm32f407xx.h
 *
 *  Created on: 14 Oca 2026
 *      Author: nurgulelmas
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>

#define __vo volatile
/*
 *  base addresses of Flash and SRAM memories
 */

#define FLASHB_BASEADDR     		 0X08000000U
#define SRAM1_BASEADDR     			 0X20000000U //112 KB-> 112X1024=114,688(DEC)-->HEX:1C000
#define SRAM2_BASEADDR				 0X20001C00U
#define ROM_BASEADDR				 0X1FFF0000U	//SYSTEM MEMORY
#define SRAM 						 SRAM1_BASEADDR

/*
 *  AHBx and APBx Bus peripheral base addresses
 */

#define PERIPH_BASE					 0x40000000U
#define APB1PERIPH_BASE				 PERIPH_BASE
#define APB2PERIPH_BASE				 0x40010000U
#define AHB1PERIPH_BASE				 0x40020000U
#define AHB2PERIPH_BASE				 0x50000000U

/*
 * Base adresses of peripherals which are hanging on AHB1 bus
 * TODO : Complete for all other peripherals
 */
#define GPIOA_BASEADDR				(AHB1PERIPH_BASE + 0x0000)//OFFSET
#define GPIOB_BASEADDR				(AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR				(AHB1PERIPH_BASE + 0x2000)
#define RCC_BASEADDR				(AHB1PERIPH_BASE + 0x3800)

/*
 * Base addresses of peripherals which are hanging on APB1 bus
 * TODO:Complete for all other peripherals
 */
#define I2C1_BASEADDR				(APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASE + 0x5C00)

#define SPI2_BASEADDR				(APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASE + 0x3C00)

#define USART2_BASEADDR				(APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR				(APB1PERIPH_BASE + 0x4800)
#define UART4_BASEADDR				(APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR				(APB1PERIPH_BASE + 0x5000)


/*
 * Base addresses of peripherals which are hanging on APB2 bus
 * TODO:Complete for all other peripherals
 */

#define EXTI_BASEADDR				(APB2PERIPH_BASE + 0x3C00)

#define SPI1_BASEADDR				(APB2PERIPH_BASE + 0x3000)

#define USART1_BASEADDR				(APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR				(APB2PERIPH_BASE + 0x1400)

#define SYSCFG_BASEADDR				(APB2PERIPH_BASE + 0x3800)



/********************peripheral register definition structurs********************************/

/*
 * Note:Register of a peripheral are spesific to MCU
 * e.g:Number of Register of SPI peripheral of STM32F4x family of MCUs may be different
 * Compared to number of register of SPI peripheral of STM32Lx or STM32F0x family of MCUs
 * Please check your Device RM
 */
typedef struct
{
	__vo uint32_t MODER;		/*< GPIO port mode register,				Address offset:0x00  */
	__vo uint32_t OTYPER;		/*< GPIO port output type register 			Address offset:0x04  */
	__vo uint32_t OSPEEDR;		/*< GPIO port output speed register			Address offset:0x08  */
	__vo uint32_t PUPDR;		/*< GPIO port pull-up/pull-down register	Address offset:0x0C  */
	__vo uint32_t IDR;			/*< GPIO port input data register 			Address offset:0x10  */
	__vo uint32_t ODR;			/*< GPIO port output data register			Address offset:0x14  */
	__vo uint32_t BSRR;			/*< GPIO port bit set/reset register		Address offset:0x18  */
	__vo uint32_t LCKR;			/*< GPIO port configuration lock register	Address offset:0x1C  */
	__vo uint32_t AFR[2];		/*< AFR[0]:GPIO alternate function low register,AFR[1]:GPIO alternate function high register	Address offset:0x20-0x24  */
}GPIO_RegDef_t;

/*
 * Peripheral register definition structure for RCC
 */


typedef struct
{
	__vo uint32_t CR;				/*< RCC clock control register,										Address offset:0x00  */
	__vo uint32_t PLLCFGR ;			/*< RCC PLL configuration register,									Address offset:0x04  */
	__vo uint32_t CFGR;				/*< RCC clock configuration register,								Address offset:0x08  */
	__vo uint32_t CIR ;				/*< RCC clock interrupt register,									Address offset:0x0C  */
	__vo uint32_t AHB1RSTR ;		/*< RCC AHB1 peripheral reset register ,							Address offset:0x10  */
	__vo uint32_t AHB2RSTR  ;		/*< RCC AHB2 peripheral reset register,								Address offset:0x14  */
	__vo uint32_t AHB3RSTR  ;		/*< RCC AHB3 peripheral reset register ,							Address offset:0x18  */
	uint32_t RESERVED0;				/*< Reserved				,										Address offset:0x1C  */
	__vo uint32_t APB1RSTR ;		/*< RCC APB1 peripheral reset register,								Address offset:0x20  */
	__vo uint32_t APB2RSTR  ;		/*< RCC APB2 peripheral reset register,								Address offset:0x24  */
	uint32_t RESERVED1;				/*< Reserved				,										Address offset:0x28  */
	uint32_t RESERVED2;				/*< Reserved				,										Address offset:0x2C  */
	__vo uint32_t AHB1ENR  ;		/*< RCC AHB1 peripheral clock register,								Address offset:0x30  */
	__vo uint32_t AHB2ENR   ;		/*< RCC AHB2 peripheral clock enable register,						Address offset:0x34  */
	__vo uint32_t AHB3ENR  ;		/*< RCC AHB3 peripheral clock enable register ,						Address offset:0x38  */
	uint32_t RESERVED3;				/*< Reserved				,										Address offset:0x3C  */
	__vo uint32_t APB1ENR  ;		/*< RCC APB1 peripheral clock enable register,						Address offset:0x40  */
	__vo uint32_t APB2ENR  ;		/*< RCC APB2 peripheral clock enable register ,						Address offset:0x44  */
	uint32_t RESERVED4;				/*< Reserved				,										Address offset:0x48  */
	uint32_t RESERVED5;				/*< Reserved				,										Address offset:0x4C  */
	__vo uint32_t AHB1LPENR  ;		/*< RCC AHB1 peripheral clock enable in low power mode register,	Address offset:0x50  */
	__vo uint32_t AHB2LPENR   ;		/*< RCC AHB2 peripheral clock enable in low power mode register,	Address offset:0x54  */
	__vo uint32_t AHB3LPENR  ;		/*< RCC AHB3 peripheral clock enable in low power mode register,	Address offset:0x58  */
	uint32_t RESERVED6;				/*< Reserved				,										Address offset:0x5C  */
	__vo uint32_t APB1LPENR  ;		/*< RCC APB1 peripheral clock enable in low power mode register,	Address offset:0x60  */
	__vo uint32_t APB2LPENR   ;		/*< RCC APB2 peripheral clock enabled in low power mode register,	Address offset:0x64  */
	uint32_t RESERVED7;				/*< Reserved				,										Address offset:0x68  */
	uint32_t RESERVED8;				/*< Reserved				,										Address offset:0x6C  */
	__vo uint32_t BDCR   ;			/*< RCC Backup domain control register,								Address offset:0x70  */
	__vo uint32_t CSR   ;			/*< RCC clock control & status register ,							Address offset:0x74  */
	uint32_t RESERVED9;				/*< Reserved				,										Address offset:0x78  */
	uint32_t RESERVED10;				/*< Reserved				,										Address offset:0x7C  */
	__vo uint32_t SSCGR   ;			/*< RCC spread spectrum clock generation register,					Address offset:0x80  */
	__vo uint32_t PLLI2SCFGR   ;	/*< RCC PLLI2S configuration register ,								Address offset:0x84  */
	__vo uint32_t PLLSAICFGR   ;	/*< RCC PLL configuration register ,								Address offset:0x88  */
	__vo uint32_t DCKCFGR    ;		/*< RCC Dedicated Clock Configuration Register ,					Address offset:0x8C  */

} RCC_RegDef_t;

/*
 * peripheral definitions(Peripheral base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA 	((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 	((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 	((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 	((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 	((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF 	((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG 	((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH 	((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI 	((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC		((RCC_RegDef_t*)RCC_BASEADDR)


/*
 * CLock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()		(RCC->AHB1ENR |= (1 << 8))

/*
 * CLock Enable Macros for I2C peripherals
 */
#define I2C1_PCLK_EN()		(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()		(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()		(RCC->APB1ENR |= (1 << 23))

/*
 * CLock Enable Macros for SPI peripherals
 */

#define SPI1_PCLK_EN()		(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()		(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()		(RCC->APB1ENR |= (1 << 15))
#define SPI5_PCLK_EN()		(RCC->APB2ENR |= (1 << 20))
#define SPI6_PCLK_EN()		(RCC->APB2ENR |= (1 << 21))

/*
 * CLock Enable Macros for USARTx peripherals
 */
#define USART1_PCLK_EN()	(RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()	(RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()	(RCC->APB1ENR |= (1 << 18))
#define USART4_PCLK_EN()	(RCC->APB1ENR |= (1 << 19))
#define USART5_PCLK_EN()	(RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN()	(RCC->APB2ENR |= (1 << 5))
/*
 * CLock Enable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_EN()	(RCC->APB2ENR |= (1 << 14))
/*
 * CLock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 8))
/*
 * CLock Disable Macros for I2C peripherals
 */
#define I2C1_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 23))
/*
 * CLock Disable Macros for SPI peripherals
 */
#define SPI1_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI())		(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 15))
#define SPI5_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 20))
#define USART6_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 5))
/*
 * CLock Disable Macros for USARTx peripherals
 */
#define USART1_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 18))
#define USART4_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 19))
#define USART5_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 5))
/*
 * CLock Disable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 14))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 0));	(RCC->AHB1RSTR &= (1 << 0));}while(0)
#define GPIOB_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 1));	(RCC->AHB1RSTR &= (1 << 1));}while(0)
#define GPIOC_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 2));	(RCC->AHB1RSTR &= (1 << 2));}while(0)
#define GPIOD_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 3));	(RCC->AHB1RSTR &= (1 << 3));}while(0)
#define GPIOE_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 4));	(RCC->AHB1RSTR &= (1 << 4));}while(0)
#define GPIOF_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 5));	(RCC->AHB1RSTR &= (1 << 5));}while(0)
#define GPIOG_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 6));	(RCC->AHB1RSTR &= (1 << 6));}while(0)
#define GPIOH_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 7));	(RCC->AHB1RSTR &= (1 << 7));}while(0)
#define GPIOI_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 8));	(RCC->AHB1RSTR &= (1 << 8));}while(0)


//some generic macros
#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET			DİSABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET


#include "stm32f407xx_gpıo_driver.h"

#endif /* INC_STM32F407XX_H_ */
