#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <stdio.h>
#include <QSerialPort>

#define DEVICE "COM2"
class SerialPort : public QSerialPort
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = 0);

signals:
    void datacome();
public slots:
    bool set_opt(QSerialPort::FlowControl flow_ctrl,QSerialPort::BaudRate nSpeed,QSerialPort::DataBits nBits,QSerialPort::Parity parity,QSerialPort::StopBits nStop);
private slots:

private:

};

#endif // SERIALPORT_H
