#ifndef PDFHEADEREDIT_H
#define PDFHEADEREDIT_H

#include <QWidget>
#include <QResizeEvent>
#include <QPrinter>
#include <QPainter>
#include <QDateTime>
#include <QStackedWidget>
#include <QPixmap>
#include "datastack.h"
#include "page_1.h"

namespace Ui {
class pdfHeaderEdit;
}

class pdfHeaderEdit : public QWidget
{
    Q_OBJECT

public:
    explicit pdfHeaderEdit(QWidget *parent = 0);
    ~pdfHeaderEdit();
    QString employeeNo;
    Ui::pdfHeaderEdit *ui;
    DataStack data2print;

public slots:
    void on_exportButton_clicked();

    void exportDataChart();

    bool exportDAtestChart(QPixmap p);

    void resizeEvent(QResizeEvent *);

private:
    int x_init;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // PDFHEADEREDIT_H
