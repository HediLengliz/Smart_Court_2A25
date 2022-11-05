#include "dell.h"
#include "ui_dell.h"

dell::dell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dell)
{
    ui->setupUi(this);
}

dell::~dell()
{
    delete ui;
}
