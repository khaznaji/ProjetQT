#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,QString,QString,int,QString,QString);
    int get_id();
    QString get_nom();
     QString get_prenom();
     QString get_mail();
     int get_num();
     QString get_niveau();
     QString get_controle();





void set_id(int);
     void set_nom(QString);
     void set_prenom(QString);
     void set_mail(QString);

     void set_num(int);
     void set_niveau(QString);

     void set_controle(QString);





  bool ajouter();
  QSqlQueryModel * afficher();
  bool supprimer(int idd);
  bool modifier (int id,QString nom,QString prenom ,QString mail,int num,QString niveau ,QString controle);
  QSqlQueryModel * rechercher(QString);
  QSqlQueryModel * tri();


private:
  QString nom,prenom,mail,niveau,controle;
  int id,num;


};
#endif // FOURNISSEUR_H
