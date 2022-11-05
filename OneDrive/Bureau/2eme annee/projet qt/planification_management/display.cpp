#include "display.h"
#include "ui_display.h"

display::display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);
}

display::~display()
{
    delete ui;
}
