#include "mainwindow.h"
#include "QrCode.hpp"
#include <QPixmap>
#include <QPixmap>
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QDataStream>
#include <QDialog>
#include <QFile>
#include <ui_mainwindow.h>
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QDesktopServices>
#include <QUrl>
#include<QPainter>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QCoreApplication>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include "arduino.h"
#include "arduino1.h"
#include "statistique.h"
#include "incendie.h"
#include "smtp.h"


using namespace qrcodegen;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Add Accused validations
    ui->Lid->setValidator(new QIntValidator(0,99999999,this));
    ui->Lname->setInputMask("aaaaaaaaaaaaaaaaaaa");
        ui->Lname->setCursorPosition(0);
        ui->Llastname->setInputMask("aaaaaaaaaaaaaaaaaaa");
        ui->Lacc_cause->setInputMask("aaaaaaaaaaaaaaaaaaa");

        //Delete Accused Validations
         ui->Lsupp->setValidator(new QIntValidator(0,99999999,this));

         //Modify Accused Validations
         ui->Lmid->setValidator(new QIntValidator(0,99999999,this));
         ui->Lmname->setInputMask("aaaaaaaaaaaaaaaaaaa");
             ui->Lmname->setCursorPosition(0);
             ui->Lmlastname->setInputMask("aaaaaaaaaaaaaaaaaaa");
             ui->Lmacc_cause->setInputMask("aaaaaaaaaaaaaaaaaaa");
             ui->le_id1->setValidator(new QIntValidator(0,99999999,this));
             ui->le_nom1->setInputMask("aaaaaaaaaaaaaaaaaaa");
                     ui->le_nom1->setCursorPosition(0);
                     ui->le_prenom1->setInputMask("aaaaaaaaaaaaaaaaaaa");
                             ui->le_prenom1->setCursorPosition(0);
                             ui->le_etat1->setInputMask("aaaaaaaaaaaaaaaaaaa");
                                     ui->le_etat1->setCursorPosition(0);
                                     ui->le_numero1->setValidator(new QIntValidator(0,99999999,this));
                                     ui->le_age1->setValidator(new QIntValidator(0,99999999,this));
                                     int ret=d.connect_arduino(); // lancer la connexion à arduino

                                     switch(ret){
                                     case(0):qDebug()<< "arduino is available and connected to : "<< d.getarduino_port_name();
                                         break;
                                     case(1):qDebug() << "arduino is available but not connected to :" <<d.getarduino_port_name();
                                        break;
                                     case(-1):qDebug() << "arduino is not available";
                                     }

    ui->tabWidget->tabBar()->setEnabled(false);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);
    ret=As.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< Ar.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<Ar.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
    ret=AA.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< AA.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<AA.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
     media = new QMediaPlayer();
     media->setMedia(QUrl("qrc:/new/prefix1/icons/mixkit-positive-interface-click-1112.wav"));
     QObject::connect(As.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
     QObject::connect(AA.getserial(),SIGNAL(readyRead()),this,SLOT(update_code()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    media->play();
}

void MainWindow::on_ADD_PUSH_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
    ui->Employee->setChecked(true);
}

void MainWindow::on_add_new_employee_clicked()
{
    media->play();
    int cin = ui->LCin->text().toInt();
    int codepin = ui->LCodePin->text().toInt();
    float salary = ui->LSalary->text().toFloat();
    QString nom = ui->LName->text();
    QString prenom = ui->LSurname->text();
    QString email = ui->LEmail->text();
    QString city = ui->LCity->text();
    QString role;
    int ns = ui->LNS->text().toInt();
    int code = ui->LCode->text().toInt();
    if(ui->HR->isChecked())
        role = "HR";
    if(ui->LA->isChecked())
        role = "LA";
    if(ui->LS->isChecked())
        role = "LS";
    if(ui->Aud->isChecked())
        role = "AUD";
    if(ui->Plannificatio->isChecked())
        role = "PLAN";
    if(ui->Employee->isChecked())
        role = "EMP";
    Employee E(cin,codepin,salary,nom,prenom,email,city,ns,role,code);
    if (E.ajouter())
    {
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The employee has been added successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
        ui->tabWidget->setCurrentIndex(1);
        ui->TabAff->setModel(E.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("The employee couldn't be added.\nMake sure that : \n1- CIN and E-MAIL hasn't been used before\n2- E-MAIL is written like \"AA@aa.xx\"\n3- NAME, SURNAME, CITY has no numbers\n4- CIN should have 8 numbers and Code should have 5 ones.\nReport it if there is any error\n"
                                "Click Cancel to verify."), QMessageBox::Cancel);
}

void MainWindow::on_LIST_PUSH_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(3);
    ui->TabAff->setModel(E.afficher());
}

void MainWindow::on_add_new_employee_2_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_add_new_employee_3_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_update_clicked()
{
    media->play();
    int cin = ui->comboEmp->currentText().toInt();
    QString email = ui-> MMAIL ->text();
    QSqlQueryModel *model;
    model = new QSqlQueryModel();
    Employee E(cin,email);
    if (E.modifier(model))
    {
        ui->TabAff->setModel(model);
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The employee has been mmodified successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
        hide();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("The employee couldn't be modified.\nMake sure that : \n1- CIN and E-MAIL exists \n2- E-MAIL is written like \"AA@aa.xx\"\nReport it if there is any error\n"
                                "Click Cancel to verify."), QMessageBox::Cancel);
}

void MainWindow::on_add_new_employee_4_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_add_new_employee_5_clicked()
{
    media->play();
    Employee E;
    E.setcin(ui->comboSuppEmp->currentText().toInt());
    if (E.supprimer(E.getcin()))
    {
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The employee has been deleted successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
        hide();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("The employee couldn't be deleted.\nVerify the CIN Number if it exists or not.\nReport if there is any error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_MOD_PUSH_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(4);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT CIN FROM EMPLOYEE");
    ui->comboEmp->setModel(model);
}

void MainWindow::on_DEL_PUSH_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(5);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT CIN FROM EMPLOYEE");
    ui->comboSuppEmp->setModel(model);
}

void MainWindow::on_EXIT_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_MAX_clicked()
{
    media->play();
    n = 1;
    ui->Tabpdf->setModel(E.search(n,0,""));
}

void MainWindow::on_SCIN_clicked()
{
    media->play();
    n = 2;
    int cin = ui->SCinn->text().toInt();
    ui->TabAff->setModel(E.search(n,cin,""));
}

void MainWindow::on_SEMAIL_clicked()
{
    media->play();
    n = 3;
    QString email = ui->SEmail->text();
    ui->TabAff->setModel(E.search(n,0,email));
}

void MainWindow::on_PDF_clicked()
{
    media->play();
    if (n!=0)
    {
        E.pdf();
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The employee has been printed in a pdf file successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                    QObject::tr("You should search for an employee to be printed in a pdf file.\n"
                                "Click OK to exit"), QMessageBox::Ok);
}

void MainWindow::on_add_new_employee_6_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_SEARCH_PUSH_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(6);
}

void MainWindow::on_SET_clicked()
{
    media->play();
    int MIN = ui->MIN->text().toInt();
    int MAX = ui->MAXX->text().toFloat();
    ui->TabSort->setModel(E.sorting(MIN,MAX,&n));
}

void MainWindow::on_SET_2_clicked()
{
    media->play();
    ui->TabSort->setModel(E.sortingall(&n));
}

void MainWindow::on_ExportExcel_clicked()
{
    media->play();
    if (n == 0)
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("The Table Is Empty"))
                                 );
    else
    {
        QString fileName = "C:/thefinalproject/Employee.xls"; //changer le chem
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->TabSort);

        //colums to export
        obj.addField(0, "Nom", "char(20)");
        obj.addField(1, "Prenom", "char(20)");
        obj.addField(2, "CIN", "char(20)");
        obj.addField(3, "NumberOfSessions", "char(20)");
        obj.addField(4, "Absence", "char(20)");
        obj.addField(5, "Salary", "char(20)");


        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
    }
}



void MainWindow::on_ImportExcel_clicked()
{
    media->play();
    if (n == 0)
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("The Table Is Empty"))
                                 );
    else
    {
        QString fileName = "C:/thefinalproject/Employee.xls"; //changer le chem
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->TabSort);

        //colums to export
        obj.addField(0, "Nom", "char(20)");
        obj.addField(1, "Prenom", "char(20)");
        obj.addField(2, "CIN", "char(20)");
        obj.addField(3, "NumberOfSessions", "char(20)");
        obj.addField(4, "Absence", "char(20)");
        obj.addField(5, "Salary", "char(20)");


        obj.export2Excel();
        QString ExcelFileName  = "C:/thefinalproject/bilan.xlsx"; //changer le chem
        QDesktopServices::openUrl(QUrl(ExcelFileName, QUrl::TolerantMode));
    }
}

void MainWindow::on_SORT_PUSH_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(7);
    n = 0;
}

void MainWindow::on_EXIT_2_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->TabSort->setModel(model);
    n = 0;
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_ADD_clicked()
{
    int cin = ui->LCinn->text().toInt();
    QString idroom = ui->comboR->currentText();
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
            ui->Tabobj->setModel(O.afficher());
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

void MainWindow::on_TODOLIST_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(8);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_ROOM FROM ROOMS");
    ui->comboR->setModel(model);
    ui->Tabobj->setModel(O.afficher());
    ui->Undone->setEnabled(false);
    ui->ToDo->setEnabled(false);
    ui->Doing->setEnabled(false);
    ui->Done->setChecked(false);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start();
}

void MainWindow::on_Tabobj_activated(const QModelIndex &index)
{
    QString val=ui->Tabobj->model()->data(index).toString();
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
            ui->Tidroom->setText(query.value(4).toString());
            QDate D = query.value(5).toDate();
            ui->Tdeadday->setText(QString::number(D.day()));
            ui->Tdeadmonth->setText(QString::number(D.month()));
            ui->Tdeadyear->setText(QString::number(D.year()));
        }
   }
}


void MainWindow::on_ADD_3_clicked()
{
    media->play();
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
                        "Click OK to exit."), QMessageBox::Ok);
}

void MainWindow::on_MarkDone_clicked()
{
    media->play();
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

void MainWindow::on_ADD_5_clicked()
{
    media->play();
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


void MainWindow::on_ADD_6_clicked()
{
    media->play();
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

void MainWindow::on_MarkDone_2_clicked()
{
    media->play();
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

void MainWindow::on_ADD_7_clicked()
{
    media->play();
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



void MainWindow::on_EXIT_4_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::showtime()
{
    media->play();
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

void MainWindow::on_EXIT_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_ADD_11_clicked()
{
    media->play();
    int cin = ui->CIN->text().toInt();

    int sum;
    if (E.verifcin(cin))
    {
        if (O.verifemp(cin))
        {
            qDeleteAll(ui->widgett->children());
            ui->Tabstat->setModel(O.objemployee(QString::number(cin)));
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

void MainWindow::on_ADD_12_clicked()
{
    media->play();
    cihart = new Cihart(this);
    cihart->show();
}

void MainWindow::on_EXIT_5_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_ADD_13_clicked()
{
    media->play();
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

void MainWindow::on_ADD_14_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    media->play();
    codee = ui->LCodee->text();
    if (codee == "691470258")
    {
        ui->tabWidget->setCurrentIndex(1);
        QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
                QObject::tr("Admin Mode Has Been Activated\n"
                            "Click Ok to exit."), QMessageBox::Ok);
        ui->LCodee->setText("");
    }
    QSqlQuery query;
    query.prepare("SELECT ROLE from EMPLOYEE where CODE = :code");
    query.bindValue(":code",codee);
    if (query.exec())
    {
        if(query.next())
        {
            QString r;
            r = query.value(0).toString();
            if (r == "HR")
            {
                QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
                        QObject::tr("Operation has been finished successfully\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
                ui->tabWidget->setCurrentIndex(1);
            }
            if (r == "PLAN")
            {
                QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
                        QObject::tr("Operation has been finished successfully\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
                ui->tabWidget->setCurrentIndex(9);
            }
            if (r == "LA")
            {
                QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
                        QObject::tr("Operation has been finished successfully\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
                ui->tabWidget->setCurrentIndex(13);
            }
            if (r == "LS")
            {
                QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
                        QObject::tr("Operation has been finished successfully\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
                ui->tabWidget->setCurrentIndex(21);
            }

        }
        else
           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                        QObject::tr("Code does not exist\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->LCodee->setText("");
}

void MainWindow::on_DEL_PUSH_2_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_DEL_PUSH_3_clicked()
{
    media->play();
    QString link = "https://justiceleague.daily.co/9NK3LI2zsQSw0hc6KniN";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::update_label()
{
    data=As.read_from_arduino();
    if(data=="1")
        ui->label_49->setText("NOICE DETECTED"); // si les données reçues de arduino via la liaison série sont égales à 1
    notif m("NOISE DETECTED","ROOM STATE: FULL");
    m.afficher();
}


void MainWindow::update_code()
{
    data=Ar.read_from_arduino();
    QString d = data;
    d = d.simplified();
    d.replace(" ","");
    if ((d == "C")||(d == "D"))
    {
        if (d == "C")
           ui->LCodee->setText("");
        else
            on_pushButton_9_clicked();
    }
    else
    {
        if ((d != "*")||(d!="#")||(d!="A")||(d!="B"))
        {
            QString s = ui->LCodee->text();
            s = s+d;
            ui->LCodee->setText(s);
        }
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(9);
}

void MainWindow::on_ADD_19_clicked()
{
    media->play();
    int ID_ROOM = ui->LRI->text().toInt();
    QString ID_ROOMs = ui->LRI->text();
        QString pincode = ui->LCP->text();
        QString number = ui->LRN->text();
        QString room_type = ui->LRT->text();
        QString creation_date = ui->dateEdit->date().toString();
        QString room_state = ui->LRS->text();
        room r(ID_ROOM,pincode,number,room_type,creation_date,room_state);
        //cout<<r.getpincode().toInt()<<endl;

        if (r.addroom())
        {
            QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                        QObject::tr("The room has been added successfully.\n"
                                    "Click OK to exit"), QMessageBox::Ok);
            notif m("Room","Room Added !");
            m.afficher();


            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                                       le->clear();}
                                  QFile file("C:/thefinalproject/logs/historiques.txt");
                                  if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                      return;
                                  QTextStream cout(&file);
                                  QString d_info = QDateTime::currentDateTime().toString();
                                  QString message2=" + "+d_info+" A Room has been added by ID : "+ID_ROOMs+"\n";
                                  cout << message2;

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Failed"),
                        QObject::tr("The room couldn't be added."
                                    "Click Cancel to verify."), QMessageBox::Cancel);
}

void MainWindow::on_DISPLAY_PUSH_clicked()
{
    media->play();
    ui->tableView->setModel(r.displayroom());
    ui->tabWidget->setCurrentIndex(11);


}


void MainWindow::on_PDF_5_clicked()
   {
        media->play();
        QPdfWriter pdf("C:/thefinalproject/room.pdf");

           QPainter painter(&pdf);
           int i = 4000;
                  painter.setPen(Qt::darkCyan);
                  painter.setFont(QFont("Time New Roman", 25));
                  painter.drawText(3000,1400,"ROOMS LIST");
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Time New Roman", 15));
                  painter.drawRect(100,100,9400,2500);
                  painter.drawRect(100,3000,9400,500);
                  painter.setFont(QFont("Time New Roman", 9));
                  painter.drawText(400,3300,"ID ROOM");
                  painter.drawText(1350,3300,"PINCODE");
                  painter.drawText(2200,3300,"ROOM NUMBER");
                  painter.drawText(3400,3300,"ROOM TYPE");
                  painter.drawText(4400,3300,"CREATION DATE");
                  painter.drawText(6200,3300,"ROOM STATE");
                  painter.drawRect(100,3000,9400,9000);

                  QSqlQuery query;
                  query.prepare("select * from ROOMS");
                  query.exec();
                  while (query.next())
                  {
                      painter.drawText(400,i,query.value(0).toString());
                      painter.drawText(1350,i,query.value(1).toString());
                      painter.drawText(2300,i,query.value(2).toString());
                      painter.drawText(3400,i,query.value(3).toString());
                      painter.drawText(4400,i,query.value(4).toString());
                      painter.drawText(6200,i,query.value(5).toString());




                     i = i + 350;
                  }
                  QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                  QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_radioButton_clicked()
{
    media->play();
    room r;
    ui->tableView->setModel(r.triID());
}

void MainWindow::on_radioButton_2_clicked()
{
    media->play();
    room r;
    ui->tableView->setModel(r.triPIN());
}

void MainWindow::on_radioButton_3_clicked()
{
    media->play();
    room r;
    ui->tableView->setModel(r.triNUM());
}

void MainWindow::on_radioButton_4_clicked()
{
    media->play();
    room r;
    ui->tableView->setModel(r.triTYPE());
}

void MainWindow::on_radioButton_5_clicked()
{
    media->play();
    room r;
    ui->tableView->setModel(r.triDATE());
}


void MainWindow::on_radioButton_6_clicked()
{
    media->play();
    room r;
    ui->tableView->setModel(r.triSTATE());
}

void MainWindow::on_pushButton_clicked()
{
    media->play();
    room rs;
    QVariant id_ff = ui->tableView->model()->data(ui->tableView->selectionModel()->currentIndex(),Qt::DisplayRole);
    int idd = id_ff.toInt();
    QString id_ffs = id_ff.toString();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "DELETE", "Are you Sure you want to DELETE this ROOM?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=rs.deleteroom(idd);
          if(test)
          {

              notif m("Room","Room deleted !");
              m.afficher();

              foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                                         le->clear();}
                                    QFile file("C:/thefinalproject/logs/historiques.txt");
                                    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                        return;
                                    QTextStream cout(&file);
                                    QString d_info = QDateTime::currentDateTime().toString();
                                    QString message2=" - "+d_info+" A Room has been deleted by ID : "+id_ffs+"\n";
                                    cout << message2;
              ui->tableView->setModel(r.displayroom());

          }
      }
}


void MainWindow::on_LRN_4_textEdited(const QString &arg1)
{
    room a;
    ui->tableView->setModel(a.SEARCH(arg1));
}

void MainWindow::on_MOD_PUSH_3_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(12);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_ROOM FROM ROOMS");
    ui->comboRoom->setModel(model);
}

void MainWindow::on_MOD_2_clicked()
{

   media->play();
   room rs;
   ui->comboRoom->clear();
   ui->comboRoom->addItems(rs.search_id());

    int ID_ROOM = ui->comboRoom->currentText().toInt();
    QString ID_ROOMss = ui->comboRoom->currentText();
    QString pincodee = ui->LCP_m->text();
    QString number = ui->LRN_m->text();
    QString room_type = ui->LRT_m->text();
   QString creation_date = ui->dateEdit_m->date().toString();
    QString room_state = ui->LRS_m->text();
    room r;
         bool test=r.modifyroom(ID_ROOM,pincodee,number,room_type,creation_date,room_state);
          if(test)
          {
              QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                          QObject::tr("The room has been Updated successfully!.\n"
                                      "Click OK to exit"), QMessageBox::Ok);
              notif m("Room","Room modified !");
              m.afficher();

              foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                                         le->clear();}
                                    QFile file("C:/thefinalproject/logs/historiques.txt");
                                    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                        return;
                                    QTextStream cout(&file);
                                    QString d_info = QDateTime::currentDateTime().toString();
                                    QString message2=" ~ "+d_info+" A Room has been modified by ID : "+ID_ROOMss+"\n";
                                    cout << message2;
              ui->tabWidget->setCurrentIndex(9);
          }
          else
              QMessageBox::critical(nullptr, QObject::tr("Failed"),
                          QObject::tr("The room couldn't be Updated!."
                                      "Click Cancel to verify."), QMessageBox::Cancel);

}

void MainWindow::on_DISPLAY_PUSH_2_clicked()
{
    media->play();
    His=new his(this);
    His->show();
    his m;
    m.readfile();
}

void MainWindow::on_STAT_clicked()
{
    media->play();
    statis=new Statis(this);
    statis->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_3_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_4_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(9);
}

void MainWindow::on_ADD_PUSH_3_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(10);
}

void MainWindow::on_DEL_PUSH_6_clicked()
{
    media->play();
    QString link = "https://justiceleague.daily.co/9NK3LI2zsQSw0hc6KniN";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_DEL_PUSH_5_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(0);
}




void MainWindow::on_legalAffairs_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(13);
}

void MainWindow::on_PDF_ACC_clicked()
{
   media->play();
   QPdfWriter pdf("C:/thefinalproject/Accuse/Accuse.pdf");
   QPainter painter(&pdf);
   int i = 4000;
          painter.setPen(Qt::blue);
          painter.setFont(QFont("Time New Roman", 25));
          painter.drawText(3000,1400,"Accused List");
          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3000,9400,500);
          painter.setFont(QFont("Time New Roman", 9));
          painter.drawText(400,3300,"ID");
          painter.drawText(1350,3300,"Name");
          painter.drawText(2200,3300,"Last Name");
          painter.drawText(3400,3300,"Gender");
          painter.drawText(4400,3300,"Date of Birth");
          painter.drawText(6200,3300,"Accusation Cause");
          painter.drawText(7600,3300,"Date of Session");
          painter.drawRect(100,3000,9400,9000);

          QSqlQuery query;
          query.prepare("select * from accuse");
          query.exec();
          while (query.next())
          {
              painter.drawText(400,i,query.value(0).toString());
              painter.drawText(1350,i,query.value(1).toString());
              painter.drawText(2300,i,query.value(2).toString());
              painter.drawText(3400,i,query.value(3).toString());
              painter.drawText(4400,i,query.value(4).toString());
              painter.drawText(6200,i,query.value(5).toString());
              painter.drawText(7600,i,query.value(6).toString());



             i = i + 350;
          }
          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
          QObject::tr("Saved PDF!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_ADD_ACC_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(14);
}


void MainWindow::on_List_ACC_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(15);
    ui->tab_aff->setModel(A.afficher());
}



void MainWindow::on_MODIFY_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(16);
}



void MainWindow::on_DELETE_ACC_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(17);
}


void MainWindow::on_search_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(18);
}



void MainWindow::on_Sort_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(19);
    ui->tabletri->setModel(A.tri());
}



void MainWindow::on_RES_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(20);
}


void MainWindow::on_add__acc_clicked()
{
    media->play();
    int id=ui->Lid->text().toInt();
    QString name=ui->Lname->text();
    QString lastname=ui->Llastname->text();
    QDate Date_B=ui->LDate_B->date();
    Date_B.toString("mm/dd/yyyy");
    QString gender=ui->Gender->currentText();
    QString acc_cause=ui->Lacc_cause->text();
    QDate Date_S=ui->LDate_S->date();
    Date_S.toString("mm/dd/yyyy");


   Accuse A(id,name,lastname,gender,Date_B,acc_cause,Date_S);




   if(A.Ajouter())
   {

       QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("Added successfully.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);}


       else
          { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("Add failed \n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_modify_clicked()
{
    media->play();
    QSqlQuery query;
    int id=ui->Lmid->text().toInt();
     QString id_string=QString::number(id);
    QString name=ui->Lmname->text();
    QString lastname=ui->Lmlastname->text();
    QDate Date_B=ui->LmDate_B->date();
    Date_B.toString("mm/dd/yyyy");
    QString gender=ui->LMgender->currentText();
    QString acc_cause=ui->Lmacc_cause->text();
    QDate Date_S=ui->LMDateS->date();
    Date_S.toString("mm/dd/yyyy");

    Accuse A(id, name,lastname, gender, Date_B, acc_cause, Date_S);

    if(A.rech(id))
{
        bool test=A.modifier(id,name,lastname,gender,Date_B,acc_cause,Date_S);

        if(test)
          {
              QMessageBox::information(nullptr,QObject::tr("Database is not open"
                                                         "Modification Failed"),
                                                   QObject::tr("Database is open"
                                                               " Modified Successfully.\n"
                                                               "Click Cancel to exit ."),QMessageBox::Cancel);
                   }
              else
              {
              QMessageBox::critical(nullptr,QObject::tr(""
                                                        ""),
                                               QObject::tr(" FAILED MODIFY.\n"
                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
              }
}
    else
    {QMessageBox::critical(nullptr, QObject::tr("Not found Accused"),
                           QObject::tr("Not found Accused \n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_supp_btn_clicked()
{
    media->play();
    QSqlQuery query;
    QMessageBox msgBox;


    int id=ui->Lsupp->text().toInt();
    if(A.rech(id))
    {
    if(A.supprimer(id))
        {

            QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("Deleted successfully.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}


            else
               { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("Delete failed \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    }
    else{ QMessageBox::critical(nullptr, QObject::tr("Not found"),
                                QObject::tr("Not found \n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}

}


void MainWindow::on_getsrch_clicked()
{
    media->play();
    QMessageBox msgBox;

        int id=ui->Lid_rech->text().toInt();
      QSqlQueryModel *verif=A.recherche(id);
      if(A.rech(id))
        {           if (verif!=nullptr)
                   {
                       ui->tablerech->setModel(verif);
                   }
        }
                   else
                   {QMessageBox::critical(nullptr, QObject::tr("Not found ID"),
                                                   QObject::tr("Not found ID \n"
                                                               "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_UPLOAD_clicked()
{
    int id=ui->Lid_save->text().toInt();
    QString RS=ui->L_results->text();
    //QSqlQueryModel *verif=A.recherche(id);
                /* if (verif!=nullptr)
                 {*/
  QFile file("C:/thefinalproject/Accuse/Results.txt");
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "ID:  "<<id<<"         Result Of session:  "<<RS<<endl;

        // optional, as QFile destructor will already do it:
        file.close();

        QMessageBox::information(this, QObject::tr("Results were sucessfully saved!"),
        QObject::tr("Results were sucessfully saved!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_Stats_clicked()
{
    media->play();
statistique st;
st.exec();
}






void MainWindow::on_qrcodegen_clicked()
{
    media->play();
    ui->tab_aff->setModel(A.afficher());
    int tabeq=ui->tab_aff->currentIndex().row(); //track selected item
                  QVariant idd=ui->tab_aff->model()->data(ui->tab_aff->model()->index(tabeq,0));
                  QString id=idd.toString();
                  QSqlQuery qry;
                  qry.prepare("select * from ACCUSE");
                  //qry.bindValue(":IDP",id);
                  qry.exec();

                  QString name;
                  QString lastname;
                  QString Date_B;
                  QString acc_cause;
                  QString Date_S;

                 while(qry.next()){

                     id=qry.value(0).toString();
                     name=qry.value(1).toString();
                       lastname=qry.value(2).toString();
                      Date_B=qry.value(3).toString();
                      acc_cause=qry.value(4).toString();
                      Date_S=qry.value(6).toString();



                  }
                  id=QString(id);
                         id="ID:\t" +id+ "NAME\t:" +name+ "LASTNAME:\t" +lastname+ "DATE_B:\t" +Date_B+ "ACC_CAUSE:\t" +acc_cause+ "DATE_S:\t" +Date_S ;
                  QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

                  QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                  for (int y = 0; y < qr.getSize(); y++) {
                      for (int x = 0; x < qr.getSize(); x++) {
                          int color = qr.getModule(x, y);

                          if(color==0)
                              im.setPixel(x, y,qRgb(254, 254, 254));
                          else
                              im.setPixel(x, y,qRgb(0, 0, 0));
                      }
                  }
                  im=im.scaled(200,200);
                 ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));
   }



void MainWindow::on_LogOutACC_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(0);

}


void MainWindow::on_EXIT_AACC_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(13);
}

void MainWindow::on_EXIT_DACC_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(13);
}

void MainWindow::on_EXIT_MACC_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(13);
}

void MainWindow::on_EXIT_DACC_2_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(13);
}

void MainWindow::on_EXIT_RACC_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(13);
}

void MainWindow::on_EXIT_TACC_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(13);
}

void MainWindow::on_EXIT_RSACC_clicked()
{
    media->play();
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(13);
}

void MainWindow::on_online_clicked()
{
    media->play();
    QString link = "https://justiceleague.daily.co/9NK3LI2zsQSw0hc6KniN";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_incendie_clicked()
{
    media->play();
    incendie inc;
    inc.exec();
}

void MainWindow::on_incendie_2_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(14);
}

void MainWindow::on_pb_ajouter_clicked()
{
    media->play();
    int id=ui->le_id1->text().toInt();

     QString nom=ui->le_nom1->text();
    QString prenom=ui->le_prenom1->text();
    int numero=ui->le_numero1->text().toInt();
    QString etat=ui->le_etat1->text();
     int age=ui->le_age1->text().toInt();
    Aj a(id,nom,prenom,numero,etat,age);
     QSqlQuery query;
    QByteArray b;
    QString s ;
  if (a.ajouter())
  {
      stat();
      s="welcome " ;
      query.prepare("select NOM from Aj where ID= :ID ") ;
      query.bindValue(":ID",id);
      query.exec() ;
      query.next() ;
      s+=query.value(0).toString() ;
      b= s.toUtf8() ;
      d.write_to_arduino(b);



      QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("AJOUT successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}



else
  {
      s="deja " ;
      query.prepare("select NOM from Aj where ID= :ID ") ;
      query.bindValue(":ID",id);
      query.exec() ;
      query.next() ;
       s+=query.value(0).toString() ;
      b= s.toUtf8() ;
      d.write_to_arduino(b);

      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("AJOUT failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}


}

void MainWindow::on_hiiii_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(22);
}



void MainWindow::on_pushButton_6_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(24);
}

void MainWindow::on_mod_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(25);
}

void MainWindow::on_hkkk_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(23);
}


void MainWindow::on_aff_clicked()
{
    media->play();
    ui->ta->setModel(a.afficher());
}

void MainWindow::on_pushButton_tri_clicked()
{
    media->play();
    Aj P;
    QString choix=ui->comboBox_tri->currentText();
    if (choix=="age")
    {
        ui->ta->setModel(P.tri_agecroissant());

        bool test=P.tri_agecroissant();// tri produit
        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri croissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
         {    QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri croissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}

    }
    if (choix=="nom")
    {
      ui->ta-> setModel(P.tri_nomcroissant());

        bool test=P.tri_nomcroissant();//tri produit
        if (test)
        {


          { QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri croissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);}


        }
        else
          {   QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri croissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}

    }
}

void MainWindow::on_pushButton_trid_clicked()
{
    media->play();
    Aj P;
    QString choix=ui->comboBox_trid->currentText();
    if (choix=="age")
    {
        ui->ta->setModel(P.tri_agedecroissant());


        bool test=P.tri_agedecroissant();//tri produit
        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri decroissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
             {QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri decroissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}

    }
    if (choix=="nom")
    {
        ui->ta->setModel(P.tri_nomdecroissant());
        bool test=P.tri_nomdecroissant();//tri produit
        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri decroissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
         {   QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri decroissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}

    }
}



void MainWindow::on_PUSH_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(21);
}

void MainWindow::on_pb_supp_clicked()
{
    media->play();
    Aj  a1;QMessageBox msgbox;
    a1.setid(ui->le_supp->text().toInt());
    if (a1.chercher(a1.getid()))
    { bool test=a1.supprimer(a1.getid());

     if (test)
         msgbox.setText("suppression avec succes");
      else
    msgbox.setText("echec de suppression");}
            else
     { msgbox.setText("id inexistant");}
    msgbox.exec();
}

void MainWindow::on_MODIFIER_clicked()
{
    media->play();
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int numero=ui->le_num->text().toInt();
    QString etat=ui->le_etat->text();
     int age=ui->le_age->text().toInt();

        Aj C(id,nom,prenom,numero,etat,age);
        bool test=C.modifier(id,nom,prenom,numero,etat,age);
   if (C.chercher(id)==false)
   {QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("id inexistant.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}


   else {

      if(test) QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("MODIFIER successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("MODIFIER failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}


}

void MainWindow::on_rech_clicked()
{
    media->play();
    Aj p;
    QString choix=ui->comboBox_chercher->currentText();

    if (choix=="id")
    {
        QString id = ui->lineEdit_rech->text();

        bool test=p.rechercherid(id);
            if(test)

              {  QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("CHERCHER successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}


               else
                  { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("CHERCHER failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}
            ui->tableView_2->setModel(p.rechercherid(id));

    }
    if (choix=="nom")
    {
        QString nom = ui->lineEdit_rech->text();

        bool test=p.recherchernom(nom);
            if(test)

               { QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("CHERCHER successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}


               else
                  { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("CHERCHER failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}
            ui->tableView_2->setModel(p.recherchernom(nom));
    }
    if (choix=="age")
    {
        QString age = ui->lineEdit_rech->text();

        bool test=p.rechercherage(age);
            if(test)

            {QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("CHERCHER successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}


               else
                  { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("CHERCHER failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel); }
            ui->tableView_2->setModel(p.rechercherage(age));
    }



}

void MainWindow::on_rechercher_clicked()
{
   media->play();
   ui->tabWidget->setCurrentIndex(26);
}


void MainWindow::on_pushButton_26_clicked()
{
    media->play();
    a.telechargerPDF();

             { QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("telcha successful.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}


}

void MainWindow::on_pushButton_7_clicked()
{
   media->play();
   QPdfWriter pdf("C:/thefinalproject/Liste.pdf");
       QPainter painter(&pdf);
       int i = 4000;
       painter.setPen(Qt::black);
       painter.setFont(QFont("Arial", 30));
       painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/thefinalproject/icons/Logo.ico"));
       painter.drawText(3000,1500,"LISTE DES AJ");
       painter.setPen(Qt::blue);
       painter.setFont(QFont("Arial", 50));
       painter.drawRect(2700,200,6300,2600);
       painter.drawRect(0,3000,9600,500);
       painter.setPen(Qt::black);
       painter.setFont(QFont("Arial", 9));
       painter.drawText(300,3300,"ID");
       painter.drawText(2300,3300,"NOM");
       painter.drawText(4300,3300,"PRENOM");
       painter.drawText(6300,3300,"AGE");
       painter.drawText(8000,3300,"NUMERO");
       painter.drawText(9300,3300,"ETAT");
       QSqlQuery query;
       query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
       time_t tt;
       struct tm* ti;
       time(&tt);
       ti=localtime(&tt);
       asctime(ti);
       painter.drawText(500,300, asctime(ti));
       query.prepare("select * from AJ");
       query.exec();
       while (query.next())
       {
           painter.drawText(300,i,query.value(0).toString());
           painter.drawText(2300,i,query.value(1).toString());
           painter.drawText(4300,i,query.value(2).toString());
           painter.drawText(6300,i,query.value(3).toString());
           painter.drawText(8000,i,query.value(4).toString());
           painter.drawText(10000,i,query.value(5).toString());

           i = i +500;
       }
       int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
       if (reponse == QMessageBox::Yes)
       {
           QDesktopServices::openUrl(QUrl::fromLocalFile("C:/thefinalproject/Liste.pdf"));

   }    painter.end();

   if (reponse == QMessageBox::No)
   {
       painter.end();
   }
   QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                                  QObject::tr("The Operation has been finished successful.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_19_clicked()
{
    media->play();
    QSqlQueryModel * model= new QSqlQueryModel();
                     model->setQuery("select * from Aj where age < 18 ");
                     float code=model->rowCount();
                     model->setQuery("select * from Aj where age between 18 and 30 ");
                     float codee=model->rowCount();
                     model->setQuery("select * from Aj where age >30 ");
                     float codeee=model->rowCount();
                     float total=code+codee+codeee;
                     QString a=QString("moins de 18 \t"+QString::number((code*100)/total,'f',2)+"%" );
                     QString b=QString("entre 18 et 30 \t"+QString::number((codee*100)/total,'f',2)+"%" );
                     QString c=QString("+30 \t"+QString::number((codeee*100)/total,'f',2)+"%" );
                     QPieSeries *series = new QPieSeries();
                     series->append(a,code);
                     series->append(b,codee);
                     series->append(c,codeee);
             if (code!=0)
             {QPieSlice *slice = series->slices().at(0);
              slice->setLabelVisible();
              slice->setPen(QPen());}
             if ( codee!=0)
             {
                      // Add label, explode and define brush for 2nd slice
                      QPieSlice *slice1 = series->slices().at(1);
                      //slice1->setExploded();
                      slice1->setLabelVisible();
             }
             if(codeee!=0)
             {
                      // Add labels to rest of slices
                      QPieSlice *slice2 = series->slices().at(2);
                      //slice1->setExploded();
                      slice2->setLabelVisible();
             }
                     // Create the chart widget
                     QChart *chart = new QChart();
                     // Add data to chart with title and hide legend
                     chart->addSeries(series);
                     chart->setTitle("Pourcentage Par age :Nombre Des Espaces "+ QString::number(total));
                     chart->legend()->hide();
                     // Used to display the chart
                     QChartView *chartView = new QChartView(chart);
                     chartView->setRenderHint(QPainter::Antialiasing);
                     chartView->resize(1000,500);
                     chartView->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(21);
}


void MainWindow::on_pushButton_28_clicked()
{
  media->play();
    ui->tabWidget->setCurrentIndex(21);
}

void MainWindow::on_EXIT_6_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_31_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_32_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_33_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(21);
}

void MainWindow::on_Sort_2_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(15);
    ui->tab_aff->setModel(A.afficher());
}

void MainWindow::on_DEL_PUSH_10_clicked()
{
    media->play();
    QString link = "https://justiceleague.daily.co/9NK3LI2zsQSw0hc6KniN";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_DEL_PUSH_9_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_DEL_PUSH_8_clicked()
{
    media->play();
    QString link = "https://justiceleague.daily.co/9NK3LI2zsQSw0hc6KniN";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_DEL_PUSH_7_clicked()
{
    media->play();
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_22_clicked()
{
    Smtp* smtp = new Smtp("justiceleaguee121@gmail.com","ala12345", "smtp.gmail.com", 465);
    smtp->sendMail("justiceleaguee121@gmail.com", "justiceleaguee121@gmail.com" , "ui->subjectLineEdit_2->text()" ,"ui->message_2->toPlainText()");
    QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );

}
