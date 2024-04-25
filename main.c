#include "stm32f10x.h"                  // Device header
#include "config_timer.h"
#include "button.h"
#include "stm32f10x_gpio.h"             // Device:StdPeriph Drivers:GPIO
#include "stm32f10x_rcc.h"              // Device:StdPeriph Drivers:RCC

void gpio_config()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
}
int main(void)
{
	gpio_config();
	RCC->APB2ENR |= (1<<2); // GPIOA
	GPIOA->CRL = 0x33444448; // 
	SetSystem72Mhz();
	ConfigureTimer3();
	//setup_input();
	
	while(1)
	{
		//function_button();
	}
}