/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created: Fri May 29 02:47:40 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homePage
{
public:

    void setupUi(QWidget *homePage)
    {
        if (homePage->objectName().isEmpty())
            homePage->setObjectName(QString::fromUtf8("homePage"));
        homePage->resize(800, 450);

        retranslateUi(homePage);

        QMetaObject::connectSlotsByName(homePage);
    } // setupUi

    void retranslateUi(QWidget *homePage)
    {
        homePage->setWindowTitle(QApplication::translate("homePage", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class homePage: public Ui_homePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
