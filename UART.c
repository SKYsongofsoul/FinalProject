#include "LPC11XX.H"
#include "UART.h"
#define UART_BPS  115200

void UART_Init(void)
{
  uint16_t usFdiv;
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<16);
  LPC_IOCON->PIO1_6 &=~0x07;    
	LPC_IOCON->PIO1_6 |=0x01;     //设置为RXD功能
	LPC_IOCON->PIO1_7 &=~0x07;
	LPC_IOCON->PIO1_7 |=0x01;      //设置为TXD功能
	
	LPC_IOCON->PIO2_0 &=~0x07;    
	LPC_IOCON->PIO2_0 |=0x00;
	LPC_IOCON->PIO2_1 &=~0x07;    
	LPC_IOCON->PIO2_1 |=0x00; 
	LPC_IOCON->PIO2_2 &=~0x07;    
	LPC_IOCON->PIO2_2 |=0x00; 
	LPC_IOCON->PIO2_3 &=~0x07;    
	LPC_IOCON->PIO2_3 |=0x00; 
	LPC_IOCON->PIO2_4 &=~0x07;    
	LPC_IOCON->PIO2_4 |=0x00; 
	LPC_IOCON->PIO2_5 &=~0x07;    
	LPC_IOCON->PIO2_5 |=0x00; 
	LPC_IOCON->PIO2_6 &=~0x07;    
	LPC_IOCON->PIO2_6 |=0x00; 
	LPC_IOCON->PIO2_7 &=~0x07;    
	LPC_IOCON->PIO2_7 |=0x00;
	LPC_SYSCON->SYSAHBCLKCTRL &=~(1<<16);
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<6);
	LPC_GPIO2->DIR =0xff;
	LPC_GPIO2->DATA=0xff;
  LPC_SYSCON->SYSAHBCLKCTRL |=(1<<12);  //使能UART时钟
  LPC_SYSCON->UARTCLKDIV =0x01;          //时钟分频值为1
	LPC_UART-> LCR=0x83;                //8位传输，1个停止位，无奇偶校验，允许访问除数锁存器    
	usFdiv =(SystemCoreClock/LPC_SYSCON->UARTCLKDIV/16)/UART_BPS;  //计算该波特率要求的除数锁存器值
	LPC_UART->DLM =usFdiv/256;             //写除数锁存器高位值
	LPC_UART->DLL =usFdiv%256;                //写除数锁存器低位值
	LPC_UART->LCR =0x03;                     //DLAB置0
	LPC_UART->FCR =0x07;  //允许FIFO，清空RxFIFO和TxFIFO，FIFO触发点为1B
	}

	
uint8_t UART_GetByte(void)
{

  uint8_t ucRcvData;
	while((LPC_UART->LSR &0x01)==0);  //等待接收到数据
	ucRcvData =LPC_UART ->RBR;          //读出数据
	return(ucRcvData);               //返回读出的数据

}	

void UART_Sendbyte(uint8_t ucDat)
{
 LPC_UART->THR =ucDat ;          //发送数据
 while((LPC_UART->LSR&0x40)==0);	//等待发送完毕，TEMT置位

}


void UART_SendStr(char *pucStr)
{

while(1)
{
	if( *pucStr =='\0')break;
	UART_Sendbyte(*pucStr++);
	
}

}













