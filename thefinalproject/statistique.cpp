#include "statistique.h"
#include "ui_statistique.h"

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}

int statistique::Stat_partie1()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from EMPLOYEES where SALARY BETWEEN '1' AND '200'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

int statistique::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from EMPLOYEES where SALARY BETWEEN '201' AND '800'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

int statistique::Stat_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from EMPLOYEES where SALARY BETWEEN '801' AND '3000'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}



void statistique::paintEvent(QPaintEvent *)
{

    int a=Stat_partie1();
    int b=Stat_partie2();
    int c=Stat_partie3();

        float s1= a*100 ;
        float s2=b*100;
        float nb = a+b+c ;

        float q1 = s1/nb ;
        float q2 =s2/nb;

        float x = (q1*360)/100 ;

        float y = (q2*360)/100;

        float z =360-(x+y) ;


    QPainter painter(this);
    QRectF size=QRectF(100,100,this->width()-500,this->width()-500);

    painter.setBrush(Qt::red);
        painter.drawPie(size,0,16*x);
        ui->label_1->setText("Salary between 0-200") ;
        painter.setBrush(Qt::green);
        painter.drawPie(size,16*x,16*y);
        ui->label_2->setText("Salary between 200-800") ;
        painter.setBrush(Qt::blue);
        painter.drawPie(size,16*(y+x),16*z);
        ui->label_3->setText("Salary between 800-3000") ;

    ui->stat1->setNum(q1) ;
    ui->stat2->setNum(q2) ;
    ui->stat3->setNum(100-q1-q2) ;

}


