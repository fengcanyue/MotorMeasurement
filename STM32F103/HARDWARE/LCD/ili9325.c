#include "ili9325.h"
#include "ascii.h"
#include "delay.h"  	

typedef struct
{
  vu16 LCD_REG;
  vu16 LCD_RAM;
} LCD_TypeDef;

/* Note: LCD /CS is CE4 - Bank 4 of NOR/SRAM Bank 1~4 */
#define LCD_BASE        ((u32)(0x60000000 | 0x0C000000))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

u16  DeviceCode;
/***************************LCD初始化*******************************/
void LCD_Init(void)
{
	LCD_guanjiao();
	LCD_FSMC();

	DeviceCode = LCD_ReadReg(0x0000);	 //当使用多个LCD时读取设备码并选择

		LCD_WriteReg(0x00E5,0x78F0); 
		LCD_WriteReg(0x0001,0x0100); 
		LCD_WriteReg(0x0002,0x0700); 
		LCD_WriteReg(0x0003,0x1030); 
		LCD_WriteReg(0x0004,0x0000); 
		LCD_WriteReg(0x0008,0x0202);  
		LCD_WriteReg(0x0009,0x0000);
		LCD_WriteReg(0x000A,0x0000); 
		LCD_WriteReg(0x000C,0x0000); 
		LCD_WriteReg(0x000D,0x0000);
		LCD_WriteReg(0x000F,0x0000);
		//power on sequence VGHVGL
		LCD_WriteReg(0x0010,0x0000);   
		LCD_WriteReg(0x0011,0x0007);  
		LCD_WriteReg(0x0012,0x0000);  
		LCD_WriteReg(0x0013,0x0000); 
		LCD_WriteReg(0x0007,0x0000); 
		//vgh 
		LCD_WriteReg(0x0010,0x1690);   
		LCD_WriteReg(0x0011,0x0227);
		delay_ms(100);
		//vregiout 
		LCD_WriteReg(0x0012,0x009D); //0x001b
		delay_ms(100); 
		//vom amplitude
		LCD_WriteReg(0x0013,0x1900);
		delay_ms(100); 
		//vom H
		LCD_WriteReg(0x0029,0x0025); 
		LCD_WriteReg(0x002B,0x000D); 
		//gamma
		LCD_WriteReg(0x0030,0x0007);
		LCD_WriteReg(0x0031,0x0303);
		LCD_WriteReg(0x0032,0x0003);// 0006
		LCD_WriteReg(0x0035,0x0206);
		LCD_WriteReg(0x0036,0x0008);
		LCD_WriteReg(0x0037,0x0406); 
		LCD_WriteReg(0x0038,0x0304);//0200
		LCD_WriteReg(0x0039,0x0007); 
		LCD_WriteReg(0x003C,0x0602);// 0504
		LCD_WriteReg(0x003D,0x0008); 
		//ram
		LCD_WriteReg(0x0050,0x0000); 
		LCD_WriteReg(0x0051,0x00EF);
		LCD_WriteReg(0x0052,0x0000); 
		LCD_WriteReg(0x0053,0x013F);  
		LCD_WriteReg(0x0060,0xA700); 
		LCD_WriteReg(0x0061,0x0001); 
		LCD_WriteReg(0x006A,0x0000); 
		//
		LCD_WriteReg(0x0080,0x0000); 
		LCD_WriteReg(0x0081,0x0000); 
		LCD_WriteReg(0x0082,0x0000); 
		LCD_WriteReg(0x0083,0x0000); 
		LCD_WriteReg(0x0084,0x0000); 
		LCD_WriteReg(0x0085,0x0000); 
		//
		LCD_WriteReg(0x0090,0x0010); 
		LCD_WriteReg(0x0092,0x0600); 
		
		LCD_WriteReg(0x0007,0x0133);
		LCD_WriteReg(0x00,0x0022);//
	
}
/**************************清屏及写入背光颜色**********************/
void LCD_Clear(u16 Color)		  
{
  u32 index = 0;
  ili9325_SetCursor(0,0); 
  LCD_WriteRAM_Prepare(); /* Prepare to write GRAM */

  for(index = 0; index < 76800; index++)
  {
    LCD->LCD_RAM = Color;
  }  
}
/******************************准备向液晶写入数据*********************/
void LCD_WriteRAM_Prepare(void)		   
{
  LCD->LCD_REG = 0x22;
}

/**************************读取LCD注册码**************************************/
u16 LCD_ReadReg(u16 LCD_Reg)				 
{
  LCD->LCD_REG = LCD_Reg;		 //写入16位命令
  LCD->LCD_RAM;
  return (LCD->LCD_RAM);
}
/**************************向LCD中所选的REG写入数据****************************/
void LCD_WriteReg(u8 LCD_Reg, u16 LCD_RegValue)	 
{
  LCD->LCD_REG = LCD_Reg;		//写入寄存器地址
  LCD->LCD_RAM = LCD_RegValue;	//写入数据
}
/**************************向LCD中所选的RAM写入数据****************************/
void LCD_WriteRAM(u16 LCD_RegValue)	 
{
  LCD->LCD_RAM = LCD_RegValue;	//写入数据
}
/******************写入图片**************************************************/
void LCD_WriteBMP( u16 Height, u16 Width, u8 *bitmap)
{
  vu32 index;
  vu32 size = Height * Width;
  u16 *bitmap_ptr = (u16 *)bitmap;

//  LCD_WriteReg(0x03, 0x1038);	  //屏幕左右相反
 
  for(index = 0; index < size; index++)
  {
	LCD->LCD_RAM = (*bitmap_ptr++);
  }
}
/**********************管脚配置**********************************************/
void LCD_guanjiao(void)
{
	u16 a=1000;
	GPIO_InitTypeDef GPIO_InitStructure;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE |
                         RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG ,ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
                                GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | 
                                GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
                                GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | 
                                GPIO_Pin_15;
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_Init(GPIOF, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_Init(GPIOG, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;		  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_ResetBits(GPIOD, GPIO_Pin_11);  //管脚复位
  while(a--);
  GPIO_SetBits(GPIOD, GPIO_Pin_11);
}
/******************************FSMC配置*********************************/
void LCD_FSMC()
{
    FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
    FSMC_NORSRAMTimingInitTypeDef  p; 
    
    
    p.FSMC_AddressSetupTime = 0x02;	 //地址建立时间
    p.FSMC_AddressHoldTime = 0x00;	 //地址保持时间
    p.FSMC_DataSetupTime = 0x05;		 //数据建立时间
    p.FSMC_BusTurnAroundDuration = 0x00;
    p.FSMC_CLKDivision = 0x00;
    p.FSMC_DataLatency = 0x00;
    p.FSMC_AccessMode = FSMC_AccessMode_B;	 // 一般使用模式B来控制LCD
    
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM4;
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
    //FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;
		FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;  
    
    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 
    
    /* 使能 FSMC Bank1_SRAM Bank */
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4, ENABLE);  
}

void ili9325_DisplayStringLine(u8 Line, u8 *ptr, u16 charColor)
{
  u32 i = 0;
  u16 refcolumn = 0;
  while ((*ptr != 0) & (i < 16))
  {
    ili9325_PutChar(refcolumn, Line, *ptr, charColor);
		refcolumn += 20;
    ptr++;
    i++;
 }
}
void LCD_printString(u16 x,u16 y, u8 *ptr, u16 charColor)
{
  u32 i = 0;
  u16 refcolumn = x;
  while ((*ptr != 0) & (i < 120))
  {
    LCD_ShowChar(refcolumn, y, *ptr, charColor);
		refcolumn += 6;
    ptr++;
    i++;
 }
}

/****************************************************************************
* 名    称：void ili9325_PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor)
* 功    能：在指定座标显示一个8x16点阵的ascii字符
* 入口参数：x          列座标
*           y          行座标
*           charColor  字符的颜色
*           bkColor    字符背景颜色
* 出口参数：无
* 说    明：显示范围限定为可显示的ascii码
* 调用方法：ili9325_PutChar(10,10,'a',0x0000,0xffff);
****************************************************************************/
void ili9325_PutChar(u16 x,u16 y,u32 c,u16 charColor)
{
  u16 i=0;
  u16 j=0;
//  u16 z=0;

  u32 tmp_char=0;

  for (i=0;i<40;i++)
  {
    tmp_char  =ascii_8x16[((c-0x20)*120)+(3*i)];
		tmp_char<<=8;
		tmp_char |=ascii_8x16[((c-0x20)*120)+(3*i+1)];
		tmp_char<<=8;
		tmp_char |=ascii_8x16[((c-0x20)*120)+(3*i+2)];
    for (j=0;j<24;j++)
    {
      if ( (tmp_char >> 23-j) & 0x01 == 0x01)
      {
        ili9325_SetPoint(x+j,y+i,charColor); // 字符颜色
      }
    }
  }
}
void LCD_ShowChar(u16 x,u16 y,u32 c, u16 charColor)
{  							  
	u8 temp,t1,t;
	u16 y0=y;
	u8 csize=12;		//得到字体一个字符对应点阵集所占的字节数	
	//设置窗口		   
	c=c-' ';//得到偏移后的值
	for(t=0;t<csize;t++)
	{   
		temp=asc2_1206[c][t]; 	 	//调用1206字体
		for(t1=0;t1<8;t1++)
		{			    
			if(temp&0x80)ili9325_SetPoint(x,y,charColor);
			temp<<=1;
			y++;
			if(x>=320)return;		//超区域了
			if((y-y0)==12)
			{
				y=y0;
				x++;
				if(x>=320)return;	//超区域了
				break;
			}
		}  	 
	}  	
} 
/****************************************************************************
* 名    称：void ili9325_SetPoint(u16 x,u16 y,u16 point)
* 功    能：在指定座标画点
* 入口参数：x      行座标
*           y      列座标
*           point  点的颜色
* 出口参数：无
* 说    明：
* 调用方法：ili9325_SetPoint(10,10,0x0fe0);
****************************************************************************/
void ili9325_SetPoint(u16 x,u16 y,u16 point)
{
  if ( (x>320)||(y>240) ) return;
  ili9325_SetCursor(x,y);

  LCD->LCD_REG=0x22;;
  LCD->LCD_RAM=point;
}
/****************************************************************************
* 名    称：void ili9325_SetCursor(u16 x,u16 y)
* 功    能：设置屏幕座标
* 入口参数：x      行座标
*           y      列座标
* 出口参数：无
* 说    明：
* 调用方法：ili9325_SetCursor(10,10);
****************************************************************************/
__inline void ili9325_SetCursor(u16 x,u16 y)
{
    LCD_WriteReg(0x0020,y);        //行
  	LCD_WriteReg(0x0021,0x13f-x);  //列
}

/****************************************************************************
* 名    称：u16 ili9325_GetPoint(u16 x,u16 y)
* 功    能：获取指定座标的颜色值
* 入口参数：x      行座标
*           y      列座标
* 出口参数：当前座标颜色值
* 说    明：
* 调用方法：i=ili9325_GetPoint(10,10);
****************************************************************************/
u16 ili9325_GetPoint(u16 x,u16 y)
{
  ili9325_SetCursor(x,y);
  if(DeviceCode==0x7783)
    return (LCD_ReadRAM());
  else
   return 
 	(ili9325_BGR2RGB(LCD_ReadRAM()));
}

/****************************************************************************
* 名    称：u16 ili9325_BGR2RGB(u16 c)
* 功    能：RRRRRGGGGGGBBBBB 改为 BBBBBGGGGGGRRRRR 格式
* 入口参数：c      BRG 颜色值
* 出口参数：RGB 颜色值
* 说    明：内部函数调用
* 调用方法：
****************************************************************************/
u16 ili9325_BGR2RGB(u16 c)
{
  u16  r, g, b, rgb;

  b = (c>>0)  & 0x1f;
  g = (c>>5)  & 0x3f;
  r = (c>>11) & 0x1f;
  
  rgb =  (b<<11) + (g<<5) + (r<<0);

  return( rgb );
}

u16 LCD_ReadRAM(void)
{
  vu16 dummy;
  /* Write 16-bit Index (then Read Reg) */
  LCD->LCD_REG = 0x22; /* Select GRAM Reg */
  /* Read 16-bit Reg */
  dummy = LCD->LCD_RAM; 
  return LCD->LCD_RAM;
}


