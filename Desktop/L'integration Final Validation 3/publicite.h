#ifndef PUBLICITE_H
#define PUBLICITE_H
#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>



class publicite
{
public:
    publicite();
    publicite(int,QString,QString,QString,QString);
     int get_id();
     QString get_titre();
     QString get_form();
     QString get_description();
     QString get_dte();



     void set_id(int);
     void set_titre(QString);
     void set_form(QString);
     void set_description(QString);
     void set_dte(QString);





     bool ajouter();
     QSqlQueryModel * afficher();
     bool supprimer(int);
      bool modifier(int,QString,QString,QString,QString);
     QSqlQueryModel * rechercher(QString);
         QSqlQueryModel * tri();
         QSqlQueryModel * rechercheDynamic(QString);

private:
    QString titre,form,description,dte;
    int id;

};


#endif // PUBLICITE_H
