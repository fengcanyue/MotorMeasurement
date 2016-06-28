# MotorMeasurement
电机转速转矩测量系统分两部分：1.基于STM32F103单片机的信号采集模块。2、用Qt编写的界面显示软件
##环境
Keil uVision4   
J-Link ARM  V4.50l驱动

##演示说明
打开MotorMeasurement\STM32F103\USER\test01.uvproj编译并下载程序到板子上  
然后打开上位机QT程序，点击开始，打开电机，即可看到测量数据。

