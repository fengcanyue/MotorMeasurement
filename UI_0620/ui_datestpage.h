/********************************************************************************
** Form generated from reading UI file 'datestpage.ui'
**
** Created: Fri May 29 02:47:40 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATESTPAGE_H
#define UI_DATESTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_DATestPage
{
public:
    myButton *pushButton;
    QLabel *label;
    myButton *exportCharButton;

    void setupUi(QWidget *DATestPage)
    {
        if (DATestPage->objectName().isEmpty())
            DATestPage->setObjectName(QString::fromUtf8("DATestPage"));
        DATestPage->resize(800, 450);
        pushButton = new myButton(DATestPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 350, 161, 51));
        pushButton->setFocusPolicy(Qt::TabFocus);
        label = new QLabel(DATestPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 400, 161, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        exportCharButton = new myButton(DATestPage);
        exportCharButton->setObjectName(QString::fromUtf8("exportCharButton"));
        exportCharButton->setGeometry(QRect(410, 350, 161, 51));
        exportCharButton->setFocusPolicy(Qt::TabFocus);

        retranslateUi(DATestPage);

        QMetaObject::connectSlotsByName(DATestPage);
    } // setupUi

    void retranslateUi(QWidget *DATestPage)
    {
        DATestPage->setWindowTitle(QApplication::translate("DATestPage", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label->setText(QString());
        exportCharButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DATestPage: public Ui_DATestPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATESTPAGE_H
