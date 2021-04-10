#ifndef PARTENAIRE_H
#define PARTENAIRE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Partenaire
{
public:
    Partenaire();
    Partenaire(int,QString,QString,QString,int);
    int getid();
    int getnum();
    QString getnom();
    QString getprenom();
    QString getadressem();

    void setnom (QString);
    void setprenom(QString);
    void setadressem(QString);
    void setnum(int);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(int);
    bool modifier(int,QString,QString,QString,int );



private:
    int id,num;
    QString nom,prenom,adressem;
};




#endif // PARTENAIRE_H
