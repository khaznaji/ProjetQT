#include "Membre.h"
#include <QDebug>
#include "connexion.h"
Membre::Membre()
{
id=0;
num=0;
nom="";
prenom="";
adr="";
mail="";
slr=0;
}
Membre::Membre(int id,int num, int slr,QString nom,QString prenom,QString adr, QString mail)
{
  this->id=id;
 this->slr=slr;
    this->num=num;
  this->nom=nom;
  this->prenom=prenom;
    this->adr=adr;
    this->mail=mail;
}
void Membre::set_nom(QString name){ nom=name; }
void Membre::set_prenom(QString last){ prenom=last; }
void Membre::set_adr(QString adresse){ adr=adresse; }
void Membre::set_mail(QString email){ mail=email; }
void Membre::set_num(int number){num=number;}
void Membre::set_id(int idm){id=idm;}

bool Membre::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(slr);
QString res2= QString::number(num);
query.prepare("INSERT INTO membre (ID, NOM, SLR, PRENOM, NUM, ADR, MAIL) "
                    "VALUES (:id, :nom, :slr ,:prenom , :num, :adr, :mail)");
query.bindValue(":id", res);
query.bindValue(":slr", res1);
query.bindValue(":num", res2);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adr", adr);
query.bindValue(":mail", mail);

return    query.exec();
}
QSqlQueryModel * Membre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from membre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numero De Téléphone"));

    return model;
}
bool Membre::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from membre where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Membre::modifier (int id,int num ,int slr, QString nom ,QString prenom,QString adr,QString mail)
{
    QSqlQuery query;
    query.prepare("UPDATE membre SET id= :id,num= :num,slr = :slr,nom = :nom,prenom = :prenom,adr = :adr, mail = :mail  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":num",num);
    query.bindValue(":slr",slr);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adr",adr);
    query.bindValue(":mail",mail);
    return    query.exec();
}
//recherche
QSqlQueryModel *Membre::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from membre where id LIKE '"+rech+"%' or id LIKE '"+rech+"%'");
    return model;
}
//tri
QSqlQueryModel * Membre::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from membre ORDER BY slr ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero De Téléphone"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Slr"));

        return model;

}
int Membre::calculer(QString type) {
      QSqlQuery query;

      query.prepare("select *  from membre  where ( slr = :type)");
      query.bindValue(":type", type);

   query.exec();
      int total = 0;
      while (query.next()) {
        total++;
      }
return total;

      }
