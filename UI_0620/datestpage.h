#ifndef DATESTPAGE_H
#define DATESTPAGE_H

#include <QWidget>
#include "outputconfig.h"
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include "serialport.h"
#include "page_1.h"
#define PERIOD 1
extern QStackedWidget *stack;
namespace Ui {
class DATestPage;
}

class DATestPage : public QWidget
{
    Q_OBJECT

public:
    explicit DATestPage(QWidget *parent = 0);
    ~DATestPage();
    QTimer *timer;
    int da_index;
    int msgq_id;
    int maxindex;
    int count;
    QList<int> index_list;
    QList<double> test_torsionlist;
    QList<double> test_speedlist;
    SerialPort  *port;
private slots:
    void on_pushButton_clicked();
    void sendmsg();
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void on_exportCharButton_clicked();
    char back_translate(unsigned char uc)
    {
         char c;
         if(uc>=0 && uc<=9)
            uc+=48;
         else if(uc>=10 && uc<=15)
            uc+=55;
         c=static_cast<char>(uc);
         return c;
    }

public slots:
    void appendData(double arg1,double arg2);
private:
    Ui::DATestPage *ui;
    int x_init;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // DATESTPAGE_H
