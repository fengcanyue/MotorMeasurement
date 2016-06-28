#ifndef __VAR_SPACE_H
#define __VAR_SPACE_H
#include "sys.h"

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
uint16_t getTIM3Counter(void);
void clearTIM2Counter(void);
void setTIM2Frequency(uint16_t sumcnt);
uint16_t getTIM2Frequency(void);

void addTIM3Counter(void);
uint16_t getTIM3Counter(void);
void clearTIM3Counter(void);
void setTIM3Frequency(uint16_t sumcnt);
uint16_t getTIM3Frequency(void);

#endif
