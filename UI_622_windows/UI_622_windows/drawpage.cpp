#include "drawpage.h"
#include "ui_picture.h"

extern int timer_period;
QList<double> *torsionlist_draw;
QList<double> *speedlist_draw;
QList<double> *powerlist_draw;
DrawPage::DrawPage(QWidget *parent) :
    QWidget(parent)
{
    this->setFocusPolicy(Qt::NoFocus);
    switchButton=new myComboBox(this);
    switchButton->addItem(QString::fromUtf8("\u8F6C\u901F"));
    switchButton->addItem(QString::fromUtf8("\u8F6C\u77E9"));
    switchButton->addItem(QString::fromUtf8("\u529F\u7387"));
    speedpage=new Picture(this);
    Kwpage=new Picture(this);
    Nmpage=new Picture(this);

    torsionlist_draw=&Nmpage->values;
    speedlist_draw=&speedpage->values;
    powerlist_draw=&Kwpage->values;

    switchButton->setGeometry(QRect(width()/36,height()/3,width()*71/800,height()/15));
    speedpage->setGeometry(0,0,width(),height());
    Kwpage->setGeometry(0,0,width(),height());
    Nmpage->setGeometry(0,0,width(),height());
    speedpage->ui->y1Property->addItem(QString::fromUtf8("\u8F6C\u901F r/min"));
    Nmpage->ui->y1Property->addItem(QString::fromUtf8("\u8F6C\u77E9 Nm"));
    Kwpage->ui->y1Property->addItem(QString::fromUtf8("\u529F\u7387 Kw"));
    Kwpage->close();
    Nmpage->close();
    startButton=new  myButton(this);
    startButton->setText(QString::fromUtf8("\u5f00\u59cb"));

    startButton->setGeometry(QRect(10*width()/800,350*height()/450,width()*100/800,height()*60/450));
    startButton->raise();
    timer=new QTimer(this);
    status=STOPPED;
    connect(switchButton,SIGNAL(currentIndexChanged(int)),this,SLOT(changPage(int)));
    connect(startButton,SIGNAL(clicked()),this,SLOT(collectData()));
}

void DrawPage::resizeEvent(QResizeEvent *)
{
    switchButton->setGeometry(QRect(width()/36,height()/3,width()*71/800,height()/15));
    speedpage->setGeometry(0,0,width(),height());
    Kwpage->setGeometry(0,0,width(),height());
    Nmpage->setGeometry(0,0,width(),height());
    switchButton->raise();
    startButton->setGeometry(QRect(10*width()/800,350*height()/450,width()*100/800,height()*60/450));
}

void DrawPage::changPage(int arg)
{
    switch (arg) {
    case 0:
        speedpage->show();
        Nmpage->close();
        Kwpage->close();
        switchButton->raise();
        break;
    case 1:
        speedpage->close();
        Nmpage->show();
        Kwpage->close();
        switchButton->raise();
        break;
    case 2:
        speedpage->close();
        Nmpage->close();
        Kwpage->show();
        switchButton->raise();
        break;
    }
}

void DrawPage::getYmax(QList<qreal> list)
{
    speedpage->yMax=list.at(0);
    Nmpage->yMax=list.at(1);
    Kwpage->yMax=list.at(2);
    speedpage->update();
    Nmpage->update();
    Kwpage->update();
}

void DrawPage::collectData()
{
    if(status==STOPPED)
    {
            startButton->setText(QString::fromUtf8("\u505c\u6b62"));
            status=STARTED;
    }
    else
    {
            startButton->setText(QString::fromUtf8("\u5f00\u59cb"));
            status=STOPPED;
    }
}
