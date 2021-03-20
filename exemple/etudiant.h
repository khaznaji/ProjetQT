#ifndef ETUDIANT_H
#define ETUDIANT_H
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


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
private:
    QString titre,type,lieu;

};

#endif // ETUDIANT_H
