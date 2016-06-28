/********************************************************************************
** Form generated from reading UI file 'outputconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTCONFIG_H
#define UI_OUTPUTCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "mybutton.h"
#include "mycombobox.h"

QT_BEGIN_NAMESPACE

class Ui_OutPutConfig
{
public:
    myButton *okbutton;
    myComboBox *output_1;
    myComboBox *output_2;
    QLabel *label_2;
    QLabel *label_1;

    void setupUi(QWidget *OutPutConfig)
    {
        if (OutPutConfig->objectName().isEmpty())
            OutPutConfig->setObjectName(QStringLiteral("OutPutConfig"));
        OutPutConfig->resize(800, 450);
        okbutton = new myButton(OutPutConfig);
        okbutton->setObjectName(QStringLiteral("okbutton"));
        okbutton->setGeometry(QRect(330, 310, 151, 61));
        output_1 = new myComboBox(OutPutConfig);
        output_1->setObjectName(QStringLiteral("output_1"));
        output_1->setGeometry(QRect(110, 80, 401, 71));
        QFont font;
        font.setPointSize(40);
        output_1->setFont(font);
        output_2 = new myComboBox(OutPutConfig);
        output_2->setObjectName(QStringLiteral("output_2"));
        output_2->setGeometry(QRect(110, 180, 401, 71));
        output_2->setFont(font);
        label_2 = new QLabel(OutPutConfig);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(520, 180, 181, 71));
        QFont font1;
        font1.setPointSize(18);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_1 = new QLabel(OutPutConfig);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(520, 80, 181, 71));
        label_1->setFont(font1);
        label_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(OutPutConfig);

        QMetaObject::connectSlotsByName(OutPutConfig);
    } // setupUi

    void retranslateUi(QWidget *OutPutConfig)
    {
        OutPutConfig->setWindowTitle(QApplication::translate("OutPutConfig", "Form", 0));
        okbutton->setText(QApplication::translate("OutPutConfig", "ok", 0));
        output_1->clear();
        output_1->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("OutPutConfig", "1", 0)
         << QApplication::translate("OutPutConfig", "2", 0)
         << QApplication::translate("OutPutConfig", "3", 0)
         << QApplication::translate("OutPutConfig", "4", 0)
         << QApplication::translate("OutPutConfig", "5", 0)
         << QApplication::translate("OutPutConfig", "6", 0)
         << QApplication::translate("OutPutConfig", "7", 0)
         << QApplication::translate("OutPutConfig", "8", 0)
         << QApplication::translate("OutPutConfig", "9", 0)
         << QApplication::translate("OutPutConfig", "10", 0)
         << QApplication::translate("OutPutConfig", "11", 0)
         << QApplication::translate("OutPutConfig", "12", 0)
         << QApplication::translate("OutPutConfig", "13", 0)
         << QApplication::translate("OutPutConfig", "14", 0)
         << QApplication::translate("OutPutConfig", "15", 0)
         << QApplication::translate("OutPutConfig", "16", 0)
         << QApplication::translate("OutPutConfig", "17", 0)
         << QApplication::translate("OutPutConfig", "18", 0)
         << QApplication::translate("OutPutConfig", "19", 0)
         << QApplication::translate("OutPutConfig", "20", 0)
        );
        output_2->clear();
        output_2->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("OutPutConfig", "1", 0)
         << QApplication::translate("OutPutConfig", "2", 0)
         << QApplication::translate("OutPutConfig", "3", 0)
         << QApplication::translate("OutPutConfig", "4", 0)
         << QApplication::translate("OutPutConfig", "5", 0)
         << QApplication::translate("OutPutConfig", "6", 0)
         << QApplication::translate("OutPutConfig", "7", 0)
         << QApplication::translate("OutPutConfig", "8", 0)
         << QApplication::translate("OutPutConfig", "9", 0)
         << QApplication::translate("OutPutConfig", "10", 0)
         << QApplication::translate("OutPutConfig", "11", 0)
         << QApplication::translate("OutPutConfig", "12", 0)
         << QApplication::translate("OutPutConfig", "13", 0)
         << QApplication::translate("OutPutConfig", "14", 0)
         << QApplication::translate("OutPutConfig", "15", 0)
         << QApplication::translate("OutPutConfig", "16", 0)
         << QApplication::translate("OutPutConfig", "17", 0)
         << QApplication::translate("OutPutConfig", "18", 0)
         << QApplication::translate("OutPutConfig", "19", 0)
         << QApplication::translate("OutPutConfig", "20", 0)
        );
        label_2->setText(QApplication::translate("OutPutConfig", "\346\250\241\346\213\237\350\276\223\345\207\2722\351\200\211\346\213\251(mA)", 0));
        label_1->setText(QApplication::translate("OutPutConfig", "\346\250\241\346\213\237\350\276\223\345\207\2721\351\200\211\346\213\251(mA)", 0));
    } // retranslateUi

};

namespace Ui {
    class OutPutConfig: public Ui_OutPutConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTCONFIG_H
