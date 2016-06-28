#include "led.h" 

//初始化PE.2和PE.3为输出口.并使能这两个口的时钟		    
//LED IO初始化				  
//stm32f107 LED0:PE2 LED1:PE3 
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE , ENABLE);	 //使能PE 端口时钟
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				 //LED0-->PE.2 端口配置
 GPIO_Init(GPIOE, &GPIO_InitStructure);					 //根据设定参数初始化GPIOE.2
 GPIO_SetBits(GPIOE,GPIO_Pin_2);						 //PE.2 输出高

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	    		 //LED1-->PE.3 端口配置, 推挽输出
 GPIO_Init(GPIOE, &GPIO_InitStructure);	  				 //根据设定参数初始化GPIOE.3
 GPIO_SetBits(GPIOE,GPIO_Pin_3); 						 //PE.3 输出高 
}
 
