#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>
#include <QKeyEvent>
#include <QFocusEvent>
#include "mybutton.h"
#include <QStackedWidget>

extern QStackedWidget *stack;
class myComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit myComboBox(QWidget *parent = 0);

signals:

public slots:
    void keyPressEvent(QKeyEvent *k)
    {
        int index=this->currentIndex();
        switch (k->key()) {
        case Qt::Key_4:
            index=index-1>-1?index-1:0;
            this->setCurrentIndex(index);
            break;
        case Qt::Key_6:
            index=index+1>this->count()-1?index:index+1;
            this->setCurrentIndex(index);
            break;
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
    void focusInEvent(QFocusEvent *){
        setStyleSheet("color:red");
    }
    void focusOutEvent(QFocusEvent *){
        setStyleSheet("color:black");
    }
};

#endif // MYCOMBOBOX_H
