/********************************************************************************
** Form generated from reading UI file 'helppage.ui'
**
** Created: Fri May 29 02:47:40 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPPAGE_H
#define UI_HELPPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helpPage
{
public:

    void setupUi(QWidget *helpPage)
    {
        if (helpPage->objectName().isEmpty())
            helpPage->setObjectName(QString::fromUtf8("helpPage"));
        helpPage->resize(400, 300);
        helpPage->setFocusPolicy(Qt::TabFocus);
        helpPage->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 198, 255);"));

        retranslateUi(helpPage);

        QMetaObject::connectSlotsByName(helpPage);
    } // setupUi

    void retranslateUi(QWidget *helpPage)
    {
        helpPage->setWindowTitle(QApplication::translate("helpPage", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class helpPage: public Ui_helpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPPAGE_H
