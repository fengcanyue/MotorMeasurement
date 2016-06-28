#ifndef OUTPUTCONFIG_H
#define OUTPUTCONFIG_H

#include <QWidget>
#include <QResizeEvent>
#include "serialport.h"
#include "page_1.h"

namespace Ui {
class OutPutConfig;
}

class OutPutConfig : public QWidget
{
    Q_OBJECT

public:
    explicit OutPutConfig(QWidget *parent = 0);
    ~OutPutConfig();
private slots:
    void on_okbutton_clicked();
    void resizeEvent(QResizeEvent *);
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

private:
    Ui::OutPutConfig *ui;
    SerialPort *port;
    int x_init;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // OUTPUTCONFIG_H
