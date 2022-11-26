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
    Abs = 0;
    S_Obj.succ = 0;
    S_Obj.fail = 0;
    S_Obj.somme = 0;
    S_Obj.pourc = -1;
    ns = 0;
}

Employee::Employee(int cin,int codepin,float salary,QString nom,QString prenom,QString email,QString city,int NOMBRESCEANCE,QString role,int code)
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
    ns = NOMBRESCEANCE;
    Abs = 0;
    Role = role;
    Code = code;
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

int Employee::getcode()
{
    return Code;
}

////////////////////////////////////////////////////////////SET FUNCTIONS////////////////////////////////////////////////////////////

void Employee::setcin(int cin)
{
    CIN = cin;
};

void Employee::setcode(int code)
{
    Code = code;
}

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
    QString code_string = QString::number(Code);
    QString objns = QString::number(ns);
    query.prepare("INSERT INTO EMPLOYEE (CIN, CODE_PIN, SALARY, NOM, PRENOM, E_MAIL, CITY, NOMBRESCEANCE, ABSENCE, CODE, ROLE)"  "VALUES (:CIN ,:Code_Pin ,:Salary, :Nom , :Prenom, :E_mail , :City, :NOMBRESCEANCE, :ABSENCE, :CODE, :ROLE)");
    query.bindValue(":CIN",cin_string);
    query.bindValue(":Code_Pin",codepin_string);
    query.bindValue(":Salary",salary_string);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":E_mail",E_mail);
    query.bindValue(":City",City);
    query.bindValue(":NOMBRESCEANCE",ns);
    query.bindValue(":ABSENCE",Abs);
    query.bindValue(":CODE",Code);
    query.bindValue(":ROLE",Role);
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
            query.prepare("Delete from OBJECTIVE where CIN=:CIN");
            query.bindValue(":CIN",CIN);
            query.exec();
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

bool Employee::modifier(QSqlQueryModel* model)
{
    QSqlQuery query;
    QString cin_string = QString::number(CIN);
    int row_count = 0;
    query.prepare("SELECT * FROM EMPLOYEE where CIN=:CIN");
    query.bindValue(":CIN",CIN);
    if (query.exec())
    {
        while(query.next() && row_count != 1)
             row_count++;
        if(row_count == 1)
        {
            afficheremail(model);
            query.prepare("UPDATE EMPLOYEE SET CIN =:CIN, E_MAIL=:E_mail where CIN=:CIN");
            query.bindValue(":E_mail",E_mail);
            query.bindValue(":CIN",cin_string);
            return query.exec();
        }
        else
            return false;
    }
    else
        return false;
}

void Employee::afficheremail(QSqlQueryModel* model)
{
          model = new QSqlQueryModel();
          model->setQuery("SELECTCIN, E_MAIL FROM employee");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("E-MAIL"));
}

////////////////////////////////////////////////////////////METIERS////////////////////////////////////////////////////////////

QSqlQueryModel* Employee::sorting(int min,int max,int* n)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM, CIN, NOMBRESCEANCE, ABSENCE, SALARY from EMPLOYEE where SALARY > :min and SALARY < :max order by SALARY ");
    query.bindValue(":min",min);
    query.bindValue(":max",max);
    query.exec();
    *n = 0;
    while(query.next())
    {
        (*n)++;
    }
    query.first();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SURNAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("N/SESSIONS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ABSENCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SALARY"));
    return model;
}

QSqlQueryModel* Employee::sortingall(int* n)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM, CIN, NOMBRESCEANCE, ABSENCE, SALARY from EMPLOYEE order by SALARY ");
    query.exec();
    *n = 0;
    while(query.next())
    {
        *n = *n + 1;
    }
    query.first();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SURNAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("N/SESSIONS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ABSENCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SALARY"));
    return model;
}

void Employee::ERROR()
{
    QMessageBox::critical(nullptr, QObject::tr("SEARCH FAILED"),
                QObject::tr("Employee couldn't be founded.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

QSqlQueryModel* Employee::search(int state,int cin,QString email)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    int row_count = 0;
    switch(state)
    {
        case 1 :
            query.prepare("SELECT NOM,PRENOM,CIN,SALARY,CITY,E_MAIL,CODE_PIN FROM EMPLOYEE where SALARY = (SELECT MAX(SALARY) from EMPLOYEE)");
            break;
        case 2 :
            query.prepare("SELECT NOM,PRENOM,CIN,SALARY,CITY,E_MAIL,CODE_PIN FROM EMPLOYEE where CIN=:CIN");
            query.bindValue(":CIN",cin);
            break;
        case 3 :
            query.prepare("SELECT NOM,PRENOM,CIN,SALARY,CITY,E_MAIL,CODE_PIN FROM EMPLOYEE where E_MAIL=:EMAIL");
            query.bindValue(":EMAIL",email);
            break;
    }
    if (query.exec())
    {
        if(query.next())
        {
            setnom(query.value(0).toString());
            setprenom(query.value(1).toString());
            setcin(query.value(2).toInt());
            setsalary(query.value(3).toFloat());
            setcity(query.value(4).toString());
            setemail(query.value(5).toString());
            setcodepin(query.value(6).toInt());
            query.previous();
        }
        while(query.next())
        {
            row_count++;
        }
        if(row_count == 1)
        {
            query.first();

            model->setQuery(query);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("NAME"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("SURNAME"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALARY"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));

        }
        else
            ERROR();
    }
    else
       ERROR();
    return model;
}

QString Employee::currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}

void Employee::pdf()
{
    QString html =
    "<body bgcolor=#bfbeba>"
        "<div align=right>"
           "Ariana, "+currDate()+
        "</div>"
        "<div align=left>"
           "Justice League<br>"
           "Eprit<br>"
           "Ariana soghra, Ghazela"
        "</div>"
        "<h1 align=center style=\"color:#333333\">Informations About "+getnom()+" "+getprenom()+"</h1>"
        "<p align=justify>"
           "<br><br><br><br><br><br><br><br><br>"
           "<b>NOM: </b>"+getnom()+
           "<br><br><br><b>PRENOM: </b>"+getprenom()+
           "<br><br><br><b>CIN: </b>"+QString::number(getcin())+
           "<br><br><br><b>CITY: </b>"+getcity()+
           "<br><br><br><b>CODEPIN: </b>"+QString::number(getcodepin())+
            "<br><br><br><b>EMAIL: </b>"+getemail()+
            "<br><br><br><b>SALARY: </b>"+QString::number(getsalary())+
        "</p>"
        "<div align=right>Human Resources</div>"
        "<div align=center><img src=\"C:/Users/Ala/Desktop/2A/projet/Logo.PNG\" width=\"500\" height=\"400\"></div>"
    "</body>";

    QTextDocument *document = new QTextDocument();
    document->setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(getnom()+".pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document->print(&printer);
}

bool Employee::verifcin(int cin)
{
    QSqlQuery query;
    int row_count = 0;
    query.prepare("SELECT * FROM EMPLOYEE where CIN=:CIN");
    query.bindValue(":CIN",cin);
    if (query.exec())
    {
        while(query.next() && row_count != 1)
             row_count++;
        if(row_count == 1)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Employee::isempty()
{
    QSqlQuery query;
    int row_count = 0;
    query.prepare("SELECT * FROM EMPLOYEE");
    if (query.exec())
    {
        while(query.next() && row_count != 1)
             row_count++;
        if(row_count != 0)
            return true;
        else
            return false;
    }
    else
        return false;
}
