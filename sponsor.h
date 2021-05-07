#ifndef SPONSOR_H
#define SPONSOR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Sponsor
{
public:
    Sponsor();
    Sponsor(int,QString,QString,QString,QString,QString,int);
    int getid();
    QString getadresse();
    QString getmail();
    int getnumtel();
    QString getnom();
    QString getproduit();
    QString getconvention();

    void setadresse (QString);
    void setmail(QString);
    void setnom(QString);
    void setproduit(QString);
    void setnumtel(int);
    void setconvention(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    //bool modifier(int,QString,QString,QString,QString,QString,int);
    bool modifier(int,QString,QString,QString,QString,QString,int);
    QSqlQueryModel * rechercher(int);
    QSqlQueryModel * afficher_tri();



private:
    int id,numtel;
    QString nom,adresse,mail,produit,convention;
};

#endif
