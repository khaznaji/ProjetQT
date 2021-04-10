#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Projet
{
public:
    Projet();
    Projet(int,QString,QString,QString,QString,QString,int);
    int getid();
    int getbudget();
    QString getdatedebut();
    QString getnom();
    QString gettype();
    QString getstatus();
    QString getadresse();

    void setnom (QString);
    void settype(QString);
    void setstatus(QString);
    void setadresse(QString);
    void setbudget(int);
    void setdatedebut(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,QString,int);
    //bool modifier(int,QString,QString,QString,QString,QString,int);
  //  bool modifier();
    QSqlQueryModel * rechercher(int);
    QSqlQueryModel * afficher_tri();



private:
    int id,budget;
    QString nom,type,status,adresse,datedebut;
};

#endif // PROJET_H
