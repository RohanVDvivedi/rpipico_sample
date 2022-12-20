/*
	A simple blink program built for stm32f103 on a blue pill board or alike
*/

#include<regs/resets.h>
#include<regs/gpio.h>
#include<regs/sio.h>

void delay_for(volatile int clocks)
{
	while(clocks--)
	{
		asm("nop");
	}
}

// GPIO 25 is the LED pin

void main(void)
{
	RESETS->RESET &= (~(1 << 5));
	while(!(RESETS->RESET_DONE & (1 << 5)));

	GPIO->STATUS_CTRL[25].GPIO_CTRL &= (~(0x1f));
	GPIO->STATUS_CTRL[25].GPIO_CTRL |= (0x5);

	SIO->GPIO_OE |= (1 << 25);

	while(1)
	{
		SIO->GPIO_OUT ^= (1 << 25);
		delay_for(300000);
	}
}