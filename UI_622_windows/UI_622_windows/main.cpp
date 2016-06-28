#include "mainwindow.h"
#include <QApplication>
#include "keyboard.h"
#include "receiver_thread.h"
#include "uartthread.h"

bool COLLECT_FLAG;
unsigned char uart_torsion[2];//转矩数组
unsigned char uart_speed[2];//转速数组
bool change_flag;
UartThread *uart_ptr;//串口进程

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setOverrideCursor(Qt::BlankCursor);
    change_flag=false;
    MainWindow w;
    QFont font;
    font.setFamily("wenquanyi");//设定字体
    a.setFont(font);//设定生效
    w.show();
//    w.setWindowState(Qt::WindowFullScreen);
    UartThread ut;//串口进程
    uart_ptr=&ut;
    ut.start();
    COLLECT_FLAG=false;
    receiver_thread *t=new receiver_thread;
    QObject::connect(t,SIGNAL(newDataReceived(double,double)),&w,SLOT(getData(double,double)));
    t->start();
    return a.exec();
}
