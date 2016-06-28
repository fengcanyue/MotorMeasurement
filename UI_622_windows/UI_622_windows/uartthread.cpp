#include "uartthread.h"
#include <QDebug>
#include <QDateTime>
#include <QApplication>
#include <ras.h>
#include <winbase.h>
#define COMMENT 1
extern unsigned char uart_torsion[2];
extern unsigned char uart_speed[2];
extern bool change_flag;

UartThread::UartThread(QObject *parent) :
    QThread(parent)
{
    setTerminationEnabled(true);//调用terminate,结束线程，线程是否立即终止取决于操作系统。线程被终止时，所有等待该线程Finished的线程都将被唤醒。
}

//将接收到的报文数据转换成整型
int UartThread::translate(char c)
{
    int data;
    data=static_cast<int>(c);//以二进制（位模式）的方式被解释为整型
    if(data>=48 && data <=57)//根据ascii值判断是否接收到了0~9
        data-=48;
    else if(data>=65 && data<=70)//根据ascii值判断是否接收到了A~F
        data-=55;
    else
        data=-1;
    return data;
}

void UartThread::run()
{
    char udata;
    char data[4];
    int cnt=0;
    port=new SerialPort;
    port->setPortName(DEVICE);
    if(!port->open(QIODevice::ReadWrite))
    {
        qDebug()<<"open port false when receive data";
    }
    if(!port->set_opt(QSerialPort::NoFlowControl,QSerialPort::Baud115200,QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop))
    {
       qDebug()<<"config com error";
       qApp->exit(-1);
    }
    while(1)
    {
        if(!port->waitForReadyRead(INT_MAX))
           continue;
        port->read(&udata,1);
        if(udata=='Q')
        {
             while(cnt!=4)
             {
                 if(!port->waitForReadyRead(INT_MAX))
                    continue;
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
                 if(!port->waitForReadyRead(INT_MAX))
                    continue;
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
                  printf("get :%d\n",udata);
                  continue;
        }
//        qDebug()<<udata;
//        qDebug()<<data[0];
//        qDebug()<<data[1];
//        qDebug()<<data[2];
//        qDebug()<<data[3];
        memset(data,0,4);//清空数组内存
        change_flag=true;
    }
}
