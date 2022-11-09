#ifndef AAAAAA_H
#define AAAAAA_H

#include <QDialog>
#include"aj.h"
namespace Ui {
class aaaaaa;
}

class aaaaaa : public QDialog
{
    Q_OBJECT

public:
    explicit aaaaaa(QWidget *parent = nullptr);
    ~aaaaaa();

private:
    Ui::aaaaaa *ui;
};

#endif // AAAAAA_H
