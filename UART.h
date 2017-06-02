#ifndef _URAT_H
#define _URAT_H
#include "LPC11XX.H"

void UART_Sendbyte(uint8_t ucDat);
void UART_SendStr(char *pucStr);
void UART_Init(void);
uint8_t UART_GetByte(void);

#endif 









