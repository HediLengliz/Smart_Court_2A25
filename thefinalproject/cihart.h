#ifndef CIHART_H
#define CIHART_H

#include <QDialog>
#include <QVector>
#include <QtCharts/QtCharts>
#include <QSqlQuery>

namespace Ui {
class Cihart;
}

class Cihart : public QDialog
{
    Q_OBJECT

typedef struct
{
   QString nom,prenom;
   QString cin;
   int fin,unfin,tod,doi;
   QBarSet* set;
}chartt;

public:
    explicit Cihart(QWidget *parent = nullptr);
    ~Cihart();
    QVector<chartt> vect;

private:
    Ui::Cihart *ui;
};

#endif // CIHART_H
