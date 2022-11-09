#include "sta.h"
#include "ui_sta.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include<QSqlQuery>

#include <QFrame>
#include<QFileDialog>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
sta::sta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sta)
{
    ui->setupUi(this);

    // background //
              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(198, 156, 109));
              gradient.setColorAt(0.38, QColor(237, 187, 130));
              gradient.setColorAt(1, QColor(255, 200, 138));
              ui->plot->setBackground(QBrush(gradient));

              QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //couleurs
              amande->setName("Repartition des Aj selon nom d juges ");
              amande->setPen(QPen(QColor(247, 198, 132).lighter(150)));
              amande->setBrush(QColor(247, 198, 132));

               //axe des abscisses
              QVector<double> ticks;
              QVector<QString> labels;
               tempa.statistique(&ticks,&labels);

              QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
              textTicker->addTicks(ticks, labels);
              ui->plot->xAxis->setTicker(textTicker);
              ui->plot->xAxis->setTickLabelRotation(60);
              ui->plot->xAxis->setSubTicks(false);
              ui->plot->xAxis->setTickLength(0, 4);
              ui->plot->xAxis->setRange(0, 8);
              ui->plot->xAxis->setBasePen(QPen(Qt::black));
              ui->plot->xAxis->setTickPen(QPen(Qt::black));
              ui->plot->xAxis->grid()->setVisible(true);
              ui->plot->xAxis->grid()->setPen(QPen(QColor(242, 149, 102), 0, Qt::DotLine));
              ui->plot->xAxis->setTickLabelColor(Qt::black);
              ui->plot->xAxis->setLabelColor(Qt::black);

              // axe des ordonnées
              ui->plot->yAxis->setRange(0,10);
              ui->plot->yAxis->setPadding(5);
              ui->plot->yAxis->setLabel("quantite");
              ui->plot->yAxis->setBasePen(QPen(Qt::black));
              ui->plot->yAxis->setTickPen(QPen(Qt::black));
              ui->plot->yAxis->setSubTickPen(QPen(Qt::black));
              ui->plot->yAxis->grid()->setSubGridVisible(true);
              ui->plot->yAxis->setTickLabelColor(Qt::black);
              ui->plot->yAxis->setLabelColor(Qt::black);
              ui->plot->yAxis->grid()->setPen(QPen(QColor(242, 149, 102), 0, Qt::SolidLine));
              ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(242, 149, 102), 0, Qt::DotLine));

              // ajout des données  (statistiques de la quantité)//

              QVector<double> PlaceData;
              QSqlQuery q1("select quantite from produit");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);

              ui->plot->legend->setVisible(true);
              ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plot->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(5);
              ui->plot->legend->setFont(legendFont);
              ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}



sta::~sta()
{
    delete ui;
}
