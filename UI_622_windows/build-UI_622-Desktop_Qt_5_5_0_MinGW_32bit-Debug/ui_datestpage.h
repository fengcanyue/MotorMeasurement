/********************************************************************************
** Form generated from reading UI file 'datestpage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATESTPAGE_H
#define UI_DATESTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
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
            DATestPage->setObjectName(QStringLiteral("DATestPage"));
        DATestPage->resize(800, 450);
        pushButton = new myButton(DATestPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 350, 161, 51));
        pushButton->setFocusPolicy(Qt::TabFocus);
        label = new QLabel(DATestPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 400, 161, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        exportCharButton = new myButton(DATestPage);
        exportCharButton->setObjectName(QStringLiteral("exportCharButton"));
        exportCharButton->setGeometry(QRect(410, 350, 161, 51));
        exportCharButton->setFocusPolicy(Qt::TabFocus);

        retranslateUi(DATestPage);

        QMetaObject::connectSlotsByName(DATestPage);
    } // setupUi

    void retranslateUi(QWidget *DATestPage)
    {
        DATestPage->setWindowTitle(QApplication::translate("DATestPage", "Form", 0));
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
