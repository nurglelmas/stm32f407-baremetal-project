/*
 * 003led_button_ext.c
 *
 *  Created on: 24 Oca 2026
 *      Author: nurgulelmas
 */


#include "stm32f407xx.h"

#define HIGH	1
#define LOW		0
#define BTN_PRESSED	LOW

void delay(void)
{
	for(uint32_t i=0;i<500000/2;i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GPIOBtn;

	//this is led gpio configuration
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_Init(&GpioLed);

	//this is btn gpio configuration

	GPIOBtn.pGPIOx = GPIOB;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_PU;

	GPIO_PeriClockControl(GPIOB,ENABLE);
	GPIO_Init(&GPIOBtn);
	uint8_t btn_prev_state = HIGH;

	while(1)
	{
	    uint8_t btn_curr_state = GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_12);

	    // Butona yeni basıldıysa
	    if(btn_curr_state == BTN_PRESSED && btn_prev_state == HIGH)
	    {
	        delay();  // debounce
	        GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
	    }

	    btn_prev_state = btn_curr_state;
	}

	return 0;

}
