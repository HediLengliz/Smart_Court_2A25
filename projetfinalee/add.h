#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QIntValidator>
#include <QMessageBox>

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

private slots:

    void on_add_new_employee_clicked();

private:
    Ui::Add *ui;
};

#endif // ADD_H
