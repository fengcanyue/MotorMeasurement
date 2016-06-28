#ifndef MYWATCH_H
#define MYWATCH_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QResizeEvent>
#include <QDebug>
#include <QTimer>
#define POINTER_STEP 20 //
#define MAX_INCRE_SIZE 10 //
extern double torsion_test_max;
class myWatch;
class myWatch : public QWidget
{
    Q_OBJECT
public:
    explicit myWatch(QWidget *parent = 0);
    qreal max;
    QString type;
    QString unit;
    QLabel *valueLabel;
    QTimer *timer;
signals:
    void maxChanged(double);
public slots:
    void paintEvent(QPaintEvent *);
    void paintPointer(QPainter &p);
    void resizeEvent(QResizeEvent *);
    void setValue(double arg){
        if(qAbs(arg)>max && isAutoAdjust())
        {
            while(qAbs(arg)>max)
               max=max*MAX_INCRE_SIZE;
            //repaint();
            emit maxChanged(max);
        }
       /*
        value_new=arg;
        if(value>max)
            value=max;//使当前值不超量程
        while(value!=value_new && value<=max+POINTER_STEP*max/50)
       {
            qreal dv=value_new-value;
            if(dv>0 &&  dv>=POINTER_STEP*max/50)
                value+=POINTER_STEP*max/50;
            else if(dv>0 && dv<POINTER_STEP*max/50)
                value+=dv;
            else if(dv<0 && dv<=-POINTER_STEP*max/50)
                value-=POINTER_STEP*max/50;
            else if(dv<0 && dv>-POINTER_STEP*max/50)
                value+=dv;
            repaint();
       }
      */
      value=arg;
      //repaint();
    }
    void displayValue(double vu);
    bool isAutoAdjust()
    {
        return autoadjust;
    }
    void setAutoAdjust(bool t)
    {
        autoadjust=t;
    }
    void setMax(double m)
    {
        max=m;
    }
    double Max()
    {
        return max;
    }

private:
    qreal value;
    qreal value_new;
    bool autoadjust;//
private slots:


};

#endif // MYWATCH_H
