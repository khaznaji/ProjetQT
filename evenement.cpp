#include "evenement.h"
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
void evenement::set_titre(QString tit){ titre=tit; }
void evenement::set_type(QString typ){ type=typ; }
void evenement::set_lieu(QString lie){ lieu=lie; }


bool evenement::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO evenement (TITRE, TYPE, LIEU) "
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

  query.prepare("UPDATE evenement set type='"+type+"',lieu='"+lieu+"' WHERE titre LIKE '"+titre+"' ");
   return query.exec();
    }
QSqlQueryModel * evenement::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from evenement ORDER BY titre ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));

        return model;
}
