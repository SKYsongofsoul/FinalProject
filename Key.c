#include "Key.h"
#include "LCD1602.h"


int up = 0;
int set_temperature_MAX = 30;
int set_temperature_MIN = 10;

void GPIOinit()
{
	LPC_GPIO3->DIR &= ~(1<<0);
	LPC_GPIO3->DIR &= ~(1<<1);
	LPC_GPIO3->DIR &= ~(1<<2);
	LPC_GPIO3->DIR &= ~(1<<3);
	LPC_GPIO3->DIR &= ~(1<<4);
}

void KEY_1()
{
	if((LPC_GPIO3->DATA & (1<<0)) == (0<<0))
	{	
		    Delayms(10);
			  if((LPC_GPIO3->DATA & (1<<0)) == (0<<0))   
				{
					while(1)
					{
					  if((LPC_GPIO3->DATA & (1<<0)) == (1<<0))
						{
					     up--;
							 break;
 						}
				  }
					if(up > 2)  up = 2;
					if(up < 0)  up = 0;
				}
	}
}

void KEY_2()
{
	if((LPC_GPIO3->DATA & (1<<1)) == (0<<1))
	{	
		    Delayms(10);
			  if((LPC_GPIO3->DATA & (1<<1)) == (0<<1))   
				{
					while(1)
					{
					  if((LPC_GPIO3->DATA & (1<<1)) == (1<<1))
						{
					     up++;
							 break;
 						}
				  }
					if(up > 2)  up = 2;
					if(up < 0)  up = 0;
				}
	}
}

void KEY_3()
{
	if((LPC_GPIO3->DATA & (1<<2)) == (0<<2))
	{	
		    Delayms(10);
			  if((LPC_GPIO3->DATA & (1<<2)) == (0<<2))   
				{
					while(1)
					{
					  if((LPC_GPIO3->DATA & (1<<2)) == (1<<2))
						{
							if(up == 1)   set_temperature_MAX++;
							if(up == 2)   set_temperature_MIN++;
							break;
 						}
				  }
					
				}
	}
}


void KEY_4()
{
	if((LPC_GPIO3->DATA & (1<<3)) == (0<<3))
	{	
		    Delayms(10);
			  if((LPC_GPIO3->DATA & (1<<3)) == (0<<3))   
				{
					while(1)
					{
					  if((LPC_GPIO3->DATA & (1<<3)) == (1<<3))
						{
					    if(up == 1)   set_temperature_MAX--;
							if(up == 2)   set_temperature_MIN--;
							break;
 						}
				  }
				}
	}
}



int KEY_5()
{
	if((LPC_GPIO3->DATA & (1<<4)) == (0<<4))
	{	
		    Delayms(10);
			  if((LPC_GPIO3->DATA & (1<<4)) == (0<<4))   
				{
					while(1)
					{
					  if((LPC_GPIO3->DATA & (1<<4)) == (1<<4))
						{
					     return 1;
						}
				}
		}
		else 
			return 0;
	}
}












































