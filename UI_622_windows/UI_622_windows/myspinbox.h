#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include <QDoubleSpinBox>
#include <QKeyEvent>
#include <QFocusEvent>
#include "mybutton.h"
#include <QStackedWidget>

extern QStackedWidget *stack;
class mySpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit mySpinBox(QWidget *parent = 0);

signals:

public slots:
    void keyPressEvent(QKeyEvent *k){
        switch (k->key()) {
           case Qt::Key_Minus:
        system("sudo halt");
        break;

        case Qt::Key_8:
            focusPreviousChild();
            break;
        case Qt::Key_2:
            focusNextChild();
            break;
        case Qt::Key_4:
            stepUp();
            break;
        case Qt::Key_6:
            stepDown();
            break;
        case Qt::Key_7:
            stack->setCurrentIndex(0);
            break;
        }
    }
    void focusInEvent(QFocusEvent *){
        setStyleSheet("color:red");
    }
    void focusOutEvent(QFocusEvent *){
        setStyleSheet("color:black");
    }

};

#endif // MYSPINBOX_H
