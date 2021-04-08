#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>


class participant
{public:
    participant();
   participant(QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_adresse();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
     bool modifier(QString);
    QSqlQueryModel * rechercher(QString);
        QSqlQueryModel * tri();

private:
    QString nom,prenom,adresse;

};


#endif // PARTICIPANT_H
