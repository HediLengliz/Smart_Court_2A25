#ifndef SEARCHPDF_H
#define SEARCHPDF_H

#include <QDialog>
#include "employee.h"
#include <QMessageBox>
#include <QIntValidator>

namespace Ui {
class searchpdf;
}

class searchpdf : public QDialog
{
    Q_OBJECT

public:
    explicit searchpdf(QWidget *parent = nullptr);
    ~searchpdf();
    int n;

private slots:
    void on_MAX_clicked();

    void on_PDF_clicked();

    void on_SCIN_clicked();

    void on_SEMAIL_clicked();

    void on_add_new_employee_clicked();

private:
    Ui::searchpdf *ui;
    Employee E;
};

#endif // SEARCHPDF_H
