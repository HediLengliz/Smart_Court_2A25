#ifndef STA_H
#define STA_H
#include "aj.h"
#include <QDialog>

namespace Ui {
class sta;
}

class sta : public QDialog
{
    Q_OBJECT

public:
    explicit sta(QWidget *parent = nullptr);
    ~sta();

private:
    Ui::sta *ui;
    Aj tempa;
};

#endif // STA_H
