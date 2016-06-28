#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QKeyEvent>
#include <QFocusEvent>
#include <QStackedWidget>
#include <QResizeEvent>
class myButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent = 0);
    QString color;

signals:

public slots:
    void focusInEvent(QFocusEvent *){
        setStyleSheet("border-style: inset; border-width: 3px;border-radius: 20px;border-color:rgb(255, 20, 110);padding:-99999;background-color:red;color:black;");
    }
    void focusOutEvent(QFocusEvent *){
        setStyleSheet("border-style: inset; border-width: 3px;border-radius: 20px;border-color:rgb(46, 130, 255);padding:-99999;background-color:blue;color:black;");
    }
    void keyPressEvent(QKeyEvent *k);
    void keyReleaseEvent(QKeyEvent *k);
    void resizeEvent(QResizeEvent *);

};

#endif // MYBUTTON_H
