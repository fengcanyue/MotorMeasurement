#include "var_space.h"

#define DataLen 10	//串口发送报文长度
#define DacLen 5			//DAC接收报文长度
#define TestLen 9

uint8_t getDataLen(void);
uint8_t getDacLen(void);

void setSendState(uint8_t state);
uint8_t getSendState(void);

void setTxData(uint8_t data, uint8_t n);
uint8_t getTxData(uint8_t n);

void setTIM2Period(double capcnt);
uint16_t getTIM2Period(void);

void setTIM3Period(uint32_t capcnt);
uint16_t getTIM3Period(void);

void addTIM2Counter(void);
uint16_t getTIM2Counter(void);
void clearTIM2Counter(void);
void setTIM2Frequency(uint16_t sumcnt);
uint16_t getTIM2Frequency(void);

void addTIM3Counter(void);
uint16_t getTIM3Counter(void);
void clearTIM3Counter(void);
void setTIM3Frequency(uint16_t sumcnt);
uint16_t getTIM3Frequency(void);

//发送状态 1：单次发送  2：连续发送
uint8_t sendState = 0;
//发送数据数组
uint8_t TxData[DataLen] = {0};
//TIM2周期
uint16_t TIM2Period = 0;
//TIM3周期
uint16_t TIM3Period = 0;
//TIM2频率计数器
uint16_t TIM2Counter = 0;
//TIM3频率计数器
uint16_t TIM3Counter = 0;
//TIM2频率
uint16_t TIM2Frequency = 0;
//TIM3频率
uint16_t TIM3Frequency = 0;

//测试数据
uint32_t TestData = 0;

//获取发送数据长度
uint8_t getDataLen(void)
{
	return DataLen;
}

/***********************************************************/
//获取DAC数据长度
uint8_t getDacLen(void)
{
	return DacLen;
}

/***********************************************************/
//发送状态
void setSendState(uint8_t state)
{
	sendState = state;
}


uint8_t getSendState(void)
{
	return sendState;
}

/***********************************************************/
//发送数组
void setTxData(uint8_t data, uint8_t n)
{
	if(n<DataLen){
		TxData[n] = data;
	}
}

uint8_t getTxData(uint8_t n)
{
	if(n<DataLen){
		return TxData[n];
	}
	else return 0x55;
}

/***********************************************************/
//TIM2捕获周期
void setTIM2Period( double capcnt)
{
	
 	TIM2Period = (uint16_t)((72000000-1 )/capcnt); //计数频率
	//做了修正
	if(TIM2Period<480)
	TIM2Period =TIM2Period;	
}
//低频 测周期法
uint16_t getTIM2Period(void)
{
	return TIM2Period;
}

/***********************************************************/
//TIM3捕获周期
void setTIM3Period(uint32_t capcnt)
{
 	TIM3Period = (72000000-1) / capcnt; //计数频率
}
//低频 测周期法
uint16_t getTIM3Period(void)
{
	return TIM3Period;
}

/***********************************************************/
//TIM2捕获频率
void addTIM2Counter(void)
{
 	TIM2Counter ++; //计数频率
}

uint16_t getTIM2Counter(void)
{
 	return TIM2Counter;
}

void clearTIM2Counter(void)
{
	TIM2Counter = 0; //清零计数器
}

void setTIM2Frequency(uint16_t sumcnt)
{
 	TIM2Frequency = sumcnt;
}
//高频 测频率法
uint16_t getTIM2Frequency(void)
{
	return TIM2Frequency;
}

/***********************************************************/
//TIM3捕获频率
void addTIM3Counter(void)
{
 	++TIM3Counter ; //计数频率
}

uint16_t getTIM3Counter(void)
{
 	return TIM3Counter;
}

void clearTIM3Counter(void)
{
	TIM3Counter = 0; //清零计数器
}

void setTIM3Frequency(uint16_t sumcnt)
{
 	TIM3Frequency = sumcnt;
}
//高频 测频率法
uint16_t getTIM3Frequency(void)
{
	return TIM3Frequency;
}

