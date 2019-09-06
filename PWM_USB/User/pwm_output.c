#include "pwm_output.h"

static void TIM1_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure;	//����ṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //�����ʼ���ṹ��
	
	//���úͳ�ʼ��GPIO
	RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //ʹ�ܶ�ʱ��3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��GPIO����
	TIM_DeInit(TIM1);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);	//ѡ��TIM3������ӳ��
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);	
	//ѡ��TIM3��channels ��ΪPWM���������TIM3->PA6,PA7,PB0,PB1���ĸ�channel�ֱ���,����ʹ�á�û���ض��塰��
	//GPIO PWM��Ӧ��channel���ż�https://www.cnblogs.com/zhoubatuo/p/6135103.html
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;	//TIM_CH2 ��TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);		//��ʼ������
	
	//��ʼ����ʱ��
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //�����ʼ���ṹ��
	
	//��ʼ��TIM3
	TIM_TimeBaseStructure.TIM_Period = arr;				//�Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		//TIMXԤ��Ƶ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);	//�������Ϲ��ܶԶ�ʱ�����г�ʼ��
	
	//����TIM3_CH2 ��PWMģʽ��ʹ��TIM3��CH2���
	//TIM_OCInitTypeDef TIM_OCInitStructure;	//����ṹ��
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	//ѡ��ʱ��ģʽ��TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	
	TIM_OCInitStructure.TIM_Pulse = 200;//��Ҫ����ռ�ձȵĻ������ǿ��Խ������Ϊ���ǵĺ���������ֵ�����п���
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 400;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM1,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 600;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM1,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 800;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM1,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��

	TIM_ARRPreloadConfig(TIM1,ENABLE);
	TIM_Cmd(TIM1,ENABLE);	//ʹ�ܶ�ʱ��TIM3
}


static void TIM2_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure;	//����ṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //�����ʼ���ṹ��
	
	//���úͳ�ʼ��GPIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʹ�ܶ�ʱ��3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��GPIO����
	TIM_DeInit(TIM2);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM2, ENABLE);	//ѡ��TIM3������ӳ��
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM2,ENABLE);	
	//ѡ��TIM2��channels ��ΪPWM���������TIM2->PA6,PA7,PB0,PB1���ĸ�channel�ֱ���,����ʹ�á�û���ض��塰��
	//GPIO PWM��Ӧ��channel���ż�https://www.cnblogs.com/zhoubatuo/p/6135103.html
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;	//TIM_CH2 ��TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);		//��ʼ������
	
	
	//��ʼ����ʱ��
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //�����ʼ���ṹ��
	
	//��ʼ��TIM3
	TIM_TimeBaseStructure.TIM_Period = arr;				//�Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		//TIMXԤ��Ƶ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);	//�������Ϲ��ܶԶ�ʱ�����г�ʼ��
	
	//����TIM3_CH2 ��PWMģʽ��ʹ��TIM3��CH2���
	//TIM_OCInitTypeDef TIM_OCInitStructure;	//����ṹ��
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	//ѡ��ʱ��ģʽ��TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	
	TIM_OCInitStructure.TIM_Pulse = 200;//��Ҫ����ռ�ձȵĻ������ǿ��Խ������Ϊ���ǵĺ���������ֵ�����п���
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 400;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM2,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 600;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM2,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 800;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM2,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_ARRPreloadConfig(TIM2,ENABLE);
	TIM_Cmd(TIM2,ENABLE);	//ʹ�ܶ�ʱ��TIM3
}


static void TIM3_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure;	//����ṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //�����ʼ���ṹ��
	
	//���úͳ�ʼ��GPIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʹ�ܶ�ʱ��3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��GPIO����
	TIM_DeInit(TIM3);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);	//ѡ��TIM3������ӳ��
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);	
	//ѡ��TIM3��channels ��ΪPWM���������TIM3->PA6,PA7,PB0,PB1���ĸ�channel�ֱ���,����ʹ�á�û���ض��塰��
	//GPIO PWM��Ӧ��channel���ż�https://www.cnblogs.com/zhoubatuo/p/6135103.html
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;	//TIM_CH2 ��TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);		//��ʼ������
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;	//TIM_CH2 ��TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);		//��ʼ������
	
	
	//��ʼ����ʱ��
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //�����ʼ���ṹ��
	
	//��ʼ��TIM3
	TIM_TimeBaseStructure.TIM_Period = arr;				//�Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		//TIMXԤ��Ƶ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);	//�������Ϲ��ܶԶ�ʱ�����г�ʼ��
	
	//����TIM3_CH2 ��PWMģʽ��ʹ��TIM3��CH2���
	//TIM_OCInitTypeDef TIM_OCInitStructure;	//����ṹ��
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	//ѡ��ʱ��ģʽ��TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	
	TIM_OCInitStructure.TIM_Pulse = 2000;//��Ҫ����ռ�ձȵĻ������ǿ��Խ������Ϊ���ǵĺ���������ֵ�����п���
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 4000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 6000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM3,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 8000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_Cmd(TIM3,ENABLE);	//ʹ�ܶ�ʱ��TIM3
}

static void TIM4_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure;	//����ṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //�����ʼ���ṹ��
	
	//���úͳ�ʼ��GPIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //ʹ�ܶ�ʱ��4
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//ʹ��GPIO����
	TIM_DeInit(TIM4);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);	//ѡ��TIM3������ӳ��
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);	
	//ѡ��TIM3��channels ��ΪPWM���������TIM3->PA6,PA7,PB0,PB1���ĸ�channel�ֱ���,����ʹ�á�û���ض��塰��
	//GPIO PWM��Ӧ��channel���ż�https://www.cnblogs.com/zhoubatuo/p/6135103.html
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;	//TIM_CH2 ��TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);		//��ʼ������
	
	//��ʼ����ʱ��
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; //�����ʼ���ṹ��
	
	//��ʼ��TIM3
	TIM_TimeBaseStructure.TIM_Period = arr;				//�Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		//TIMXԤ��Ƶ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);	//�������Ϲ��ܶԶ�ʱ�����г�ʼ��
	
	//����TIM3_CH2 ��PWMģʽ��ʹ��TIM3��CH2���
	//TIM_OCInitTypeDef TIM_OCInitStructure;	//����ṹ��
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	//ѡ��ʱ��ģʽ��TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	
	TIM_OCInitStructure.TIM_Pulse = 2000;//��Ҫ����ռ�ձȵĻ������ǿ��Խ������Ϊ���ǵĺ���������ֵ�����п���
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 4000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM4,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 6000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM4,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_OCInitStructure.TIM_Pulse = 8000;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM4,&TIM_OCInitStructure);	//�������϶���Ľṹ�������г�ʼ��
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);	//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��
	
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	TIM_Cmd(TIM4,ENABLE);	//ʹ�ܶ�ʱ��TIM3
}


void Init(u16 arr, u16 psc)
{
	TIM1_PWM_Init(arr,psc);
	TIM2_PWM_Init(arr,psc);
	TIM3_PWM_Init(arr,psc);
	TIM4_PWM_Init(arr,psc);
}
