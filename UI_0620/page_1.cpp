#include "page_1.h"
#include "ui_page_1.h"

extern bool datest_switch;
extern int timer_period;
extern double speed_test_max;
extern bool COLLECT_FLAG;
Page_1::Page_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_1)
{
    ui->setupUi(this);
    setStyleSheet("background-color:black");
    state=StoppedState;
    setZeroButton=new myButton(this);
    setZeroButton->setText(QString::fromUtf8("\u8F6C\u77E9\u8C03\u96F6"));
    //setZeroButton->setGeometry(width()*600/800,height()*50/450,width()*150/800,height()*100/450);
    //ui->startButton->setText(QString::fromUtf8("开始"));//\u5f00\u59cb
    ui->startButton->setText(QString::fromUtf8("开始"));//\u5f00\u59cb
    //ui->startButton->setStyleSheet("opacity: 0");
    ui->stopButton->setText(QString::fromUtf8("停止"));//\u505c\u6b62
    ui->startButton->setGeometry(width()*350/800,height()*280/450,width()*99/800,height()*41/450);
    ui->stopButton->setGeometry(width()*350/800,height()*370/450,width()*99/800,height()*41/450);
    this->setFocusPolicy(Qt::NoFocus);
    powerWatch=new myWatch(this);
    speedWatch=new myWatch(this);
    torsionWatch=new myWatch(this);
    torsionWatch->setAutoAdjust(false);//
    ui->startButton->raise();
    ui->stopButton->raise();
    torsionWatch->show();
//    speedWatch->setGeometry(-width()/80,height()*180/450,width()*350/800,height()*350/450);
//    torsionWatch->setGeometry(width()*450/800+width()/80,height()*180/450,width()*350/800,height()*350/450);
//    powerWatch->setGeometry((width()-width()/2.5)/2,width()/48,width()/2.5,width()/2.5);
    speedWatch->type=QString::fromUtf8("\u8F6C\u901F");
    torsionWatch->type=QString::fromUtf8("\u8F6C\u77E9");
    powerWatch->type=QString::fromUtf8("\u529F\u7387");
    powerWatch->unit="Kw";
    speedWatch->unit="r/min";
    torsionWatch->unit="Nm";
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(refreshUI()));
    connect(this,SIGNAL(changeTorsion(double)),torsionWatch,SLOT(setValue(double)));
    connect(this,SIGNAL(changeSpeed(double)),speedWatch,SLOT(setValue(double)));
    connect(this,SIGNAL(changePower(double)),powerWatch,SLOT(setValue(double)));
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(startButton_clicked()));
    connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(stopButton_clicked()));
    connect(speedWatch,SIGNAL(maxChanged(double)),this,SLOT(updateMax(double)));
}

Page_1::~Page_1()
{
    delete ui;
}

void Page_1::resizeEvent(QResizeEvent *)
{
//    speedWatch->setGeometry(-width()/80,height()*180/450,width()*350/800,height()*350/450);
//    torsionWatch->setGeometry(width()*450/800+width()/80,height()*180/450,width()*350/800,height()*350/450);
//    powerWatch->setGeometry((width()-width()/2.5)/2,width()/48,width()/2.5,width()/2.5);
    //三个显示表盘位置&大小设置
    speedWatch->setGeometry(-width()/80,height()*172/450,width()*355/800,height()*360/450);
    torsionWatch->setGeometry(width()*450/800+width()/80,height()*172/450,width()*355/800,height()*360/450);
    powerWatch->setGeometry((width()-width()/2.5)/2,width()/57,width()/2.5,width()/2.5);

    ui->startButton->setGeometry(width()*340/800,height()*280/450,width()*120/800,height()*51/450);
    ui->stopButton->setGeometry(width()*340/800,height()*370/450,width()*120/800,height()*51/450);
    setZeroButton->setGeometry(width()*600/800,height()*50/450,width()*120/800,height()*51/450);
}

void Page_1::setTorsionMaxandPeriod(double torsion,double dur)
{
    torsionWatch->setMax(torsion);
    duration=dur*1000;
}

void Page_1::updateMax(double mmm)
{
    powerWatch->setMax(torsionWatch->Max()*mmm/1000);
}

void Page_1::startButton_clicked()
{
    if(timer->isActive())
       return;
    timer->start(400);
    state=StartedState;
    COLLECT_FLAG=true;
}

void Page_1::stopButton_clicked()
{
     timer->stop();
     state=StoppedState;
     COLLECT_FLAG=false;
     resetAll();
     refreshUI();
}

void Page_1::setWatchValues(double torsion, double speed)
{
    if(state==StartedState)
    {
        speed_test_max=speedWatch->max;
        emit changeSpeed(speed);
        emit changeTorsion(torsion);
        double v;
        v=torsion*speed*1.0/9950;
        double power=qAbs(v);
        emit changePower(power);
        ItemType item;   //push collected data to dataStack
        item.power_value=power;
        item.speed_value=speed;
        item.torsion_value=torsion;
        item.speed_max=speedWatch->max;
        item.torsion_max=torsionWatch->max;
        datastack.stack.push(item);
        if(datest_switch)//
        {
          emit getTestData(torsion,speed);
        }
    }
}

void Page_1::resetAll()
{
      torsionWatch->setValue(0);
      speedWatch->setValue(0);
      powerWatch->setValue(0);
}

void Page_1::refreshUI()
{
      torsionWatch->repaint();
      speedWatch->repaint();
      powerWatch->repaint();
}

void Page_1::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        x_init = event->x();    //获取点击时的x坐标
    }
    else if(event->button()==Qt::RightButton){
    }
}

void Page_1::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->x() - x_init > 25){    //若松手时x坐标偏右，则返回主页
        stack->setCurrentIndex(0);
        //qDebug()<<"left";
    }
}

