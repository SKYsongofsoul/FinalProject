#include "LPC11XX.H"
#include "UART.h"
#define UART_BPS  115200

void UART_Init(void)
{
  uint16_t usFdiv;
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<16);
  LPC_IOCON->PIO1_6 &=~0x07;    
	LPC_IOCON->PIO1_6 |=0x01;     //����ΪRXD����
	LPC_IOCON->PIO1_7 &=~0x07;
	LPC_IOCON->PIO1_7 |=0x01;      //����ΪTXD����
	
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
  LPC_SYSCON->SYSAHBCLKCTRL |=(1<<12);  //ʹ��UARTʱ��
  LPC_SYSCON->UARTCLKDIV =0x01;          //ʱ�ӷ�ƵֵΪ1
	LPC_UART-> LCR=0x83;                //8λ���䣬1��ֹͣλ������żУ�飬������ʳ���������    
	usFdiv =(SystemCoreClock/LPC_SYSCON->UARTCLKDIV/16)/UART_BPS;  //����ò�����Ҫ��ĳ���������ֵ
	LPC_UART->DLM =usFdiv/256;             //д������������λֵ
	LPC_UART->DLL =usFdiv%256;                //д������������λֵ
	LPC_UART->LCR =0x03;                     //DLAB��0
	LPC_UART->FCR =0x07;  //����FIFO�����RxFIFO��TxFIFO��FIFO������Ϊ1B
	}

	
uint8_t UART_GetByte(void)
{

  uint8_t ucRcvData;
	while((LPC_UART->LSR &0x01)==0);  //�ȴ����յ�����
	ucRcvData =LPC_UART ->RBR;          //��������
	return(ucRcvData);               //���ض���������

}	

void UART_Sendbyte(uint8_t ucDat)
{
 LPC_UART->THR =ucDat ;          //��������
 while((LPC_UART->LSR&0x40)==0);	//�ȴ�������ϣ�TEMT��λ

}


void UART_SendStr(char *pucStr)
{

while(1)
{
	if( *pucStr =='\0')break;
	UART_Sendbyte(*pucStr++);
	
}

}













