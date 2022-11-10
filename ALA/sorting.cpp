#include "sorting.h"
#include "ui_sorting.h"

Sorting::Sorting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sorting)
{
    ui->setupUi(this);
}

Sorting::~Sorting()
{
    delete ui;
}

void Sorting::on_SET_clicked()
{
    int MIN = ui->MIN->text().toInt();
    int MAX = ui->MAX->text().toFloat();
    ui->TabAff->setModel(E.sorting(MIN,MAX));
}

void Sorting::on_EXIT_clicked()
{
    hide();
}
void Sorting::on_SET_2_clicked()
{
    ui->TabAff->setModel(E.sortingall());
}
