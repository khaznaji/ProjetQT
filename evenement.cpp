#include "evenement.h"
#include <QDebug>
#include "connexion.h"

evenement::evenement()
{
titre=" ";
type=" ";
lieu=" ";
datedebut=" ";
datefin=" ";

}
evenement::evenement(QString titre,QString type,QString lieu,QString datedebut,QString datefin)
{
  this->titre=titre; //affecter les nouvelles valeurs insere par l'utilisateur et les attribue au niveau des attibuts

  this->type=type;
  this->lieu=lieu;
  this->datedebut=datedebut;
  this->datefin=datefin;



}
void evenement::set_titre(QString tit){ titre=tit; }
void evenement::set_type(QString typ){ type=typ; }
void evenement::set_lieu(QString lie){ lieu=lie; }
void evenement::set_datedebut(QString ddebut){ datedebut=ddebut; }
void evenement::set_datefin(QString dfin){ datefin=dfin; }


bool evenement::ajouter() //implementer l_objet ajouter
{
QSqlQuery query;

query.prepare("INSERT INTO evenement (TITRE, TYPE, LIEU, DATEDEBUT, DATEFIN) "
                    "VALUES (:titre, :type, :lieu, :datedebut, :datefin)");
query.bindValue(":titre", titre); //bindvalue sert a faire la correspondance entre le nom de la variable et la valeur stocke au niveau de la zone saisie par  l'utilisateur
query.bindValue(":type", type);
query.bindValue(":lieu", lieu);
query.bindValue(":datedebut", datedebut);
query.bindValue(":datefin", datefin);



return    query.exec(); // exec methode retourne true or false ; preparation , correspndance , execution
}

QSqlQueryModel * evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TITRE"));//entrin d'ajouter le nom du coloone du tableau
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEDEBUT "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEFIN"));


    return model;
}

bool evenement::supprimer(QString titre)
{
QSqlQuery query;

query.prepare("Delete from evenement where TITRE = :titre ");
query.bindValue(":titre", titre);
return    query.exec();
}
QSqlQueryModel *evenement::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from evenement where titre LIKE '"+rech+"%' or type LIKE '"+rech+"%'");
    return model;
}
bool evenement::modifier(QString titre)
{
    QSqlQuery query;

  query.prepare("UPDATE evenement set type='"+type+"',lieu='"+lieu+"',datedebut='"+datedebut+"',datefin='"+datefin+"' WHERE titre LIKE '"+titre+"' ");
   return query.exec();
    }
QSqlQueryModel * evenement::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from evenement ORDER BY titre ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datefin"));


        return model;
}
