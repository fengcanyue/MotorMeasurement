/********************************************************************************
** Form generated from reading UI file 'picture.ui'
**
** Created: Sat May 30 08:06:16 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURE_H
#define UI_PICTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "mycombobox.h"

QT_BEGIN_NAMESPACE

class Ui_Picture
{
public:
    myComboBox *y1Property;
    myComboBox *xRange;

    void setupUi(QWidget *Picture)
    {
        if (Picture->objectName().isEmpty())
            Picture->setObjectName(QString::fromUtf8("Picture"));
        Picture->resize(720, 450);
        Picture->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        y1Property = new myComboBox(Picture);
        y1Property->setObjectName(QString::fromUtf8("y1Property"));
        y1Property->setGeometry(QRect(20, 150, 71, 30));
        y1Property->setFocusPolicy(Qt::TabFocus);
        xRange = new myComboBox(Picture);
        xRange->setObjectName(QString::fromUtf8("xRange"));
        xRange->setGeometry(QRect(20, 300, 71, 30));
        QWidget::setTabOrder(y1Property, xRange);

        retranslateUi(Picture);

        QMetaObject::connectSlotsByName(Picture);
    } // setupUi

    void retranslateUi(QWidget *Picture)
    {
        Picture->setWindowTitle(QApplication::translate("Picture", "Form", 0, QApplication::UnicodeUTF8));
        xRange->clear();
        xRange->insertItems(0, QStringList()
         << QApplication::translate("Picture", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "2000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "5000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Picture", "10000", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class Picture: public Ui_Picture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURE_H
