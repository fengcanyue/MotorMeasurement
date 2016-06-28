#include "picture.h"
#include "ui_picture.h"

extern QList<qreal> yvalue;
Picture::Picture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Picture)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::NoFocus);
    ui->y1Property->setFocusPolicy(Qt::NoFocus);
    ui->xRange->setFocusPolicy(Qt::TabFocus);
    label=new QLabel(this);
    QFont font(QString::fromUtf8("\u6977\u4F53"),15);
    label->setFont(font);
    label->setStyleSheet("color:red");
    yMax=1;
}

Picture::~Picture()
{
    delete ui;
}

void Picture::resizeEvent(QResizeEvent *)
{
    ui->y1Property->setGeometry(QRect(width()/36,height()/3,width()*71/800,height()/15));
    ui->xRange->setGeometry(QRect(width()/36,height()*2/3,width()*71/800,height()/15));
}

void Picture::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(-10,-10,width()+20,height()+20);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    double xUnit,yUnit;
    yUnit=height()*8/100;
    xUnit=(width()-width()/4.8-width()/36)/10;

    //picture
    label->setText(ui->y1Property->currentText()+"\n"+QString::fromUtf8("\u65f6\u95f4:s"));
    label->setGeometry(width()*0.88,height()/7.5,width()/12,height()/10);
    // Y 轴
    for(int i=0;i<11;++i)
    {
       painter.drawLine(QPointF(width()/4.8,height()/8+i*yUnit),QPointF(width()/4.8+10*xUnit,height()/8+i*yUnit));
       painter.drawText(QRect(width()/4.8-5-QVariant(yMax-i*yMax/10).toString().length()*10,height()/8+i*yUnit-3,QVariant(yMax-i*yMax/10).toString().length()*10,15),Qt::AlignRight,QVariant(yMax-i*yMax/10).toString());
    }
    // X轴
    for(int i=0;i<11;++i)
    {
       painter.drawLine(QPointF(width()/4.8+i*xUnit,height()/8),QPointF(width()/4.8+i*xUnit,height()/8+10*yUnit));
       painter.drawText(QPointF(width()/4.8-5+i*xUnit,height()/8+10*yUnit+10),QVariant(i*ui->xRange->currentText().toInt()/10).toString());
    }

    pen.setColor(Qt::blue);
    painter.setPen(pen);
  //  painter.drawLine(QPointF(ui->horizontalSlider->value()+width()/4.8,height()/8),QPointF(ui->horizontalSlider->value()+width()/4.8,height()/8+10*yUnit));
    painter.setPen(QPen(Qt::red,3,Qt::SolidLine));
    painter.setRenderHints(QPainter::Antialiasing);
    drawDataLine(painter,xUnit,yUnit);
}

void Picture::drawDataLine(QPainter &p,double dx,double dy)
{
    double xMax=ui->xRange->currentText().toDouble();
    xunit=dx*10/xMax;
    yunit=dy*10/yMax;
    double zeroLine=height()/8+10*dy;
    int j,i=0;
    j=values.size()-xMax-1;
    if(j<0)
        j=0;
    for(;j<values.size()-1;++i,++j)
        p.drawLine(QPointF(width()/4.8+i*xunit,zeroLine-qAbs(values.at(j))*yunit),QPointF(width()/4.8+(i+1)*xunit,zeroLine-qAbs(values.at(j+1))*yunit));
}

void Picture::on_y1Property_currentIndexChanged(int)
{
    repaint();
}

void Picture::keyPressEvent(QKeyEvent *)
{

}

void Picture::on_xRange_currentIndexChanged(int)
{
    repaint();
}

void Picture::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        x_init = event->x();
    }
    else if(event->button()==Qt::RightButton){
    }
}

void Picture::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->x() - x_init > 25){
        stack->setCurrentIndex(0);
    }
}
