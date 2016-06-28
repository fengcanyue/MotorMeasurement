#include "capture3re.h"
#include "var_space.h"

//定时器3通道2输入捕获配置
//devin:这个是蛋疼的映射方法，上个程序猿脑残的设计
//TIM3_CH2 PC7(REMAP)

TIM_ICInitTypeDef  TIM3_ICInitStructure;

void TIM3RE_Cap_Init(u16 arr,u16 psc)
{	 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//使能TIM3时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC ,ENABLE); 	//使能GPIOC时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;  //PC7 清除之前设置  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //PC7 输入  
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);						 //PC7 下拉
	
	//初始化定时器3 TIM3	 
	TIM_TimeBaseStructure.TIM_Period = arr; //设定计数器自动重装值 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 	//预分频器   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
  
	//初始化TIM3输入捕获参数
// 	TIM3_ICInitStructure.TIM_Channel = TIM_Channel_2; //CC1S=01 	选择输入端 IC1映射到TI1上
// 	TIM3_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
// 	TIM3_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
// 	TIM3_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
// 	TIM3_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
// 	//TIM_ICInit(TIM3, &TIM3_ICInitStructure);
// 	TIM_PWMIConfig(TIM3, &TIM3_ICInitStructure);                 //根据参数配置TIM外设信息
	
//  	TIM_SelectInputTrigger(TIM3, TIM_TS_TI2FP2);//选择IC2为始终触发源
//  	TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);//TIM从模式：触发信号的上升沿重新初始化计数器和触发寄存器的更新事件
//  	TIM_SelectMasterSlaveMode(TIM2, TIM_MasterSlaveMode_Enable); //启动定时器的被动触发
	TIM_TIxExternalClockConfig(TIM3,TIM_TIxExternalCLK1Source_TI2,TIM_ICPolarity_Rising,0);
	TIM_SetCounter(TIM3, 0);   // 清零计数器CNT
    TIM_Cmd(TIM3,ENABLE); 
	//中断分组初始化
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级1级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器 
	
// 	TIM_ITConfig(TIM3,TIM_IT_CC2 ,ENABLE);//允许更新中断 ,允许CC1IE捕获中断	
// 	
// 	TIM_Cmd(TIM3,ENABLE ); 	//使能定时器3
 
}

uint16_t  TIM3CH2_CAPTURE_CNT=0;	//捕获计数溢出次数
uint16_t	TIM3CH2_CAPTURE_VAL;			//当前输入捕获值
uint8_t TIM3CH2_CAPTURE_SAT=0; //当前捕获状态 0为等待上升沿 1为等待下降沿
 
//定时器3中断服务程序	 
//void TIM3_IRQHandler(void)
//{ 
// 	//判断是否为更新中断
// 	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) 
// 	{
// 		TIM3CH2_CAPTURE_CNT++;	//溢出次数计数
// 		TIM3CH2_CAPTURE_VAL=0XFFFF;
// 	}
// 	if (TIM_GetITStatus(TIM3, TIM_IT_CC2) != RESET) //判断是否为捕获中断
// 	{
// 		if(TIM3CH2_CAPTURE_SAT)
// 		{
// 			TIM3CH2_CAPTURE_SAT=0;
// 			TIM_OC2PolarityConfig(TIM3,TIM_ICPolarity_Rising); 	//CC2P=0 设置为上升沿捕获
// 			addTIM3Counter();	//捕获计数,高频方法
// 		}
// 		else
// 		{
// 			TIM3CH2_CAPTURE_SAT=1;
// 			TIM_OC2PolarityConfig(TIM3,TIM_ICPolarity_Falling);	//CC2P=1 设置为下降沿捕获
// 		}
		
// 		TIM3CH1_CAPTURE_VAL= TIM_GetCapture2(TIM3);	//获取当前计数值
// 		setTIM3Period(TIM3CH2_CAPTURE_VAL + TIM3CH2_CAPTURE_CNT*65535);	//更新捕获周期
// 		
// 		TIM3CH2_CAPTURE_CNT = 0; //捕获下个上升沿，停止计数
// 		TIM3CH2_CAPTURE_VAL = 0XFFFF;	//数据清空准备下次捕捉计数
// 		TIM_SetCounter(TIM3,0);
//	}
	
	//TIM_ClearITPendingBit(TIM3, TIM_IT_CC2|TIM_IT_Update); //清除中断标志位
	//if (TIM_GetITStatus(TIM3, TIM_IT_CC2) != RESET) //判断是否为捕获中断
	//{
		//addTIM3Counter();	//捕获计数,高频方法
	//	TIM_ClearITPendingBit(TIM3, TIM_IT_CC2); //清除中断标志位
//}
 
//}
