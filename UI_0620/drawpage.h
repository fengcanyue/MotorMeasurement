#ifndef DRAWPAGE_H
#define DRAWPAGE_H

#include <QWidget>
#include "picture.h"
#include <QResizeEvent>
#include "mycombobox.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <QTimer>
#include "datastack.h"
#include "pdfheaderedit.h"
#define  KEY  1234
extern DataStack datastack;
typedef struct {
long type;
unsigned char datagram[8];
}msg_buff;
namespace Ui {
class DrawPage;
}

class DrawPage : public QWidget
{
    Q_OBJECT

public:
    explicit DrawPage(QWidget *parent = 0);
    myComboBox * switchButton;
    Picture *speedpage,*Nmpage,*Kwpage;
    myButton *startButton;
    QTimer *timer;
    typedef    enum {STARTED,STOPPED}Status;
    Status status;
    pdfHeaderEdit *pdf;

private:

public slots:
    void changPage(int arg);
    void getYmax(QList<qreal> list);

private slots:
    void resizeEvent(QResizeEvent *);
    void collectData();
};

#endif // DRAWPAGE_H
