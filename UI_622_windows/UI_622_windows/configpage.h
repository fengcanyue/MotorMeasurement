#ifndef CONFIGPAGE_H
#define CONFIGPAGE_H

#include <QWidget>
#include <QResizeEvent>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QShowEvent>
#include <QStringList>
#include "page_1.h"

extern QStackedWidget *stack;
namespace Ui {
class ConfigPage;
}

class ConfigPage : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigPage(QWidget *parent = 0);
    ~ConfigPage();
    Ui::ConfigPage *ui;
    Page_1 *p1;
signals:
    void configureChanged(double torsion_max,double duration);
public slots:
    void on_cancelButton_clicked();
    void on_okButton_clicked();
    void torsion2zero();
private slots:
    void resizeEvent(QResizeEvent *);


private:

};

#endif // CONFIGPAGE_H
