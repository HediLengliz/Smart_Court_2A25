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
    int ns = ui->LNS->text().toInt();
    Employee E(cin,codepin,salary,nom,prenom,email,city,ns);
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
                    QObject::tr("The employee couldn't be added.\nMake sure that : \n1- CIN and E-MAIL hasn't been used before\n2- E-MAIL is written like \"AA@aa.xx\"\nReport it if there is any error\n"
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
        QString fileName = "C:/Users/Ala/Documents/thefinalproject/Employee.xls"; //changer le chem
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
        QString fileName = "C:/Users/Ala/Documents/thefinalproject/Employee.xls"; //changer le chem
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
        QString ExcelFileName  = "C:/Users/Ala/Documents/thefinalproject/bilan.xlsx"; //changer le chem
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
