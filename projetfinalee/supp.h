#ifndef SUPP_H
#define SUPP_H

#include <QDialog>
#include "employee.h"
#include <QMessageBox>

namespace Ui {
class Supp;
}

class Supp : public QDialog
{
    Q_OBJECT

public:
    explicit Supp(QWidget *parent = nullptr);
    ~Supp();

private slots:
    void on_add_new_employee_clicked();

    void on_EXIT_clicked();

private:
    Ui::Supp *ui;
};

#endif // SUPP_H
