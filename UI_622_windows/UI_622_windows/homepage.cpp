#include "homepage.h"
#include "ui_homepage.h"

homePage::homePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homePage)
{
    ui->setupUi(this);
}

homePage::~homePage()
{
    delete ui;
}
