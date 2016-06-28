
#include "outputconfig.h"
#include "ui_outputconfig.h"
#include <unistd.h>
#include <QDebug>
#include "uartthread.h"
extern UartThread *uart_ptr;

#define COMMENT 0


unsigned int ma_t[20]={0xcd,0x19a,0x266,0x333,0x400,0x4cd,0x59a,0x666,0x733,0x800,0x8cd,0x99a,0xa66,0xb33,0xc00,0xccd,0xd9a,0xe66,0xf33,0xfff};
OutPutConfig::OutPutConfig(QWidget *parent) :

        QWidget(parent),
        ui(new Ui::OutPutConfig)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::NoFocus);
    ui->okbutton->setText(QString::fromUtf8("\u8bbe\u7f6e"));
}

OutPutConfig::~OutPutConfig()
{
    delete ui;
}

void OutPutConfig::resizeEvent(QResizeEvent *)
{
    ui->okbutton->setGeometry(QRect(330*width()/800, 310*height()/450, 151*width()/800, 61*height()/450));
    ui->output_1->setGeometry(QRect(110*width()/800, 80*height()/450, 401*width()/800, 71*height()/450));
    ui->output_2->setGeometry(QRect(110*width()/800, 180*height()/450, 401*width()/800, 71*height()/450));
    ui->label_2->setGeometry(QRect(520*width()/800, 180*height()/450, 181*width()/800, 71*height()/450));
    ui->label_1->setGeometry(QRect(520*width()/800, 80*height()/450, 181*width()/800, 71*height()/450));
}

void OutPutConfig::on_okbutton_clicked()
{
    union{
        int int16;
        char char8[2];
    }data0,data1;
    //char data[2];
    memset(data0.char8,0,2);
    memset(data1.char8,0,2);
    port=new SerialPort;
    port->setPortName(DEVICE);
    if(!port->open(QIODevice::ReadWrite))
    {
        qDebug()<<"open port false when test DAC";
    }
    port->set_opt(QSerialPort::NoFlowControl,QSerialPort::Baud115200,QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop);
//    if(!port->setBlockMode())
//    {
//       printf("fcntl failed when set DAC\n");
//    }
    //data[0]=ui->output_1->currentIndex();
    data0.int16=ui->output_1->currentIndex()*100;
    //data[1]=ui->output_2->currentIndex()+0x20;
    data1.int16=ui->output_1->currentIndex()*100+0x20*100;
    //int n= port->write(&data[0],1);
    int n= port->write(&data0.char8[0],2);
    if(n==1)
       printf("%x\n",data0.int16);
    usleep(100);
    //n= port->write(&data[1],1);
    n= port->write(&data1.char8[0],2);
    if(n==1)
       printf("%x\n",data1.int16);
    port->close();
    delete port;
}
