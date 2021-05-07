#ifndef MATERIEL_H
#define MATERIEL_H


#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>

class Materiel
{
public:
    Materiel();
    Materiel(QString,QString,int,int,int,int,int);
     QString get_nom();
     QString get_type();
     int get_cout();
     int get_duree();
     int get_volume();
     int get_poids();
     int get_nbr();


     void set_nom(QString);
     void set_type(QString);
     void set_cout(int);
     void set_duree(int);
     void set_volume(int);
     void set_poids(int);
     void set_nbr(int);




  bool ajouter();
  QSqlQueryModel * afficher();
  bool supprimer(QString);
  bool modifier(QString nom,QString type,int cout ,int duree ,int volume ,int poids ,int nbr);
  QSqlQueryModel * rechercher(QString);
  QSqlQueryModel * tri();


private:
  QString nom,type;
  int cout,duree,nbr,volume,poids;


};

#endif // MATERIEL_H
