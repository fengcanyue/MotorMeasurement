#include "mycombobox.h"

myComboBox::myComboBox(QWidget *parent) :
    QComboBox(parent)
{
    setFocusPolicy(Qt::TabFocus);
}
