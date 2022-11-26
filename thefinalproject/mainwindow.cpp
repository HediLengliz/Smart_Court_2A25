#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->setEnabled(false);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_code()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_ADD_PUSH_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
    ui->Employee->setChecked(true);
}

void MainWindow::on_add_new_employee_clicked()
{
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
    ui->tabWidget->setCurrentIndex(3);
    ui->TabAff->setModel(E.afficher());
}

void MainWindow::on_add_new_employee_2_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_add_new_employee_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_update_clicked()
{
    int cin = ui->MCin ->text().toInt();
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
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_add_new_employee_5_clicked()
{
    Employee E;
    E.setcin(ui->SCin->text().toInt());
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
    ui->tabWidget->setCurrentIndex(4);
}

void MainWindow::on_DEL_PUSH_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}

void MainWindow::on_EXIT_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_MAX_clicked()
{
    n = 1;
    ui->Tabpdf->setModel(E.search(n,0,""));
}

void MainWindow::on_SCIN_clicked()
{
    n = 2;
    int cin = ui->SCinn->text().toInt();
    ui->TabAff->setModel(E.search(n,cin,""));
}

void MainWindow::on_SEMAIL_clicked()
{
    n = 3;
    QString email = ui->SEmail->text();
    ui->TabAff->setModel(E.search(n,0,email));
}

void MainWindow::on_PDF_clicked()
{
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
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->Tabpdf->setModel(model);
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_SEARCH_PUSH_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
}

void MainWindow::on_SET_clicked()
{
    int MIN = ui->MIN->text().toInt();
    int MAX = ui->MAXX->text().toFloat();
    ui->TabSort->setModel(E.sorting(MIN,MAX,&n));
}

void MainWindow::on_SET_2_clicked()
{
    ui->TabSort->setModel(E.sortingall(&n));
}

void MainWindow::on_ExportExcel_clicked()
{
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
    ui->tabWidget->setCurrentIndex(7);
    n = 0;
}

void MainWindow::on_EXIT_2_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    ui->TabSort->setModel(model);
    n = 0;
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_ADD_clicked()
{
    int cin = ui->LCinn->text().toInt();
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
    ui->tabWidget->setCurrentIndex(8);
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
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::showtime()
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

void MainWindow::on_EXIT_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_ADD_11_clicked()
{
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
    cihart = new Cihart(this);
    cihart->show();
}

void MainWindow::on_EXIT_5_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_ADD_13_clicked()
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

void MainWindow::on_ADD_14_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    codee = ui->LCodee->text();
    if (codee == "691470258")
    {
        ui->tabWidget->setCurrentIndex(1);
        QMessageBox::information(nullptr, QObject::tr("Task has been finished"),
                QObject::tr("Admin Mode Has Been Activated\n"
                            "Click Ok to exit."), QMessageBox::Ok);
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
            ui->LCodee->setText("");
        }
        else
           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                        QObject::tr("Code does not exist\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_DEL_PUSH_2_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_DEL_PUSH_3_clicked()
{
    QString link = "https://justiceleague.daily.co/9NK3LI2zsQSw0hc6KniN";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::update_code()
{
    data=A.read_from_arduino();
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
