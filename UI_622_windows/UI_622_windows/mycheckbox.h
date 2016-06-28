#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>
#include <QKeyEvent>
#include <QFocusEvent>
#include "mybutton.h"
#include <QStackedWidget>

extern QStackedWidget *stack;
class myCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit myCheckBox(QWidget *parent = 0);
    //1:可取消勾选 0：不可取消
    int flag;
signals:

public slots:
    void keyPressEvent(QKeyEvent *k){
         if(k->key()==Qt::Key_Enter && !this->isChecked())
             this->setChecked(true);
        else if(k->key()==Qt::Key_Enter && this->isChecked() && this->flag==1)
             this->setChecked(false);
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
    void focusInEvent(QFocusEvent *){
//        if(flag==1)
//            setStyleSheet("background-color:red");
//        else if(flag==0)
            setStyleSheet("background-color:red;");
    }
    void focusOutEvent(QFocusEvent *){
//        if(flag==1)
//            setStyleSheet("background-color:rgb(0,170,0)");
//        else if(flag==0)
            setStyleSheet("background-color:white");
    }

};

#endif // MYCHECKBOX_H
