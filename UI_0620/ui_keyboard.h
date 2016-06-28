/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created: Sat May 30 08:06:16 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "keybutton.h"

QT_BEGIN_NAMESPACE

class Ui_keyBoard
{
public:
    keyButton *Q;
    keyButton *W;
    keyButton *E;
    keyButton *R;
    keyButton *T;
    keyButton *Y;
    keyButton *U;
    keyButton *I;
    keyButton *O;
    keyButton *P;
    keyButton *A;
    keyButton *S;
    keyButton *D;
    keyButton *F;
    keyButton *G;
    keyButton *H;
    keyButton *J;
    keyButton *K;
    keyButton *L;
    keyButton *Z;
    keyButton *X;
    keyButton *C;
    keyButton *V;
    keyButton *B;
    keyButton *N;
    keyButton *M;
    keyButton *lock;
    keyButton *num1;
    keyButton *num2;
    keyButton *num3;
    keyButton *num4;
    keyButton *num5;
    keyButton *num6;
    keyButton *num7;
    keyButton *num8;
    keyButton *num9;
    keyButton *num0;
    keyButton *backspace;
    keyButton *point;
    keyButton *leftLine;
    keyButton *rightLine;
    keyButton *semicolon;
    keyButton *question;
    keyButton *minus;
    keyButton *comma;

    void setupUi(QWidget *keyBoard)
    {
        if (keyBoard->objectName().isEmpty())
            keyBoard->setObjectName(QString::fromUtf8("keyBoard"));
        keyBoard->resize(740, 170);
        keyBoard->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        Q = new keyButton(keyBoard);
        Q->setObjectName(QString::fromUtf8("Q"));
        Q->setGeometry(QRect(50, 50, 51, 31));
        Q->setFocusPolicy(Qt::TabFocus);
        W = new keyButton(keyBoard);
        W->setObjectName(QString::fromUtf8("W"));
        W->setGeometry(QRect(110, 50, 51, 31));
        W->setFocusPolicy(Qt::TabFocus);
        E = new keyButton(keyBoard);
        E->setObjectName(QString::fromUtf8("E"));
        E->setGeometry(QRect(170, 50, 51, 31));
        E->setFocusPolicy(Qt::TabFocus);
        R = new keyButton(keyBoard);
        R->setObjectName(QString::fromUtf8("R"));
        R->setGeometry(QRect(230, 50, 51, 31));
        R->setFocusPolicy(Qt::TabFocus);
        T = new keyButton(keyBoard);
        T->setObjectName(QString::fromUtf8("T"));
        T->setGeometry(QRect(290, 50, 51, 31));
        T->setFocusPolicy(Qt::TabFocus);
        Y = new keyButton(keyBoard);
        Y->setObjectName(QString::fromUtf8("Y"));
        Y->setGeometry(QRect(350, 50, 51, 31));
        Y->setFocusPolicy(Qt::TabFocus);
        U = new keyButton(keyBoard);
        U->setObjectName(QString::fromUtf8("U"));
        U->setGeometry(QRect(410, 50, 51, 31));
        U->setFocusPolicy(Qt::TabFocus);
        I = new keyButton(keyBoard);
        I->setObjectName(QString::fromUtf8("I"));
        I->setGeometry(QRect(470, 50, 51, 31));
        I->setFocusPolicy(Qt::TabFocus);
        O = new keyButton(keyBoard);
        O->setObjectName(QString::fromUtf8("O"));
        O->setGeometry(QRect(530, 50, 51, 31));
        O->setFocusPolicy(Qt::TabFocus);
        P = new keyButton(keyBoard);
        P->setObjectName(QString::fromUtf8("P"));
        P->setGeometry(QRect(590, 50, 51, 31));
        P->setFocusPolicy(Qt::TabFocus);
        A = new keyButton(keyBoard);
        A->setObjectName(QString::fromUtf8("A"));
        A->setGeometry(QRect(80, 90, 51, 31));
        A->setFocusPolicy(Qt::TabFocus);
        S = new keyButton(keyBoard);
        S->setObjectName(QString::fromUtf8("S"));
        S->setGeometry(QRect(140, 90, 51, 31));
        S->setFocusPolicy(Qt::TabFocus);
        D = new keyButton(keyBoard);
        D->setObjectName(QString::fromUtf8("D"));
        D->setGeometry(QRect(200, 90, 51, 31));
        D->setFocusPolicy(Qt::TabFocus);
        F = new keyButton(keyBoard);
        F->setObjectName(QString::fromUtf8("F"));
        F->setGeometry(QRect(260, 90, 51, 31));
        F->setFocusPolicy(Qt::TabFocus);
        G = new keyButton(keyBoard);
        G->setObjectName(QString::fromUtf8("G"));
        G->setGeometry(QRect(320, 90, 51, 31));
        G->setFocusPolicy(Qt::TabFocus);
        H = new keyButton(keyBoard);
        H->setObjectName(QString::fromUtf8("H"));
        H->setGeometry(QRect(380, 90, 51, 31));
        H->setFocusPolicy(Qt::TabFocus);
        J = new keyButton(keyBoard);
        J->setObjectName(QString::fromUtf8("J"));
        J->setGeometry(QRect(440, 90, 51, 31));
        J->setFocusPolicy(Qt::TabFocus);
        K = new keyButton(keyBoard);
        K->setObjectName(QString::fromUtf8("K"));
        K->setGeometry(QRect(500, 90, 51, 31));
        K->setFocusPolicy(Qt::TabFocus);
        L = new keyButton(keyBoard);
        L->setObjectName(QString::fromUtf8("L"));
        L->setGeometry(QRect(560, 90, 51, 31));
        L->setFocusPolicy(Qt::TabFocus);
        Z = new keyButton(keyBoard);
        Z->setObjectName(QString::fromUtf8("Z"));
        Z->setGeometry(QRect(90, 130, 51, 31));
        Z->setFocusPolicy(Qt::TabFocus);
        X = new keyButton(keyBoard);
        X->setObjectName(QString::fromUtf8("X"));
        X->setGeometry(QRect(150, 130, 51, 31));
        X->setFocusPolicy(Qt::TabFocus);
        C = new keyButton(keyBoard);
        C->setObjectName(QString::fromUtf8("C"));
        C->setGeometry(QRect(210, 130, 51, 31));
        C->setFocusPolicy(Qt::TabFocus);
        V = new keyButton(keyBoard);
        V->setObjectName(QString::fromUtf8("V"));
        V->setGeometry(QRect(270, 130, 51, 31));
        V->setFocusPolicy(Qt::TabFocus);
        B = new keyButton(keyBoard);
        B->setObjectName(QString::fromUtf8("B"));
        B->setGeometry(QRect(330, 130, 51, 31));
        B->setFocusPolicy(Qt::TabFocus);
        N = new keyButton(keyBoard);
        N->setObjectName(QString::fromUtf8("N"));
        N->setGeometry(QRect(390, 130, 51, 31));
        N->setFocusPolicy(Qt::TabFocus);
        M = new keyButton(keyBoard);
        M->setObjectName(QString::fromUtf8("M"));
        M->setGeometry(QRect(450, 130, 51, 31));
        M->setFocusPolicy(Qt::TabFocus);
        lock = new keyButton(keyBoard);
        lock->setObjectName(QString::fromUtf8("lock"));
        lock->setGeometry(QRect(10, 130, 71, 31));
        lock->setFocusPolicy(Qt::TabFocus);
        num1 = new keyButton(keyBoard);
        num1->setObjectName(QString::fromUtf8("num1"));
        num1->setGeometry(QRect(10, 10, 51, 31));
        num1->setFocusPolicy(Qt::TabFocus);
        num2 = new keyButton(keyBoard);
        num2->setObjectName(QString::fromUtf8("num2"));
        num2->setGeometry(QRect(70, 10, 51, 31));
        num2->setFocusPolicy(Qt::TabFocus);
        num3 = new keyButton(keyBoard);
        num3->setObjectName(QString::fromUtf8("num3"));
        num3->setGeometry(QRect(130, 10, 51, 31));
        num3->setFocusPolicy(Qt::TabFocus);
        num4 = new keyButton(keyBoard);
        num4->setObjectName(QString::fromUtf8("num4"));
        num4->setGeometry(QRect(190, 10, 51, 31));
        num4->setFocusPolicy(Qt::TabFocus);
        num5 = new keyButton(keyBoard);
        num5->setObjectName(QString::fromUtf8("num5"));
        num5->setGeometry(QRect(250, 10, 51, 31));
        num5->setFocusPolicy(Qt::TabFocus);
        num6 = new keyButton(keyBoard);
        num6->setObjectName(QString::fromUtf8("num6"));
        num6->setGeometry(QRect(310, 10, 51, 31));
        num6->setFocusPolicy(Qt::TabFocus);
        num7 = new keyButton(keyBoard);
        num7->setObjectName(QString::fromUtf8("num7"));
        num7->setGeometry(QRect(370, 10, 51, 31));
        num7->setFocusPolicy(Qt::TabFocus);
        num8 = new keyButton(keyBoard);
        num8->setObjectName(QString::fromUtf8("num8"));
        num8->setGeometry(QRect(430, 10, 51, 31));
        num8->setFocusPolicy(Qt::TabFocus);
        num9 = new keyButton(keyBoard);
        num9->setObjectName(QString::fromUtf8("num9"));
        num9->setGeometry(QRect(490, 10, 51, 31));
        num9->setFocusPolicy(Qt::TabFocus);
        num0 = new keyButton(keyBoard);
        num0->setObjectName(QString::fromUtf8("num0"));
        num0->setGeometry(QRect(550, 10, 51, 31));
        num0->setFocusPolicy(Qt::TabFocus);
        backspace = new keyButton(keyBoard);
        backspace->setObjectName(QString::fromUtf8("backspace"));
        backspace->setGeometry(QRect(670, 10, 61, 31));
        point = new keyButton(keyBoard);
        point->setObjectName(QString::fromUtf8("point"));
        point->setGeometry(QRect(510, 130, 51, 31));
        point->setFocusPolicy(Qt::TabFocus);
        leftLine = new keyButton(keyBoard);
        leftLine->setObjectName(QString::fromUtf8("leftLine"));
        leftLine->setGeometry(QRect(570, 130, 51, 31));
        leftLine->setFocusPolicy(Qt::TabFocus);
        rightLine = new keyButton(keyBoard);
        rightLine->setObjectName(QString::fromUtf8("rightLine"));
        rightLine->setGeometry(QRect(650, 50, 51, 31));
        semicolon = new keyButton(keyBoard);
        semicolon->setObjectName(QString::fromUtf8("semicolon"));
        semicolon->setGeometry(QRect(680, 90, 51, 31));
        question = new keyButton(keyBoard);
        question->setObjectName(QString::fromUtf8("question"));
        question->setGeometry(QRect(630, 130, 51, 31));
        minus = new keyButton(keyBoard);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setGeometry(QRect(610, 10, 51, 31));
        comma = new keyButton(keyBoard);
        comma->setObjectName(QString::fromUtf8("comma"));
        comma->setGeometry(QRect(620, 90, 51, 31));
        QWidget::setTabOrder(num1, W);
        QWidget::setTabOrder(W, E);
        QWidget::setTabOrder(E, R);
        QWidget::setTabOrder(R, T);
        QWidget::setTabOrder(T, Y);
        QWidget::setTabOrder(Y, U);
        QWidget::setTabOrder(U, I);
        QWidget::setTabOrder(I, O);
        QWidget::setTabOrder(O, P);
        QWidget::setTabOrder(P, A);
        QWidget::setTabOrder(A, S);
        QWidget::setTabOrder(S, D);
        QWidget::setTabOrder(D, F);
        QWidget::setTabOrder(F, G);
        QWidget::setTabOrder(G, H);
        QWidget::setTabOrder(H, J);
        QWidget::setTabOrder(J, K);
        QWidget::setTabOrder(K, L);
        QWidget::setTabOrder(L, Z);
        QWidget::setTabOrder(Z, X);
        QWidget::setTabOrder(X, C);
        QWidget::setTabOrder(C, V);
        QWidget::setTabOrder(V, B);
        QWidget::setTabOrder(B, N);
        QWidget::setTabOrder(N, M);
        QWidget::setTabOrder(M, lock);
        QWidget::setTabOrder(lock, Q);
        QWidget::setTabOrder(Q, num2);
        QWidget::setTabOrder(num2, num3);
        QWidget::setTabOrder(num3, num4);
        QWidget::setTabOrder(num4, num5);
        QWidget::setTabOrder(num5, num6);
        QWidget::setTabOrder(num6, num7);
        QWidget::setTabOrder(num7, num8);
        QWidget::setTabOrder(num8, num9);
        QWidget::setTabOrder(num9, num0);
        QWidget::setTabOrder(num0, backspace);
        QWidget::setTabOrder(backspace, point);
        QWidget::setTabOrder(point, leftLine);
        QWidget::setTabOrder(leftLine, rightLine);
        QWidget::setTabOrder(rightLine, semicolon);
        QWidget::setTabOrder(semicolon, question);
        QWidget::setTabOrder(question, minus);
        QWidget::setTabOrder(minus, comma);

        retranslateUi(keyBoard);

        QMetaObject::connectSlotsByName(keyBoard);
    } // setupUi

    void retranslateUi(QWidget *keyBoard)
    {
        keyBoard->setWindowTitle(QApplication::translate("keyBoard", "Form", 0, QApplication::UnicodeUTF8));
        Q->setText(QApplication::translate("keyBoard", "Q", 0, QApplication::UnicodeUTF8));
        W->setText(QApplication::translate("keyBoard", "W", 0, QApplication::UnicodeUTF8));
        E->setText(QApplication::translate("keyBoard", "E", 0, QApplication::UnicodeUTF8));
        R->setText(QApplication::translate("keyBoard", "R", 0, QApplication::UnicodeUTF8));
        T->setText(QApplication::translate("keyBoard", "T", 0, QApplication::UnicodeUTF8));
        Y->setText(QApplication::translate("keyBoard", "Y", 0, QApplication::UnicodeUTF8));
        U->setText(QApplication::translate("keyBoard", "U", 0, QApplication::UnicodeUTF8));
        I->setText(QApplication::translate("keyBoard", "I", 0, QApplication::UnicodeUTF8));
        O->setText(QApplication::translate("keyBoard", "O", 0, QApplication::UnicodeUTF8));
        P->setText(QApplication::translate("keyBoard", "P", 0, QApplication::UnicodeUTF8));
        A->setText(QApplication::translate("keyBoard", "A", 0, QApplication::UnicodeUTF8));
        S->setText(QApplication::translate("keyBoard", "S", 0, QApplication::UnicodeUTF8));
        D->setText(QApplication::translate("keyBoard", "D", 0, QApplication::UnicodeUTF8));
        F->setText(QApplication::translate("keyBoard", "F", 0, QApplication::UnicodeUTF8));
        G->setText(QApplication::translate("keyBoard", "G", 0, QApplication::UnicodeUTF8));
        H->setText(QApplication::translate("keyBoard", "H", 0, QApplication::UnicodeUTF8));
        J->setText(QApplication::translate("keyBoard", "J", 0, QApplication::UnicodeUTF8));
        K->setText(QApplication::translate("keyBoard", "K", 0, QApplication::UnicodeUTF8));
        L->setText(QApplication::translate("keyBoard", "L", 0, QApplication::UnicodeUTF8));
        Z->setText(QApplication::translate("keyBoard", "Z", 0, QApplication::UnicodeUTF8));
        X->setText(QApplication::translate("keyBoard", "X", 0, QApplication::UnicodeUTF8));
        C->setText(QApplication::translate("keyBoard", "C", 0, QApplication::UnicodeUTF8));
        V->setText(QApplication::translate("keyBoard", "V", 0, QApplication::UnicodeUTF8));
        B->setText(QApplication::translate("keyBoard", "B", 0, QApplication::UnicodeUTF8));
        N->setText(QApplication::translate("keyBoard", "N", 0, QApplication::UnicodeUTF8));
        M->setText(QApplication::translate("keyBoard", "M", 0, QApplication::UnicodeUTF8));
        lock->setText(QApplication::translate("keyBoard", "unlocked", 0, QApplication::UnicodeUTF8));
        num1->setText(QApplication::translate("keyBoard", "1", 0, QApplication::UnicodeUTF8));
        num2->setText(QApplication::translate("keyBoard", "2", 0, QApplication::UnicodeUTF8));
        num3->setText(QApplication::translate("keyBoard", "3", 0, QApplication::UnicodeUTF8));
        num4->setText(QApplication::translate("keyBoard", "4", 0, QApplication::UnicodeUTF8));
        num5->setText(QApplication::translate("keyBoard", "5", 0, QApplication::UnicodeUTF8));
        num6->setText(QApplication::translate("keyBoard", "6", 0, QApplication::UnicodeUTF8));
        num7->setText(QApplication::translate("keyBoard", "7", 0, QApplication::UnicodeUTF8));
        num8->setText(QApplication::translate("keyBoard", "8", 0, QApplication::UnicodeUTF8));
        num9->setText(QApplication::translate("keyBoard", "9", 0, QApplication::UnicodeUTF8));
        num0->setText(QApplication::translate("keyBoard", "0", 0, QApplication::UnicodeUTF8));
        backspace->setText(QApplication::translate("keyBoard", "back", 0, QApplication::UnicodeUTF8));
        point->setText(QApplication::translate("keyBoard", ".", 0, QApplication::UnicodeUTF8));
        leftLine->setText(QApplication::translate("keyBoard", "/", 0, QApplication::UnicodeUTF8));
        rightLine->setText(QApplication::translate("keyBoard", "\\", 0, QApplication::UnicodeUTF8));
        semicolon->setText(QApplication::translate("keyBoard", ";", 0, QApplication::UnicodeUTF8));
        question->setText(QApplication::translate("keyBoard", "?", 0, QApplication::UnicodeUTF8));
        minus->setText(QApplication::translate("keyBoard", "-", 0, QApplication::UnicodeUTF8));
        comma->setText(QApplication::translate("keyBoard", ",", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class keyBoard: public Ui_keyBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
