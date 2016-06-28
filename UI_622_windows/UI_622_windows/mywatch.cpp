#include "mywatch.h"

myWatch::myWatch(QWidget *parent) :
    QWidget(parent)
{
    this->resize(200,200);
    setFocusPolicy(Qt::NoFocus);
    max=1;
    value=0;
    value_new=0;
    valueLabel=new QLabel(this);
    valueLabel->setGeometry(width()*9/32,width()/2+2,width()*14/32,width()/10);
    valueLabel->setStyleSheet(" background-color:gray;\n color:red");
    valueLabel->setAlignment(Qt::AlignLeft);
    setAutoAdjust(true);
    timer=new QTimer;
    //timer->start(200);
    //connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
}

void myWatch::resizeEvent(QResizeEvent *)
{
        repaint();
        valueLabel->setGeometry(width()*9/32,width()/2+2,width()*14/32,width()/10);
}

void myWatch::paintPointer(QPainter &p)
{
    QFont font3(QString::fromUtf8("\u5B8B\u4F53"),width()/20);
    p.setPen(QPen(Qt::red));
    p.setBrush(QBrush(Qt::red));
    if(value<=max)
    {
        p.drawPie(width()/20+width()*15/800,width()/20+width()*15/800,width()-width()/10-width()*30/800,width()-width()/10-width()*30/800,200*16-qreal(value/max)*220*16,1*16);
        displayValue(value);
    }
    else
    {
        p.drawPie(width()/20+width()*15/800,width()/20+width()*15/800,width()-width()/10-width()*30/800,width()-width()/10-width()*30/800,200*16-qreal(max/max)*220*16,1*16);
        valueLabel->setText("XXXXX");
    }
    p.setPen(QPen(Qt::green));
    p.setBrush(QBrush(Qt::black));
    //画黑心绿圆
    p.drawEllipse(QPointF(width()/20+(width()-width()/10)/2,width()/20+(width()-width()/10)/2),width()/4,width()/4);
    p.setBrush(QBrush(Qt::green));
    //画绿线
    p.drawLine(QPointF(width()/20+(width()-width()/10)/2-width()/4,width()/20+(width()-width()/10)/2),QPointF(width()/20+(width()-width()/10)/2+width()/4,width()/20+(width()-width()/10)/2));
    p.setFont(font3);
    p.drawText(QRect(width()*3/8,width()/2-width()/6+2,width()/4,width()/10),Qt::AlignCenter,type);
    p.drawText(QRect(width()*3/8,width()/2+width()/10+2,width()/4,width()/10),Qt::AlignCenter,unit);
}

void myWatch::paintEvent(QPaintEvent *)
{
    QFont font;
    font.setPointSize(width()/30);
    font.setBold(true);
    QFont font2;
   // font.setFamily("wenquanyi");
   // font2.setFamily("wenquanyi");
    font2.setPointSize(width()/35);
    font2.setBold(true);
    valueLabel->setFont(font);
    valueLabel->setAlignment(Qt::AlignCenter);
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
   // painter.drawRect(0,0,width(),height());
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::blue));
    painter.setBrush(QBrush(Qt::blue));
    // 蓝外圈
    double dx,dy;
    dx=dy=width()/20;
    double circle1_d=width()-2*dx;
    painter.drawArc(dx,dy,circle1_d,circle1_d,-20*16,220*16);
    painter.setBrush(QBrush());
    painter.setPen(QPen(Qt::yellow));
    for(int i=0;i<11;++i)
    {
        //画长刻度
        painter.drawPie(dx+width()*100/800,dy+width()*100/800,width()-width()/10-width()*200/800,width()-width()/10-width()*200/800,200*16-22*16*i,0);
    }
    for(int i=0;i<50;++i)
    {
        //画短刻度
        painter.drawPie(dx+width()*130/800,dy+width()*130/800,width()-width()/10-width()*260/800,width()-width()/10-width()*260/800,200*16-4.4*16*i,0);
    }
    painter.setBrush(QBrush(Qt::black));
    painter.setPen(QPen(Qt::black));
    //画黑圆
    painter.drawEllipse(QPointF(width()/20+(width()-width()/10)/2,width()/20+(width()-width()/10)/2),width()/3.8,width()/3.8);
    paintPointer(painter);
    painter.setPen(QPen(Qt::white));
    painter.setFont(font2);
        QString a1,a2,a3,a4;
        int max_x=max*1000;
        switch(max_x)
        {
        case 1:
            a1="0.0001";
            a2="0.0005";
            a3="0.0009";
            a4="0.001";
            break;
        case 2:
            a1="0.0002";
            a2="0.001";
            a3="0.0018";
            a4="0.002";
            break;
        case 5:
            a1="0.0005";
            a2="0.0025";
            a3="0.0045";
            a4="0.005";
            break;
        case 10:
            a1="0.001";
            a2="0.005";
            a3="0.009";
            a4="0.01";
            break;
        case 20:
            a1="0.002";
            a2="0.01";
            a3="0.018";
            a4="0.02";
            break;
        case 50:
            a1="0.005";
            a2="0.025";
            a3="0.045";
            a4="0.05";
            break;
        case 100:
            a1="0.01";
            a2="0.05";
            a3="0.09";
            a4="0.1";
            break;
        case 200:
            a1="0.02";
            a2="0.1";
            a3="0.18";
            a4="0.2";
            break;
        case 500:
            a1="0.05";
            a2="0.25";
            a3="0.45";
            a4="0.5";
            break;
        default:
            a1=QVariant(max*0.1).toString();
            a2=QVariant(max*0.5).toString();
            a3=QVariant(max*0.9).toString();
            a4=QVariant(max).toString();
            break;
        }
        if(a4.length()>5)
        {
            a1=a1.left(a1.length()-3)+"k";
            a2=a2.left(a2.length()-3)+"k";
            a3=a3.left(a3.length()-3)+"k";
            a4=a4.left(a4.length()-3)+"k";
        }
        painter.drawText(QPointF(dx+(width()-width()/10)/2-(width()-width()/8)/2,width()/20+(width()-width()/10)/2),a1.left(6));
        painter.drawText(QPointF(dx+(width()-width()/10)/2+(width()-width()/10-width()*200/800)/2+width()/50,width()/20+(width()-width()/10)/2),a3.left(6));
        painter.drawText(QPointF(dx+(width()-width()/10)/2-a2.length()*3,width()/20+(width()-width()/10)/2-(width()-width()/4.3)/2),a2.left(6));
        painter.drawText(width()*8/10+width()/50,width()*6.5/10,a4.left(6));
        painter.drawText(width()*1/10,width()*6.5/10,"0");
}

void myWatch::displayValue(double vu)
{
        valueLabel->setText(QVariant(vu).toString().left(7));
        //qDebug()<<"gagagagdjhdkashdu";
        //qDebug()<<vu.toString();
}
