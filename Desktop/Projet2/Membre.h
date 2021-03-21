#ifndef MEMBRE_H
#define MEMBRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Membre
{public:

    //Constructeurs

    Membre();
    Membre(int,int,int,QString,QString,QString,QString);

    //Les Getters:

    QString get_nom();
    QString get_prenom();
    QString get_adr();
    QString get_mail();
    int get_id();
    int get_slr();
    int get_num();

    //Les Setters:

    void set_nom(QString);
    void set_prenom(QString);
    void set_mail(QString);
    void set_num(int);
    void set_id(int);
    void set_adr(QString);

    //Crud

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,int,QString,QString,QString,QString);
private:
    QString nom,prenom,adr,mail;
    int id,num,slr;
};

#endif // MEMBRE_H
