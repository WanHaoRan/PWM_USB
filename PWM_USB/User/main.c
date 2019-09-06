#include "main.h"
#include "usart.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "usbio.h"
#include "led.h"
#include "stm32f10x.h"

extern volatile uint32_t EP1_ReceivedCount;
extern volatile uint32_t EP2_ReceivedCount;

int main(void)
{
	uint8_t data[24];
	uint8_t pin_time[24]; // 每个pwm的占空比
	u32 time;
	uint32_t i=0;
	//uint32_t start = 1;
	Set_System();//系统时钟初始化
	SystemInit();
	USART_Configuration();//串口1初始化

	USB_Interrupts_Config();
	Set_USBClock();
	USB_Init();

	LED_GPIO_Config();/* GPIO端口配置 */ 
	
	for(i=0;i<24;i++){
		pin_time[i]=25;
	}
	time = 0;
	while(1)
	{
		//open 790nm
		
		GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	 // 关闭所有LED
		GPIO_SetBits(GPIOA, GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_8);
		GPIO_SetBits(GPIOB, GPIO_Pin_5);	 
			
		Delay_1000();
		Delay_1000();
		
		
		//820nm
		GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	 // 关闭所有LED
		GPIO_SetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_9);
		GPIO_SetBits(GPIOB, GPIO_Pin_1 | GPIO_Pin_8);	 
		
		Delay_1000();
		Delay_1000();
		
		//890nm
		GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	 // 关闭所有LED
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_6 | GPIO_Pin_14);	 
		
		Delay_1000();
		Delay_1000();
		
		//920nm
		GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	 // 关闭所有LED
		GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_7);
		GPIO_SetBits(GPIOB, GPIO_Pin_4 | GPIO_Pin_12);	

		Delay_1000();
		Delay_1000();
		
		//950nm
		GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	 // 关闭所有LED
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
		GPIO_SetBits(GPIOB, GPIO_Pin_10 | GPIO_Pin_7 | GPIO_Pin_13);	 
		
		Delay_1000();
		Delay_1000();
		
		//990nm
		GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	 // 关闭所有LED
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
		GPIO_SetBits(GPIOB, GPIO_Pin_11 | GPIO_Pin_9 | GPIO_Pin_15);	 
		Delay_1000();
		Delay_1000();
		
		GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	 // 关闭所有LED
		//GPIO_SetBits(GPIOA, GPIO_Pin_3);
		//GPIO_SetBits(GPIOB, GPIO_Pin_11 | GPIO_Pin_9 | GPIO_Pin_15);	 
		Delay_1000();
		Delay_1000();
		/**/
		/*the default set
		if(EP1_ReceivedCount > 0){
			USB_GetData(ENDP1,data,EP1_ReceivedCount);
			for(i=0;i<24;i++){
				pin_time[i] = data[i];
			}
			USB_SendData(ENDP1,pin_time,EP1_ReceivedCount);
			EP1_ReceivedCount=0;
			//GPIO_ResetBits(GPIOA,GPIO_Pin_12);
			//GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)(0));//((1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_12))));
		}
		
		if(EP2_ReceivedCount > 0){
			USB_GetData(ENDP2,data,EP2_ReceivedCount);
			USB_SendData(ENDP2,data,EP2_ReceivedCount);
			for(i=0;i<24;i++){
				pin_time[i] = data[i];
			}
			EP2_ReceivedCount=0;	
			GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)(0));//((1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_12))));
		}
		
		
		
		if(time == pin_time[0]) GPIO_WriteBit(GPIOB, GPIO_Pin_0, (BitAction)(0));
		if(time == pin_time[1]) GPIO_WriteBit(GPIOB, GPIO_Pin_1, (BitAction)(0));
		if(time == pin_time[2]) GPIO_WriteBit(GPIOB, GPIO_Pin_3, (BitAction)(0));
		if(time == pin_time[3]) GPIO_WriteBit(GPIOA, GPIO_Pin_9, (BitAction)(0));
		if(time == pin_time[4]) GPIO_WriteBit(GPIOB, GPIO_Pin_5, (BitAction)(0));
		if(time == pin_time[5]) GPIO_WriteBit(GPIOB, GPIO_Pin_6, (BitAction)(0));
		if(time == pin_time[6]) GPIO_WriteBit(GPIOB, GPIO_Pin_7, (BitAction)(0));
		if(time == pin_time[7]) GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)(0));
		if(time == pin_time[8]) GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)(0));
		if(time == pin_time[9]) GPIO_WriteBit(GPIOB, GPIO_Pin_10, (BitAction)(0));
		if(time == pin_time[10]) GPIO_WriteBit(GPIOB, GPIO_Pin_11, (BitAction)(0));
		if(time == pin_time[11]) GPIO_WriteBit(GPIOB, GPIO_Pin_12, (BitAction)(0));
		if(time == pin_time[12]) GPIO_WriteBit(GPIOB, GPIO_Pin_13, (BitAction)(0));
		if(time == pin_time[13]) GPIO_WriteBit(GPIOB, GPIO_Pin_14, (BitAction)(0));
		if(time == pin_time[14]) GPIO_WriteBit(GPIOB, GPIO_Pin_15, (BitAction)(0));
		if(time == pin_time[15]) GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)(0));
		if(time == pin_time[16]) GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)(0));
		if(time == pin_time[17]) GPIO_WriteBit(GPIOA, GPIO_Pin_2, (BitAction)(0));
		if(time == pin_time[18]) GPIO_WriteBit(GPIOA, GPIO_Pin_3, (BitAction)(0));
		if(time == pin_time[19]) GPIO_WriteBit(GPIOA, GPIO_Pin_4, (BitAction)(0));
		if(time == pin_time[20]) GPIO_WriteBit(GPIOA, GPIO_Pin_5, (BitAction)(0));
		if(time == pin_time[21]) GPIO_WriteBit(GPIOA, GPIO_Pin_6, (BitAction)(0));
		if(time == pin_time[22]) GPIO_WriteBit(GPIOA, GPIO_Pin_7, (BitAction)(0));
		if(time == pin_time[23]) GPIO_WriteBit(GPIOA, GPIO_Pin_8, (BitAction)(0));
		
		if(time == 100){
			time = 0;
			GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 |GPIO_Pin_9);
			GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	 // 关闭所有LED
		}
		time++;
		*/
	}
}




/*********************************END OF FILE**********************************/
