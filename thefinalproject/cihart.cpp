#include "cihart.h"
#include "ui_cihart.h"

Cihart::Cihart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cihart)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM, CIN FROM employee");
    query.exec();
    chartt t;
    QBarSeries *series = new QBarSeries();
    while (query.next())
    {
        t.nom = query.value(0).toString();
        t.prenom = query.value(1).toString();
        t.cin = query.value(2).toString ();
        vect.push_front(t);
    }
    for(QVector<chartt>::iterator it = vect.begin();it != vect.end();it++)
    {
        QString cin = it->cin;
        QSqlQuery querys;
        querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN and STATE = 'Done'");
        querys.bindValue(":CIN",cin);
        querys.exec();
        it->fin = 0;
        while(querys.next())
             (it->fin)+=1;
        querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN and STATE = 'Undone'");
        querys.bindValue(":CIN",cin);
        querys.exec();
        it->unfin = 0;
        while(querys.next())
             (it->unfin)+=1;
        querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN and STATE = 'Doing'");
        querys.bindValue(":CIN",cin);
        querys.exec();
        it->doi = 0;
        while(querys.next())
             (it->doi)+=1;
        querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN and STATE = 'To Do'");
        querys.bindValue(":CIN",cin);
        querys.exec();
        it->tod = 0;
        while(querys.next())
             (it->tod)+=1;
        it->set = new QBarSet(it->nom + " " + it->prenom);
        //*(it->set) << it->fin << it->unfin << it->doi << it->tod;
        *(it->set) << it->fin << it->unfin << it->doi << it->tod;
        series->append(it->set);
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("The Barchart of the employees");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList cat;
    cat << "Done" << "Undone" << "Doing" << "To do";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(cat);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalWidget);
}

Cihart::~Cihart()
{
    delete ui;
}
