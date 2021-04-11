#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sponsor.h"
#include "marketing.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabsponsor->setModel(tmpsponsor.afficher());
    ui->tabmarketing->setModel(tmpmarketing.afficher());
    ui->lineEdit_24->setValidator(new QIntValidator(100, 999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_6->text().toInt();
    QString nom= ui->lineEdit_38->text();
    QString adresse= ui->lineEdit_8->text();
    QString mail= ui->lineEdit_9->text();
    QString produit= ui->lineEdit_10->text();
    QString convention= ui->lineEdit_11->text();
    int numtel = ui->lineEdit_12->text().toInt();



  Sponsor e(id,nom,adresse,mail,produit,convention,numtel);
  bool test=e.ajouter();
  if(test)
{

      ui->tabsponsor->setModel(tmpsponsor.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un sponsor"),
                  QObject::tr("sponsor ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un sponsor"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_3_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpsponsor.supprimer(id);
    if(test)
    {ui->tabsponsor->setModel(tmpsponsor.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un sponsor"),
                    QObject::tr("sponsor supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un sponsor"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_24->text().toInt();
    QString nom= ui->lineEdit_20->text();
    QString type= ui->lineEdit_25->text();
    QString date= ui->lineEdit_26->text();
    int num = ui->lineEdit_27->text().toInt();



  Marketing e(id,nom,type,date,num);
  bool test=e.ajouter();
  if(test)
{

      ui->tabmarketing->setModel(tmpmarketing.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter marketing"),
                  QObject::tr("Marketing ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter marketing"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_4_clicked()
{
    int id = ui->lineEdit_14->text().toInt();
    bool test=tmpmarketing.supprimer(id);
    if(test)
    {ui->tabmarketing->setModel(tmpmarketing.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer marketing"),
                    QObject::tr("marketing supprimé.\n"
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
        QString nom=ui->lineEdit_38->text();
        QString adresse=ui->lineEdit_8->text();
        QString mail=ui->lineEdit_9->text();
        QString produit=ui->lineEdit_10->text();
        QString convention=ui->lineEdit_11->text();
        int numtel= ui->lineEdit_12->text().toInt();



            Sponsor f;
            bool test=f.modifier(id,nom,adresse,mail,produit,convention,numtel);

            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("modifie une Sponsor"),
                                  QObject::tr("Sponsor modifiée.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tabsponsor->setModel(tmpsponsor.afficher());
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tabsponsor->setModel(tmpsponsor.afficher());

}

//recherche
void MainWindow::on_pb_ajouter_2_clicked()
{
    int id;

        id=ui->lineEdit_5->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabsponsor->setModel(tmpsponsor.rechercher(id));
}
}


void MainWindow::on_pushButton_9_clicked()
{
    int id;

        id=ui->lineEdit_19->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabmarketing->setModel(tmpmarketing.rechercher(id));
}

}



/*void MainWindow::on_radioButton_clicked()
{
    ui->tabprojet->setModel( tmpprojet.afficher_tri());
}

void MainWindow::on_tabsponsor_activated(const QModelIndex &index)
{
    QString idd = ui->tabsponsor->model()->data(index).toString() ;
   QSqlQuery qry;
   qry.prepare("SELECT * from sponsor where id = '"+idd+"'") ;
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
   qry1.prepare("SELECT * from sponsor where id = '"+idd+"'") ;
   if (qry1.exec())
   {
       while (qry1.next()) {
           ui->lineEdit_id_2->setText(qry1.value(0).toString()) ;
       }
   }
   ui->tabsponsor->setModel(tabsponsor.afficher());
   ui->tabsponsor->setModel(tabsponsor.afficher());//refresh
}

void MainWindow::on_pushButton_clicked()
{
    ui->tabsponsor->setModel( tabsponsor.afficher_tri());
    ui->tabsponsor->setModel( tabsponsor.afficher_tri());
}*/








void MainWindow::on_pushButton_clicked()
{
    ui->tabsponsor->setModel( tmpsponsor.afficher_tri());

}

void MainWindow::on_pushButton_8_clicked()
{
    int id= ui->lineEdit_24->text().toInt();
        QString nom=ui->lineEdit_20->text();
        QString type=ui->lineEdit_25->text();
        QString date=ui->lineEdit_26->text();
        int num= ui->lineEdit_27->text().toInt();



            Marketing f;
            bool test=f.modifier(id,nom,type,date,num);

            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("modifie une Marketing"),
                                  QObject::tr("Marketing modifiée.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tabmarketing->setModel(tmpmarketing.afficher());
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tabmarketing->setModel(tmpmarketing.afficher());

}
