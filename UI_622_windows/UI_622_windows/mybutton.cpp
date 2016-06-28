#include "mybutton.h"
#include <QLayout>

extern QStackedWidget *stack;
myButton::myButton(QWidget *parent) :
    QPushButton(parent)
{
    QFont font;
    font.setFamily("wenquanyi");
    font.setPointSize(160);
    font.setBold(true);
    setFont(font);
    setFocusPolicy(Qt::TabFocus);
    setStyleSheet("border-style: inset; border-width: 3px;border-radius: 20px;border-color: rgb(46, 130, 255);padding:-99999;background-color:blue;color:black;");
}

void myButton::keyPressEvent(QKeyEvent *k)
{
    if(k->key()==Qt::Key_Enter)
    {
        this->click();
        setStyleSheet("border-style: inset; border-width: 0px;border-radius: 20px;border-color:rgb(255, 20, 110);padding: -99999;background-color:red;color:black;");
    }
    switch (k->key()) {
    case Qt::Key_8:
        focusPreviousChild();
        break;
    case Qt::Key_2:
        focusNextChild();
        break;
    case Qt::Key_7:
        stack->setCurrentIndex(0);
        break;
    case Qt::Key_Minus:
        system("sudo halt");
        break;
    }
}

void myButton::keyReleaseEvent(QKeyEvent *k)
{
    if(k->key()==Qt::Key_Enter)
    setStyleSheet("border-style: inset; border-width: 3px;border-radius: 20px;border-color:rgb(255, 20, 110);padding: -99999;background-color:red;color:black;");
}

void myButton::resizeEvent(QResizeEvent *)
{
    QFont font(QString::fromUtf8("\u5B8B\u4F53"),width()/7);
    setFont(font);
}
