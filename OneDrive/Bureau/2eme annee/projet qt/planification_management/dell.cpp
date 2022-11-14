#include "dell.h"
#include "ui_dell.h"
#include <QMessageBox>
#include "room.h"

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

void dell::on_DELETE_clicked()
{
   int ID_ROOM = ui->LRI->text().toInt();

    if(r.deleteroom(ID_ROOM))
    {
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The room has been Deleted successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
        hide();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("The room couldn't be Deleted."
                                "Click Cancel to verify."), QMessageBox::Cancel);
}
