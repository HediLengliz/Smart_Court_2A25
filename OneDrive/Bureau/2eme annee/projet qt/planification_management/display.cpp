#include "display.h"
#include "ui_display.h"
#include "room.h"
#include <QMessageBox>

display::display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);
    ui->tableView->setModel(r.displayroom());
}

display::~display()
{
    delete ui;
}

