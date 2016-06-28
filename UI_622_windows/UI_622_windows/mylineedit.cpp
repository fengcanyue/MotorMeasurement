#include "mylineedit.h"

myLineEdit::myLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    setFocusPolicy(Qt::TabFocus);
    focusMove=true;
}
