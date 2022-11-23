#include "verifcin.h"
#include "ui_verifcin.h"
#include <QVBoxLayout>
#include <QWidget>

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
        else
            QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                QObject::tr("Check the ID_OBJ and the objectives.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("SEARCH FAILED"),
                    QObject::tr("Employee couldn't be founded.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

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
        {
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
                ui->Doing->setChecked(true);
                ui->ToDo->setEnabled(false);
                ui->Done->setEnabled(false);
                ui->Undone->setEnabled(false);
            }
            if (T == "Undone")
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
        if (O.verifdate(idobj))
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                        QObject::tr("The employee has passed the deadline .\n"
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
        if (O.verifdate(s))
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                        QObject::tr("The employee has passed the deadline .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
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
}

void verifcin::on_ADD_5_clicked()
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
        if (O.verifdate(s))
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                        QObject::tr("The employee has passed the deadline .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        else
        {
            O.modifydone(s,3);
            QMessageBox::information(nullptr, QObject::tr("Task has been found"),
                    QObject::tr("Operation has been finished successfully.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            ui->TabAff->setModel(O.afficher());
            ui->Undone->setEnabled(true);
            ui->Undone->setChecked(true);
            ui->Doing->setEnabled(false);
            ui->ToDo->setEnabled(false);
            ui->Done->setEnabled(false);
        }
    }
}

void verifcin::on_MarkDone_2_clicked()
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
        if (O.verifdate(s))
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                        QObject::tr("The employee has passed the deadline .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        else
        {
            O.modifydone(s,4);
            QMessageBox::information(nullptr, QObject::tr("Task has been found"),
                    QObject::tr("Operation has been finished successfully.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            ui->TabAff->setModel(O.afficher());
            ui->Doing->setEnabled(true);
            ui->Doing->setChecked(true);
            ui->Undone->setEnabled(false);
            ui->ToDo->setEnabled(false);
            ui->Done->setEnabled(false);
        }
    }
}

void verifcin::on_ADD_3_clicked()
{
    QDate D;
    QString id;
    QDate st;
    QSqlQuery query,query2;
    query.prepare("SELECT ID_OBJ,DEADLINE FROM OBJECTIVE where STATE <> 'Done'");
    if(query.exec())
    {
        while(query.next())
        {
            id = query.value(0).toString();
            st = query.value(1).toDate();
            if (st <= D.currentDate())
            {
                query2.prepare("UPDATE OBJECTIVE SET STATE = 'Undone' where ID_OBJ = :ID_OBJ");
                query2.bindValue(":ID_OBJ",id);
                query2.exec();
                if (ui->Tidobj->text() == id)
                {
                    ui->Undone->setEnabled(true);
                    ui->Undone->setChecked(true);
                    ui->Doing->setEnabled(false);
                    ui->ToDo->setEnabled(false);
                    ui->Done->setEnabled(false);
                }
            }
        }
    }
    ui->TabAff->setModel(O.afficher());
    QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
            QObject::tr("Operation has been finished successfully\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void verifcin::on_ADD_6_clicked()
{
    QString s = ui->Tidobj->text();
    if(O.del(s))
    {
        QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
                QObject::tr("Operation has been finished successfully\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
        ui->TabAff->setModel(O.afficher());
        ui->Undone->setEnabled(false);
        ui->Doing->setEnabled(false);
        ui->ToDo->setEnabled(false);
        ui->Done->setEnabled(false);
        ui->Tidobj->setText("");
        ui->Tcin->setText("");
        ui->Tdescr->setText("");
        ui->Tdeadday->setText("");
        ui->Tdeadmonth->setText("");
        ui->Tdeadyear->setText("");
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("The employee couldn't be deleted .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void verifcin::on_ADD_11_clicked()
{
    int cin = ui->CIN->text().toInt();

    int sum;
    if (E.verifcin(cin))
    {
        if (O.verifemp(cin))
        {
            qDeleteAll(ui->widgett->children());
            ui->TabAff2->setModel(O.objemployee(QString::number(cin)));
            O.stat(&sum,&fin,&unfin,&doi,&tod,QString::number(cin));
            ui->SUM->setText(QString::number(sum));
            ui->FIN->setText(QString::number(fin));
            ui->UNFIN->setText(QString::number(unfin));
            ui->DOI->setText(QString::number(doi));
            ui->TOD->setText(QString::number(tod));

            QPieSeries *series = new QPieSeries();
            series->append("Done",fin);
            series->append("Undone",unfin);
            series->append("In Progress",doi);
            series->append("To do",tod);

            QPieSlice *slice = series->slices().at(1);
            slice->setExploded(true);
            slice->setLabelVisible();
            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTitle("The statistics of This Employee");

            QChartView *chartview = new QChartView(chart);
            chartview->setRenderHint(QPainter::Antialiasing);
            QVBoxLayout *mainLayout = new QVBoxLayout;
            mainLayout ->addWidget(chartview);
            ui->widgett->setLayout(mainLayout);
            ui->widgett->show();
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("SEARCH FAILED"),
                    QObject::tr("Employee couldn't be founded.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void verifcin::on_ADD_12_clicked()
{
    cihart = new Cihart(this);
    cihart->show();
}

void verifcin::on_ADD_13_clicked()
{
    QString cin = ui->LCIN->text();
    QSqlQuery query;
    int row_count = 0;
    query.prepare("SELECT * FROM EMPLOYEE where CIN=:CIN");
    query.bindValue(":CIN",cin);
    if (query.exec())
    {
        while(query.next() && row_count != 1)
             row_count++;
        if(row_count == 1)
        {
            query.prepare("UPDATE EMPLOYEE SET ABSENCE = ABSENCE + 1 where CIN=:CIN");
            query.bindValue(":CIN",cin);
            if (query.exec())
                QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
                        QObject::tr("Operation has been finished successfully\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            else
                QMessageBox::critical(nullptr, QObject::tr("SEARCH FAILED"),
                            QObject::tr("Task couldn't get done.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("TASK FAILED"),
                        QObject::tr("Employee couldn't be founded.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("CHECK YOUR DATABASE\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void verifcin::on_ADD_14_clicked()
{
    hide();
}

void verifcin::on_EXIT_3_clicked()
{
    hide();
}
