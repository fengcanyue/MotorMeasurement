#include "uartthread.h"
#include <QDebug>
#include <QDateTime>
#include <QApplication>

#define COMMENT 0
extern unsigned char uart_torsion[2];
extern unsigned char uart_speed[2];
extern bool change_flag;

UartThread::UartThread(QObject *parent) :
    QThread(parent)
{
    setTerminationEnabled(true);
}

int UartThread::translate(char c)
{
    int data;
    data=static_cast<int>(c);
    if(data>=48 && data <=57)
        data-=48;
    else if(data>=65 && data<=70)
        data-=55;
    else
        data=-1;
    return data;
}

void UartThread::run()
{
    port=new SerialPort;
    if(!port->open("/dev/ttyAMA0",O_RDWR|O_NOCTTY|O_NDELAY))
    {
        qDebug()<<"uart open false when receive data";
        qApp->exit();
    }
    port->set_opt('N',115200,8,'N',1);
    if(!port->setBlockMode())
    {
       printf("fcntl failed when receive data\n");
    }
    char udata;
    char data[4];
    int cnt=0;
    memset(data,0,4);
    while(1)
    {
        port->read(&udata,1);
        if(udata=='Q')
        {
           // read(fd,data,4);
                 while(cnt!=4)
        	 {
                 port->read(&data[cnt],1);
            	 ++cnt;
       		} 
               cnt=0;
            uart_torsion[0]=translate(data[0])*16+translate(data[1]);
            uart_torsion[1]=translate(data[2])*16+translate(data[3]);
        }
        else if(udata=='P')
        {
                 while(cnt!=4)
       		 {
                 port->read(&data[cnt],1);
            	 ++cnt;
      		 } 
               cnt=0;
           // read(fd,data,4);
            uart_speed[0]=translate(data[0])*16+translate(data[1]);
            uart_speed[1]=translate(data[2])*16+translate(data[3]);
        }
        else
        {
                  printf("get :%c\n",udata);
                  continue;
        }
#if COMMENT
        printf("%c\n",udata);
        printf("%c\n",data[0]);
        printf("%c\n",data[1]);
        printf("%c\n",data[2]);
        printf("%c\n",data[3]);
#endif
        memset(data,0,4);
        change_flag=true;
    }
}
