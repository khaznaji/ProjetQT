#ifndef MEMBRE_H
#define MEMBRE_H

#include<QString>
#include<QSqlQuery>

class Membre
{
public:
    Membre();
    Membre(int,int,QString,QString,QString,QString,QString);
    int getid(){return id;}
    int getnum(){return num;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getadr(){return adr;}
    QString getmail(){return mail;}
    QString getdate(){return date;}
    void setid(int);
    void setnum(int);
    void setnom(QString);
    void setprenom(QString);
    void setadr(QString);
    void setmail(QString);
    void setdate(QString);
    bool ajouter();

private:
    int id,num;
    QString nom,prenom,adr,mail,date;


};

#endif // MEMBRE_H
