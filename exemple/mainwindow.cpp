#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);


ui->tabetudiant->setModel(tmpevenement.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    QString titre= ui->lineEdit_titre->text();
    QString type= ui->lineEdit_type->text();
    QString lieu= ui->lineEdit_lieu->text();

  evenement e(titre,type,lieu);
  bool test=e.ajouter();
  if(test)
{

      ui->tabetudiant->setModel(tmpevenement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
 QString titre= ui->lineEdit_titre->text();
bool test=tmpevenement.supprimer(titre);
if(test)
{ui->tabetudiant->setModel(tmpevenement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
