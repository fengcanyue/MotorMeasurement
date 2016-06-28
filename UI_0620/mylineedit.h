#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>
#include <QFocusEvent>
#include <QDebug>
#include "mybutton.h"
#include <QStackedWidget>
#include "keyboard.h"

extern QStackedWidget *stack;
class myLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit myLineEdit(QWidget *parent = 0);
    bool focusMove;
    keyBoard *keyboard;
    WId wid;
signals:
    void enterPushed(QString arg1);

public slots:
    void keyPressEvent(QKeyEvent *k){
        switch (k->key()) {
            case Qt::Key_Minus:
        system("sudo halt");
        break;

        case Qt::Key_8:
            if(focusMove)
            focusPreviousChild();
            break;
        case Qt::Key_2:
            if(focusMove)
            focusNextChild();
            break;
        case Qt::Key_7:
            if(focusMove)
                stack->setCurrentIndex(0);
            break;
        case Qt::Key_Enter:
            emit enterPushed(text());
            break;
        case Qt::Key_0:
            keyboard=(keyBoard*)QWidget::find(wid);
            keyboard->show();
            keyboard->inputWidget=this;
            keyboard->gainFocus();
            break;
        }
    }
    void focusInEvent(QFocusEvent *){
        setStyleSheet("background-color:red");
    }
    void focusOutEvent(QFocusEvent *){
        setStyleSheet("background-color:white");
    }

};

#endif // MYLINEEDIT_H
