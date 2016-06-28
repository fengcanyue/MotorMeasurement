#include "receiver_thread.h"
#include <QDebug>
#include <QDir>
#define  BUFFER_SIZE 80
#define  UPDATE_SIZE  2
#define AVE_BUFF_SIZE 10

extern double torsion_test_max;
extern double impulse_num;
extern int timer_period;
extern bool COLLECT_FLAG;
extern unsigned char uart_torsion[2];
extern unsigned char uart_speed[2];
extern bool change_flag;
receiver_thread::receiver_thread(QObject *parent) :
    QThread(parent)
{
    //file.setFileName("/mnt/"/*+QDateTime::currentDateTime().toString("hh_mm_ss")+*/+"data.txt");
    QDir dir;
    dir.cd("/mnt");
    int cnt=dir.count();
    QString fname="/mnt/data"+QString::number(cnt)+".txt";
    QString fname0="/mnt/data_displayed"+QString::number(cnt)+".txt";
    file.setFileName(fname);
    file.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);
    stream.setDevice(&file);
    stream.setCodec("GBK");
    stream<<QString::fromUtf8("\u91C7  \u96C6  \u65F6  \u95F4")<<"        ";
    stream<<QString::fromUtf8("\u8F6C\u77E9")<<"    ";
    stream<<QString::fromUtf8("\u8F6C\u901F")<<"     ";
    stream<<QString::fromUtf8("\u529F\u7387")<<"     "<<QString::fromUtf8("\u8F6C\u901F\u4F20\u611F\u5668\u6BCF\u5708\u8109\u51B2\u6570")<<"\n";
    stream.flush();
    file.flush();

    //data displayed txt
    file0.setFileName(fname);
    file0.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);
    stream0.setDevice(&file);
    stream0.setCodec("GBK");
    stream0<<QString::fromUtf8("\u91C7  \u96C6  \u65F6  \u95F4")<<"        ";
    stream0<<QString::fromUtf8("\u8F6C\u77E9")<<"    ";
    stream0<<QString::fromUtf8("\u8F6C\u901F")<<"     ";
    stream0<<QString::fromUtf8("\u529F\u7387")<<"     "<<QString::fromUtf8("\u8F6C\u901F\u4F20\u611F\u5668\u6BCF\u5708\u8109\u51B2\u6570")<<"\n";
    stream0.flush();
    file0.flush();
}

void receiver_thread::run()
{
    torsion_test_max=0.5;
    while (1) {
        while(!COLLECT_FLAG)
        {
            //do nothing,just wait
            msleep(timer_period);
        }
        double vt,vs,vp;
        if(!change_flag)
        {
            msleep(timer_period);
            continue;
        }
//        vt=(uart_torsion[0]*256+uart_torsion[1]-10000)*1.0*torsion_test_max/5000;
	vt = ((uart_torsion[0]*256+uart_torsion[1])*1.0*torsion_test_max/5000) - 10000*1.0*torsion_test_max/5000;
        vs=(uart_speed[0]*256+uart_speed[1])*1.0*60/impulse_num;
        if(vs==-10)
           vs=0;
        if(vt==-1)
           vt=0;
//        qDebug()<<vt;
//        qDebug()<<vs;
        change_flag=false;
        torsionlist.append(vt);
        speedlist.append(vs);
        vp=qAbs(vt*vs*1.0/9950);
        stream<<QDateTime::currentDateTime().toString("MM-dd hh:mm:ss:zzz ")<<"  ";
        stream<<QString(QString::number(vt)+"           ").left(7)<<"  ";
        stream<<QString(QString::number(vs)+"           ").left(7)<<"  ";
        stream<<QString(QString::number(vp)+"           ").left(7)<<"  ";
        stream<<impulse_num<<"\n";
        stream.flush();
        file.flush();
        if(torsionlist.size()==BUFFER_SIZE)   // data size equals BUFFER_SIZE
        {
             double v1,v2,v3;
             v1=getValue(torsionlist,0.2,0.6,BUFFER_SIZE);
             v2=getValue(speedlist,0.2,0.6,BUFFER_SIZE);
             v3=qAbs(v1*v2*1.0/9950);
             stream0<<QDateTime::currentDateTime().toString("MM-dd hh:mm:ss:zzz ")<<"  ";
             stream0<<QString(QString::number(v1)+"           ").left(7)<<"  ";
             stream0<<QString(QString::number(v2)+"           ").left(7)<<"  ";
             stream0<<QString(QString::number(v3)+"           ").left(7)<<"  ";
             stream0<<impulse_num<<"\n";
             stream0.flush();
             file0.flush();   
             emit newDataReceived(v1,v2);
             torsionlist.clear();
             speedlist.clear();
        } //endif
    }//endwhile
}
