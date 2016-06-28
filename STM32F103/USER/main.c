#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
// #include "usart1.h"
#include "usart2.h"
#include "timer.h"
#include "capture2.h"
#include "capture3re.h"
#include "var_space.h"
#include "dac.h"
#include "dma.h"
#include "pwm.h"

u8 SendBuff[10];

int main(void)
{
	NVIC_Configuration();				// 设置中断优先级分组
	delay_init();
	SendBuff[0]='P';	//	报文头的标识
	SendBuff[5]='Q';	//	报文头的标识
	
	//初始化芯片硬件
	LED_Init();
 	TIM5_Int_Init(499,7200-1);	//定时器设置 7200分频 10kHz 定时500单位 = 50ms
	TIM4_Int_Init(4999,72-1);	//定时器设置 72分频 1MHz 定时5000单位 = 5ms
	TIM2_Cap_Init(0XFFFF,0);		//TIM2以72Mhz频率计数
	TIM3RE_Cap_Init(0XFFFF,0);		//TIM3以72Mhz频率计数
	uart2_init(115200);	 							//串口初始化为115200
 	Dac1_Init();		 	//DAC通道1初始化 //PA.4 输出
 	Dac2_Init();		 	//DAC通道2初始化 //PA.5 输出
	DMA_USART_Config(DMA1_Channel7,(u32)&USART2->DR,(u32)SendBuff,10);

	//初始化主板硬件
	Dac1_Set_Vol(0);
	Dac2_Set_Vol(0);
	
	//开启PWM
	TIM1_PWM_Init(199,72-1); //不分频。PWM 频率=72000/(899+1)=80Khz
	TIM_SetCompare1(TIM1,100); //设置占空比
	
	
	while(1)
	{
		//工作闪光提示
		LED0=0;
		LED1=1;
		delay_ms(500);
		LED0=1;
		LED1=0;
		delay_ms(500);
	}
	
}
