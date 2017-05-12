#include "LPC11xx.h"                    // Device header

uint16_t count = 0;
uint32_t table[10] = {0xfc0,0xff9,0xfa4,0xfb0,0xf99,0xf92,0xf82,0xff8,0xf80,0xf90};


void delay()
{
	uint16_t i = 4000;
	while(i--);
	
}
void delay2()
{
	uint16_t x,y;
	for(x=500;x>0;x--)
	for(y=10;y>0;y--);
}


void GPIOinit()
{
	LPC_GPIO2->DIR = 0xFFF;
	LPC_GPIO2->DATA = 0xFFF;
	LPC_GPIO3->DIR &= ~(1<<0);
	LPC_GPIO3->DIR &= ~(1<<1);
	LPC_GPIO3->IE |= (1<<0);
  LPC_GPIO3->IE |= (1<<1);
	LPC_GPIO3->IS &= ~(1<<0);
	LPC_GPIO3->IS &= ~(1<<1);
	LPC_GPIO3->IEV &= ~(1<<0);
	LPC_GPIO3->IEV &= ~(1<<1);
	NVIC_EnableIRQ(EINT3_IRQn);
}

void Display(uint32_t value)
{
	uint32_t temp;
	
	temp = table[value/1000];
	temp &= ~(1<<8);
	LPC_GPIO2->DATA &= temp;
	delay();
	LPC_GPIO2->DATA = 0xFFF;


  temp = table[value%1000/100];
	temp &= ~(1<<9);
	LPC_GPIO2->DATA &= temp;
	delay();
	LPC_GPIO2->DATA = 0xFFF;
	

	temp = table[value%100/10];
	temp &= ~(1<<10);
	LPC_GPIO2->DATA &= temp;
	delay();
	LPC_GPIO2->DATA = 0xFFF;
	

	temp = table[value%10];
	temp &= ~(1<<11);
  LPC_GPIO2->DATA &= temp;
	delay();
	LPC_GPIO2->DATA = 0xFFF;
	
}


void PIOINT3_IRQHandler()
{
	if((LPC_GPIO3->MIS & (1<<0)) == (1<<0))
	{
		delay2(); 
    if((LPC_GPIO3->MIS & (1<<0)) == (1<<0))
		{
			count ++;
			LPC_GPIO3->IC = (1<<0);
		}	
	}
	if((LPC_GPIO3->MIS & (1<<1)) == (1<<1))
	{
		delay2(); 
    if((LPC_GPIO3->MIS & (1<<1)) == (1<<1))	
		{
			count --;
			LPC_GPIO3->IC = (1<<1);
		}	
	}
	
}




int main()
{
	GPIOinit ();
	while(1)
	{
		Display (count);
	}
}















