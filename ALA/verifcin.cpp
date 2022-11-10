#include "verifcin.h"
#include "ui_verifcin.h"

verifcin::verifcin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verifcin)
{
    ui->setupUi(this);
    ui->TabAff->setModel(O.afficher());
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start();
}

verifcin::~verifcin()
{
    delete ui;
}

void verifcin::on_EXIT_clicked()
{
    hide();
}

void verifcin::on_ADD_clicked()
{
    int cin = ui->LCin->text().toInt();
    QString idroom = ui->LIdroom->text();
    int idobj = ui->LObj->text().toInt();
    QString descr = ui->LDescr->text();
    int day=ui->LDEADLINE->selectedDate().day();
    int month=ui->LDEADLINE->selectedDate().month();
    int year=ui->LDEADLINE->selectedDate().year();
    QDate D(year,month,day);
    Objective o(idobj,cin,descr,idroom,D);
    if (E.verifcin(cin))
    {
        if(o.ajouter())
        {
            QMessageBox::information(nullptr, QObject::tr("Employee has been found"),
                    QObject::tr("Operation has been finished successfully.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            ui->TabAff->setModel(O.afficher());
        }
    }
    else
        E.ERROR();

}

void verifcin::on_TabAff_activated(const QModelIndex &index)
{
    QString val=ui->TabAff->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from OBJECTIVE where ID_OBJ = :ID_OBJ");
    query.bindValue(":ID_OBJ",val);
    if (query.exec())
    {
        if (query.next())
            ui->Tidobj->setText(query.value(0).toString());
            ui->Tcin->setText(query.value(1).toString());
            ui->Tdescr->setText(query.value(2).toString());
            QString T = query.value(3).toString();
            if (T == "Done")
            {
                ui->Done->setEnabled(true);
                ui->Done->setChecked(true);
                ui->ToDo->setEnabled(false);
                ui->Doing->setEnabled(false);
                ui->Undone->setEnabled(false);
            }
            if (T == "To Do")
            {
                ui->ToDo->setEnabled(true);
                ui->ToDo->setChecked(true);
                ui->Doing->setEnabled(false);
                ui->Undone->setEnabled(false);
                ui->Done->setEnabled(false);
            }
            if (T == "Doing")
            {
                ui->Doing->setEnabled(true);
                ui->Doing->setChecked(false);
                ui->ToDo->setEnabled(false);
                ui->Doing->setEnabled(true);
                ui->Undone->setEnabled(false);
            }
            if (T == "UnDone")
            {
                ui->Undone->setEnabled(true);
                ui->Undone->setChecked(true);
                ui->ToDo->setEnabled(false);
                ui->Doing->setEnabled(false);
                ui->Done->setChecked(false);
            }
            //ui->Tstate->setText(query.value(3).toString());
            ui->Tidroom->setText(query.value(4).toString());
            QDate D = query.value(5).toDate();
            ui->Tdeadday->setText(QString::number(D.day()));
            ui->Tdeadmonth->setText(QString::number(D.month()));
            ui->Tdeadyear->setText(QString::number(D.year()));
    }
}

void verifcin::showtime()
{
    QTime timee = QTime::currentTime();
    int s = timee.second();
    int h = timee.hour();
    int m = timee.minute();
    QString ss = QString::number(s);
    QString mm = QString::number(m);
    QString hh = QString::number(h);
    QString time = (hh+" : "+mm+" : "+ss);
    ui->Time->setText(time);
}



void verifcin::on_MarkDone_clicked()
{
    QString idobj = ui->Tidobj->text();
    if (idobj == "")
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("Please select a task from the table .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        O.modifydone(idobj,1);
        QMessageBox::information(nullptr, QObject::tr("Task has been found"),
                QObject::tr("Operation has been finished successfully.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
        ui->TabAff->setModel(O.afficher());
        ui->Done->setEnabled(true);
        ui->Done->setChecked(true);
        ui->ToDo->setEnabled(false);
        ui->Doing->setEnabled(false);
        ui->Undone->setEnabled(false);
    }

}

void verifcin::on_EXIT_2_clicked()
{
    hide();
}

void verifcin::on_ADD_7_clicked()
{
    QString s = ui->Tidobj->text();
    if (s == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("Please select a task from the table .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        O.modifydone(s,2);
        QMessageBox::information(nullptr, QObject::tr("Task has been found"),
                QObject::tr("Operation has been finished successfully.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
        ui->TabAff->setModel(O.afficher());
        ui->ToDo->setEnabled(true);
        ui->ToDo->setChecked(true);
        ui->Doing->setEnabled(false);
        ui->Undone->setEnabled(false);
        ui->Done->setEnabled(false);
    }
}
