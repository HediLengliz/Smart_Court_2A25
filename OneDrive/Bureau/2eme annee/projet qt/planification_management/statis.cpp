#include "statis.h"
#include "ui_statis.h"

Statis::Statis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statis)
{
    ui->setupUi(this);
}

Statis::~Statis()
{
    delete ui;
}

int Statis::Stat_MAJ()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ROOMS where ROOM_TYPE BETWEEN 'A' AND 'Z'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

int Statis::Stat_mini()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from EMPLOYEES where ROOM_TYPE BETWEEN 'a' AND 'z'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

int Statis::Stat_ROOM_NUMBER()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ROOMS where  ROOM_NUMBER BETWEEN '0' AND '3000'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}



void Statis::paintEvent(QPaintEvent *)
{

    int a=Stat_MAJ();
    int b=Stat_mini();
    int c=Stat_ROOM_NUMBER();

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
