#include "todoja.h"
#include "ui_todoja.h"

Todoja::Todoja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Todoja)
{
    ui->setupUi(this);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * from MEETING");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DAT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_LS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_A"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_AUD"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Description"));
    ui->TabAff->setModel(model);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start();
}

Todoja::~Todoja()
{
    delete ui;
}

void Todoja::on_ADD_clicked()
{
    QString idmet = ui->LMET->text();
    QString idroom = ui->LIdroom->text();
    QString ida = ui->IDA->text();
    QString idaud = ui->Tidobj->text();
    QString descr = ui->LDescr->text();
    int day=ui->LDATE->selectedDate().day();
    int month=ui->LDATE->selectedDate().month();
    int year=ui->LDATE->selectedDate().year();
    QString idls = ui->IDLS->text();
    QDate D(year,month,day);
    QDate d;
    if (D >= d.currentDate())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO MEETING (ID_MET, DAT, ID_LS, ID_A, ID_AUD, ID_ROOM, OBJ)" "VALUES(:IDMET, :DAT, :ID_LS, :ID_A, :ID_AUD, :ID_ROOM, :OBJ)");
        query.bindValue(":IDMET",idmet);
        query.bindValue(":DAT",D);
        query.bindValue(":ID_LS",idls);
        query.bindValue(":ID_A",ida);
        query.bindValue(":ID_AUD",idaud);
        query.bindValue(":ID_ROOM",idroom);
        query.bindValue(":OBJ",descr);
        if (query.exec())
        {
            QMessageBox::information(nullptr, QObject::tr("Task finished"),
                    QObject::tr("Operation has been finished successfully.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            QSqlQueryModel* model = new QSqlQueryModel();
            model->setQuery("SELECT * from MEETING");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MET"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("DAT"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_LS"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_A"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_AUD"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("Description"));
            ui->TabAff->setModel(model);
        }
        else
            QMessageBox::information(nullptr, QObject::tr("ERROR"),
                    QObject::tr("CHECK your inputs.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                QObject::tr("Out of Date.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void Todoja::on_ADD_6_clicked()
{
    QDate D;
    QString id;
    QDate st;
    QSqlQuery query,query2;
    query.prepare("SELECT ID_MET,DAT FROM MEETING");
    if(query.exec())
    {

        while(query.next())
        {
            id = query.value(0).toString();
            st = query.value(1).toDate();
            if (st <= D.currentDate())
            {
                query2.prepare("Delete from MEETING where ID_MET = :ID_MET");
                query2.bindValue(":ID_MET",id);
                query2.exec();
            }
            QMessageBox::information(nullptr, QObject::tr("Task finished"),
                    QObject::tr("Operation has been finished successfully.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            QSqlQueryModel* model = new QSqlQueryModel();
            model->setQuery("SELECT * from MEETING");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MET"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("DAT"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_LS"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_A"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_AUD"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("Description"));
            ui->TabAff->setModel(model);
        }
    }
}

void Todoja::on_EXIT_clicked()
{
    hide();
}

void Todoja::on_EXIT_2_clicked()
{
    hide();
}

void Todoja::showtime()
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
