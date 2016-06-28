#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <stdio.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = 0);

signals:

public slots:
    int set_opt(char flow_ctrl, int nSpeed, int nBits, char nEvent, int nStop);
    bool open(QString _file,int _mode);
    void close();
    int read(void *_buf, int _size);
    int write(void *_buf, int _size);
    int Handle();
    bool setBlockMode(bool ok=true);
private:
    int _fd;
};

#endif // SERIALPORT_H
