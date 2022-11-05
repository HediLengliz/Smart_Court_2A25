#include "modify.h"
#include "ui_modify.h"
#include "room.h"
#include <QMessageBox>
Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_MOD_clicked()
{
    int ID_ROOM = ui->LRI->text().toInt();
         int pincode = ui->LCP->text().toInt();
         int number = ui->LRN->text().toInt();
         QString room_type = ui->LRT->text();
         QString creation_date = ui->LCD->text();
         QString room_state = ui->LRS->text();
         room r(ID_ROOM,pincode,number,room_type,creation_date,room_state);
         if (r.modifyroom())
         {
             QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                         QObject::tr("The room has been Modified successfully.\n"
                                     "Click OK to exit"), QMessageBox::Ok);
             hide();
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Failed"),
                         QObject::tr("The room couldn't be Modified."
                                     "Click Cancel to verify."), QMessageBox::Cancel);

}
