#ifndef TASK_H
#define TASK_H

#include <QDialog>
#include "verifcin.h"
#include "todoja.h"

namespace Ui {
class Task;
}

class Task : public QDialog
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

private slots:
    void on_add_new_employee_2_clicked();

    void on_add_new_employee_clicked();

    void on_add_new_employee_3_clicked();

private:
    Ui::Task *ui;
    verifcin *Verifcin;
    Todoja *todoja;
};

#endif // TASK_H
