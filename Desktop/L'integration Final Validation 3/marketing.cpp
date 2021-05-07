#include "marketing.h"
#include <QDebug>
#include "connexion.h"
#include <QSqlQuery>


Marketing::Marketing()
{   id=0;
    nom="";
    type="";
    date="";
    num=0;
}
Marketing::Marketing(int id,QString nom,QString type,QString date, int num)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->date=date;
    this->num=num;
}
int Marketing::getid(){return id;}
QString Marketing::getnom(){return  nom;}
QString Marketing::gettype(){return  type;}
QString Marketing::getdate(){return  date;}
int Marketing::getnum(){return num;}

bool Marketing::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO marketing (ID, NOM, TYPE, DATEM,  NUME) "
                    "VALUES (:id, :nom, :type, :datem, :nume)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":datem", date);
query.bindValue(":nume", num);

return    query.exec();
}

QSqlQueryModel * Marketing::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from marketing");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num"));
    return model;
}

bool Marketing::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from marketing where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * Marketing::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from marketing where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
bool Marketing::modifier(int id ,QString nom,QString type,QString date,int num)
{
    QSqlQuery query;
    query.prepare("UPDATE marketing SET id= :id,nom= :nom,type = :type,datem = :datem,nume= :nume  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":datem",date);
    query.bindValue(":nume",num);

    return    query.exec();
}

Marketingh::Marketingh()
{
nom="";
datee="";
fn="";
}
Marketingh::Marketingh(QString nom,QString datee,QString fn)
{
    this->nom=nom;
    this->datee=datee;
    this->fn=fn ;
}
QString Marketingh::get_datee(){return  datee;}
QString Marketingh::get_fn(){return  fn;}
QString Marketingh::get_nom(){return  nom;}
bool Marketingh::ajoutehis()
{
    QSqlQuery query;
    query.prepare("INSERT INTO historique2 (NOM, DATEE, FN) "
                  "VALUES (:nom, :datee, :fn)");
    query.bindValue(":nom", nom);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
bool Marketingh::modifierhis()
{
    QSqlQuery query;
    query.prepare("UPDATE historique2 SET datee='"+datee+"',fn='"+fn+"' where nom='"+nom+"'  ;");
    query.bindValue(":nom",nom);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
QSqlQueryModel * Marketingh::afficherhis()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from historique2");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("fonction "));
        return model;

}

