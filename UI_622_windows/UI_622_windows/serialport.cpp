#include "serialport.h"
#include <QDebug>

//extern unsigned char uart_torsion[2];
//extern unsigned char uart_speed[2];
SerialPort::SerialPort(QObject *parent) :
    QSerialPort(parent)
{
   // connect(_port,SIGNAL(readyRead()),this,SLOT(sendsignal()));
}

bool SerialPort::set_opt(QSerialPort::FlowControl flow_ctrl,QSerialPort::BaudRate nSpeed,QSerialPort::DataBits nBits,QSerialPort::Parity parity,QSerialPort::StopBits nStop)
{
  if(setFlowControl(flow_ctrl)
    && setDataBits(nBits)
    && setParity(parity)
    && setBaudRate(nSpeed)
    && setStopBits(nStop))
      return true;
  else
      return false;
}

