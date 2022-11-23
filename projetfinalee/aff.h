#ifndef AFF_H
#define AFF_H

#include <QDialog>
#include <QIntValidator>
#include <QMessageBox>
#include "employee.h"
#include "exportexcelobject.h"

namespace Ui {
class Aff;
}

class Aff : public QDialog
{
    Q_OBJECT

public:
    explicit Aff(QWidget *parent = nullptr);
    ~Aff();

private slots:

    void on_add_new_employee_clicked();

    void on_ExportExcel_clicked();

    void on_ImportExcel_clicked();

private:
    Ui::Aff *ui;
    Employee E;
};

#endif // AFF_H
