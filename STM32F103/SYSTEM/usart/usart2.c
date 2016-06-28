#include "usart2.h"
#include "var_space.h"
#include "math.h"

//extern uint32_t TestData;

void Dac1_Set_Vol(u16 vol);
void Dac2_Set_Vol(u16 vol);

//初始化IO 串口2 
//bound:波特率
void uart2_init(u32 bound){
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	//devin:这里是USART2的重映射，上个设计者蛋疼的设计
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);    
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD ,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);   /*重映射指令，属于GPIO操作*/
	
	//USART2_TXUSART2_TX   PD.5
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //PD.5
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
	GPIO_Init(GPIOD, &GPIO_InitStructure); //初始化PD.5
   
	//USART2_RX	  PD.6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; //PD.6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_Init(GPIOD, &GPIO_InitStructure);  //初始化PD.6

	//USART2 NVIC 配置

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置

	USART_InitStructure.USART_BaudRate = bound;//一般设置为9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

	USART_Init(USART2, &USART_InitStructure); //初始化串口
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//接收寄存器满开启中断
	USART_Cmd(USART2, ENABLE);                    //使能串口 
	USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE);

}

//uint16_t R[20]={165,330,495,660,825,990,1155,1320,1485,1650,1815,1980,2145,2310,2475,2640,2805,2970,3135,3300}; //DAC输出表
//uint16_t R[20]={676,693,709,726,742,759,775,792,808,825,841,858,874,891,907,924,940,957,973,990}; //DAC输出表
int RecLen=0;//
union{
	//struct{uint16_t ch1;uint16_t ch2;}ch;
	uint16_t Res_16;
	uint8_t Res_8[2];
	}Res;
float R;
void USART2_IRQHandler(void)                	//串口2中断服务程序
{
	//uint8_t Res;
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)  //接收中断(接收寄存器满中断)0
	{
		
		Res.Res_8[RecLen++]=USART_ReceiveData(USART2);//(USART2->DR);	//读取接收到的数据
		if(RecLen==2)
		{	RecLen=0;		
			if(Res.Res_16<=0x14*100 && Res.Res_16 >0)
			{
				R=Res.Res_16/100.0*165;
				//Dac1_Set_Vol(R[Res - 0x01]); //设定DAC值;
					Dac1_Set_Vol(R); //设定DAC值;
			}
			else if(Res.Res_16>0x20*100 && Res.Res_16<=0x34*100)
			{
				 R=(Res.Res_16-3200)/100.0*165;
				
				//Dac2_Set_Vol(R[Res - 0x21]); //设定DAC值;
				Dac2_Set_Vol(R); //设定DAC值;
			}
			 else if (Res.Res_16==0)
			{
				Dac1_Set_Vol(0); //关闭DAC1
			}
			 else if (Res.Res_16==0x20*100)
			{
				Dac2_Set_Vol(0); //关闭DAC2
			}
		}
	}
	
	if(USART_GetITStatus(USART2, USART_IT_TXE) != RESET) //发送中断(发送寄存器空中断)
	{
		
	}
	
} 


