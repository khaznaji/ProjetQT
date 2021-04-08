#include "participant.h"
#include <QDebug>
#include "connexion.h"

participant::participant()
{
nom=" ";
prenom=" ";
adresse=" ";

}
participant::participant(QString nom,QString prenom,QString adresse)
{
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;


}
QString participant::get_nom(){return  nom;}
QString participant::get_prenom(){return prenom;}
QString participant::get_adresse(){return adresse;}


bool participant::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO participant (NOM, PRENOM, ADRESSE) "
                    "VALUES (:nom, :prenom, :adresse)");
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);


return    query.exec();
}

QSqlQueryModel * participant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from participant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}

bool participant::supprimer(QString nom)
{
QSqlQuery query;

query.prepare("Delete from participant where NOM = :nom ");
query.bindValue(":nom", nom);
return    query.exec();
}
QSqlQueryModel *participant::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from participant where nom LIKE '"+rech+"%' or prenom LIKE '"+rech+"%'");
    return model;
}
bool participant::modifier(QString nom)
{
    QSqlQuery query;

  query.prepare("UPDATE participant set prenom='"+prenom+"',adresse='"+adresse+"' WHERE nom LIKE '"+nom+"' ");
   return query.exec();
    }
QSqlQueryModel * participant::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from participant ORDER BY nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));



        return model;
}
