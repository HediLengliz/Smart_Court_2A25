#include "aaaaaa.h"
#include "ui_aaaaaa.h"
#include"aj.h"

#include <QMessageBox>

aaaaaa::aaaaaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aaaaaa)
{
    ui->setupUi(this);
}

aaaaaa::~aaaaaa()
{
    delete ui;
}
