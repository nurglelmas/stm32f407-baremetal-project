/*
 * main.c
 *
 *  Created on: 29 Oca 2026
 *      Author: nurgulelmas
 */

#include "stm32f407xx.h"

int main(void)
{
	return 0;
}

void EXTI0_IRQHandler(void)
{
	//handle the ınterrupt
	GPIO_IRQHandling(0);
}
