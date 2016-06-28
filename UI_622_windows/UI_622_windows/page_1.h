#ifndef PAGE_1_H
#define PAGE_1_H

#include <QWidget>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QPaintEvent>
#include <QPainter>
#include "mywatch.h"
#include "mybutton.h"
#include <QTimer>
#include "datastack.h"
#include <QFile>
#include "myspinbox.h"
extern DataStack datastack;
extern QStackedWidget *stack;
namespace Ui {
class Page_1;
}

class Page_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Page_1(QWidget *parent = 0);
    ~Page_1();
    Ui::Page_1 *ui;
    myWatch *speedWatch,*torsionWatch,*powerWatch;
    QStackedWidget *parentStack;
    QLabel *label;
    myButton *setZeroButton;
    typedef enum{StartedState,StoppedState}runningState;
    runningState state;
    int duration;
    QTimer *timer;
public slots:
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent *k){
        switch (k->key()) {
        case Qt::Key_7:
            stack->setCurrentIndex(0);
            break;
        case Qt::Key_8:
            focusPreviousChild();
            break;
        case Qt::Key_2:
            focusNextChild();
            break;
        }
    }
    void setWatchValues(double torsion, double speed);
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.setBrush(QBrush(Qt::black));
        painter.drawRect(0,0,width(),height());
    }

    void setTorsionMaxandPeriod(double torsion,double dur);

    void updateMax(double mmm);

    void startButton_clicked();

    void stopButton_clicked();
    
    void refreshUI();
signals:
    void changeTorsion(double torion);
    void changeSpeed(double speed);
    void changePower(double power);
    void getTestData(double torsion,double speed);
private slots:

    void resetAll();
};

#endif // PAGE_1_H
