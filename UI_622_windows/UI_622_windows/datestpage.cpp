#include "datestpage.h"
#include "ui_datestpage.h"
#include <QDebug>
#include "pdfheaderedit.h"
#include <unistd.h>
extern unsigned int ma_t[20];
extern double torsion_test_max;
extern double speed_test_max;
bool datest_switch;
extern pdfHeaderEdit *pdf;
DATestPage::DATestPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DATestPage)
{
    ui->setupUi(this);
    ui->pushButton->setText(QString::fromUtf8("\u5F00\u59CB\u6D4B\u8BD5"));
    ui->exportCharButton->setText(QString::fromUtf8("\u5BFC\u51FA\u56FE\u8868"));
    timer=new QTimer(this);
    da_index=0;
    maxindex=0; //  0 da_index up,1 da_index down
    _current_torsion=0;
    _current_speed=0;
    connect(timer,SIGNAL(timeout()),this,SLOT(sendmsg()));
    count=0;
    datest_switch=false;
    QFont font;
    font.setFamily("wenquanyi");
    //font.setPointSize(36);
    this->setFont(font);
}

DATestPage::~DATestPage()
{
    delete ui;
}

void DATestPage::on_pushButton_clicked()
{
    if(timer->isActive())
        return;
    datest_switch=true;
    index_list.clear();
    test_torsionlist.clear();
    test_speedlist.clear();
    sendmsg();
    timer->start(PERIOD*60*1000/40);
    ui->label->setText(QString::fromUtf8("\u6B63\u5728\u6D4B\u8BD5"));
}

void DATestPage::sendmsg()
{
    index_list.append(da_index);
    repaint();
    ++count;
    char data[2];
    data[0]=da_index;
    data[1]=0x20;
    port=new SerialPort;
    port->setPortName(DEVICE);
    if(!port->open(QIODevice::ReadWrite))
    {
        qDebug()<<"open port false when test DAC";
    }
    port->set_opt(QSerialPort::NoFlowControl,QSerialPort::Baud115200,QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop);
//    if(!port->setBlockMode())
//    {
//       printf("fcntl failed when test DAC\n");
//    }
    port->write(data,2);
    port->close();
    delete port;
    if(maxindex==1 && da_index==0)
    {
        timer->stop();
        maxindex=0;
        datest_switch=false;
        ui->label->setText(QString::fromUtf8("\u6D4B\u8BD5\u5B8C\u6210"));
    }
    if(da_index==20)
        maxindex=1;
    if(maxindex==1)
        --da_index;
    else
        ++da_index;
}

void DATestPage::appendData(double arg1, double arg2)
{
    _current_torsion=arg1;
    _current_speed=arg2;
}

void DATestPage::resizeEvent(QResizeEvent *)
{
    ui->pushButton->setGeometry(width()*230/800,height()*350/450,width()*161/800,height()*51/450);
    ui->exportCharButton->setGeometry(width()*410/800,height()*350/450,width()*161/800,height()*51/450);
    ui->label->setGeometry(width()*320/800,height()*401/450,width()*161/800,height()*41/450);
}

void DATestPage::paintEvent(QPaintEvent *)
{ 
    test_speedlist.append(_current_speed);
    test_torsionlist.append(_current_torsion);
    QPainter *painter=new QPainter(this);
    double dacwidth=640/39;
    double dacheight=300/10;
    /*********************draw chart box********************************/
    for(int i=0;i<41;++i)
    {
        if(i==0 || i==40)
            painter->setPen(QPen(Qt::black,2.5,Qt::SolidLine));
        else
            painter->setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter->drawLine(QPointF((80+i*dacwidth)*width()/800,40*height()/450),QPointF((80+i*dacwidth)*width()/800,340*height()/450));
    }
    for(int i=0;i<11;++i)
    {
        if(i==0 || i==10)
            painter->setPen(QPen(Qt::black,2.5,Qt::SolidLine));
        else
            painter->setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter->drawLine(QPointF(80*width()/800,(40+i*dacheight)*height()/450),QPoint(720*width()/800,(40+i*dacheight)*height()/450));
    }
    /************************************************************************/
    painter->setPen(QPen(Qt::darkBlue,3,Qt::SolidLine));
    for(int i=0;i<index_list.size();++i)
    {
        painter->drawLine(QPointF((80+i*dacwidth)*width()/800,(340-index_list.at(i)*12)*height()/450),QPointF((80+i*dacwidth+dacwidth-2)*width()/800,(340-index_list.at(i)*12)*height()/450));
    }
    painter->setPen(QPen(Qt::red,3,Qt::SolidLine));
    for(int i=0;i<test_torsionlist.size()-2;++i)
    {
        painter->drawLine(QPointF((80+i*17)*width()/800,(340-qAbs(test_torsionlist.at(i))*300/torsion_test_max)*height()/450),QPointF((80+i*17+17)*width()/800,(340-qAbs(test_torsionlist.at(i+1))*300/torsion_test_max)*height()/450));
    }
    painter->setPen(QPen(Qt::darkGreen,3,Qt::SolidLine));
    for(int i=0;i<test_speedlist.size()-2;++i)
    {
        painter->drawLine(QPointF((80+i*17)*width()/800,(340-qAbs(test_speedlist.at(i))*300/speed_test_max)*height()/450),QPointF((80+i*17+17)*width()/800,(340-qAbs(test_speedlist.at(i+1))*300/speed_test_max)*height()/450));
    }
    /**************************************************************************/
    painter->setPen(QPen(Qt::white,Qt::SolidLine));
    painter->setBrush(QBrush(Qt::white,Qt::SolidPattern));
    painter->drawRect(723*width()/800,0,80*width()/800,height());

    painter->setPen(QPen(Qt::red,Qt::SolidLine));
    for(int i=0;i<11;++i)//left kedu
    {
        painter->drawLine(QPointF(50*width()/800,(340-30*i)*height()/450),QPointF(80*width()/800,(340-30*i)*height()/450));
        painter->drawText(QPointF(5*width()/800,(340-30*i)*height()/450+5),QString::number(torsion_test_max*i/10).left(5));
    }
    painter->drawText(QPointF(5*width()/800,360*height()/450),QString::fromUtf8("\u8F6C\u77E9(Nm)"));
    painter->setPen(QPen(Qt::darkGreen,Qt::SolidLine));
    for(int i=0;i<11;++i)//right kedu
    {
        painter->drawLine(QPointF(720*width()/800,(340-30*i)*height()/450),QPointF(750*width()/800,(340-30*i)*height()/450));
        painter->drawText(QPointF(755*width()/800,(340-30*i)*height()/450+5),QString::number(speed_test_max*i/10).left(5));
    }
    painter->drawText(QPointF(725*width()/800,360*height()/450),QString::fromUtf8("\u8F6C\u901F(r/min)"));
    painter->end();
}

void DATestPage::on_exportCharButton_clicked()
{
    ui->exportCharButton->hide();
    ui->pushButton->hide();
    ui->label->hide();
    QPixmap pix=QPixmap::grabWidget(this,0,20*width()/800,width(),380*height()/450);
    //pix.save("/home/wly/ss.jpg","JPG",100);
    if(pdf->exportDAtestChart(pix))
        ui->label->setText(QString::fromUtf8("\u5BFC\u51FA\u6210\u529F"));
    else
        ui->label->setText(QString::fromUtf8("\u5BFC\u51FA\u5931\u8D25"));
    ui->exportCharButton->show();
    ui->pushButton->show();
    ui->label->show();
}
