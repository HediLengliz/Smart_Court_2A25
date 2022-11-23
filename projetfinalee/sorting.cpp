#include "sorting.h"
#include "ui_sorting.h"

Sorting::Sorting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sorting)
{
    ui->setupUi(this);
}

Sorting::~Sorting()
{
    delete ui;
}

void Sorting::on_SET_clicked()
{
    int MIN = ui->MIN->text().toInt();
    int MAX = ui->MAX->text().toFloat();
    ui->TabAff->setModel(E.sorting(MIN,MAX,&n));
}

void Sorting::on_EXIT_clicked()
{
    hide();
}
void Sorting::on_SET_2_clicked()
{
    ui->TabAff->setModel(E.sortingall(&n));
}

void Sorting::on_ExportExcel_clicked()
{
    if (n == 0)
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("The Table Is Empty"))
                                 );
    else
    {
        QString fileName = "C:/Users/Ala/Desktop/Projjeeet/build-Atelier_Connexion-Desktop_Qt_5_9_9_MinGW_32bit-Debug/Employee.xls";
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->TabAff);

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

void Sorting::on_ImportExcel_clicked()
{
    if (n == 0)
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("The Table Is Empty"))
                                 );
    else
    {
        QString fileName = "C:/Users/Ala/Desktop/Projjeeet/build-Atelier_Connexion-Desktop_Qt_5_9_9_MinGW_32bit-Debug/Employee.xls";
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->TabAff);

        //colums to export
        obj.addField(0, "Nom", "char(20)");
        obj.addField(1, "Prenom", "char(20)");
        obj.addField(2, "CIN", "char(20)");
        obj.addField(3, "NumberOfSessions", "char(20)");
        obj.addField(4, "Absence", "char(20)");
        obj.addField(5, "Salary", "char(20)");


        obj.export2Excel();
        QString ExcelFileName  = "C:/Users/Ala/Desktop/Projjeeet/build-Atelier_Connexion-Desktop_Qt_5_9_9_MinGW_32bit-Debug/bilan.xlsx";
        QDesktopServices::openUrl(QUrl(ExcelFileName, QUrl::TolerantMode));
    }
}
