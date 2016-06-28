#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QResizeEvent>


namespace Ui {
class keyBoard;
}

class keyBoard : public QWidget
{
    Q_OBJECT

public:
    explicit keyBoard(QWidget *parent = 0);
    ~keyBoard();
    QWidget *inputWidget;
    bool islocked;
public slots:
    void gainFocus();

private slots:
    void on_lock_clicked();

    void resizeEvent(QResizeEvent *);


private:
    Ui::keyBoard *ui;
};

#endif // KEYBOARD_H
