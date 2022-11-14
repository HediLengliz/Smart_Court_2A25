#ifndef MODIFY_H
#define MODIFY_H
#include "room.h"
#include <QDialog>

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
    void on_MOD_2_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::Modify *ui;
    Modify* mod;
    room r;
};

#endif // MODIFY_H
