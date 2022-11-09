#ifndef AAA_H
#define AAA_H
#include"aj.h"
#include <QDialog>

namespace Ui {
class aaa;
}

class aaa : public QDialog
{
    Q_OBJECT

public:
    explicit aaa(QWidget *parent = nullptr);
    ~aaa();

private slots:
    void on_aff_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_trid_clicked();

private:
    Ui::aaa *ui;
    Aj a;

};

#endif // AAA_H
