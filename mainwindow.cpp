#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet.h"
#include "partenaire.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QPrinter>
#include <QFileDialog>
#include<QTextDocument>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabprojet->setModel(tmpprojet.afficher());
    ui->tabpartenaire->setModel(tmppartenaire.afficher());
    ui->lineedit_id->setValidator(new QIntValidator(100, 999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineedit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString type= ui->lineEdit_type->text();
    QString status= ui->lineEdit_status->text();
    QString adresse= ui->lineEdit_adresse->text();
    QString datedebut= ui->lineEdit_datedebut->text();
    int budget = ui->lineEdit_budget->text().toInt();



  Projet e(id,nom,type,status,adresse,datedebut,budget);
  bool test=e.ajouter();
  if(test)
{

      ui->tabprojet->setModel(tmpprojet.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un projet"),
                  QObject::tr("Projet ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Projet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_3_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpprojet.supprimer(id);
    if(test)
    {ui->tabprojet->setModel(tmpprojet.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Projet"),
                    QObject::tr("Projet supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Projet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_15->text().toInt();
    QString nom= ui->lineEdit_16->text();
    QString prenom= ui->lineEdit_17->text();
    QString adressem= ui->lineEdit_18->text();
    int num = ui->lineEdit_13->text().toInt();



  Partenaire e(id,nom,prenom,adressem,num);
  bool test=e.ajouter();
  if(test)
{

      ui->tabpartenaire->setModel(tmppartenaire.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Partenaire"),
                  QObject::tr("Partenaire ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Partenaire"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_4_clicked()
{
    int id = ui->lineEdit_14->text().toInt();
    bool test=tmppartenaire.supprimer(id);
    if(test)
    {ui->tabpartenaire->setModel(tmppartenaire.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Partenaire"),
                    QObject::tr("Partenaire supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Partenaire"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton10_clicked()
{
    int id= ui->lineEdit_6->text().toInt();
    QString nom=ui->lineEdit_7->text();
    QString type=ui->lineEdit_8->text();
    QString status=ui->lineEdit_9->text();
    QString adresse=ui->lineEdit_10->text();
    QString datedebut=ui->lineEdit_11->text();
    int budget= ui->lineEdit_12->text().toInt();



        Projet f;
        bool test=f.modifier(id,nom,type,status,adresse,datedebut,budget);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifie une fonction"),
                              QObject::tr("fonctin modifiée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tabprojet->setModel(tmpprojet.afficher());
}

//recherche
void MainWindow::on_pb_ajouter_2_clicked()
{
    int id;

        id=ui->lineEdit_5->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabprojet->setModel(tmpprojet.rechercher(id));
}
}


void MainWindow::on_pushButton_9_clicked()
{
    int id;

        id=ui->lineEdit_19->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabpartenaire->setModel(tmppartenaire.rechercher(id));
}

}



/*void MainWindow::on_radioButton_clicked()
{
    ui->tabprojet->setModel( tmpprojet.afficher_tri());
}
*/
void MainWindow::on_tabprojet_activated(const QModelIndex &index)
{
    QString idd = ui->tabprojet->model()->data(index).toString() ;
   QSqlQuery qry;
   qry.prepare("SELECT * from projet where id = '"+idd+"'") ;
   if (qry.exec())
   {
       while (qry.next()) {
           ui->lineEdit_6->setText(qry.value(0).toString()) ;
          ui->lineEdit_7->setText(qry.value(1).toString()) ;
          ui->lineEdit_8->setText(qry.value(2).toString()) ;
          ui->lineEdit_9->setText(qry.value(3).toString()) ;
          ui->lineEdit_10->setText(qry.value(4).toString()) ;
          ui->lineEdit_11->setText(qry.value(5).toString()) ;
          ui->lineEdit_12->setText(qry.value(6).toString()) ;
       }
   }
   QSqlQuery qry1;
   qry1.prepare("SELECT * from projet where id = '"+idd+"'") ;
   if (qry1.exec())
   {
       while (qry1.next()) {
           ui->lineEdit_id_2->setText(qry1.value(0).toString()) ;
       }
   }
   ui->tabprojet->setModel(tmpprojet.afficher());
   ui->tabprojet->setModel(tmpprojet.afficher());//refresh
}

void MainWindow::on_pushButton_clicked()
{
    ui->tabprojet->setModel( tmpprojet.afficher_tri());
    ui->tabprojet->setModel( tmpprojet.afficher_tri());
}

void MainWindow::on_pushButton_8_clicked()
{
    int id= ui->lineEdit_24->text().toInt();
    QString nom=ui->lineEdit_20->text();
    QString prenom=ui->lineEdit_25->text();
    QString adressem=ui->lineEdit_26->text();
    int num= ui->lineEdit_27->text().toInt();



        Partenaire f;
        bool test=f.modifier(id,nom,prenom,adressem,num);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifie une fonction"),
                              QObject::tr("fonctin modifiée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tabpartenaire->setModel(tmppartenaire.afficher());
}

void MainWindow::on_tabpartenaire_activated(const QModelIndex &index)
{

        QString idd = ui->tabpartenaire->model()->data(index).toString() ;
       QSqlQuery qry;
       qry.prepare("SELECT * from partenaire where id = '"+idd+"'") ;
       if (qry.exec())
       {
           while (qry.next()) {
               ui->lineEdit_24->setText(qry.value(0).toString()) ;
              ui->lineEdit_20->setText(qry.value(1).toString()) ;
              ui->lineEdit_25->setText(qry.value(2).toString()) ;
              ui->lineEdit_26->setText(qry.value(3).toString()) ;
              ui->lineEdit_27->setText(qry.value(4).toString()) ;

           }
       }
       QSqlQuery qry1;
       qry1.prepare("SELECT * from partenaire where id = '"+idd+"'") ;
       if (qry1.exec())
       {
           while (qry1.next()) {
               ui->lineEdit_14->setText(qry1.value(0).toString()) ;
           }
       }
       ui->tabpartenaire->setModel(tmppartenaire.afficher());
       ui->tabpartenaire->setModel(tmppartenaire.afficher());//refresh
    }


void MainWindow::on_pushButton_7_clicked()
{
    QString str;
    str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> GESTION DES PARTENAIRES </font><br /> <br /> "));
    str.append("<table border=1><tr>");
    str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">nom</font>&nbsp;&nbsp;"+"</td>");
    str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">Prenom</font>&nbsp;&nbsp;"+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""20"">adresse</font>&nbsp;&nbsp;")+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">numero</font>&nbsp;&nbsp;")+"</td>");
    QSqlQuery * query=new QSqlQuery();
    query->exec("SELECT nom,prenom,adressem,num FROM partenaire");
    while(query->next())
    {
        str.append("<tr><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
        str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
        str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
         str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");

}

    str.append("</table></center><body></html>");

    QPrinter printer;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    QString path= QFileDialog::getSaveFileName(NULL,"imprimer","gestion des Partenaire","PDF(*.pdf");
     if(path.isEmpty()) return;
     printer.setOutputFileName(path);
     QTextDocument doc;
     doc.setHtml(str);
     doc.print(&printer);
}
