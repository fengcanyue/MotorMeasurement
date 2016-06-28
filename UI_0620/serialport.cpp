#include "serialport.h"

SerialPort::SerialPort(QObject *parent) :
    QObject(parent),
    _fd(-1)
{
}

bool SerialPort::open(QString _file,int _mode)
{
    _fd=::open(_file.toStdString().c_str(),_mode);
    if(_fd==-1)
        return false;
    return true;
}

void SerialPort::close()
{
    ::close(_fd);
}

int SerialPort::write(void *_buf, int _size)
{
    return ::write(_fd,_buf,_size);
}

int SerialPort::read(void *_buf, int _size)
{
    return ::read(_fd,_buf,_size);
}

int SerialPort::Handle()
{
    return _fd;
}

bool SerialPort::setBlockMode(bool ok)
{
    int ret;
    if(ok)
       ret=fcntl(_fd,F_SETFL,0);//block
    else
       ret=fcntl(_fd,F_SETFL,FNDELAY);//not block
    if(ret<0)
        return false;
    return true;
}

int SerialPort::set_opt(char flow_ctrl, int nSpeed, int nBits, char nEvent, int nStop)
{
    struct termios newtio;
    struct termios oldtio;

    if(tcgetattr(_fd,&oldtio) != 0)
    {
        perror("SetupSerial 1");
        return -1;
    }

    bzero(&newtio,sizeof(newtio));
    newtio.c_cflag |= CLOCAL |CREAD;
    newtio.c_cflag &= ~CSIZE;

    switch(flow_ctrl)
    {
    case 'n':
    case 'N':
        newtio.c_cflag &= (~CRTSCTS);
        newtio.c_iflag &= (~(IXON | IXOFF | IXANY));
        break;

        /*software (XON/XOFF) flow control*/
    case 's':
    case 'S':
        newtio.c_cflag &= (~CRTSCTS);
        newtio.c_iflag |= (IXON | IXOFF | IXANY);
        break;
    case 'h':
    case 'H':
        newtio.c_cflag |= CRTSCTS;
        newtio.c_iflag &= (~(IXON | IXOFF | IXANY));
        break;
    }

/***********数据位选择****************/
    switch(nBits)
    {
        case 7:
        newtio.c_cflag |= CS7;
        break;
        case 8:
        newtio.c_cflag |= CS8;
        break;
    }
/***********校验位选择****************/
    switch(nEvent)
    {
        case 'o':
        case 'O':
        newtio.c_cflag |= PARENB;
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
            break;
        case 'e':
        case 'E':
        newtio.c_iflag |= (INPCK |ISTRIP);
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
            break;
        case 'n':
        case 'N':
        newtio.c_cflag &= ~PARENB;
            break;
    }
/***********波特率选择****************/
    switch(nSpeed)
    {
        case 2400:
        cfsetispeed(&newtio,B2400);
        cfsetospeed(&newtio,B2400);
            break;
         case 4800:
        cfsetispeed(&newtio,B4800);
        cfsetospeed(&newtio,B4800);
            break;
         case 9600:
        cfsetispeed(&newtio,B9600);
        cfsetospeed(&newtio,B9600);
            break;
         case 57600:
        cfsetispeed(&newtio,B57600);
        cfsetospeed(&newtio,B57600);
            break;
         case 115200:
        cfsetispeed(&newtio,B115200);
        cfsetospeed(&newtio,B115200);
            break;
         case 460800:
        cfsetispeed(&newtio,B460800);
        cfsetospeed(&newtio,B460800);
            break;
         default:
        cfsetispeed(&newtio,B9600);
        cfsetospeed(&newtio,B9600);
                break;
    }
/***********停止位选择****************/
    if(nStop == 1){
        newtio.c_cflag &= ~CSTOPB;
    }
    else if(nStop ==2){
        newtio.c_cflag |= CSTOPB;
    }
    newtio.c_cc[VTIME] = 1;
    newtio.c_cc[VMIN] = 1;   //阻塞条件下有效

    tcflush(_fd,TCIFLUSH);
    if((tcsetattr(_fd,TCSANOW,&newtio)) != 0)
    {
        perror("com set error");
        return -1;
    }
    printf("set done!\n");
    return 0;
}
