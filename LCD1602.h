 /*****************************************************************************************************************************************************

 *LCD.hͷ�Ĳ���***************************

 */

#ifndef __LCD_H__

#define __LCD_H__

 

 

/***************************************************************************************

LCD 1602 �������ã�

4:RES  0.2

5:R/W  2.7

6:E    2.8

7:DB0  2.1

8:DB1  0.3

9:DB2  1.9

10:DB3 2.4

11:DB4 2.5

12:DB5 0.6

13:DB6 0.7

14:DB7 2.9

*****************************************************************************************/

 

/************************************************************************************************************************************************************************ *Դ���򲿷�*************************************************

 */

#include "LPC11xx.h"

//#include "Urat.h"

 

#define TDELAY 2

#define LCD_RS_LOW 		LPC_GPIO2->DATA &= ~(1<<0)	//����״̬����
#define LCD_RS_HIGH		LPC_GPIO2->DATA |=  (1<<0)	//
#define LCD_RW_LOW		LPC_GPIO2->DATA &= ~(1<<1)	//��дʹ������
#define LCD_RW_HIGH		LPC_GPIO2->DATA |=  (1<<1)	//
#define LCD_E_LOW		LPC_GPIO2->DATA &= ~(1<<2)	//ʹ�ܶ�
#define LCD_E_HIGH		LPC_GPIO2->DATA |=  (1<<2)	//

#define LCD_DATAPORT	LPC_GPIO2->DATA	            //DB0��DB7���ݶ˿�
#define LCD_DATA_IN		LPC_GPIO2->DIR &= ~0xFFF	//���ö˿�Ϊ����
#define LCD_DATA_OUT	LPC_GPIO2->DIR |=  0xFFF	//���ö˿�Ϊ��� 

                                                      

 

void Delayms(uint16_t ms);
void SysTick_Handler(void);
uint8_t Busy_Check(void);
void LCD_WriteCommand(uint32_t cmd);
void LCD_WriteData(uint32_t dat);
uint8_t LCD_DisplayChar(uint8_t x, uint8_t y, uint8_t ch);
uint8_t LCD_DisplayStr(uint8_t x, uint8_t y, uint8_t *pStr);
void LCD_IOInit(void);
void InitLCD(void);









#endif


