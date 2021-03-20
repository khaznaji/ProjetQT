#include "etudiant.h"
#include <QDebug>
#include "connexion.h"

evenement::evenement()
{
titre=" ";
type=" ";
lieu=" ";

}
evenement::evenement(QString titre,QString type,QString lieu)
{
  this->titre=titre;
  this->type=type;
  this->lieu=lieu;


}
QString evenement::get_titre(){return  titre;}
QString evenement::get_type(){return type;}
QString evenement::get_lieu(){return lieu;}


bool evenement::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO membre (TITRE, TYPE, LIEU) "
                    "VALUES (:titre, :type, :lieu)");
query.bindValue(":titre", titre);
query.bindValue(":type", type);
query.bindValue(":lieu", lieu);


return    query.exec();
}

QSqlQueryModel * evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TITRE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));

    return model;
}

bool evenement::supprimer(QString titre)
{
QSqlQuery query;

query.prepare("Delete from membre where TITRE = :titre ");
query.bindValue(":titre", titre);
return    query.exec();
}



