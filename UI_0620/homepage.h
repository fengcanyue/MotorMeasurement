#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

namespace Ui {
class homePage;
}

class homePage : public QWidget
{
    Q_OBJECT

public:
    explicit homePage(QWidget *parent = 0);
    ~homePage();

private:
    Ui::homePage *ui;
};

#endif // HOMEPAGE_H
