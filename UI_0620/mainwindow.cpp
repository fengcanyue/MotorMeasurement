#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_pdfheaderedit.h"
#include "ui_configpage.h"
#include "ui_picture.h"
extern double torsion_test_max;
extern double impulse_num;
extern double speed_test_max;
extern QList<double> *torsionlist_draw;
extern QList<double> *speedlist_draw;
extern QList<double> *powerlist_draw;
DataStack datastack;
QStackedWidget *stack;
pdfHeaderEdit *pdf;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromUtf8("\u8f6c\u77e9\u8f6c\u901f\u6d4b\u91cf\u4eea"));
    setWindowState(Qt::WindowMaximized);
    home=new homePage;
    sysstatusbutton=new myButton(home);
    drawbutton=new myButton(home);
    outputbutton=new myButton(home);
    da_testbutton=new myButton(home);
    pdfeditbutton=new myButton(home);
    sysconfigbutton=new myButton(home);

    sysstatusbutton->setText(QString::fromUtf8("\u7cfb\u7edf\u663e\u793a"));
    drawbutton->setText(QString::fromUtf8("\u91c7\u6837\u66f2\u7ebf"));
    pdfeditbutton->setText(QString::fromUtf8("\u62a5\u8868\u7f16\u8f91"));
    sysconfigbutton->setText(QString::fromUtf8("\u7cfb\u7edf\u8bbe\u7f6e"));
    outputbutton->setText(QString::fromUtf8("\u6A21\u62DF\u8F93\u51FA"));
    da_testbutton->setText(QString::fromUtf8("\u6A21\u62DF\u6D4B\u8BD5"));

    sysstatusbutton->setGeometry(QRect(width()*80/800,height()*80/450,width()*200/800,height()*130/450));
    drawbutton->setGeometry(QRect(width()*80/800,height()*280/450,width()*200/800,height()*130/450));
    pdfeditbutton->setGeometry(QRect(width()*520/800,height()*80/450,width()*200/800,height()*130/450));
    sysconfigbutton->setGeometry(QRect(width()*520/800,height()*280/450,width()*200/800,height()*130/450));
    outputbutton->setGeometry(QRect(width()*300/800,height()*80/450,width()*200/800,height()*130/450));
    da_testbutton->setGeometry(QRect(width()*300/800,height()*280/450,width()*200/800,height()*130/450));

    widgets=new QStackedWidget(this);
    stack=widgets;
    widgets->setGeometry(0,0,width(),height());
    widgets->addWidget(home);   //0
    keyboard=new keyBoard;
    keyboard->setGeometry((width()-width()*610/800)/2,height()-height()*130/450,width()*610/800,height()*130/450);
    keyboard->hide();
    page1=new Page_1;
    widgets->addWidget(page1);  //1
    drawpage=new DrawPage;
    widgets->addWidget(drawpage); //2
    outputpage=new OutPutConfig;
    widgets->addWidget(outputpage); //3
    pdfPage=new pdfHeaderEdit;
    pdf=pdfPage;
    /*******************************************************/
    pdfPage->ui->subTitleEdit->wid=keyboard->winId();
    pdfPage->ui->NoEdit->wid=keyboard->winId();
    pdfPage->ui->typeNoEdit->wid=keyboard->winId();
    pdfPage->ui->faxEdit->wid=keyboard->winId();
    pdfPage->ui->companyEdit->wid=keyboard->winId();
    pdfPage->ui->telEdit->wid=keyboard->winId();
    pdfPage->ui->websiteEdit->wid=keyboard->winId();
    pdfPage->ui->mailEdit->wid=keyboard->winId();
    pdfPage->ui->sizeEdit->wid=keyboard->winId();
    /*****************************************************/
    widgets->addWidget(pdfPage); //4
    configpage=new ConfigPage;
    widgets->addWidget(configpage);  //5
    da_testpage=new DATestPage;
    widgets->addWidget(da_testpage); //6

    topWidget=new QWidget(this);
    topWidget->setFocusPolicy(Qt::NoFocus);
    topWidget->setGeometry(0,0,width(),height()*30/450);
    topWidget->setStyleSheet("background-color: rgb(74, 153, 255);");
//    helpbutton=new helpButton(topWidget);
//    helpbutton->setGeometry(topWidget->width()*9/10,0,topWidget->width()/10,topWidget->height());
//    helpbutton->setIcon(style()->standardIcon(QStyle::SP_MessageBoxQuestion));
//    helpbutton->setText(QString::fromUtf8("\u5E2E\u52A9"));
//    helpbutton->hide();//
    helpLabel=new QLabel(topWidget);
    helpLabel->setGeometry(0,0,topWidget->width()*9/10,topWidget->height());
    QFont titleFont(QString("\u6977\u4F53"),20, QFont::Bold);
    helpLabel->setFont(titleFont);
    helpLabel->setText(QString::fromUtf8("\u5170\u9675\u8F6C\u77E9\u8F6C\u901F\u6D4B\u91CF\u4EEA"));
//    timeLabel=new QLabel(topWidget);
//    timeLabel->setGeometry(width()/2,0,width()-helpbutton->width(),topWidget->height());
//    timeLabel->hide();//
//    helppage=new helpPage;
 //   timer=new QTimer(this);
 //   timer->start(1000);
    drawpage->pdf=pdfPage;
    page1->torsionWatch->setMax(torsion_test_max);

    connect(drawbutton,SIGNAL(clicked()),this,SLOT(drawButton_clicked()));
    connect(sysstatusbutton,SIGNAL(clicked()),this,SLOT(statusButton_clicked()));
    connect(sysconfigbutton,SIGNAL(clicked()),this,SLOT(configButton_clicked()));
    connect(pdfeditbutton,SIGNAL(clicked()),this,SLOT(pdfEditButton_clicked()));
    connect(da_testbutton,SIGNAL(clicked()),this,SLOT(showDAtestPage()));
//    connect(helpbutton,SIGNAL(clicked()),this,SLOT(showHelp()));
    connect(outputbutton,SIGNAL(clicked()),this,SLOT(showOutPutPage()));
 //   connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    sysstatusbutton->setFocus();
    connect(widgets,SIGNAL(currentChanged(int)),this,SLOT(changeLabel(int)));
    connect(configpage,SIGNAL(configureChanged(double,double)),page1,SLOT(setTorsionMaxandPeriod(double,double)));
    connect(page1,SIGNAL(getTestData(double,double)),da_testpage,SLOT(appendData(double,double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    keyboard->setGeometry((width()-width()*610/800)/2,height()-height()*130/450,width()*610/800,height()*130/450);
    home->setGeometry(0,0,width(),height());

    sysstatusbutton->setGeometry(QRect(width()*80/800,height()*80/450,width()*200/800,height()*130/450));
    drawbutton->setGeometry(QRect(width()*80/800,height()*280/450,width()*200/800,height()*130/450));
    pdfeditbutton->setGeometry(QRect(width()*520/800,height()*80/450,width()*200/800,height()*130/450));
    sysconfigbutton->setGeometry(QRect(width()*520/800,height()*280/450,width()*200/800,height()*130/450));
    outputbutton->setGeometry(QRect(width()*300/800,height()*80/450,width()*200/800,height()*130/450));
    da_testbutton->setGeometry(QRect(width()*300/800,height()*280/450,width()*200/800,height()*130/450));
    widgets->setGeometry(0,0,width(),height());
    topWidget->setGeometry(0,0,width(),height()*30/450);
  //  helpbutton->setGeometry(topWidget->width()*9/10,0,topWidget->width()/10,topWidget->height());
    helpLabel->setGeometry(0,0,topWidget->width()*9/10,topWidget->height());
//    timeLabel->setGeometry(width()/2,0,width()-helpbutton->width(),topWidget->height());
  //  helpbutton->raise();
}

void MainWindow::updateTime()
{
  //  timeLabel->setText(QDateTime::currentDateTime().toString(QString::fromUtf8("yyyy\u5E74MM\u6708dd\u65E5hh:mm:ss")));
}

void MainWindow::saveWorkerNum(QString arg1)
{
    if(arg1.isEmpty() || arg1.isNull())
        return;
    pdfPage->employeeNo=arg1;
    sysstatusbutton->setFocus();
    configpage->on_okButton_clicked();
}

void MainWindow::statusButton_clicked()
{
    widgets->setCurrentIndex(1);
}

void MainWindow::showDAtestPage()
{
    widgets->setCurrentIndex(6);
}

void MainWindow::showOutPutPage()
{
    widgets->setCurrentIndex(3);
}

void MainWindow::drawButton_clicked()
{
    widgets->setCurrentIndex(2);
}

void MainWindow::configButton_clicked()
{
    widgets->setCurrentIndex(5);
}

void MainWindow::pdfEditButton_clicked()
{
    widgets->setCurrentIndex(4);
}

void MainWindow::showHelp()
{
 //   helppage->resize(width()/2,height()/1.5);
 //   helppage->show();
 //   helppage->move((width()-helppage->width())/2,(height()-helppage->height())/2);
}

void MainWindow::changeLabel(int index)
{
    switch (index) {
    case 0:
        helpLabel->setText(QString::fromUtf8("\u5170\u9675\u8F6C\u77E9\u8F6C\u901F\u6D4B\u91CF\u4EEA"));
       /* if(page1->state==Page_1::StartedState)
              page1->stopButton_clicked();
	configpage->on_okButton_clicked();*/
        break;
    case 1:
        helpLabel->setText(QString::fromUtf8("\u7CFB\u7EDF\u72B6\u6001"));
        break;
    case 2:
        helpLabel->setText(QString::fromUtf8("\u91C7\u6837\u66F2\u7EBF"));
        break;
    case 3:
        helpLabel->setText(QString::fromUtf8("\u6A21\u62DF\u8F93\u51FA"));
        break;
    case 4:
        helpLabel->setText(QString::fromUtf8("\u62A5\u8868\u7F16\u8F91"));
        break;
    case 5:
        helpLabel->setText(QString::fromUtf8("\u7CFB\u7EDF\u8BBE\u7F6E"));
        break;
    case 6:
        helpLabel->setText(QString::fromUtf8("\u6A21\u62DF\u6D4B\u8BD5"));
        break;
    }
}

void MainWindow::getData(double torsion, double speed)
{
    if(page1->state==Page_1::StartedState)
        page1->setWatchValues(torsion,speed);
    if(drawpage->status==DrawPage::STARTED)
    {
        qDebug()<<"start";
        double power;
        power=torsion*speed*1.0/9950;
        torsionlist_draw->append(torsion);
        speedlist_draw->append(qAbs(speed));
        powerlist_draw->append(qAbs(power));

        drawpage->Kwpage->yMax=torsion_test_max*speed_test_max;
        drawpage->Nmpage->yMax=torsion_test_max;
        drawpage->speedpage->yMax=speed_test_max;

        drawpage->Kwpage->repaint();
        drawpage->Nmpage->repaint();
        drawpage->speedpage->repaint();
    }
}
