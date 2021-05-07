#ifndef MARKETING_H
#define MARKETING_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Marketing
{
public:
    Marketing();
    Marketing(int,QString,QString,QString,int);
    int getid();
    QString getnom();
    QString gettype();
    QString getdate();
    int getnum();

    void setnom (QString);
    void settype (QString);
    void setdate(QString);
    void setnum(int);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(int);
    bool modifier(int,QString,QString,QString,int);




private:
    int id,num;
    QString nom,type,date;
};
class Marketingh
{
public:
       Marketingh() ;
       Marketingh(QString,QString,QString) ;
       QString get_nom();
       QString get_datee();
       QString get_fn();
       QSqlQueryModel * afficherhis() ;
       bool ajoutehis();
       bool modifierhis() ;
private:

    QString nom,datee,fn ;
};




#endif
