#ifndef CALAN_H
#define CALAN_H
#include"aj.h"
#include <QDialog>

namespace Ui {
class calan;
}

class calan : public QDialog
{
    Q_OBJECT

public:
    explicit calan(QWidget *parent = nullptr);
    ~calan();

private:
    Ui::calan *ui;
    Aj a;
};

#endif // CALAN_H
