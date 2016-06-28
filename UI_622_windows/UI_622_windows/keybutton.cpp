#include "keybutton.h"

keyButton::keyButton(QWidget *parent) :
    myButton(parent)
{
    flag=0;
    board=(keyBoard*)this->parentWidget();
    QFont font(QString::fromUtf8("\u5B8B\u4F53"),width()/5);
    setFont(font);
}

void keyButton::resizeEvent(QResizeEvent *)
{
    QFont font(QString::fromUtf8("\u5B8B\u4F53"),width()/5);
    setFont(font);
    setText(text());
}
