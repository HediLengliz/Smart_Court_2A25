#ifndef STATIS_H
#define STATIS_H

#include <QDialog>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
#include <QWidget>
namespace Ui {
class Statis;
}

class Statis : public QDialog
{
    Q_OBJECT

public:
    explicit Statis(QWidget *parent = nullptr);
    ~Statis();
    int Stat_MAJ();
    int Stat_mini();
    int Stat_ROOM_NUMBER();

    void paintEvent(QPaintEvent *) ;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Statis *ui;
};

#endif // STATIS_H
