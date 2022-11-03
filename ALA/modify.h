#ifndef MODIFY_H
#define MODIFY_H

#include <QDialog>
#include "employee.h"
#include <QMessageBox>

namespace Ui {
class Modify;
}

class Modify : public QDialog
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = nullptr);
    ~Modify();

private slots:
    void on_update_clicked();

private:
    Ui::Modify *ui;
};

#endif // MODIFY_H
