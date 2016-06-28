#include "timer.h"
#include "dma.h"
#include "var_space.h"


uint16_t sumShiftFilter(void);
uint16_t pretreatment0(void);
uint16_t pretreatment1(void);
uint16_t RankMaxToMin(uint16_t array[],uint16_t len);
void copy(uint16_t a[],uint16_t b[],uint16_t len);
extern uint16_t getPeriod(uint32_t );

uint32_t getAveragePeriod(void);
extern u8 SendBuff[];

//通用定时器中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器4!
void TIM4_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //时钟使能

	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM4, //TIM4
		TIM_IT_Update ,
		ENABLE  //使能
		);
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM4中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设

}

//通用定时器中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器5
void TIM5_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE); //时钟使能

	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM5, //TIM5
		TIM_IT_Update ,
		ENABLE  //使能
		);
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;  //TIM5溢出中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	TIM_Cmd(TIM5, ENABLE);  //使能TIMx外设

}


uint8_t HexTable[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};   //16进制字符表

#define StackLen 10
uint16_t SendData0 = 0; //比较过后要发送的数据0
uint16_t SendData1 = 0; //比较过后要发送的数据1
uint16_t DataStack0[StackLen] = {0}; //滤波器数组
uint8_t StackCursor0 = 0; //滤波器数组游标
uint16_t DataStack1[StackLen] = {0}; //滤波器数组
uint8_t StackCursor1 = 0; //滤波器数组游标

void TIM4_IRQHandler(void)   //TIM4中断
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源
		{
			
			SendData0 = getTIM2Period();	//无滤波
			//SendData0 = getPeriod(0);
			//SendData0 =getAveragePeriod();
			SendData1 = getTIM3Frequency();
//			DataStack0[StackCursor0] = getTIM2Period();	//有滤波
//			SendData0 = pretreatment0(); //预处理
//			DataStack1[StackCursor1] = getTIM3Frequency();
//			SendData1 = pretreatment1(); //预处理
			//数据装载
			SendBuff[1] = HexTable[(SendData0>>12)&0x0f];
			SendBuff[2] = HexTable[(SendData0>>8)&0x0f];
			SendBuff[3] = HexTable[(SendData0>>4)&0x0f];
			SendBuff[4] = HexTable[(SendData0)&0x0f];
			SendBuff[6] = HexTable[(SendData1>>12)&0x0f];
			SendBuff[7] = HexTable[(SendData1>>8)&0x0f];
			SendBuff[8] = HexTable[(SendData1>>4)&0x0f];
			SendBuff[9] = HexTable[(SendData1)&0x0f];
			DMA_USART_Enable(DMA1_Channel7);
		}
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源
}

void TIM5_IRQHandler(void)   //TIM5中断
{
	//if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源
		//{
			 
			setTIM3Frequency(sumShiftFilter()); //累加滑动滤波
			//setTIM3Frequency(pretreatment0());
			//clearTIM3Counter(); //清除累加器
		//}
	TIM_ClearITPendingBit(TIM5, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源
}

uint8_t ShiftFilterCursor = 0;  //滤波器游标
uint16_t CounterGroup[25]={0};
uint16_t Rank[25]={0};


uint16_t sumShiftFilter(void)
{
    //uint8_t i = 0;
    uint16_t sumTemp = 0;
	
    CounterGroup[ShiftFilterCursor] = TIM_GetCounter(TIM3);
	TIM_SetCounter(TIM3, 0);   // 清零计数器CNT
    TIM_Cmd(TIM3,ENABLE);
    ShiftFilterCursor++;
    ShiftFilterCursor = (ShiftFilterCursor % 25); //游标循环自加
	copy(Rank,CounterGroup,25);
	sumTemp=RankMaxToMin(Rank,24);//排序
//     for(i=0; i<20; i++)
//     {
//         sumTemp += Rank[i];
//     }
    return (uint16_t)(sumTemp);
}

//预处理函数（用于滑动平均滤波），窗口大小：StackLen
uint16_t pretreatment0(void)
{
	uint32_t temp = 0;
	uint16_t ave = 0;
	uint8_t counter;
	DataStack0[StackCursor0]=sumShiftFilter();
	for(counter=0; counter<StackLen; counter++)
	{
		temp = temp+DataStack0[counter];
	}
	StackCursor0++;
	StackCursor0 = (StackCursor0 % StackLen); //游标循环自加
	ave = temp /StackLen;
	return ave; //移位处理取平均
}

uint16_t pretreatment1(void)
{
	uint32_t temp = 0;
	uint16_t ave = 0;
	uint8_t counter;
	for(counter=0; counter<StackLen; counter++)
	{
		temp = temp+DataStack1[counter];
	}										   
	StackCursor1++;
	StackCursor1 = (StackCursor1 % StackLen); //游标循环自加
	ave = temp /StackLen;
	return ave; //移位处理取平均
}
//冒泡法排序
uint16_t RankMaxToMin(uint16_t array[],uint16_t len)  
{  
    int i,j;  
	uint16_t temp=0;
	uint16_t sumTemp = 0;
    for(j=0;j<len;j++)  
		for(i=0;i<len-j;i++)  
			if(array[i]<array[i+1])  
			{  
				temp=array[i];  
				array[i]=array[i+1];  
				array[i+1]=temp;  
			}
	for(i=1; i<21; i++)
    {
        sumTemp += array[i];
    }
	return sumTemp;
}  
//复制数组数据
void copy(uint16_t a[],uint16_t b[],uint16_t len)
{
	int i=0;
	for (i=0;i<len;i++)
		a[i]=b[i];
}

