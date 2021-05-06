#include "web.h"
#include "ui_web.h"

web::web(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::web)
{
    ui->setupUi(this);
}

web::~web()
{
    delete ui;
}
