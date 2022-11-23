#ifndef SORTING_H
#define SORTING_H

#include <QDialog>
#include "employee.h"
#include "exportexcelobject.h"
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class Sorting;
}

class Sorting : public QDialog
{
    Q_OBJECT

public:
    explicit Sorting(QWidget *parent = nullptr);
    ~Sorting();
    int n=0;

private slots:
    void on_SET_clicked();

    void on_EXIT_clicked();

    void on_SET_2_clicked();

    void on_ExportExcel_clicked();

    void on_ImportExcel_clicked();

private:
    Ui::Sorting *ui;
    Employee E;
};

#endif // SORTING_H
