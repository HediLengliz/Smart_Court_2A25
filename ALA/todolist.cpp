#include "todolist.h"
#include "ui_todolist.h"
#include <QMessageBox>

todolist::todolist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::todolist)
{
    ui->setupUi(this);
    if(O.CIN == 11445179)
        QMessageBox::information(nullptr, QObject::tr("Employee has been found"),
                    QObject::tr("Operation has been finished successfully.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

todolist::~todolist()
{
    delete ui;
}
