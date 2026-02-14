/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: 10 Şub 2026
 *      Author: nurgulelmas
 */


#include "stm32f407xx_spi_driver.h"
#include "stm32f407xx.h"
/********************************************************************************************
 * @fn				-SPI_PeriClockControl
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-none
 *
 * @Note			-none
 */

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx,uint8_t EnorDi)
{
		if(EnorDi==ENABLE)
		{
			if(pSPIx == SPI1)
			{
				SPI1_PCLK_EN();
			}else if(pSPIx == SPI2)
			{
				SPI2_PCLK_EN();
			}else if(pSPIx == SPI3)
			{
				SPI3_PCLK_EN();
			}
		}else
		{
			//TODO
		}

}
/********************************************************************************************
 * @fn				-SPI_Inıt
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-none
 *
 * @Note			-none
 */
void SPI_Init(SPI_Handle_t *pSPIHandle)
{

	//peripheral clock enabled

	SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);

	//first lets configure the SPI_CR1 register
	uint32_t tempreg = 0;

	//1.configure the device mode
	tempreg |= pSPIHandle -> SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;

	//2.configure the bus config
	if(pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//bidi mode should be cleared
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
	}else if(pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		//bidi mode should be set
		tempreg |= (1 << SPI_CR1_BIDIMODE);
	}else if(pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		//BİDİ mode should be cleared
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
		//RXONLY must be set
		tempreg |= (1 << SPI_CR1_RXONLY);
	}
	//3.Configure the spi serial clock speed(baud rate)
	tempreg|= pSPIHandle -> SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

	//4.Configure the DFF
	tempreg|= pSPIHandle -> SPIConfig.SPI_DFF <<SPI_CR1_DFF;

	//5.Configure the CPOL
	tempreg|= pSPIHandle -> SPIConfig.SPI_CPOL << SPI_CR1_CPOL;

	//6.Configure the CPHA
	tempreg|= pSPIHandle -> SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

	//7. Configure SSM
	tempreg |= pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM;


	//CR1 register'a yaz
	pSPIHandle->pSPIx->CR1 = tempreg;
}

/********************************************************************************************
 * @fn				-SPI_Delnit
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-none
 *
 * @Note			-none
 */
void SPI_Delnit(SPI_RegDef_t *pSPIx)
{

}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx,uint32_t FlagName)
{
	if(pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}
/********************************************************************************************
 * @fn				-SPI_SendData
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-none
 *
 * @Note			-THİS İS BLOKİNG CALL
 */
void SPI_SendData(SPI_RegDef_t  *pSPIx,uint8_t *pTxBuffer,uint32_t Len)
{
	while(Len>0)
	{
		//1.wait until TXE is set
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG) == FLAG_RESET);

		//Check the DFF bit in CR1
		if( (pSPIx->CR1 & ( 1 << SPI_CR1_DFF) ) )
		{
			//16 BİT DFF
			//1.load the data in to the
			pSPIx -> DR = *((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}else
		{
			//8 bit
			pSPIx -> DR = *pTxBuffer;
			Len--;
			pTxBuffer++;
		}
	}
}
/********************************************************************************************
 * @fn				-SPI_ReceiveData
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-none
 *
 * @Note			-none
 */
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer,uint32_t Len)
{

}
/********************************************************************************************
 * @fn				-SPI_PeripheralControl
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-none
 *
 * @Note			-none
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		pSPIx -> CR1 |= (1 << SPI_CR1_SPE);
	}else
	{
		pSPIx -> CR1 &= ~(1 << SPI_CR1_SPE);
	}
}
/********************************************************************************************
 * @fn				-SPI_SSIConfig
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-none
 *
 * @Note			-none
 */

void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << SPI_CR1_SSI);
    }
    else
    {
        pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
    }
}
