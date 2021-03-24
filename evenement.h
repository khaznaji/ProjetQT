#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>


class evenement
{public:
    evenement();
   evenement(QString,QString,QString);
   QString get_titre();
       QString get_type();
       QString get_lieu();

       void set_titre(QString);
       void set_type(QString);
       void set_lieu(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();


private:
    QString titre,type,lieu;

};

#endif // EVENEMENT_H
