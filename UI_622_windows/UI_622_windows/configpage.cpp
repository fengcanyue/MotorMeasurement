#include "configpage.h"
#include "ui_configpage.h"
#include "mainwindow.h"

double torsion_test_max;
double impulse_num;
double speed_test_max;
int timer_period;
//mySpinBox *impulsespin;
ConfigPage::ConfigPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigPage)
{
    ui->setupUi(this);
    connect(ui->setzerobutton,SIGNAL(clicked()),this,SLOT(torsion2zero()));
    //impulsespin=ui->doubleSpinBox;
    speed_test_max=1;
    on_cancelButton_clicked();
    on_okButton_clicked();
}

ConfigPage::~ConfigPage()
{
    delete ui;
}

void ConfigPage::resizeEvent(QResizeEvent *)
{
    int hh;
    hh=71*height()/450;
    ui->torsion_max_edit->setGeometry(width()*20/800,height()*60/450,231*width()/800,hh);
    ui->label->setGeometry(width()*260/800,height()*60/450,121*width()/800,hh);

    ui->comboBox_2->setGeometry(width()*20/800,height()*200/450,231*width()/800,hh);
    ui->label_2->setGeometry(width()*260/800,height()*200/450,121*width()/800,hh);

    ui->doubleSpinBox_2->setGeometry(420*width()/800,60*height()/450,231*width()/800,hh);
    ui->label_5->setGeometry(660*width()/800,60*height()/450,121*width()/800,hh);
    ui->label_6->setGeometry(420*width()/800,130*height()/450,231*width()/800,hh);

    ui->doubleSpinBox->setGeometry(420*width()/800,200*height()/450,231*width()/800,hh);
    ui->label_7->setGeometry(660*width()/800,200*height()/450,121*width()/800,hh);

    ui->okButton->setGeometry(150*width()/800,300*height()/450,151*width()/800,hh);
    ui->cancelButton->setGeometry(320*width()/800,300*height()/450,151*width()/800,hh);
    ui->setzerobutton->setGeometry(490*width()/800,300*height()/450,151*width()/800,hh);
    ui->ret->setGeometry(150*width()/800,380*height()/450,490*width()/800,60*height()/450);
}

void ConfigPage::torsion2zero()
{
     stack->setCurrentIndex(1);
     p1=(Page_1*)stack->widget(1);
     p1->setZeroButton->setFocus();
}

void ConfigPage::on_okButton_clicked()
{
    if(ui->torsion_max_edit->text().isEmpty() || ui->torsion_max_edit->text().toDouble()==0 || ui->doubleSpinBox->value()==0)
    {
        ui->ret->setText(QString::fromUtf8("\u8BBE\u7F6E\u6709\u8BEF"));
        return;
    }
    QFile  file("configuration.txt");
    file.open(QIODevice::ReadWrite);
    file.resize(0);
    QTextStream stream(&file);
    stream.setCodec("Utf8");
    QString data=ui->torsion_max_edit->text()+"#"+QVariant(ui->doubleSpinBox->value()).toString()+"#"+QVariant(ui->comboBox_2->currentIndex()).toString()+"#"+QVariant(ui->doubleSpinBox_2->value()).toString()+"#";
    stream<<data;
    stream.flush();
    file.flush();
    file.close();
    torsion_test_max=ui->torsion_max_edit->value();
    impulse_num=ui->doubleSpinBox->value();
    timer_period=ui->doubleSpinBox_2->value()*1000;
    emit configureChanged(torsion_test_max,ui->doubleSpinBox_2->value());
    ui->ret->clear();
}

void ConfigPage::on_cancelButton_clicked()
{
    QFile file("configuration.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);
    QStringList setList;
    stream.setCodec("utf8");
    QString content=stream.readLine();
    if(content.isEmpty() || content.count("#")!=4)
    {
        file.resize(0);
        stream<<"0.5#60#0#0.005#";
        setList<<"0.5"<<"60"<<"0"<<"0.005";
    }
    else
    setList=content.split("#",QString::SkipEmptyParts);
    file.close();
    ui->torsion_max_edit->setValue(setList.at(0).toDouble());
    ui->doubleSpinBox->setValue(setList.at(1).toDouble());
    ui->comboBox_2->setCurrentIndex(setList.at(2).toInt());
    ui->doubleSpinBox_2->setValue(setList.at(3).toDouble());
    torsion_test_max=ui->torsion_max_edit->value();
    impulse_num=ui->doubleSpinBox->value();
    timer_period=ui->doubleSpinBox_2->value()*1000;
}
