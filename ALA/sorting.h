#ifndef SORTING_H
#define SORTING_H

#include <QDialog>
#include "employee.h"

namespace Ui {
class Sorting;
}

class Sorting : public QDialog
{
    Q_OBJECT

public:
    explicit Sorting(QWidget *parent = nullptr);
    ~Sorting();

private slots:
    void on_SET_clicked();

    void on_EXIT_clicked();

    void on_SET_2_clicked();

private:
    Ui::Sorting *ui;
    Employee E;
};

#endif // SORTING_H
