#ifndef DELL_H
#define DELL_H

#include <QDialog>

namespace Ui {
class dell;
}

class dell : public QDialog
{
    Q_OBJECT

public:
    explicit dell(QWidget *parent = nullptr);
    ~dell();

private:
    Ui::dell *ui;
};

#endif // DELL_H
