#ifndef ADHERANT_H
#define ADHERANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class adherant
{public:
    adherant();
      adherant(QString,QString,QString,QString,QString,QString,QString);
       QString get_id();
       QString get_nom();
       QString get_prenom();
       QString get_numtel();
       QString get_mail();
       QString get_type();
       QString get_competence();


       void set_id(QString);
       void set_nom(QString);
       void set_prenom(QString);
       void set_numtel(QString);
       void set_mail(QString);
       void set_type(QString);
       void set_competence(QString);




    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();


private:
    QString id,nom,prenom,numtel,mail,type,competence;

};

#endif // ADHERANT_H
