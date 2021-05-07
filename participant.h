#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>


class participant
{public:
    participant();
   participant(QString,QString,QString,int,int,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_mail();
    int get_CIN();
    int get_numtel();
    QString get_datenaissance();
    QString get_typeeve();

    void set_nom(QString);
    void set_prenom(QString);
    void set_mail(QString);
    void set_CIN(int);
    void set_numtel(int);
    void set_datenaissance(QString);
    void set_typeeve(QString);





    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
     bool modifier(QString,QString,QString,int,int,QString,QString);
    QSqlQueryModel * rechercher(QString);
        QSqlQueryModel * tri();

private:
    QString nom,prenom,mail,datenaissance,typeeve;
    int CIN,numtel;

};


#endif // PARTICIPANT_H
