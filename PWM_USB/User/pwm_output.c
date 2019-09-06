#include "pwm_output.h"

static void TIM1_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体
	TIM_OCInitTypeDef TIM_OCInitStructure;	//定义结构体
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //定义初始化结构体
	
	//配置和初始化GPIO
	RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //使能定时器3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);	//使能GPIO外设
	TIM_DeInit(TIM1);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);	//选择TIM3部分重映像
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);	
	//选择TIM3的channels 作为PWM的输出引脚TIM3->PA6,PA7,PB0,PB1，四个channel分别定义,我们使用“没有重定义“的
	//GPIO PWM对应的channel引脚见https://www.cnblogs.com/zhoubatuo/p/6135103.html
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;	//TIM_CH2 和TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);		//初始化引脚
	
	//初始化定时器
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //定义初始化结构体
	
	//初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = arr;				//自动重装载寄存器的值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		//TIMX预分频的值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);	//根据以上功能对定时器进行初始化
	
	//设置TIM3_CH2 的PWM模式，使能TIM3的CH2输出
	//TIM_OCInitTypeDef TIM_OCInitStructure;	//定义结构体
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	//选择定时器模式，TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	
	TIM_OCInitStructure.TIM_Pulse = 200;//需要控制占空比的话，我们可以将这个作为我们的函数的输入值来进行控制
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 400;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM1,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 600;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM1,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 800;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM1,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在

	TIM_ARRPreloadConfig(TIM1,ENABLE);
	TIM_Cmd(TIM1,ENABLE);	//使能定时器TIM3
}


static void TIM2_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体
	TIM_OCInitTypeDef TIM_OCInitStructure;	//定义结构体
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //定义初始化结构体
	
	//配置和初始化GPIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //使能定时器3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);	//使能GPIO外设
	TIM_DeInit(TIM2);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM2, ENABLE);	//选择TIM3部分重映像
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM2,ENABLE);	
	//选择TIM2的channels 作为PWM的输出引脚TIM2->PA6,PA7,PB0,PB1，四个channel分别定义,我们使用“没有重定义“的
	//GPIO PWM对应的channel引脚见https://www.cnblogs.com/zhoubatuo/p/6135103.html
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;	//TIM_CH2 和TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);		//初始化引脚
	
	
	//初始化定时器
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //定义初始化结构体
	
	//初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = arr;				//自动重装载寄存器的值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		//TIMX预分频的值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);	//根据以上功能对定时器进行初始化
	
	//设置TIM3_CH2 的PWM模式，使能TIM3的CH2输出
	//TIM_OCInitTypeDef TIM_OCInitStructure;	//定义结构体
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	//选择定时器模式，TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	
	TIM_OCInitStructure.TIM_Pulse = 200;//需要控制占空比的话，我们可以将这个作为我们的函数的输入值来进行控制
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 400;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM2,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 600;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM2,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 800;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM2,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_ARRPreloadConfig(TIM2,ENABLE);
	TIM_Cmd(TIM2,ENABLE);	//使能定时器TIM3
}


static void TIM3_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体
	TIM_OCInitTypeDef TIM_OCInitStructure;	//定义结构体
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //定义初始化结构体
	
	//配置和初始化GPIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //使能定时器3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);	//使能GPIO外设
	TIM_DeInit(TIM3);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);	//选择TIM3部分重映像
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);	
	//选择TIM3的channels 作为PWM的输出引脚TIM3->PA6,PA7,PB0,PB1，四个channel分别定义,我们使用“没有重定义“的
	//GPIO PWM对应的channel引脚见https://www.cnblogs.com/zhoubatuo/p/6135103.html
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;	//TIM_CH2 和TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);		//初始化引脚
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;	//TIM_CH2 和TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);		//初始化引脚
	
	
	//初始化定时器
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //定义初始化结构体
	
	//初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = arr;				//自动重装载寄存器的值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		//TIMX预分频的值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);	//根据以上功能对定时器进行初始化
	
	//设置TIM3_CH2 的PWM模式，使能TIM3的CH2输出
	//TIM_OCInitTypeDef TIM_OCInitStructure;	//定义结构体
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	//选择定时器模式，TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	
	TIM_OCInitStructure.TIM_Pulse = 2000;//需要控制占空比的话，我们可以将这个作为我们的函数的输入值来进行控制
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 4000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 6000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM3,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 8000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_Cmd(TIM3,ENABLE);	//使能定时器TIM3
}

static void TIM4_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体
	TIM_OCInitTypeDef TIM_OCInitStructure;	//定义结构体
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //定义初始化结构体
	
	//配置和初始化GPIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //使能定时器4
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//使能GPIO外设
	TIM_DeInit(TIM4);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);	//选择TIM3部分重映像
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);	
	//选择TIM3的channels 作为PWM的输出引脚TIM3->PA6,PA7,PB0,PB1，四个channel分别定义,我们使用“没有重定义“的
	//GPIO PWM对应的channel引脚见https://www.cnblogs.com/zhoubatuo/p/6135103.html
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;	//TIM_CH2 和TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);		//初始化引脚
	
	//初始化定时器
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //定义初始化结构体
	
	//初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = arr;				//自动重装载寄存器的值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		//TIMX预分频的值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);	//根据以上功能对定时器进行初始化
	
	//设置TIM3_CH2 的PWM模式，使能TIM3的CH2输出
	//TIM_OCInitTypeDef TIM_OCInitStructure;	//定义结构体
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	//选择定时器模式，TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	
	TIM_OCInitStructure.TIM_Pulse = 2000;//需要控制占空比的话，我们可以将这个作为我们的函数的输入值来进行控制
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 4000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM4,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 6000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM4,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_OCInitStructure.TIM_Pulse = 8000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM4,&TIM_OCInitStructure);	//根据以上定义的结构体来进行初始化
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);	//使能定时器TIM2在CCR2上的预装在
	
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	TIM_Cmd(TIM4,ENABLE);	//使能定时器TIM3
}


void Init(u16 arr, u16 psc)
{
	TIM1_PWM_Init(arr,psc);
	TIM2_PWM_Init(arr,psc);
	TIM3_PWM_Init(arr,psc);
	TIM4_PWM_Init(arr,psc);
}
