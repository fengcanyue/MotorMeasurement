#ifndef RECEIVER_THREAD_H
#define RECEIVER_THREAD_H

#include <QThread>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#define  KEY  1234
typedef struct {
long type;
unsigned char datagram[8];
}msg_buf;

class receiver_thread : public QThread
{
    Q_OBJECT
public:
    explicit receiver_thread(QObject *parent = 0);
    msg_buf * data;
    QList<double> torsionlist;
    QList<double> speedlist;
    QList<double> torsion_ave_list;
    QList<double> speed_ave_list;
    double torsion_old;
    double speed_old;
    QFile file,file0;
    QTextStream stream,stream0;
    int shmid;
    unsigned char *shmaddr;

signals:
    void newDataReceived(double torsion,double speed);
public slots:
    void run();
    int max(QList<double> L)  //return the index of the max data of the list
    {
        if(L.size()==0)
            return -1;
        int i=0,pos=0;
        double m=L.at(0);
        for(;i<L.size();++i)
            if(m<L.at(i))
            {
                m=L.at(i);
                pos=i;
            }
        return pos;
    }

    int min(QList <double> L)  //return the index of the min data of the list
    {
        if(L.size()==0)
            return -1;
        int i=0,pos=0;
        double m=L.at(0);
        for(;i<L.size();++i)
            if(m>L.at(i))
            {
                m=L.at(i);
                pos=i;
            }
        return pos;
    }
    double getValue(QList <double> L,double l,double r,double total)
    {
        double val[L.size()];
        double a;
        for(int i=0;i<L.size();++i)
           val[i]=L.at(i);
        for(int j=0;j<L.size()-1;++j)
         for(int i=0;i<L.size()-1;++i)
           if(val[i]>val[i+1])
           { 
           	a=val[i+1];
                val[i+1]=val[i];
                val[i]=a;
           }
        a=0;
        for(int i=total*l-1;i<total*r-1;++i)
          a=a+val[i];
        a=a/(total*(r-l));
        return a;
    }
};

#endif // RECEIVER_THREAD_H
