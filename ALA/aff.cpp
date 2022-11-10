#include "aff.h"
#include "ui_aff.h"

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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
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
