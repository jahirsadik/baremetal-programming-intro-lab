#include<stdio.h>
#include "led.h"
#include "clock_config.h"

void task1_handler(void);

int main(void)
{
	config_sysclk();
	led_init_all();
	task1_handler();
	for(;;);
}


void task1_handler(void)
{
	while(1)
	{
		led_toggle(PWR_PIN, LED_PIN);
	}

}
