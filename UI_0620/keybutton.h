#ifndef KEYBUTTON_H
#define KEYBUTTON_H

#include "mybutton.h"
#include <QKeyEvent>
#include <QFocusEvent>
#include "keybutton.h"
#include "keyboard.h"
#include "mylineedit.h"

class keyButton : public myButton
{
    Q_OBJECT
public:
    explicit keyButton(QWidget *parent = 0);
    struct {
    myButton *upButton;
    myButton *downButton;
    myButton *leftButton;
    myButton *rightButton;
    }neighbor;
    myButton *nextButton;
    int flag;//0 输入键 1 功能键
    keyBoard *board;
    myLineEdit *edit;

signals:

public slots:
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent *k){
        switch (k->key()) {
        case Qt::Key_8:
            //if(neighbor.upButton!=0)
            nextButton=neighbor.upButton;
            if(nextButton!=0)
            nextButton->setFocus();
            break;
        case Qt::Key_2:
            nextButton=neighbor.downButton;
            if(nextButton!=0)
            nextButton->setFocus();
            break;
        case Qt::Key_4:
            nextButton=neighbor.leftButton;
            if(nextButton!=0)
            nextButton->setFocus();
            break;
        case Qt::Key_6:
            nextButton=neighbor.rightButton;
            if(nextButton!=0)
            nextButton->setFocus();
            break;
        case Qt::Key_Enter:
            if(flag==0)
            {
                char letter;
                letter=this->text().at(0).toAscii();
                if(!board->islocked && letter>=65 && letter<=90)
                    letter=letter+32;
                edit=(myLineEdit*)board->inputWidget;
                edit->setText(edit->text()+letter);
            }
            else if(flag==1)
            {
                if(text()=="back")
                {
                    edit=(myLineEdit*)board->inputWidget;
                    edit->setText(edit->text().remove(edit->text().length()-1,1));
                }
                else
                click();
            }
            break;
       case Qt::Key_0:
            board->hide();
            break;
        }
    }

};

#endif // KEYBUTTON_H
