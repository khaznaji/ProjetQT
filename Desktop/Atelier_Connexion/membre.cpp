#include "membre.h"
#include<QSqlQuery>
#include<QtDebug>
Membre::Membre()
{
id=0;
nom=" ";
prenom=" ";
adr=" ";
mail=" ";}
Membre::Membre(int id,int num,QString nom,QString prenom,QString adr,QString mail,QString date)
{this->id=id; this->num=num; this->nom=nom; this->prenom=prenom; this->adr=adr; this->mail=mail; this->date=date;}
int Membre::getid (int);
int Membre::getnum(int);
QString Membre::getnom(QString);
QString Membre::getprenom(QString);
QString Membre::getadr(QString);
QString Membre::getmail(QString);
QString Membre::getdate(QString);
void Membre::setid(int id){this->id=id;}
void Membre::setnum(int num){this->num=num;}
void Membre::setnom(QString nom){this->nom=nom;}
void Membre::setprenom(QString prenom){this->prenom=prenom;}
void Membre::setadr(QString adr){this->adr=adr;}
void Membre::setmail(QString mail){this->mail=mail;}
void Membre::setdate(QString date){this->date=date;}
bool Membre::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString num_string=QString::number(num);
    query.prepare("INSERT INTO membre (id, nom, prenom, adr, mail, date_n) "
                  "VALUES (:id, :nom, :prenom, :adr, :mail, :date_n)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adr", adr);
    query.bindValue(":mail", mail);
    query.bindValue(":num", num_string);
    query.bindValue(":date_n", date);
    return query.exec();


}
