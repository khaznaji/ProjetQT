#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"membre.h"
#include"fonction.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_2_clicked()
{ int id=ui->le_id->text().toInt();
    int num=ui->le_num->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString adr=ui->le_adr->text();
    QString mail=ui->le_mail->text();
    QString date=ui->la_date->text();
    Membre M(id,num,nom,prenom,adr,mail,date);
}

void MainWindow::on_pb_ajouter_clicked()
{
    int idfonction=ui->idf->text().toInt();
        QString dep=ui->dep->text();
        QString dir=ui->dir->text();
        QString service=ui->poste->text();
        QString poste=ui->service->text();
}
