#include "pdfheaderedit.h"
#include "ui_pdfheaderedit.h"
#include "drawpage.h"
#include <QDir>

pdfHeaderEdit::pdfHeaderEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pdfHeaderEdit)
{
    ui->setupUi(this);
    ui->logo->setGeometry(40*width()/800,height()*60/450,155*width()/800,101*height()/450);
    ui->check1->setGeometry(width()*80/720,height()*300/450,width()*80/720,height()*30/450);
    ui->check2->setGeometry(width()*300/720,height()*300/450,width()*80/720,height()*30/450);
    ui->check3->setGeometry(width()*520/720,height()*300/450,width()*80/720,height()*30/450);
    ui->verticalLayoutWidget_2->setGeometry(width()/18*10,5+height()/9,width()/10,height()/4.5);
    ui->verticalLayoutWidget_3->setGeometry(width()/1.53,5+height()/9,width()/4,height()/4.5);
    ui->verticalLayoutWidget->setGeometry(width()/4,5+height()/9,width()/4,height()/4.5);
    ui->horizontalLayoutWidget->setGeometry(width()/12,height()/9*4,width()*5/6,height()/9);
    ui->label->setGeometry(width()/24,height()*50/450,width()*11/12,height()*121/450);
    ui->label_8->setGeometry(width()/24,height()*2/5,width()*11/12,height()*171/450);
    ui->exportButton->setGeometry(width()*250/800,height()*360/450,width()*131/800,height()*51/450);
    ui->exportDataChartButton->setGeometry(width()*400/800,height()*360/450,width()*131/800,height()*51/450);
    ui->ret->setGeometry(250*width()/800,410*height()/450,281*width()/800,31*height()/450);
    ui->check1->flag=1;
    ui->check2->flag=1;
    ui->check3->flag=1;
    QPixmap pix(":/new/prefix1/logo.jpg");
    ui->logo->setPixmap(pix);
    connect(ui->exportDataChartButton,SIGNAL(clicked()),this,SLOT(exportDataChart()));
    QDir dir;
    dir.mkdir("pdffiles");
}

pdfHeaderEdit::~pdfHeaderEdit()
{
    delete ui;
}

void pdfHeaderEdit::on_exportButton_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("./pdffiles/"+QDateTime::currentDateTime().toString("MMdd-hh-mm-ss")+"picture.pdf");
    printer.setPageSize(QPrinter::A4);
    QPainter painter;
    painter.begin(&printer);
    QFont titlefont(QString::fromUtf8("\u9ed1\u4f53"),20);
    QFont textfont(QString::fromUtf8("\u5b8b\u4f53"),12);
    painter.setFont(titlefont);
    painter.drawText(200,50,ui->companyEdit->text());
    painter.setFont(textfont);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLine(QPointF(20,100),QPointF(700,100));
    painter.drawText(50,120,QString::fromUtf8("\u7535\u8bdd:")+ui->telEdit->text());
    painter.drawText(400,120,QString::fromUtf8("\u4f20\u771f:")+ui->faxEdit->text());
    painter.drawText(50,140,QString::fromUtf8("\u7535\u5b50\u4fe1\u7bb1:")+ui->mailEdit->text());
    painter.drawText(400,140,QString::fromUtf8("\u7f51\u5740:")+ui->websiteEdit->text());
    painter.drawLine(QPointF(20,150),QPointF(700,150));
    painter.drawText(50,170,QString::fromUtf8("\u89c4\u683c:")+ui->sizeEdit->text());
    painter.drawText(300,170,QString::fromUtf8("\u578b\u53f7:")+ui->typeNoEdit->text());
    painter.drawText(550,170,QString::fromUtf8("\u7f16\u53f7:")+ui->NoEdit->text());
    painter.drawText(50,200,QString::fromUtf8("\u64cd\u4f5c\u5458\u5de5\u53f7:")+employeeNo);
    painter.drawText(550,200,QString::fromUtf8("\u65f6\u95f4:")+QDate::currentDate().toString("yyyy-MM-dd"));
    painter.drawLine(QPointF(20,210),QPointF(700,210));
    QStackedWidget *wid=(QStackedWidget*)parentWidget();
    int ww=wid->widget(2)->width();
    int hh=wid->widget(2)->height();
    DrawPage *dp=(DrawPage *)wid->widget(2);
    int hlevel=0;
    painter.drawPixmap(20,20,150,70,*ui->logo->pixmap());
    if(ui->check1->isChecked())
    {
        QPixmap pix=QPixmap::grabWidget(dp->speedpage,QRect(ww/36+ww/8,hh/9,ww-ww/36-ww/8,hh-hh/9-hh/23));
        QPixmap newpix=pix.scaled(QSize(500,280),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        painter.drawPixmap(QPointF(120,230),newpix);
        hlevel++;
    }
    if(ui->check2->isChecked())
    {
        QPixmap pix=QPixmap::grabWidget(dp->Nmpage,QRect(ww/36+ww/8,hh/9,ww-ww/36-ww/8,hh-hh/9-hh/23));
        QPixmap newpix=pix.scaled(QSize(500,280),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        painter.drawPixmap(QPointF(120,230+hlevel*285),newpix);
        hlevel++;
    }
    if(ui->check3->isChecked())
    {
        QPixmap pix=QPixmap::grabWidget(dp->Kwpage,QRect(ww/36+ww/8,hh/9,ww-ww/36-ww/8,hh-hh/9-hh/23));
        QPixmap newpix=pix.scaled(QSize(500,280),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        painter.drawPixmap(QPointF(120,230+hlevel*285),newpix);
    }
    if(painter.end())
        ui->ret->setText(QString::fromUtf8("\u5199\u5165\u6210\u529F"));
    else
        ui->ret->setText(QString::fromUtf8("\u5199\u5165\u5931\u8D25"));
    ui->subTitleEdit->clear();
    ui->NoEdit->clear();
    ui->typeNoEdit->clear();
    ui->sizeEdit->clear();
}

void pdfHeaderEdit::exportDataChart()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("./pdffiles/"+QDateTime::currentDateTime().toString("MMdd-hh-mm-ss")+"data.pdf");
    printer.setPageSize(QPrinter::A4);
    QPainter painter;
    painter.begin(&printer);
    newpage:QFont titlefont(QString::fromUtf8("\u9ed1\u4f53"),20);
    QFont textfont(QString::fromUtf8("\u5b8b\u4f53"),12);
    painter.setFont(titlefont);
    painter.drawText(200,50,ui->companyEdit->text());
    painter.setFont(textfont);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLine(QPointF(20,100),QPointF(700,100));
    painter.drawText(50,120,QString::fromUtf8("\u7535\u8bdd:")+ui->telEdit->text());
    painter.drawText(400,120,QString::fromUtf8("\u4f20\u771f:")+ui->faxEdit->text());
    painter.drawText(50,140,QString::fromUtf8("\u7535\u5b50\u4fe1\u7bb1:")+ui->mailEdit->text());
    painter.drawText(400,140,QString::fromUtf8("\u7f51\u5740:")+ui->websiteEdit->text());
    painter.drawLine(QPointF(20,150),QPointF(700,150));
    painter.drawText(50,170,QString::fromUtf8("\u89c4\u683c:")+ui->sizeEdit->text());
    painter.drawText(300,170,QString::fromUtf8("\u578b\u53f7:")+ui->typeNoEdit->text());
    painter.drawText(550,170,QString::fromUtf8("\u7f16\u53f7:")+ui->NoEdit->text());
    painter.drawText(50,200,QString::fromUtf8("\u64cd\u4f5c\u5458\u5de5\u53f7:")+employeeNo);
    painter.drawText(550,200,QString::fromUtf8("\u65f6\u95f4:")+QDate::currentDate().toString("yyyy-MM-dd"));
    painter.drawLine(QPointF(20,210),QPointF(700,210));
    painter.drawText(60,260,QString::fromUtf8("\u8F6C\u77E9(Nm)"));
    painter.drawText(180,260,QString::fromUtf8("\u8F6C\u901F(r/min)"));
    painter.drawText(300,260,QString::fromUtf8("\u529F\u7387(Kw)"));
    painter.drawText(400,260,QString::fromUtf8("\u8F6C\u77E9\u91CF\u7A0B(Nm)"));
    painter.drawText(555,260,QString::fromUtf8("\u8F6C\u901F\u91CF\u7A0B(r/min)"));
    painter.drawPixmap(20,20,150,70,*ui->logo->pixmap());
    ItemType item;
    int i=1;
    int count=0;
    while(!data2print.stack.isEmpty() && count<100)
    {
        item=data2print.stack.pop();
        if(260+20*i>1000)
        {
            printer.newPage();
            goto newpage;
        }
        painter.drawText(60,260+20*i,QVariant(item.torsion_value).toString());
        painter.drawText(180,260+20*i,QVariant(item.speed_value).toString());
        painter.drawText(300,260+20*i,QVariant(item.power_value).toString());
        painter.drawText(400,260+20*i,QVariant(item.torsion_max).toString());
        painter.drawText(555,260+20*i,QVariant(item.speed_max).toString());
        ++i;
        ++count;
    }
    data2print.stack.clear();
    if(painter.end())
        ui->ret->setText(QString::fromUtf8("\u5199\u5165\u6210\u529F"));
    else
        ui->ret->setText(QString::fromUtf8("\u5199\u5165\u5931\u8D25"));
}

bool pdfHeaderEdit::exportDAtestChart(QPixmap p)
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("./pdffiles/"+QDateTime::currentDateTime().toString("MMdd-hh-mm-ss")+"datest.pdf");
    printer.setPageSize(QPrinter::A4);
    QPainter painter;
    painter.begin(&printer);
    QFont titlefont(QString::fromUtf8("\u9ed1\u4f53"),20);
    QFont textfont(QString::fromUtf8("\u5b8b\u4f53"),12);
    painter.setFont(titlefont);
    painter.drawText(200,50,ui->companyEdit->text());
    painter.setFont(textfont);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLine(QPointF(20,100),QPointF(700,100));
    painter.drawText(50,120,QString::fromUtf8("\u7535\u8bdd:")+ui->telEdit->text());
    painter.drawText(400,120,QString::fromUtf8("\u4f20\u771f:")+ui->faxEdit->text());
    painter.drawText(50,140,QString::fromUtf8("\u7535\u5b50\u4fe1\u7bb1:")+ui->mailEdit->text());
    painter.drawText(400,140,QString::fromUtf8("\u7f51\u5740:")+ui->websiteEdit->text());
    painter.drawLine(QPointF(20,150),QPointF(700,150));
    painter.drawText(50,170,QString::fromUtf8("\u89c4\u683c:")+ui->sizeEdit->text());
    painter.drawText(300,170,QString::fromUtf8("\u578b\u53f7:")+ui->typeNoEdit->text());
    painter.drawText(550,170,QString::fromUtf8("\u7f16\u53f7:")+ui->NoEdit->text());
    painter.drawText(50,200,QString::fromUtf8("\u64cd\u4f5c\u5458\u5de5\u53f7:")+employeeNo);
    painter.drawText(550,200,QString::fromUtf8("\u65f6\u95f4:")+QDate::currentDate().toString("yyyy-MM-dd"));
    painter.drawLine(QPointF(20,210),QPointF(700,210));
    painter.drawPixmap(20,20,150,70,*ui->logo->pixmap());
    QPixmap newp=p.scaled(QSize(700,p.height()),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    painter.drawPixmap(20,230,newp.width(),newp.height(),newp);
    return painter.end();
}

void pdfHeaderEdit::resizeEvent(QResizeEvent *)
{
    ui->logo->setGeometry(40*width()/800,height()*60/450,155*width()/800,101*height()/450);
    ui->check1->setGeometry(width()*80/720,height()*300/450,width()*80/720,height()*30/450);
    ui->check2->setGeometry(width()*300/720,height()*300/450,width()*80/720,height()*30/450);
    ui->check3->setGeometry(width()*520/720,height()*300/450,width()*80/720,height()*30/450);
    ui->verticalLayoutWidget_2->setGeometry(width()/18*10,5+height()/9,width()/10,height()/4.5);
    ui->verticalLayoutWidget_3->setGeometry(width()/1.53,5+height()/9,width()/4,height()/4.5);
    ui->verticalLayoutWidget->setGeometry(width()/4,5+height()/9,width()/4,height()/4.5);
    ui->horizontalLayoutWidget->setGeometry(width()/12,height()/9*4,width()*5/6,height()/9);
    ui->label->setGeometry(width()/24,height()*50/450,width()*11/12,height()*121/450);
    ui->label_8->setGeometry(width()/24,height()*2/5,width()*11/12,height()*171/450);
    ui->exportButton->setGeometry(width()*250/800,height()*360/450,width()*131/800,height()*51/450);
    ui->exportDataChartButton->setGeometry(width()*400/800,height()*360/450,width()*131/800,height()*51/450);
    ui->ret->setGeometry(250*width()/800,410*height()/450,281*width()/800,31*height()/450);
}
