/********************************************************************************
** Form generated from reading UI file 'page_1.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_1_H
#define UI_PAGE_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_Page_1
{
public:
    myButton *stopButton;
    myButton *startButton;

    void setupUi(QWidget *Page_1)
    {
        if (Page_1->objectName().isEmpty())
            Page_1->setObjectName(QStringLiteral("Page_1"));
        Page_1->resize(800, 450);
        Page_1->setFocusPolicy(Qt::TabFocus);
        Page_1->setStyleSheet(QStringLiteral(""));
        stopButton = new myButton(Page_1);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(350, 350, 99, 41));
        startButton = new myButton(Page_1);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(350, 300, 99, 41));
        QWidget::setTabOrder(startButton, stopButton);

        retranslateUi(Page_1);

        QMetaObject::connectSlotsByName(Page_1);
    } // setupUi

    void retranslateUi(QWidget *Page_1)
    {
        Page_1->setWindowTitle(QApplication::translate("Page_1", "Form", 0));
        stopButton->setText(QString());
        startButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Page_1: public Ui_Page_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_1_H
