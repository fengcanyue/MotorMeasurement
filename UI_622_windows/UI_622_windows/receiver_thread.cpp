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
{//创建文件
    QDir dir;
    dir.mkdir("datafiles");//创建文件夹
    dir.cd("datafiles");//切换到文件夹目录
    int cnt=dir.count();//返回目录中的条目数量
    QString fname="./datafiles/data"+QString::number(cnt)+".txt";//命名格式
    QString fname0="/datafiles/data_displayed"+QString::number(cnt)+".txt";//命名格式

    //数据记录文件
    file.setFileName(fname);//设定文件名并创建文件
    file.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);//以追加模式打开txt文件
    stream.setDevice(&file);
    stream.setCodec("GBK");
    //stream<<QString::fromUtf8("采 集 时 间")<<"        ";
    stream<<QString::fromUtf8("\u91C7  \u96C6  \u65F6  \u95F4")<<"        ";//采  集  时  间
    stream<<QString::fromUtf8("\u8F6C\u77E9")<<"    ";//转矩
    stream<<QString::fromUtf8("\u8F6C\u901F")<<"     ";//转速
    stream<<QString::fromUtf8("\u529F\u7387")<<"     "<<QString::fromUtf8("\u8F6C\u901F\u4F20\u611F\u5668\u6BCF\u5708\u8109\u51B2\u6570")<<"\n";//功率 转速传感器每圈脉冲数
    stream.flush();//刷新
    file.flush();//刷新

    //数据显示文件
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

            msleep(timer_period);//等待
        }
        double vt,vs,vp;
        if(!change_flag)//判断是否接收完串口数据，接收完串口数据后change_flag=true;
        {
            msleep(timer_period);//等待
            continue;
        }
        vt=(uart_torsion[0]*256+uart_torsion[1]-10000)*1.0*torsion_test_max/5000;//频率到转矩的算法
        vs=(uart_speed[0]*256+uart_speed[1])*1.0*60/impulse_num;//频率到转矩的算法，pulse_num为系统设置里每圈脉冲数，默认为60
        if(vs==-10)
           vs=0;
        if(vt==-1)
           vt=0;
//        qDebug()<<vt;
//        qDebug()<<vs;
        change_flag=false;//确定接收的不是上一条报文
        torsionlist.append(vt);//追加到链表
        speedlist.append(vs);//追加到链表
        vp=qAbs(vt*vs*1.0/9950);//计算功率，取绝对值
        stream<<QDateTime::currentDateTime().toString("MM-dd hh:mm:ss:zzz ")<<"  ";
        stream<<QString(QString::number(vt)+"           ").left(7)<<"  ";//left(7)左截7个字符，number（）将数字转成字符串
        stream<<QString(QString::number(vs)+"           ").left(7)<<"  ";
        stream<<QString(QString::number(vp)+"           ").left(7)<<"  ";
        stream<<impulse_num<<"\n";
        stream.flush();
        file.flush();
        if(torsionlist.size()==BUFFER_SIZE)   //转矩链表到达一定长度 80
        {
             double v1,v2,v3;
             v1=getValue(torsionlist,0.2,0.6,BUFFER_SIZE);//去除最大最小部分后取平均
             v2=getValue(speedlist,0.4,0.5,BUFFER_SIZE);
             v2=ExpSmooth(v2);//指数滑动平均
             v3=qAbs(v1*v2*1.0/9950);//求功率
             stream0<<QDateTime::currentDateTime().toString("MM-dd hh:mm:ss:zzz ")<<"  ";
             stream0<<QString(QString::number(v1)+"           ").left(7)<<"  ";
             stream0<<QString(QString::number(v2)+"           ").left(7)<<"  ";
             stream0<<QString(QString::number(v3)+"           ").left(7)<<"  ";
             stream0<<impulse_num<<"\n";
             stream0.flush();
             file0.flush();   
             emit newDataReceived(v1,v2);//发射信号
             torsionlist.clear();
             speedlist.clear(); 
        } //endif
    }//endwhile
}
