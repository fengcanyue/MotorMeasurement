#ifndef UARTTHREAD_H
#define UARTTHREAD_H

#include <QObject>
#include <QThread>
#include "serialport.h"

class UartThread : public QThread
{
    Q_OBJECT
public:
    explicit UartThread(QObject *parent = 0);
    SerialPort *port;

signals:
public slots:
    void run();
    int translate(char c);
private:
 //   char data[4];
  //  char udata;
 //   int cnt;
 };

#endif // UARTTHREAD_H
