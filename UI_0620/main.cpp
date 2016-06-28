#include "mainwindow.h"
#include <QApplication>
#include "keyboard.h"
#include "receiver_thread.h"
#include "uartthread.h"
bool COLLECT_FLAG;
unsigned char uart_torsion[2];
unsigned char uart_speed[2];
bool change_flag;
UartThread *uart_ptr;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setOverrideCursor(Qt::BlankCursor);
    change_flag=false;
    MainWindow w;
    QFont font;
    font.setFamily("wenquanyi");
    a.setFont(font);
    w.show();
//    w.setWindowState(Qt::WindowFullScreen);
    UartThread ut;
    uart_ptr=&ut;
    ut.start();
    COLLECT_FLAG=false;
    receiver_thread *t=new receiver_thread;
    QObject::connect(t,SIGNAL(newDataReceived(double,double)),&w,SLOT(getData(double,double)));
    t->start();
    return a.exec();
}
