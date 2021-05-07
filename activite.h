#ifndef ACTIVITE_H
#define ACTIVITE_H


#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class activite
{public:
    activite(){};
   activite(QString,QString,QString,QString,QDate);
    QString get_nom();
    QString get_type();
    QString get_duree();
    QString get_nbr();
    QDate get_date();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
     bool modifier(QString);
    QSqlQueryModel * rechercher(QString);
        QSqlQueryModel * tri();

private:
    QString nom,type,duree,nbr;
    QDate date;

};


#endif // ACTIVITE_H
