#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QString>

#include <QSqlQuery> //execution et manipulation sql statements
#include <QSqlQueryModel>


class evenement
{public:
    evenement(); //constructeur par déf
      evenement(QString,QString,QString,QString,QString); //constructeur parametre
       QString get_titre(); //retourner chaine
       QString get_type();
       QString get_lieu();
       QString get_datedebut();
       QString get_datefin();


       void set_titre(QString); // prend une nouvelle valeur
       void set_type(QString);
       void set_lieu(QString);
       void set_datedebut(QString);
       void set_datefin(QString);


    bool ajouter();//creer methode ajouter
    QSqlQueryModel * afficher(); //retourner un tableau de type sql ( les informations)
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();
    QSqlQueryModel * rechercheDynamic(QString);




private:
    QString titre,type,lieu,datedebut,datefin;

};

#endif // EVENEMENT_H
