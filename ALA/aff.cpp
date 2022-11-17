#include "aff.h"
#include "ui_aff.h"
#include <QUrl>
#include <QDesktopServices>

Aff::Aff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aff)
{
    ui->setupUi(this);
    ui->TabAff->setModel(E.afficher());
}

Aff::~Aff()
{
    delete ui;
}

void Aff::on_add_new_employee_clicked()
{
    hide();
}

void Aff::on_ExportExcel_clicked()
{
    if (!E.isempty())
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("no records exported!"))
                                 );
    QString fileName = "C:/Users/Ala/Desktop/Projjeeet/build-Atelier_Connexion-Desktop_Qt_5_9_9_MinGW_32bit-Debug/Employee.xls";
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->TabAff);

    //colums to export
    obj.addField(0, "Nom", "char(20)");
    obj.addField(1, "Prenom", "char(20)");
    obj.addField(2, "CIN", "char(20)");
    obj.addField(3, "EMail", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

void Aff::on_ImportExcel_clicked()
{
    QString ExcelFileName  = "C:/Users/Ala/Downloads/libxl-win-4.0.4/libxl-4.0.4.0/examples/c++/code.blocks/BFF.xlsx";
    QDesktopServices::openUrl(QUrl(ExcelFileName, QUrl::TolerantMode));
}
