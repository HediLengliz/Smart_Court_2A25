#include "dell.h"
#include "ui_dell.h"
#include "room.h"
#include <QMessageBox>

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

void dell::on_DELL_clicked()
{
     int ID_ROOM= ui->LRI->text().toInt();

     if (r.deleteroom(ID_ROOM))
     {
         QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                     QObject::tr("The room has been deleted successfully.\n"
                                 "Click OK to exit"), QMessageBox::Ok);
         hide();
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Failed"),
                     QObject::tr("The room couldn't be deleted."
                                 "Click Cancel to verify."), QMessageBox::Cancel);
}
