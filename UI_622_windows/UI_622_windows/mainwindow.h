#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QLabel>
#include "mybutton.h"
#include <QStackedWidget>
#include <QLabel>
#include "page_1.h"
#include "configpage.h"
#include "pdfheaderedit.h"
#include "drawpage.h"
#include <QCloseEvent>
#include <QApplication>
#include "homepage.h"
#include <QTimer>
#include "keyboard.h"
#include "mylineedit.h"
#include "datastack.h"
#include "outputconfig.h"
#include "datestpage.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    myButton *sysconfigbutton,*sysstatusbutton,*drawbutton,*pdfeditbutton,*outputbutton,*da_testbutton;
    // helpButton *helpbutton;
    QStackedWidget *widgets;
    QLabel *label2;
    Page_1 *page1;
    ConfigPage *configpage;
    DrawPage *drawpage;
    pdfHeaderEdit *pdfPage;
    QWidget * topWidget;
    QLabel *helpLabel,*timeLabel;
    // helpPage *helppage;
    homePage *home;
    QTimer *timer;
    keyBoard *keyboard;
    OutPutConfig *outputpage;
    DATestPage *da_testpage;
public slots:
    void resizeEvent(QResizeEvent *);

    void drawButton_clicked();

    void statusButton_clicked();

    void configButton_clicked();

    void pdfEditButton_clicked();

    void showDAtestPage();

    void saveWorkerNum(QString arg1);

    void showHelp();

    void closeEvent(QCloseEvent *){
        qApp->exit();
    }
    void  getData(double torsion,double speed);

    void changeLabel(int index);

    void updateTime();

    void showOutPutPage();

private:
    Ui::MainWindow *ui;
    QLabel *label;
};

#endif // MAINWINDOW_H
