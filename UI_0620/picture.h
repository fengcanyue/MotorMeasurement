#ifndef PICTURE_H
#define PICTURE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QFile>
#include <QList>
#include <QLine>
#include <QTextStream>
#include <QKeyEvent>
#include <QDebug>
#include <QPixmap>
#include <QResizeEvent>
#include <QLabel>
#include "page_1.h"
namespace Ui {
class Picture;
}

class Picture : public QWidget
{
    Q_OBJECT

public:
    explicit Picture(QWidget *parent = 0);
    ~Picture();
    Ui::Picture *ui;
    QList<double> values;
    qreal yMax;
    QLabel *label;
    double xunit,yunit;
signals:
public slots:
    void paintEvent(QPaintEvent *);


private slots:

    void on_xRange_currentIndexChanged(int);

    void on_y1Property_currentIndexChanged(int);

    void keyPressEvent(QKeyEvent *);

    void resizeEvent(QResizeEvent*);

    void drawDataLine(QPainter &p,double dx,double dy);

private:
    int x_init;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // PICTURE_H
