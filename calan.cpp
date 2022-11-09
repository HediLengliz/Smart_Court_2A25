#include "calan.h"
#include "ui_calan.h"

calan::calan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calan)
{
    ui->setupUi(this);
    QTextCharFormat f=ui->calendarWidget->weekdayTextFormat(Qt::Saturday);

            a.calendrier(f,ui->calendarWidget);
}

calan::~calan()
{
    delete ui;
}
