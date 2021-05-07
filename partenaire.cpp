#include "partenaire.h"
#include <QDebug>
#include "connexion.h"
#include <QSqlQuery>


Partenaire::Partenaire()
{   id=0;
    nom="";
    prenom="";
    adressem="";
    num=0;
}
Partenaire::Partenaire(int id,QString nom,QString prenom,QString adressem, int num)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adressem=adressem;
    this->num=num;
}
int Partenaire::getid(){return id;}
QString Partenaire::getnom(){return  nom;}
QString Partenaire::getprenom(){return  prenom;}
QString Partenaire::getadressem(){return  adressem;}
int Partenaire::getnum(){return num;}

bool Partenaire::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO partenaire (ID, NOM, PRENOM, ADRESSEM,  NUM) "
                    "VALUES (:id, :nom, :prenom, :adressem, :num)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adressem", adressem);
query.bindValue(":num", num);

return    query.exec();
}

QSqlQueryModel * Partenaire::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from partenaire");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adressem"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num"));
    return model;
}

bool Partenaire::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from partenaire where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * Partenaire::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from partenaire where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
bool Partenaire::modifier(int id,QString nom,QString prenom,QString adressem, int num)
{
    QSqlQuery query;
    query.prepare("UPDATE partenaire SET id= :id,nom = :nom,prenom = :prenom,adressem= :adressem,num= :num  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adressem",adressem);
    query.bindValue(":num",num);


    return    query.exec();
}
