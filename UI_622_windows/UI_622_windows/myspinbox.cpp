#include "myspinbox.h"

mySpinBox::mySpinBox(QWidget *parent) :
    QDoubleSpinBox(parent)
{
    setFocusPolicy(Qt::TabFocus);
}
