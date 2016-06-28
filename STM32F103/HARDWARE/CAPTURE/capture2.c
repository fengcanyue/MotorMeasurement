#include "capture2.h"
#include "var_space.h"

//定时器2通道1输入捕获配置
//TIM2_CH2 PA1

TIM_ICInitTypeDef  TIM2_ICInitStructure;

void TIM2_Cap_Init(u16 arr,u16 psc)
{	 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//使能TIM2时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIOC时钟
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;  //PA1 清除之前设置  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //PA1 输入  
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);						 //PA1 下拉
	
	//初始化定时器2 TIM2	 
	TIM_TimeBaseStructure.TIM_Period = arr; //设定计数器自动重装值 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 	//预分频器   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
  
	//初始化TIM2输入捕获参数
	TIM2_ICInitStructure.TIM_Channel = TIM_Channel_2; //CC1S=01 	选择输入端 IC1映射到TI1上
	TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
	TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
	TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
	TIM2_ICInitStructure.TIM_ICFilter = 0x09;//IC1F=0000 配置输入滤波器 不滤波
	//TIM_ICInit(TIM2, &TIM2_ICInitStructure);
	TIM_PWMIConfig(TIM2, &TIM2_ICInitStructure);                 //根据参数配置TIM外设信息
	
	TIM_SelectInputTrigger(TIM2, TIM_TS_TI2FP2);
	TIM_SelectSlaveMode(TIM2, TIM_SlaveMode_Reset);//TIM从模式：触发信号的上升沿重新初始化计数器和触发寄存器的更新事件
	//TIM_SelectMasterSlaveMode(TIM2, TIM_MasterSlaveMode_Enable); //启动定时器的被动触发
	
	//中断分组初始化
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级1级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器 
	
	TIM_ITConfig(TIM2,TIM_IT_CC2|TIM_IT_Update ,ENABLE);//允许更新中断 ,允许CC1IE捕获中断	
						 //计数器清零
	//TIM_Cmd(TIM2, ENABLE);  //使能TIMx外设
	TIM_Cmd(TIM2,ENABLE ); 	//使能定时器2
 
}

uint16_t  TIM2CH2_CAPTURE_CNT=0;	//捕获计数溢出次数
uint16_t	TIM2CH2_CAPTURE_VAL;			//当前输入捕获值
uint8_t TIM2CH2_CAPTURE_SAT=0; //当前捕获状态 0为等待上升沿 1为等待下降沿

#define SquareLen 10	//方波长度
uint8_t square_counter=0; //方波计数器，每SquareLen个方波为一周
uint32_t PeriodGroup[SquareLen]={0};//存储十个方波周期
double avePeriod=0;
double SpeedSlide[4];//滑动滤波数组
uint8_t SpeedSlideCursor=0;//滑动滤波游标
void addPeriodGroupN(uint32_t capcnt, uint8_t n);
double getAveragePeriod(void);
double SpeedSlideFilter(double value);//滑动滤波函数
double getAveValue(uint32_t* period);

//定时器2中断服务程序	 
void TIM2_IRQHandler(void)
{ 
	//判断是否为捕获中断
 	if (TIM_GetITStatus(TIM2, TIM_IT_CC2) != RESET) //判断是否为捕获中断
	{
		
		TIM2CH2_CAPTURE_VAL= TIM_GetCapture2(TIM2);	//获取当前计数值
		//setTIM2Period(TIM2CH2_CAPTURE_VAL + TIM2CH2_CAPTURE_CNT*65535);	//更新捕获周期
		if(square_counter==SquareLen)
		{
			avePeriod = getAveValue(PeriodGroup);
			//avePeriod=getAveragePeriod();
			setTIM2Period(avePeriod);	//更新捕获周期，60周期方法
			square_counter=0;
		}
		else
		{
			addPeriodGroupN(TIM2CH2_CAPTURE_VAL+TIM2CH2_CAPTURE_CNT*65536, square_counter); //数据添加第square_counter	
			square_counter++;
			
		}
		TIM2CH2_CAPTURE_CNT = 0; //捕获下个上升沿，停止计数
		TIM2CH2_CAPTURE_VAL = 0;	//数据清空准备下次捕捉计数
		//TIM_SetCounter(TIM2,0);

		TIM_ClearITPendingBit(TIM2, TIM_IT_CC2|TIM_IT_Update); //清除中断标志位
		
	}
	//判断是否为更新中断
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
	{
		TIM2CH2_CAPTURE_CNT++;	//溢出次数计数
		if(TIM2CH2_CAPTURE_CNT > 200)
		{
			setTIM2Period(72000000);	//电机停机，上升沿无法捕获,手动置0
		}
		//TIM2CH2_CAPTURE_VAL=0XFFFF;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update); //清除中断标志位
	}
 	

}


void addPeriodGroupN(uint32_t capcnt, uint8_t n)
{
	PeriodGroup[n] = capcnt; //存储数组
}

double getAveragePeriod(void)
{
	double temp = 0;
	uint8_t i;

	for(i=0; i<SquareLen; i++)
	{
		temp += PeriodGroup[i];
	}
	return (temp/(SquareLen));
}

uint32_t getPeriod(uint32_t a)
{
	return PeriodGroup[a]/10;
}

//滑动滤波函数
double SpeedSlideFilter(double value)
{
	double sumTemp;
	uint8_t i=0;
	SpeedSlide[SpeedSlideCursor] = value;
    SpeedSlideCursor++;
    SpeedSlideCursor = (SpeedSlideCursor % 4); //游标循环自加
	for(i=0; i<4; i++)
    {
        sumTemp += SpeedSlide[i];
    }
	return sumTemp/4;
}
double getAveValue(uint32_t* period)
{
	double sum=0,tempAve;
	int i,getOutlier=0;
	for(i=0; i<SquareLen; i++)
	{
		sum += period[i];
	}
	tempAve=sum/10;
	
	for(i=0;i<SquareLen;i++)
	{
		if ((double)period[i]/tempAve>1.5)
		{
			period[i]=0;
			getOutlier=1;
			break;
		}
	}
	
	if(getOutlier==1)
	{
		sum=0;
		
		for(i=0; i<SquareLen; i++)
		{
			sum += period[i];
		}
		return sum/(SquareLen-1);
	}
	else
	{
		return tempAve;
	}
}	
