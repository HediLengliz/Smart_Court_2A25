#ifndef HR_H
#define HR_H

#include <QDialog>
#include "add.h"
#include "aff.h"
#include "supp.h"
#include "modify.h"
#include "sorting.h"
#include "searchpdf.h"
#include "verifcin.h"
#include "task.h"

namespace Ui {
class HR;
}

class HR : public QDialog
{
    Q_OBJECT

public:
    explicit HR(QWidget *parent = nullptr);
    ~HR();

private slots:

    void on_ADD_PUSH_clicked();

    void on_LIST_PUSH_clicked();

    void on_DEL_PUSH_clicked();

    void on_MOD_PUSH_clicked();

    void on_SORT_PUSH_clicked();

    void on_SEARCH_PUSH_clicked();

    void on_TODOLIST_clicked();

private:
    Ui::HR *ui;
    Add *add;
    Aff *aff;
    Supp *supp;
    Modify *mod;
    Sorting *sorting;
    searchpdf *Searchpdf;
    verifcin *Verifcin;
    Task* task;
};

#endif // HR_H
