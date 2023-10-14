#include<stdint.h>
#include "led.h"
#include "RCC.h"
#include "GPIO.h"


void led_toggle(uint8_t pwr_in, uint8_t led_out)
{
	uint32_t *pGpiodIDR = (uint32_t*) &GPIOA->IDR;

	if (*pGpiodIDR & (1 << pwr_in)) {
		led_on(led_out);
	} else {
		led_off(led_out);
	}
}

void led_on(uint8_t led_no)
{
	uint32_t *pGpiodDataReg = (uint32_t*) &GPIOA->ODR;
	*pGpiodDataReg |= (1 << led_no);
}

void led_off(uint8_t led_no)
{
	uint32_t *pGpiodDataReg = (uint32_t*) &GPIOA->ODR;
	*pGpiodDataReg &= ~(1 << led_no);
}


void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

void led_init_all(void)
{
	uint32_t *pRccAhb1enr = (uint32_t*) &RCC->AHB1ENR;
	uint32_t *pGpiodModeReg = (uint32_t*) &GPIOA->MODER;

	*pRccAhb1enr |= (1 << 0);
	*pGpiodModeReg |= (1 << (2 * LED_PIN));

    led_off(LED_PIN);
}