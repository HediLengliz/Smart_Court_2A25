#include "employee.h"


/////////////////////////////////////////////////////STRUCTURE PARAMETRE+DEFAUT/////////////////////////////////////////////////////

Employee::Employee()
{
    CIN = 0;
    Code_Pin = 0;
    Salary = 0;
    Nom = "N/A";
    Prenom = "N/A";
    E_mail = "N/A";
    City = "N/A";
    S_Obj.succ = 0;
    S_Obj.fail = 0;
    S_Obj.somme = 0;
    S_Obj.pourc = -1;
}

Employee::Employee(int cin,int codepin,float salary,QString nom,QString prenom,QString email,QString city)
{
    CIN = cin;
    Code_Pin = codepin;
    Salary = salary;
    Nom = nom;
    Prenom = prenom;
    E_mail = email;
    City = city;
    S_Obj.succ = 0;
    S_Obj.fail = 0;
    S_Obj.somme = 0;
    S_Obj.pourc = -1;
};

Employee::Employee(int cin,QString email)
{
    CIN = cin;
    E_mail = email;
}

////////////////////////////////////////////////////////////GET FUNCTIONS////////////////////////////////////////////////////////////

int Employee::getcin()
{
    return CIN;
};

int Employee::getcodepin()
{
    return Code_Pin;
};

float Employee::getsalary()
{
    return Salary;
};

QString Employee::getnom()
{
    return Nom;
};
QString Employee::getprenom()
{
    return Prenom;
};

QString Employee::getemail()
{
    return E_mail;
};

QString Employee::getcity()
{
    return City;
};

statistic_obj Employee::getstatisticobj()
{
    return S_Obj;
};

////////////////////////////////////////////////////////////SET FUNCTIONS////////////////////////////////////////////////////////////

void Employee::setcin(int cin)
{
    CIN = cin;
};

void Employee::setcodepin(int cp)
{
    Code_Pin = cp;
};

void Employee::setsalary(float s)
{
    Salary = s;
};

void Employee::setnom(QString nom)
{
    Nom = nom;
};

void Employee::setprenom(QString prenom)
{
    Prenom = prenom;
};

void Employee::setemail(QString email)
{
    E_mail = email;
};

void Employee::setcity(QString city)
{
    City = city;
};

void Employee::setstatisticobj(int numsucc,int numfail)
{
    S_Obj.succ+=numsucc;
    S_Obj.fail+=numfail;
    S_Obj.somme+=(numsucc+numfail);
    S_Obj.pourc = (S_Obj.succ / S_Obj.somme)*100;
};

////////////////////////////////////////////////////////////CRUD////////////////////////////////////////////////////////////

bool Employee::ajouter()
{
    QSqlQuery query;
    QString cin_string = QString::number(CIN);
    QString codepin_string = QString::number(Code_Pin);
    QString salary_string = QString::number(Salary);
    QString objsucc_string = QString::number(S_Obj.succ);
    QString objfail_string = QString::number(S_Obj.fail);
    QString objsom_string = QString::number(S_Obj.somme);
    QString objpourc_string = QString::number(S_Obj.pourc);
    query.prepare("INSERT INTO EMPLOYEE (CIN, CODE_PIN, SALARY, NOM, PRENOM, E_MAIL, CITY)"  "VALUES (:CIN ,:Code_Pin ,:Salary, :Nom , :Prenom, :E_mail , :City)"   );
    query.bindValue(":CIN",cin_string);
    query.bindValue(":Code_Pin",codepin_string);
    query.bindValue(":Salary",salary_string);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":E_mail",E_mail);
    query.bindValue(":City",City);
    /*query.bindValue(8,S_Obj.succ);
    query.bindValue(9,S_Obj.fail);
    query.bindValue(10,S_Obj.somme);
    query.bindValue(11,S_Obj.pourc);*/
    return query.exec();
}

QSqlQueryModel* Employee::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
          model->setQuery("SELECT NOM, PRENOM, CIN, E_MAIL FROM employee");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NAME"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("SURNAME"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-MAIL"));

    return model;
};

bool Employee::supprimer(int CIN)
{
    QSqlQuery query;
    int row_count = 0;
    //query.prepare("Delete from EMPLOYEE where CIN=:CIN");
    query.prepare("SELECT * FROM EMPLOYEE where CIN=:CIN");
    query.bindValue(":CIN",CIN);
    if (query.exec())
    {
        while(query.next() && row_count != 1)
             row_count++;
        if(row_count == 1)
        {
            query.prepare("Delete from EMPLOYEE where CIN=:CIN");
            query.bindValue(":CIN",CIN);
            return query.exec();
        }
        else
            return false;
    }
    else
        return false;
};

bool Employee::modifier()
{
    QSqlQuery query;
    QString cin_string = QString::number(CIN);
    query.prepare("UPDATE EMPLOYEE SET CIN =:CIN, E_MAIL=:E_mail where CIN=:CIN");
    query.bindValue(":E_mail",E_mail);
    query.bindValue(":CIN",cin_string);
    return query.exec();
}
