#ifndef AA_H
#define AA_H

#include <QDialog>

namespace Ui {
class AA;
}

class AA : public QDialog
{
    Q_OBJECT

public:
    explicit AA(QWidget *parent = nullptr);
    ~AA();

private slots:
    void on_pb_ajouter_clicked();

private:
    Ui::AA *ui;
};

#endif // AA_H
// hiba
