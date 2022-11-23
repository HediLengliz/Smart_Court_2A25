#ifndef TODOLIST_H
#define TODOLIST_H

#include <QDialog>
#include "objective.h"

namespace Ui {
class todolist;
}

class todolist : public QDialog
{
    Q_OBJECT

public:
    explicit todolist(QWidget *parent = nullptr);
    ~todolist();
    Objective O;

private:
    Ui::todolist *ui;
};

#endif // TODOLIST_H
