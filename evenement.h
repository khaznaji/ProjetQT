#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>


class evenement
{public:
    evenement();
      evenement(QString,QString,QString,QString,QString);
       QString get_titre();
       QString get_type();
       QString get_lieu();
       QString get_datedebut();
       QString get_datefin();


       void set_titre(QString);
       void set_type(QString);
       void set_lieu(QString);
       void set_datedebut(QString);
       void set_datefin(QString);



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();


private:
    QString titre,type,lieu,datedebut,datefin;

};

#endif // EVENEMENT_H
