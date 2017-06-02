#include "LPC11xx.h"  // LPC11xxÍâÉè¼Ä´æÆ÷
#include "string.h"
#include "LCD1602.h"
#include "Key.h"
#include "UART.h"

char GcRcvBuf1[16];
char GcRcvBuf2[16];


extern int up;
int temperature = 25;
extern int set_temperature_MAX;
extern int set_temperature_MIN;



int main()
{
	int i = 0;
	LCD_IOInit();
	InitLCD();
	GPIOinit();
	UART_Init();
	while(1)
	{
		KEY_1();
		KEY_2();
		if(up == 0)
		{
			sprintf(GcRcvBuf1,"->DisTemperature");
			sprintf(GcRcvBuf2,"  Set MAX Temper");
			if(KEY_5() == 1)
			{
				LCD_DisplayStr(0,1,"                ");
				while(1)
				{
				  sprintf(GcRcvBuf1,"Now Temperature:");
			    sprintf(GcRcvBuf2,"%d C    ",temperature);
					LCD_DisplayStr(0,1,GcRcvBuf2);
		      UART_SendStr(GcRcvBuf2);
					if((temperature > set_temperature_MAX) || (temperature < set_temperature_MIN))
					{
						for(i = 0 ; i < 10 ; i ++)
						{
							if(i < 5)   LCD_DisplayStr(0,0,"                ");
							if(i >= 5)   LCD_DisplayStr(0,0,"WARNING !!!!!!!!");
						}
					}
					else    { LCD_DisplayStr(0,0,GcRcvBuf1);}
					if(KEY_5() == 1)  break;
				}
			}
		}
		
		if(up == 1)
		{
			sprintf(GcRcvBuf1,"  DisTemperature");
			sprintf(GcRcvBuf2,"->Set MAX Temper");
			if(KEY_5() == 1)
			{
				LCD_DisplayStr(0,1,"                ");
				while(1)
				{
					KEY_3();
					KEY_4();
				  sprintf(GcRcvBuf1,"Set MAX Temper :");
			    sprintf(GcRcvBuf2,"%d C    ",set_temperature_MAX);
					LCD_DisplayStr(0,0,GcRcvBuf1);
		      LCD_DisplayStr(0,1,GcRcvBuf2);
					if(KEY_5() == 1)  break;
				}
			}
		}
		

		
		if(up == 2)
		{
			sprintf(GcRcvBuf1,"->Set MIN Temper");
			sprintf(GcRcvBuf2,"                ");
			if(KEY_5() == 1)
			{
				LCD_DisplayStr(0,1,"                ");
				while(1)
				{
					KEY_3();
					KEY_4();
				  sprintf(GcRcvBuf1,"Set MIN Temper :");
			    sprintf(GcRcvBuf2,"%d C      ",set_temperature_MIN);
					LCD_DisplayStr(0,0,GcRcvBuf1);
		      LCD_DisplayStr(0,1,GcRcvBuf2);
					if(KEY_5() == 1)  break;
				}
			}
		}
		
		LCD_DisplayStr(0,0,GcRcvBuf1);
		LCD_DisplayStr(0,1,GcRcvBuf2);
	}
}





































