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
    void on_MOD_clicked();

    void on_SAVE_clicked();

private:
    Ui::Modify *ui;
    Modify* mod;
    room r;
};

#endif // MODIFY_H
