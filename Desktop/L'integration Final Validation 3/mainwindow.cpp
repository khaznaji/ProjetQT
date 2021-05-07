
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Membre.h"
#include"fonction.h"
#include"dialog1.h"
#include"dial.h"
#include"dialo.h"
#include"mainwindow1.h"
#include"admin.h"
#include <QMessageBox>
#include<QPainter>
#include<QFileDialog>
#include<QMediaPlayer>
#include<QSound>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QSqlQuery>
#include <QPropertyAnimation>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<iostream>
#include"smtp.h"
#include<QSystemTrayIcon>
#include<stat.h>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include "mainwindowvideo.h"
#include"note.h"
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QJsonValue>
#include <QJsonValueRef>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include"publicite.h"
#include"evenement.h"
#include"participant.h"
#include"materiel.h"
#include"fournisseur.h"
#include<QTimer>
#include<QDate>
#include "projet.h"
#include "partenaire.h"
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include "sponsor.h"
#include "marketing.h"
#include"ardyuno2.h"
#include"arduin.h"

#include<QDateTime>
#include<QDesktopServices>
double firstNum;
bool userIsTypingSecondNum = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
QTimer *timer= new QTimer (this);
connect (timer ,SIGNAL(timeout()),this,SLOT (clockTimer()));
timer ->start();
//Calculator
connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt1,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt2,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt3,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt4,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt5,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt6,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt7,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt8,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButt9,SIGNAL(released()),this,SLOT(digit_pressed()));
connect(ui->pushButton_signal,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
connect(ui->pushButton_porcentage,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
connect(ui->pushButton_division,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
connect(ui->pushButton_times,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

ui->pushButton_plus->setCheckable(true);
ui->pushButton_minus->setCheckable(true);
ui->pushButton_division->setCheckable(true);
ui->pushButton_times->setCheckable(true);
//Music
/*mMediaPlayer=new QMediaPlayer(this);
connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos){ui->avance_3->setValue(pos);});
connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 dur){ui->avance_3->setMaximum(dur);});*/
//Mailing
connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
connect(ui->sendBtn_2, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn_2, SIGNAL(clicked()),this, SLOT(close()));
connect(ui->browseBtn_2, SIGNAL(clicked()), this, SLOT(browse()));
connect(ui->sendBtn_3, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn_3, SIGNAL(clicked()),this, SLOT(close()));
connect(ui->sendBtn_4, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn_4, SIGNAL(clicked()),this, SLOT(close()));
//CRUD Lina
ui->tabmembre->setModel(tmpmembre.afficher());
ui->tableView->setModel(tmpfonction.afficher());
ui->tabarticle->setModel(tmparticle.afficher());
//CRUD Yassine
ui->tabevenement->setModel(tmpevenement.afficher()); //remplir le tableau via un model
ui->tabparticipant->setModel(tmpparticipant.afficher());
ui->tabpublicite->setModel(tmppub.afficher());
MainWindow::afficherStatistique();

//CRUD Zeineb
ui->tabmateriel->setModel(tmpmateriel.afficher());
ui->tabfournisseurs->setModel(tmpfournisseur.afficher());
//crud aboud
ui->tabprojet->setModel(tmpprojet.afficher());
ui->tabpartenaire->setModel(tmppartenaire.afficher());
 //crud mahdi
 ui->tabsponsor->setModel(tmpsponsor.afficher());
 ui->tabmarketing->setModel(tmpmarketing.afficher());
 ui->lineEdit_43->setValidator(new QIntValidator(100, 999, this));
 MainWindow::afficherStatistiqueM();

 //crud hazem
 ui->tabadherant->setModel(tmpadherant.afficher());
 ui->tabactivite->setModel(tmpactivite.afficher());

//controle de saisie
 ui->lineEdit_id->setValidator(new QIntValidator(0,999,this));
 ui->lineEdit_3->setValidator(new QIntValidator(0,99999999,this));
 ui->lineEdit_4->setValidator(new QIntValidator(0,999999,this));
 ui->lineEdit_ida->setValidator(new QIntValidator(0,999,this));
 QRegExp rx("[a-zA-Z]+");
 QValidator *validator = new QRegExpValidator(rx, this);

 ui->lineEdit_nom->setValidator(validator);
 ui->lineEdit_prenom->setValidator(validator);
 ui->lineEdit->setValidator(validator);

 ui->lineEdit_13->setValidator(validator);
 ui->lineEdit_16->setValidator(validator);
 ui->lineEdit_17->setValidator(validator);
 ui->lineEdit_18->setValidator(validator);
 ui->lineEdit_type->setValidator(validator);
 ui->lineEdit_6->setValidator(validator);
// controle de saisie zeineb


 //fournisseur
  ui->le_nom->setValidator(validator);
  ui->prenom->setValidator(validator);
  ui->nv->setValidator(validator);
  ui->ctrl->setValidator(validator);

 ui->le_id->setValidator(new QIntValidator(0,999,this));
 ui->num->setValidator(new QIntValidator(0,99999999,this));
 //materiel
 ui->nom->setValidator(validator);
 ui->typ->setValidator(validator);
 ui->cout->setValidator(new QIntValidator(0,99999,this));
 ui->duree->setValidator(new QIntValidator(0,999,this));
 ui->vlm->setValidator(new QIntValidator(0,999,this));
 ui->poids->setValidator(new QIntValidator(0,999,this));
 ui->nbr->setValidator(new QIntValidator(0,999,this));


//Importation de l'image
ui->progressBar->setValue(0);
//Affectation
ui->comboBox->setModel(tmpfonction.affecter_membre());
//Affection Abderahmen
ui->comboBox_5->setModel(tmpprojet.affecter_partenaire());
//Affectation Yassine
ui->comboBox_6->setModel(tmpparticipant.affecter_evenement());

/************************************Animation1********************************************/
animation =new QPropertyAnimation(ui->label_47,"geometry");

    animation->setDuration(10000);
    animation->setStartValue(ui->label->geometry());
    animation->setEndValue(QRect(200,65,400,90));

    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    curve.setAmplitude(2.00);
    animation->setLoopCount(2);
    animation->start();
/******************************************Animation2LINA****************************************/

    animation =new QPropertyAnimation(ui->label_10,"geometry");
    animation->setDuration(10000);
    animation->setStartValue(ui->label->geometry());
    animation->setEndValue(QRect(200,65,400,90));

    QEasingCurve curver;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    curve.setAmplitude(2.00);
    animation->setLoopCount(2);
    animation->start();

/******************************************Animation2Yassine****************************************/
animation =new QPropertyAnimation(ui->label_76,"geometry");
animation->setDuration(10000);
animation->setStartValue(ui->label->geometry());
animation->setEndValue(QRect(200,65,400,90));

QEasingCurve curverr;
curve.setType(QEasingCurve::OutBounce);
animation->setEasingCurve(curve);
curve.setAmplitude(2.00);
animation->setLoopCount(2);
animation->start();
/******************************************Animation2Mahdi****************************************/

animation =new QPropertyAnimation(ui->label_223,"geometry");
animation->setDuration(10000);
animation->setStartValue(ui->label->geometry());
animation->setEndValue(QRect(200,65,400,90));

QEasingCurve cverr;
curve.setType(QEasingCurve::OutBounce);
animation->setEasingCurve(curve);
curve.setAmplitude(2.00);
animation->setLoopCount(2);
animation->start();
/******************************************Animation2Abderrahmen****************************************/

animation =new QPropertyAnimation(ui->label_224,"geometry");
animation->setDuration(10000);
animation->setStartValue(ui->label->geometry());
animation->setEndValue(QRect(200,65,400,90));

QEasingCurve cr;
curve.setType(QEasingCurve::OutBounce);
animation->setEasingCurve(curve);
curve.setAmplitude(2.00);
animation->setLoopCount(2);
animation->start();
// clock zeineb
QTimer *timer2=new QTimer(this);
connect(timer2 ,SIGNAL(timeout()),this,SLOT(showTime()));
timer->start();

QDateTime dateTime=QDateTime::currentDateTime();
QString datetimetext=dateTime.toString("dddd . dd . MMMM . yyyy");
ui->DateTime_->setText(datetimetext);
}
//Clock
void MainWindow::clockTimer()
{
    QTime time=QTime::currentTime();
  QString time_text =time.toString ("hh : mm :ss ");
  ui->Clocklabel->setText(time_text);
ui->clock2->setText(time_text);
ui->clock3->setText(time_text);
//clock zeineb
if ((time.second() % 2) == 0)
{
   time_text[3] = ' ';
   time_text[8] = ' ';




}
 ui->Digital_clock->setText(time_text);

}


//Mailing

void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
//Mailing Zeineb
void MainWindow::browse2()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file_2->setText( fileListString );

}

void MainWindow::sendMail2()
{
    Smtp* smtp = new Smtp(ui->uname_2->text(), ui->paswd_2->text(), ui->server_2->text(), ui->port_2->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText(), files );
    else
        smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*******************************************Ajouter Membre************************************************/
void MainWindow::on_pb_ajouter_clicked()
//click
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
   //
    int num = ui->lineEdit_4->text().toInt();
    int slr = ui->lineEdit_3->text().toInt();
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adr=ui->lineEdit->text();
    QString mail=ui->lineEdit_2->text();
    QString alt="@";
    QString pt=".";
    if (nom.isEmpty()||prenom.isEmpty()||adr.isEmpty() ){ui->label_31->setText("Ce Champ est obligatoire");
    ui->label_29->setText("Ce Champ est obligatoire");
    ui->label_30->setText("Ce Champ est obligatoire");}

    else if(mail.indexOf(alt)<1 || mail.indexOf(pt)<mail.indexOf(alt)+2)
 {ui->label_21->setText("Verifier le mail");}


    else {
  Membre m(id,slr,num,nom,prenom,adr,mail);
  bool test=m.ajouter();
  if(test)
{

      ui->tabmembre->setModel(tmpmembre.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un membre"),
                  QObject::tr("Membre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->label_31->setText("");
ui->label_30->setText("");
ui->label_29->setText("");
ui->label_21->setText("");

}

  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un membre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

}
/*******************************************Supprimer Membre************************************************/
void MainWindow::on_pb_supprimer_3_clicked()
//click
    { QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       //

int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpmembre.supprimer(id);
if(test)
{ui->tabmembre->setModel(tmpmembre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un membre"),
                QObject::tr("Membre supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un membre"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

/*******************************************Modifier Membre************************************************/
void MainWindow::on_pushButton_clicked()
{//click
     QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       //
       int num = ui->lineEdit_3->text().toInt();
       int slr = ui->lineEdit_4->text().toInt();
       int id = ui->lineEdit_id->text().toInt();
       QString nom= ui->lineEdit_nom->text();
       QString prenom= ui->lineEdit_prenom->text();
       QString adr=ui->lineEdit->text();
       QString mail=ui->lineEdit_2->text();
       QString alt="@";
       QString pt=".";
       if (nom.isEmpty()||prenom.isEmpty()||adr.isEmpty() ){ui->label_31->setText("Ce Champ est obligatoire");
       ui->label_29->setText("Ce Champ est obligatoire");
       ui->label_30->setText("Ce Champ est obligatoire");}

       else if(mail.indexOf(alt)<1 || mail.indexOf(pt)<mail.indexOf(alt)+2)
    {ui->label_21->setText("Verifier le mail");}
       else {
    Membre m;
    bool test=m.modifier(id,num,slr,nom,prenom,adr,mail);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie un membre"),
                          QObject::tr("membre modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->label_31->setText("");
        ui->label_30->setText("");
        ui->label_29->setText("");
        ui->label_21->setText("");
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tabmembre->setModel(tmpmembre.afficher());

}}
/*******************************************Ajouter Fonction************************************************/
void MainWindow::on_pushButton_5_clicked()
{//click
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       //
   int id = ui->comboBox->currentText().toInt();
    QString dep= ui->lineEdit_16->text();
    QString dir= ui->lineEdit_17->text();
    QString ser=ui->lineEdit_18->text();
    QString pos=ui->lineEdit_13->text();
    if (dep.isEmpty()||dir.isEmpty()||ser.isEmpty()|| pos.isEmpty() ){ui->label_53->setText("Ce Champ est obligatoire");
    ui->label_54->setText("Ce Champ est obligatoire");
    ui->label_55->setText("Ce Champ est obligatoire");
    ui->label_56->setText("Ce Champ est obligatoire");}
    else {
  fonction f (id,dep,dir,ser,pos);
  bool test=f.ajouter();
  if(test)
{

      ui->tableView->setModel(tmpfonction.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une fonction"),
                  QObject::tr("fonction ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->label_53->setText("");
    ui->label_54->setText("");
    ui->label_55->setText("");
    ui->label_56->setText("");

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une fonction"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}}
/*******************************************Supprimer Fonction************************************************/

void MainWindow::on_pushButton_4_clicked()
{//click
     QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       //
    {
    int id = ui->lineEdit_14->text().toInt();
    bool test=tmpfonction.supprimer(id);
    if(test)
    {ui->tableView->setModel(tmpfonction.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une fonction"),
                    QObject::tr("Fonction supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une fonction"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
}
/*******************************************Modifier Fonction************************************************/
void MainWindow::on_pushButton_8_clicked()
{//click
     QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       //
int id = ui->comboBox->currentText().toInt();
       QString dep= ui->lineEdit_16->text();
       QString dir= ui->lineEdit_17->text();
       QString ser=ui->lineEdit_13->text();
       QString pos=ui->lineEdit_18->text();
       if (dep.isEmpty()||dir.isEmpty()||ser.isEmpty()|| pos.isEmpty() ){ui->label_53->setText("Ce Champ est obligatoire");
       ui->label_54->setText("Ce Champ est obligatoire");
       ui->label_55->setText("Ce Champ est obligatoire");
       ui->label_56->setText("Ce Champ est obligatoire");}
       else {
    fonction f;
    bool test=f.modifier_f (id,dep,dir,pos,ser);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie une fonction"),
                          QObject::tr("fonctin modifiée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->label_54->setText("");
        ui->label_55->setText("");
        ui->label_56->setText("");
        ui->label_53->setText("");
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tmpfonction.afficher());

}}
/*******************************************Recherche et tri (Membre)************************************************/
void MainWindow::on_pushButton_9_clicked()
{//click
     QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       //
    QString rech =ui->lineEdit_5->text();

       ui->tabmembre->setModel(tmpmembre.rechercher(rech));
}


void MainWindow::on_comboBox_activated(int index)
{//click
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
ui->tabmembre->setModel(tmpmembre.tri());
}
/*******************************************Recherche et tri (Fonction)************************************************/

void MainWindow::on_pushButton_10_clicked()
{//click
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
    QString rech =ui->lineEdit_19->text();

       ui->tableView->setModel(tmpfonction.rechercher(rech));
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{//click
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
    ui->tableView->setModel(tmpfonction.tri());

}

//MUSIC
/*
void MainWindow::on_pushButton_20_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"ouvrir");
        if (filename.isEmpty()){return;}
        mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
      on_pushButton_18_clicked();
}

void MainWindow::on_pushButton_18_clicked()
{
    mMediaPlayer->play();
}

void MainWindow::on_pushButton_17_clicked()
{
    mMediaPlayer->pause();
}

void MainWindow::on_pushButton_16_clicked()
{
    mMediaPlayer->stop();
}

void MainWindow::on_avance_3_valueChanged(int value)
{
    ui->avance_3->setValue(value);

}

void MainWindow::on_pushButton_19_clicked()
{
    if(ui->pushButton_19->text()=="Muet"){
      mMediaPlayer->setMuted(true);
     ui->pushButton_19->setText("Unmuet");}
     else{ mMediaPlayer->setMuted(false);
         ui->pushButton_19->setText("Muet");}
}


*/
/******************************************* PDF (Membre)************************************************/

void MainWindow::on_pushButton_6_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tabmembre->model()->rowCount();
                     const int columnCount = ui->tabmembre->model()->columnCount();
                     QString TT = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#E7E7E7 link=#5000A1>\n"

                            "<h1 style=\"text-align: center;\"><strong> ********Liste Des Membres******** "+TT+"</strong></h1>"
                        //     "<align='right'> " << datefich << "</align>"
                         "<center></br><table border=3 cellspacing=1 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#FFF9F6> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tabmembre->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tabmembre->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tabmembre->isColumnHidden(column)) {
                                 QString data = ui->tabmembre->model()->data(ui->tabmembre->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"

                         "</body>\n"
                             "<img style=\"  grid-column: 5 / 6 grid-row: 2 / 3;\" src=\"C:/Users/User/Desktop/back.png\" alt=\"picture\" width=\"40\" height=\"30\">";

                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);

}
/*******************************************Imprimer (Membre)************************************************/

void MainWindow::on_pushButton_2_clicked()
{//click
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}
/*******************************************PDF (Fonction)************************************************/

void MainWindow::on_pushButton_3_clicked()
{//click
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView->model()->rowCount();
                     const int columnCount = ui->tableView->model()->columnCount();
 QString TT = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#E7E7E7 link=#5000A0>\n"
"<h1 style=\"text-align: center;\"><strong> ********Liste Des Fonctions******** "+TT+"</strong></h1>"
                        //     "<align='right'> " << datefich << "</align>"

                         "<center> </br></br><table border=3 cellspacing=1 cellpadding=2>\n";


                     // headers
                     out << "<thead><tr bgcolor=#FFF9F6> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView->isColumnHidden(column)) {
                                 QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n";
                         "</body>\n"
                     "<img style=\"  grid-column: 5 / 6 grid-row: 2 / 3;\" src=\"C:/Users/User/Desktop/back2.png\" alt=\"picture\" width=\"40\" height=\"30\">";

                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);

}
/*******************************************Imprimer (Fonction)************************************************/

void MainWindow::on_pushButton_7_clicked()
{//click
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}
/*******************************************NAV************************************************/

void MainWindow::on_pushButton_11_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_toolButton_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(2);
}
/*******************************************Modifier et Supreesion par selection(Membre)************************************************/

void MainWindow::on_tabmembre_activated(const QModelIndex &index)
{
    int selected_row=ui->tabmembre->currentIndex().row();


    QString selected_id=ui->tabmembre->model()->data(index.sibling(selected_row,0)).toString();

    ui->lineEdit_id->setText(selected_id);
    ui->lineEdit_id_2->setText(ui->tabmembre->model()->data(index.sibling(selected_row,0)).toString());

    ui->lineEdit_nom->setText(ui->tabmembre->model()->data(index.sibling(selected_row,1)).toString());
    ui->lineEdit_prenom->setText(ui->tabmembre->model()->data(index.sibling(selected_row,2)).toString());
    ui->lineEdit->setText(ui->tabmembre->model()->data(index.sibling(selected_row,3)).toString());
    ui->lineEdit_2->setText(ui->tabmembre->model()->data(index.sibling(selected_row,4)).toString());
    ui->lineEdit_4->setText(ui->tabmembre->model()->data(index.sibling(selected_row,5)).toString());
    ui->lineEdit_3->setText(ui->tabmembre->model()->data(index.sibling(selected_row,5)).toString());

}

/*******************************************Modifier et Supreesion par selection(Fonction)************************************************/

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    int selected_row=ui->tableView->currentIndex().row();


    QString selected_id=ui->tableView->model()->data(index.sibling(selected_row,0)).toString();
    ui->lineEdit_14->setText(ui->tableView->model()->data(index.sibling(selected_row,0)).toString());

    ui->comboBox->setCurrentText(selected_id);
    ui->lineEdit_16->setText(ui->tableView->model()->data(index.sibling(selected_row,1)).toString());

    ui->lineEdit_17->setText(ui->tableView->model()->data(index.sibling(selected_row,2)).toString());
    ui->lineEdit_13->setText(ui->tableView->model()->data(index.sibling(selected_row,3)).toString());
    ui->lineEdit_18->setText(ui->tableView->model()->data(index.sibling(selected_row,4)).toString());

}


/*********************************Stat************************************************/

void MainWindow::on_pushButton_16_clicked()
{
    int res;
                statistiques w(this);
                w.setWindowTitle("Statistiques Des Membres (Selon Salaires)");

                res = w.exec();
                qDebug() << res;
                if (res == QDialog::Rejected)
                  return;
}


void MainWindow::on_pushButton_18_clicked()
{


        video=new MainWindowvideo(this);
        video->show();

}
/*********************************Import Image************************************************/
void MainWindow::on_pushButton_19_clicked()
{
    int i=0;

         filename=QFileDialog::getOpenFileName(this,tr("choose"), "",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
        if (QString::compare(filename,QString()) !=0)
        {
            QImage image;
            bool valid=image.load(filename);
            if (valid)
            {
                image=image.scaledToWidth(ui->label_11->width(), Qt::SmoothTransformation);
                while (i<101) {
                ui->progressBar->setValue(i);
                QTimer timer;
                //        timer.setSingleShot(true);
                timer.setInterval(10);
                QEventLoop loop;
                connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                timer.start();
                loop.exec();
                i++;
            }
                ui->label_11->setPixmap(QPixmap::fromImage(image));
            }
            else
            {
                qDebug()<<"error";
            }
        }
        ui->progressBar->setValue(0);
}
//CALCULATOR
void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;

    double labelNumber;

    if((ui->pushButton_plus->isChecked()||ui->pushButton_minus->isChecked()||ui->pushButton_division->isChecked()||ui->pushButton_times->isChecked()) && (!userIsTypingSecondNum))
    {
        labelNumber = (button->text()).toDouble();
        userIsTypingSecondNum = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    //new label number
    else
    {
        if(ui->label_15->text().contains(".") && button->text() == "0")
        {
            newLabel = ui->label_15->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label_15->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }
    }

    //label of the ui
    ui->label_15->setText(newLabel);
}

void MainWindow::on_pushButton_point_released()
{
    ui->label_15->setText(ui->label_15->text()+("."));
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton *)sender();
    double labelNumber;
    QString newLabel;
    if(button->text() == "+/-")
    {
        labelNumber = ui->label_15->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_15->setText(newLabel);
    }
    if(button->text() == "%")
    {
        labelNumber = ui->label_15->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_15->setText(newLabel);
    }
}

void MainWindow::on_pushButton_C_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_times->setChecked(false);

    userIsTypingSecondNum = false;

    ui->label_15->setText("0");
}

void MainWindow::on_pushButton_equal_released()
{
    double labelNumber,secondNum;
    QString newLabel;

    secondNum = ui->label_15->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_15->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_15->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_division->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_15->setText(newLabel);
        ui->pushButton_division->setChecked(false);
    }
    else if(ui->pushButton_times->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_15->setText(newLabel);
        ui->pushButton_times->setChecked(false);
    }

    userIsTypingSecondNum = false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton *)sender();

    firstNum = ui->label_15->text().toDouble();
    button->setChecked(true);
}

void MainWindow::on_pushButton_ajouterartcile_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    int id = ui->lineEdit_ida->text().toInt();
    QString titre= ui->lineEdit_titre->text();
    QString type= ui->lineEdit_type->text();
    QString msg=ui->lineEdit_6->text();
    QString dt=ui->dateEdit->date().toString("yyyy/MM/dd");



    if ((titre.isEmpty()||type.isEmpty()||msg.isEmpty())) {ui->label_57->setText("Ce Champ est obligatoire");
            ui->label_58->setText("Ce Champ est obligatoire");
            ui->label_59->setText("Ce Champ est obligatoire");}

  else {
            article a (id,titre,type,msg,dt);
  bool test=a.ajouter();
  if(test)
{

      ui->tabarticle->setModel(tmparticle.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une article"),
                  QObject::tr("fonction ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->label_57->setText("");
            ui->label_58->setText("");
            ui->label_59->setText("");


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une article"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}}

void MainWindow::on_pushButton_modifierarticle_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
      int id = ui->lineEdit_ida->text().toInt();
      QString titre= ui->lineEdit_titre->text();
      QString type= ui->lineEdit_type->text();
      QString msg=ui->lineEdit_6->text();
      QString dt=ui->dateEdit->date().toString("yyyy/MM/dd");
      if ((titre.isEmpty()||type.isEmpty()||msg.isEmpty())) {ui->label_57->setText("Ce Champ est obligatoire");
              ui->label_58->setText("Ce Champ est obligatoire");
              ui->label_59->setText("Ce Champ est obligatoire");}
    else {

   article a;
   bool test=a.modifier_a (id,titre,type,msg,dt);

   if(test)
   {
       QMessageBox::information(nullptr, QObject::tr("modifie un article"),
                         QObject::tr("fonctin modifiée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
       ui->label_57->setText("");
                   ui->label_58->setText("");
                   ui->label_59->setText("");
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tabarticle->setModel(tmparticle.afficher());
}}

void MainWindow::on_pushButton_supparticle_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
   {
   int id = ui->lineEdit_supparticle->text().toInt();
   bool test=tmparticle.supprimer(id);
   if(test)
   {ui->tabarticle->setModel(tmparticle.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Supprimer un article"),
                   QObject::tr("article supprimée.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un article"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


   }
}

void MainWindow::on_tabarticle_activated(const QModelIndex &index)
{
    int selected_row=ui->tabarticle->currentIndex().row();


    QString selected_id=ui->tabarticle->model()->data(index.sibling(selected_row,0)).toString();

    ui->lineEdit_ida->setText(selected_id);
    ui->lineEdit_supparticle->setText(ui->tabarticle->model()->data(index.sibling(selected_row,0)).toString());

    ui->lineEdit_titre->setText(ui->tabarticle->model()->data(index.sibling(selected_row,1)).toString());
    ui->lineEdit_type->setText(ui->tabarticle->model()->data(index.sibling(selected_row,3)).toString());
    ui->dateEdit->setDate(ui->tabarticle->model()->data(index.sibling(selected_row,2)).toDate());
    ui->lineEdit_6->setText(ui->tabarticle->model()->data(index.sibling(selected_row,4)).toString());

}

void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
    ui->tabarticle->setModel(tmparticle.tri());

}



void MainWindow::on_pushButton_rechercharticle_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
    QString rech =ui->lineEdit_recherchearticle->text();

       ui->tabarticle->setModel(tmparticle.rechercher(rech));
}

/*********************************NOTEPAD************************************************/
void MainWindow::on_pushButton_20_clicked()
{
    notepad=new note(this);
    notepad->show();
}
//web
void MainWindow::on_pushButton_25_clicked()
{
    QString link="http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));
}
/*********************************ARDUINO************************************************/
void MainWindow::on_pushButton_17_clicked()
{Arduino1 =new ardyuno2(this);
    Arduino1->show();
   /* int x=0;
      ui->stackedWidget->setCurrentIndex(3);
      QString read=ard.read_from_arduino();
      int ln=read.length();
      QString id=read.right(ln-1);
      id=id.left(ln-3);
    QSqlQuery query;
          query.prepare("select presence from arduino where id='"+id+"'");

          query.exec();
          query.first();
          int presence=query.value(0).toInt();
          if(presence==0){presence=1;ui->lcdNumber->display(x++);}
          else{presence=0;ui->lcdNumber->display(x--);}

          QString xpresence=QString::number(presence);


          query.prepare("update arduino set presence='"+xpresence+"'where id='"+id+"'");
          query.exec();

          QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("select nom,prenom from arduino where presence=0");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prénom"));
              ui ->tableView_2->setModel(model);*/
}

/********************************YASSSSSINEEEEEEEEEEEEEEEEE*****************************/


void MainWindow::on_pb_ajout_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }

    QString titre= ui->lineEdit_titre_2->text();//recuperer la valeur saisie par l'utilisateur, ui est un pointeur (vers l'interface)
    QString type= ui->lineEdit_type_2->text();
    QString lieu= ui->lineEdit_lieu->text();
    QString datedebut= ui->lineEdit_datedebut->text();
    QString datefin= ui->lineEdit_datefin->text();


  evenement e(titre,type,lieu,datedebut,datefin);
  if(verifTitrey()&&verifTypey()&&verifLieuy()&&verifDatedebuty()&&verifDatefiny()){

  bool test=e.ajouter();
  if(test)
{

      ui->tabevenement->setModel(tmpevenement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un événement"),
                  QObject::tr("Evenement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un événement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pb_modifier_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        QString titre= ui->lineEdit_titre_2->text();
        QString type= ui->lineEdit_type_2->text();
        QString lieu= ui->lineEdit_lieu->text();
        QString datedebut= ui->lineEdit_datedebut->text();
        QString datefin= ui->lineEdit_datefin->text();
        evenement e(titre,type,lieu,datedebut,datefin);
        if(verifTitrey()&&verifTypey()&&verifLieuy()&&verifDatedebuty()&&verifDatefiny()){

        if(e.modifier(titre))
        {
              ui->tabevenement->setModel(tmpevenement.afficher());
                  QMessageBox::information(nullptr, QObject::tr("Modifier un événement"),
                              QObject::tr("événement modifié.\n"), QMessageBox::Cancel);

        }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un événement"),
                              QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
        }
}

void MainWindow::on_pb_supprimer_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));

      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
 QString titre= ui->lineEdit_titres->text();
bool test=tmpevenement.supprimer(titre);
if(test)
{ui->tabevenement->setModel(tmpevenement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un événement"),
                QObject::tr("Evénement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un événement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_rechercher_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QString rech =ui->lineEditrech->text();
   ui->tabevenement->setModel(tmpevenement.rechercher(rech));
}

void MainWindow::on_pb_tri_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));

       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
         ui->tabevenement->setModel(tmpevenement.tri());
}

void MainWindow::on_pb_ajouter_3_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString mail= ui->lineEdit_mail->text();
    int CIN= ui->lineEdit_CIN->text().toInt();
    int numtel= ui->lineEdit_numtel->text().toInt();
    QString datenaissance= ui->lineEdit_datenaissance->text();
    QString typeeve= ui->comboBox_6->currentText();


  participant p(nom,prenom,mail,CIN,numtel,datenaissance,typeeve);
  if(verifNomy1()&&verifPrenomy1()&&verifMaily1()&&verifCiny1()&&verifNumtely1()&&verifDatenaissancey1()){

  bool test=p.ajouter();
  if(test)
{

      ui->tabparticipant->setModel(tmpparticipant.afficher());//refresh
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->setIcon(QIcon("icone.png"));

              notifyIcon->showMessage("GESTION PARTICIPANT AJOUTE ","participant ajouté",QSystemTrayIcon::Information,15000);

          QMessageBox::information(nullptr, QObject::tr("ajouter participant"),
                                QObject::tr("participant ajouté./n"
                                   "click cancel to exit."),QMessageBox::Cancel);
          }
  }

          else
              QMessageBox::critical(nullptr, QObject::tr("ajouter participant"),
                                    QObject::tr("Erreur !./n"
                                       "click cancel to exit."),QMessageBox::Cancel);



}

void MainWindow::on_pb_modifier_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        QString nom= ui->lineEdit_nom_2->text();
        QString prenom= ui->lineEdit_prenom_2->text();
        QString mail= ui->lineEdit_mail->text();
        int CIN= ui->lineEdit_CIN->text().toInt();
        int numtel= ui->lineEdit_numtel->text().toInt();
        QString datenaissance= ui->lineEdit_datenaissance->text();
        QString typeeve= ui->comboBox_6->currentText();

        participant p;
        if(verifNomy1()&&verifPrenomy1()&&verifMaily1()&&verifCiny1()&&verifNumtely1()&&verifDatenaissancey1()){

        bool test=p.modifier(nom,prenom,mail,CIN,numtel,datenaissance,typeeve);
        if (test)
        {
              ui->tabparticipant->setModel(tmpparticipant.afficher());
                  QMessageBox::information(nullptr, QObject::tr("Modifier un participant"),
                              QObject::tr("participant modifié.\n"), QMessageBox::Cancel);

        }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un participant"),
                              QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
        }

}

void MainWindow::on_pb_supprimer2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));

       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        QString nom= ui->lineEdit_noms->text();
       bool test=tmpparticipant.supprimer(nom);
       if(test)
       {ui->tabparticipant->setModel(tmpparticipant.afficher());//refresh
           QMessageBox::information(nullptr, QObject::tr("Supprimer un participant"),
                       QObject::tr("participant supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un participant"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

    }


void MainWindow::on_pb_rechercher_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));

       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        QString rech =ui->lineEditrech_2->text();
       ui->tabparticipant->setModel(tmpparticipant.rechercher(rech));
}

void MainWindow::on_pb_tri_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
         ui->tabparticipant->setModel(tmpparticipant.tri());
}

void MainWindow::on_pb_ajouter_4_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    int id= ui->lineEdit_id_3->text().toInt();
    QString titre= ui->lineEdit_titr->text();
    QString form= ui->lineEdit_form->text();
    QString description= ui->lineEdit_descr->text();
    QString dte= ui->lineEdit_date->text();


  publicite p(id,titre,form,description,dte);
  if(verifIdy2()&&verifTitrey2()&&verifFormy2()&&verifDescriptiony2()&&verifDtey2()){

  bool test=p.ajouter();
  if(test)
{

      ui->tabpublicite->setModel(tmppub.afficher());//refresh
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->setIcon(QIcon("icone.png"));

              notifyIcon->showMessage("GESTION PUBLICITE AJOUTE ","publicite ajouté",QSystemTrayIcon::Information,15000);

          QMessageBox::information(nullptr, QObject::tr("ajouter publicite"),
                                QObject::tr("publicite ajouté./n"
                                   "click cancel to exit."),QMessageBox::Cancel);
          }
  }

          else
              QMessageBox::critical(nullptr, QObject::tr("ajouter publicite"),
                                    QObject::tr("Erreur !./n"
                                       "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_3_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));

       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       int id= ui->lineEdit_id_3->text().toInt();
       QString titre= ui->lineEdit_titr->text();
       QString form= ui->lineEdit_form->text();
       QString description= ui->lineEdit_descr->text();
       QString dte= ui->lineEdit_date->text();


        publicite p;
        if(verifIdy2()&&verifTitrey2()&&verifFormy2()&&verifDescriptiony2()&&verifDtey2()){

        bool test=p.modifier(id,titre,form,description,dte);
        if (test)
        {
              ui->tabpublicite->setModel(tmppub.afficher());
                  QMessageBox::information(nullptr, QObject::tr("Modifier une publicite"),
                              QObject::tr("publicite modifiée.\n"), QMessageBox::Cancel);

        }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier une publicite"),
                              QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
        }
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        int id= ui->lineEdit_ids->text().toInt();
       bool test=tmppub.supprimer(id);
       if(test)
       {ui->tabpublicite->setModel(tmppub.afficher());//refresh
           QMessageBox::information(nullptr, QObject::tr("Supprimer une publicite"),
                       QObject::tr("publicite supprimée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer une publicite"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_rechercher_4_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
       QString rech =ui->lineEditrech_4->text();
      ui->tabpublicite->setModel(tmppub.rechercher(rech));
}

void MainWindow::on_pb_tri_3_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
         ui->tabpublicite->setModel(tmppub.tri());
}

void MainWindow::on_tabevenement_activated(const QModelIndex &index)
{
    int selected_row=ui->tabevenement->currentIndex().row();//la propriete actuelle


        QString selected_titre=ui->tabevenement->model()->data(index.sibling(selected_row,0)).toString();
        ui->lineEdit_titres->setText(ui->tabevenement->model()->data(index.sibling(selected_row,0)).toString());// contient les textes et l'etiqutte

        ui->lineEdit_titre_2->setText(selected_titre);
        ui->lineEdit_type_2->setText(ui->tabevenement->model()->data(index.sibling(selected_row,1)).toString());

        ui->lineEdit_lieu->setText(ui->tabevenement->model()->data(index.sibling(selected_row,2)).toString());
        ui->lineEdit_datedebut->setText(ui->tabevenement->model()->data(index.sibling(selected_row,3)).toString());

        ui->lineEdit_datefin->setText(ui->tabevenement->model()->data(index.sibling(selected_row,4)).toString());
}

void MainWindow::on_tabparticipant_activated(const QModelIndex &index)
{
    int selected_row=ui->tabparticipant->currentIndex().row();


        QString selected_nom=ui->tabparticipant->model()->data(index.sibling(selected_row,0)).toString();
        ui->lineEdit_noms->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,0)).toString());

        ui->lineEdit_nom_2->setText(selected_nom);
        ui->lineEdit_prenom_2->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,1)).toString());

        ui->lineEdit_mail->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,2)).toString());
        ui->lineEdit_CIN->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,3)).toString());

        ui->lineEdit_numtel->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,4)).toString());
        ui->lineEdit_datenaissance->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,3)).toString());

        ui->lineEdit_typeeve->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,4)).toString());

}

void MainWindow::on_tabpublicite_activated(const QModelIndex &index)
{
    int selected_row=ui->tabpublicite->currentIndex().row();


        QString selected_id=ui->tabpublicite->model()->data(index.sibling(selected_row,0)).toString();
        ui->lineEdit_ids->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,0)).toString());

        ui->lineEdit_id_3->setText(selected_id);
        ui->lineEdit_titr->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,1)).toString());

        ui->lineEdit_form->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,2)).toString());
        ui->lineEdit_descr->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,3)).toString());

        ui->lineEdit_date->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,4)).toString());
}

void MainWindow::on_pb_imprimer_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));

       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void MainWindow::on_pb_imprimer_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));

       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void MainWindow::on_pb_pdf_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        QString strStream;
                         QTextStream out(&strStream);//interface pratique pour lire et ecrire

                         const int rowCount = ui->tabevenement->model()->rowCount();
                         const int columnCount = ui->tabevenement->model()->columnCount();
                          QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                         out <<  "<html>\n"
                             "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("strTitle")
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            "<h1 style=\"text-align: center;\"><strong> ********Liste Des événements******** "+TT+"</strong></h1>"

                            //     "<align='right'> " << datefich << "</align>"
                             "<center> <H1>Liste des evenements </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                         // headers
                         out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tabevenement->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tabevenement->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tabevenement->isColumnHidden(column)) {
                                     QString data = ui->tabevenement->model()->data(ui->tabevenement->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table> </center>\n"
                             "</body>\n"
    "<img style=\"  grid-column: 5 / 6 grid-row: 2 / 3;\" src=\"C:/Users/BEST TECHNOLOGIES/Downloads/back1.png\" alt=\"picture\" width=\"40\" height=\"30\">";
                             "</html>\n";

                   QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                    QPrinter printer (QPrinter::PrinterResolution);
                     printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName(fileName);

                    QTextDocument doc;
                     doc.setHtml(strStream);
                     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                     doc.print(&printer);
}

void MainWindow::on_pb_pdf_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        QString strStream;
                         QTextStream out(&strStream);//interface pratique pour lire et ecrire

                         const int rowCount = ui->tabpublicite->model()->rowCount();
                         const int columnCount = ui->tabpublicite->model()->columnCount();
                          QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                         out <<  "<html>\n"
                             "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("strTitle")
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            "<h1 style=\"text-align: center;\"><strong> ********Liste Des Publicités******** "+TT+"</strong></h1>"

                            //     "<align='right'> " << datefich << "</align>"
                             "<center> <H1>Liste des evenements </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                         // headers
                         out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tabpublicite->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tabpublicite->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tabpublicite->isColumnHidden(column)) {
                                     QString data = ui->tabpublicite->model()->data(ui->tabpublicite->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table> </center>\n"
                             "</body>\n"
    "<img style=\"  grid-column: 5 / 6 grid-row: 2 / 3;\" src=\"C:/Users/BEST TECHNOLOGIES/Downloads/back1.png\" alt=\"picture\" width=\"40\" height=\"30\">";
                             "</html>\n";

                   QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                    QPrinter printer (QPrinter::PrinterResolution);
                     printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName(fileName);

                    QTextDocument doc;
                     doc.setHtml(strStream);
                     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                     doc.print(&printer);
}

void MainWindow::on_pushButton_40_clicked()
{
    QTableView *table;
                   table = ui->tabpublicite;
                   QString filters("CSV files (*.csv);;All files (*.*)");
                   QString defaultFilter("CSV files (*.csv)");
                   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                      filters, &defaultFilter);
                   QFile file(fileName);
                   QAbstractItemModel *model =  table->model();
                   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                       QTextStream data(&file);
                       QStringList strList;
                       for (int i = 0; i < model->columnCount(); i++) {
                           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") << "\n";
                       for (int i = 0; i < model->rowCount(); i++) {
                           strList.clear();
                           for (int j = 0; j < model->columnCount(); j++) {
                               if (model->data(model->index(i, j)).toString().length() > 0)
                                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") + "\n";
                       }
                       file.close();
                       //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");


                   }
}


void MainWindow::on_pushButton_41_clicked()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);

       QUrl url("https://AC2de718dd6614da25d92acb2e9b506766:77c281aae1e10141fa98f618768a2c40@api.twilio.com/2010-04-01/Accounts/AC2de718dd6614da25d92acb2e9b506766/Messages.json");
      // QUrl url("https://AC448119ef82f78297b322e43d379ddee6:20900042d763e02de9871ef3308afa34@api.twilio.com/2010-04-01/Accounts/AC448119ef82f78297b322e43d379ddee6/Messages.json");

       QNetworkRequest request(url);

       request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");


       QUrlQuery params;
       params.addQueryItem("From", "+18053879768");
      // params.addQueryItem("From", "+12093088508");

       params.addQueryItem("To",ui->lineEdit_7->text() );//"+21690101450"
       params.addQueryItem("Body", ui->textEdit->toPlainText());
      // params.addQueryItem("Body", "test");

       // etc

       connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply*)));

       manager->post(request, params.query().toUtf8());

   }
   void MainWindow::replyFinished(QNetworkReply* reply)
   {
       //QByteArray bts = rep->readAll();


       QByteArray buffer = reply->readAll();
       qDebug() << buffer;
       QJsonDocument jsonDoc(QJsonDocument::fromJson(buffer));
       QJsonObject jsonReply = jsonDoc.object();

       QJsonObject response = jsonReply["response"].toObject();
       QJsonArray  data     = jsonReply["data"].toArray();
       qDebug() << data;
       qDebug() << response;
}
   bool MainWindow::verifTitrey()
   {
       if (ui->lineEdit_titre_2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_titre_2->text().isEmpty())
       {
           ui->lineEdit_titre_2->clear();

           ui->lineEdit_titre_2->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }

   }
   bool MainWindow::verifTypey()
   {
       if (ui->lineEdit_type_2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_type_2->text().isEmpty())
       {
           ui->lineEdit_type_2->clear();
           ui->lineEdit_type_2->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }

   }

   bool MainWindow::verifLieuy()
   {
       if (ui->lineEdit_lieu->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_lieu->text().isEmpty())
       {
           ui->lineEdit_lieu->clear();
           ui->lineEdit_lieu->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
   bool MainWindow::verifDatedebuty()
   {
       if (ui->lineEdit_datedebut->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_datedebut->text().isEmpty())
       {
           ui->lineEdit_datedebut->clear();
           ui->lineEdit_datedebut->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
   bool MainWindow::verifDatefiny()
   {
       if (ui->lineEdit_datefin->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_datefin->text().isEmpty())
       {
           ui->lineEdit_datefin->clear();
           ui->lineEdit_datefin->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }

   bool MainWindow::verifNomy1()
   {
       if (ui->lineEdit_nom_2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_nom_2->text().isEmpty())
       {
           ui->lineEdit_nom_2->clear();

           ui->lineEdit_nom_2->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }

   }
   bool MainWindow::verifPrenomy1()
   {
       if (ui->lineEdit_prenom_2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_prenom_2->text().isEmpty())
       {
           ui->lineEdit_prenom_2->clear();
           ui->lineEdit_prenom_2->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }

   }

   bool MainWindow::verifMaily1()
   {
       if (ui->lineEdit_mail->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_mail->text().isEmpty())
       {
           ui->lineEdit_mail->clear();
           ui->lineEdit_mail->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
   bool MainWindow::verifCiny1()
   {
       if (ui->lineEdit_CIN->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_CIN->text().isEmpty())
       {
           ui->lineEdit_CIN->clear();
           ui->lineEdit_CIN->setPlaceholderText("contient que des chiffres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
   bool MainWindow::verifNumtely1()
   {
       if (ui->lineEdit_numtel->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_numtel->text().isEmpty())
       {
           ui->lineEdit_numtel->clear();
           ui->lineEdit_numtel->setPlaceholderText("contient que des chiffres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
   bool MainWindow::verifDatenaissancey1()
   {
       if (ui->lineEdit_datenaissance->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_datenaissance->text().isEmpty())
       {
           ui->lineEdit_datenaissance->clear();
           ui->lineEdit_datenaissance->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
   /*bool MainWindow::verifTypeeve1()
   {
       if (ui->lineEdit_typeeve->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_typeeve->text().isEmpty())
       {
           ui->lineEdit_typeeve->clear();
           ui->lineEdit_typeeve->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }*/
   bool MainWindow::verifIdy2()
   {
       if (ui->lineEdit_id_3->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_id_3->text().isEmpty())
       {
           ui->lineEdit_id_3->clear();

           ui->lineEdit_id_3->setPlaceholderText("contient que des chiffres") ;
           return false;
       }
       else
       {
           return true;
       }

   }
   bool MainWindow::verifTitrey2()
   {
       if (ui->lineEdit_titr->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_titr->text().isEmpty())
       {
           ui->lineEdit_titr->clear();
           ui->lineEdit_titr->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }

   }

   bool MainWindow::verifFormy2()
   {
       if (ui->lineEdit_form->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_form->text().isEmpty())
       {
           ui->lineEdit_form->clear();
           ui->lineEdit_form->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
   bool MainWindow::verifDescriptiony2()
   {
       if (ui->lineEdit_descr->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_descr->text().isEmpty())
       {
           ui->lineEdit_descr->clear();
           ui->lineEdit_descr->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
   bool MainWindow::verifDtey2()
   {
       if (ui->lineEdit_date->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_date->text().isEmpty())
       {
           ui->lineEdit_date->clear();
           ui->lineEdit_date->setPlaceholderText("contient que des caracteres") ;
           return false;
       }
       else
       {
           return true;
       }
   }
//stat
   void MainWindow::afficherStatistique(){


       QSqlQuery query;


           //nombre de dons
                   QString nb_pub="";
                   query.prepare("SELECT COUNT(*) FROM publicite");
                   query.exec();
                   while(query.next()){
                   nb_pub= query.value(0).toString();}

            //nombre de famille

                   QString nb_eve="";
                   query.prepare("SELECT COUNT(*) FROM evenement");
                   query.exec();
                   while(query.next()){
                   nb_eve= query.value(0).toString();}



               QBarSet *set0 = new QBarSet("Jane");


                  *set0 << nb_pub.toInt()  << nb_eve.toInt()   ;
               QBarSeries *series = new QBarSeries();
                series->append(set0);
                QChart *chart = new QChart();
                    chart->addSeries(series);
                    chart->setTitle("statistique ");
                    chart->setAnimationOptions(QChart::SeriesAnimations);

                    QStringList categories;
                       categories << "nombre pub" <<  "nombre eve" ;
                       QBarCategoryAxis *axisX = new QBarCategoryAxis();
                       axisX->append(categories);
                       chart->addAxis(axisX, Qt::AlignBottom);
                       series->attachAxis(axisX);



                       chart->legend()->setVisible(true);
                           chart->legend()->setAlignment(Qt::AlignBottom);

                           QChartView *chartView = new QChartView(chart);
                           chartView->setRenderHint(QPainter::Antialiasing);
                           chartView->setParent(ui->horizontalFrame);


   }
   void MainWindow::on_lineEdit_8_textChanged(const QString &arg1)
   {
       ui->tabevenement->setModel(tmpevenement.rechercheDynamic(arg1));

   }

   void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
   {
       ui->tabparticipant->setModel(tmpparticipant.rechercheDynamic(arg1));

   }

   void MainWindow::on_lineEdit_48_textChanged(const QString &arg1)
   {
       ui->tabpublicite->setModel(tmppub.rechercheDynamic(arg1));

   }








// Image Zeineb
void MainWindow::on_pushButton_60_clicked()
{
    //to open the picture file

    QString fileName = QFileDialog::getOpenFileName(this,
              tr("Choose"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    //to select and show the pic
    if (QString::compare(fileName, QString()) !=0)
    {
        QImage image;
        bool valid = image.load(fileName);
        if (valid)
        {

          image = image.scaledToHeight(ui->label_pic->height(), Qt::SmoothTransformation);
          image = image.scaledToWidth(ui->label_pic->width(), Qt::SmoothTransformation);



          ui->label_pic->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //error
        }

    }

}
// Web Zeineb
void MainWindow::on_pushButton_59_clicked()
{
    QString link="http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));
}
// Ajout Materiel
void MainWindow::on_pb_ajouter_2_clicked()
{
    QString nom= ui->nom->text();
    QString type= ui->typ->text();
    int cout= ui->cout->text().toInt();
    int duree= ui->duree->text().toInt();
    int volume= ui->vlm->text().toInt();
    int poids= ui->poids->text().toInt();
    int nbr= ui->nbr->text().toInt();

    //controle de saisie
       if ((nom.isEmpty()||type.isEmpty())) {
           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Ces Chams sont obligatoires !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
       else{






  Materiel m(nom,type,cout,duree,volume,poids,nbr);
  bool test=m.ajouter();
  if(test)
{

      ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                  QObject::tr("materiel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void MainWindow::on_pb_modifier_5_clicked()
{
    QString nom= ui->nom->text();
    QString type= ui->typ->text();
    int cout= ui->cout->text().toInt();
    int duree= ui->duree->text().toInt();
    int volume= ui->vlm->text().toInt();
    int poids= ui->poids->text().toInt();
    int nbr= ui->nbr->text().toInt();

    //controle de saisie
       if ((nom.isEmpty()||type.isEmpty())) {
           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Ces Chams sont obligatoires !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
       else{






  Materiel m(nom,type,cout,duree,volume,poids,nbr);
  bool test=m.ajouter();
  if(test)
{

      ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                  QObject::tr("materiel modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void MainWindow::on_pb_supprimer_4_clicked()
{
    QString nom= ui->nomsup->text();
   bool test=tmpmateriel.supprimer(nom);
   if(test)
   {ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                   QObject::tr("materiel supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else{
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


   }
}

// TRI RECHERCHE ZEINEB
void MainWindow::on_pb_rechercher_5_clicked()
{
    QString rech =ui->rachma->text();
   ui->tabmateriel->setModel(tmpmateriel.rechercher(rech));
}

void MainWindow::on_pb_tri_5_clicked()
{
     ui->tabmateriel->setModel(tmpmateriel.tri());
}

void MainWindow::on_pushButton_57_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->tabmateriel->model()->rowCount();
                         const int columnCount = ui->tabmateriel->model()->columnCount();
                         QString TT = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
                         out <<  "<html>\n"
                             "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("strTitle")
                             <<  "</head>\n"
                             "<body bgcolor=#E7E7E7 link=#5000A1>\n"

                                "<h1 style=\"text-align: center;\"><strong> ********Liste Des Materiels******** "+TT+"</strong></h1>"
                            //     "<align='right'> " << datefich << "</align>"
                             "<center></br><table border=3 cellspacing=1 cellpadding=2>\n";

                         // headers
                         out << "<thead><tr bgcolor=#FFF9F6> <th>Numero</th>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tabmateriel->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tabmateriel->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tabmateriel->isColumnHidden(column)) {
                                     QString data = ui->tabmateriel->model()->data(ui->tabmateriel->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table> </center>\n"

                             "</body>\n"
                                 "<img style=\"  grid-column: 5 / 6 grid-row: 2 / 3;\" src=\"C:/Users/User/Desktop/back.png\" alt=\"picture\" width=\"40\" height=\"30\">";

                             "</html>\n";

                   QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                    QPrinter printer (QPrinter::PrinterResolution);
                     printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName(fileName);

                    QTextDocument doc;
                     doc.setHtml(strStream);
                     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                     doc.print(&printer);
}


void MainWindow::on_pushButton_46_clicked()
{
    int id = ui->le_id->text().toInt();
        int num = ui->num->text().toInt();

        QString nom= ui->le_nom->text();
        QString prenom= ui->prenom->text();
        QString mail= ui->mail->text();
        QString niveau= ui->nv->text();
        QString controle= ui->ctrl->text();
        QString alt="@";
            QString pt=".";


        //controle de saisie
        if ((nom.isEmpty()||prenom.isEmpty()||niveau.isEmpty()||controle.isEmpty())) {
            QMessageBox::information(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ces Champs sont obligatoires.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
                   }
        else if(mail.indexOf(alt)<1 || mail.indexOf(pt)<mail.indexOf(alt)+2)
         { QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                    QObject::tr("Vérifier Votre Mail.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                 }
        else{

      Fournisseur f( id, nom, prenom , mail, num, niveau , controle);
      bool test=f.ajouter();
      if(test)
    {

          ui->tabfournisseurs->setModel(tmpfournisseur.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);




    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void MainWindow::on_pb_modifier_4_clicked()
{
    int id = ui->le_id->text().toInt();
        int num = ui->num->text().toInt();

        QString nom= ui->le_nom->text();
        QString prenom= ui->prenom->text();
        QString mail= ui->mail->text();
        QString niveau= ui->nv->text();
        QString controle= ui->ctrl->text();
        QString alt="@";
            QString pt=".";

        //controle de saisie
        if ((nom.isEmpty()||prenom.isEmpty()||niveau.isEmpty()||controle.isEmpty())) {
            QMessageBox::information(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Ces Champs sont obligatoires.\n"), QMessageBox::Cancel);
        }
        else if(mail.indexOf(alt)<1 || mail.indexOf(pt)<mail.indexOf(alt)+2)
         {QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                   QObject::tr("Verifier le mail.\n"), QMessageBox::Cancel);}
        else{
  Fournisseur f;
  bool test=f.modifier( id, nom, prenom , mail, num, niveau , controle);
    if(test)
    {
          ui->tabfournisseurs->setModel(tmpfournisseur.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("fournisseur modifié.\n"), QMessageBox::Cancel);


    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }

}
}


void MainWindow::on_pb_supprimer2_2_clicked()
{
    int idd= ui->ids->text().toInt();
   bool test=tmpfournisseur.supprimer(idd);
   if(test)
   {ui->tabfournisseurs->setModel(tmpfournisseur.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                   QObject::tr("fournisseur supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_rechercher_3_clicked()
{
    QString rech =ui->idre->text();
   ui->tabfournisseurs->setModel(tmpfournisseur.rechercher(rech));
}

void MainWindow::on_pb_tri_4_clicked()
{
    ui->tabfournisseurs->setModel(tmpfournisseur.tri());

}

void MainWindow::on_pushButton_50_clicked()
{
    QTableView *table;
                       table = ui->tabfournisseurs;
                       QString filters("CSV files (*.csv);;All files (*.*)");
                       QString defaultFilter("CSV files (*.csv)");
                       QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                          filters, &defaultFilter);
                       QFile file(fileName);
                       QAbstractItemModel *model =  table->model();
                       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                           QTextStream data(&file);
                           QStringList strList;
                           for (int i = 0; i < model->columnCount(); i++) {
                               if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                   strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") << "\n";
                           for (int i = 0; i < model->rowCount(); i++) {
                               strList.clear();
                               for (int j = 0; j < model->columnCount(); j++) {
                                   if (model->data(model->index(i, j)).toString().length() > 0)
                                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") + "\n";
                           }
                           file.close();
                           //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");


                       }
}
//login
void MainWindow::on_pushButton_51_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Desktop/sound/bonjour_f_01 (1).mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    ui->stackedWidget->setCurrentIndex(21);
        QString utilisateur=ui->lineEdit_10->text();
        QString mdp=ui->lineEdit_11->text();
        MainWindow w;
        if ((utilisateur=="projetqt")&&(mdp=="smartclub"))
        {

            //w.show();

        }
        else{ QMessageBox::critical(nullptr, QObject::tr("Problème de connexion"),
                                              QObject::tr("Veuillez revérifier vos informations"), QMessageBox::Cancel);

                hide();
            }
}

void MainWindow::on_pushButton_61_clicked()
{
    QString filename="C:/Program Files (x86)/Windows Media Player/wmplayer.exe";
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
}

void MainWindow::on_tabmateriel_activated(const QModelIndex &index)
{   int selected_row=ui->tabmateriel->currentIndex().row();


    QString selected_id=ui->tabmateriel->model()->data(index.sibling(selected_row,0)).toString();

    ui->nom->setText(selected_id);
    ui->nomsup->setText(ui->tabmateriel->model()->data(index.sibling(selected_row,0)).toString());

    ui->typ->setText(ui->tabmateriel->model()->data(index.sibling(selected_row,1)).toString());
    ui->cout->setText(ui->tabmateriel->model()->data(index.sibling(selected_row,2)).toString());
    ui->duree->setText(ui->tabmateriel->model()->data(index.sibling(selected_row,3)).toString());
    ui->vlm->setText(ui->tabmateriel->model()->data(index.sibling(selected_row,4)).toString());
    ui->poids->setText(ui->tabmateriel->model()->data(index.sibling(selected_row,5)).toString());
    ui->nbr->setText(ui->tabmateriel->model()->data(index.sibling(selected_row,5)).toString());
}

void MainWindow::on_tabfournisseurs_activated(const QModelIndex &index)
{
    int selected_row=ui->tabfournisseurs->currentIndex().row();


    QString selected_id=ui->tabfournisseurs->model()->data(index.sibling(selected_row,0)).toString();

    ui->le_id->setText(selected_id);
    ui->ids->setText(ui->tabfournisseurs->model()->data(index.sibling(selected_row,0)).toString());

    ui->le_nom->setText(ui->tabfournisseurs->model()->data(index.sibling(selected_row,1)).toString());
    ui->prenom->setText(ui->tabfournisseurs->model()->data(index.sibling(selected_row,2)).toString());
    ui->mail->setText(ui->tabfournisseurs->model()->data(index.sibling(selected_row,3)).toString());
    ui->num->setText(ui->tabfournisseurs->model()->data(index.sibling(selected_row,4)).toString());
    ui->nv->setText(ui->tabfournisseurs->model()->data(index.sibling(selected_row,5)).toString());
    ui->ctrl->setText(ui->tabfournisseurs->model()->data(index.sibling(selected_row,5)).toString());
}

void MainWindow::on_pushButton_52_clicked()
{
    QString link="file:C:/Program Files (x86)/Adobe Photoshop CS6/Photoshop.exe" ;
               QDesktopServices ::openUrl(QUrl(link));
}
/*******************************crud aboud *****************************/
void MainWindow::on_pushButton_65_clicked()
{
    int id = ui->lineEdit_28->text().toInt();
    QString nom= ui->lineEdit_29->text();
    QString prenom= ui->lineEdit_30->text();
    QString adressem= ui->lineEdit_31->text();
    int num = ui->lineEdit_32->text().toInt();



  Partenaire e(id,nom,prenom,adressem,num);
  if(verifID2()&&verifNOM2()&&verifPRENOM()&&verifadressem()&&verifnum()){
  bool test=e.ajouter();
  if(test)
{
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->setIcon(QIcon("icone.png"));

              notifyIcon->showMessage("GESTION PARTENAIRE ","partenaire Ajouté",QSystemTrayIcon::Information,15000);

      ui->tabpartenaire->setModel(tmppartenaire.afficher());//refresh
      QMediaPlayer * erreur = new QMediaPlayer ;
     erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/partajout.mp3")) ;
         erreur->setVolume(100) ;
         erreur->play() ;
QMessageBox::information(nullptr, QObject::tr("Ajouter un Partenaire"),
                  QObject::tr("Partenaire ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  }

  else
  {QMediaPlayer * erreur = new QMediaPlayer ;
      erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/erreur.mp3")) ;
          erreur->setVolume(100) ;
          erreur->play() ;

      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Partenaire"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void MainWindow::on_pushButton_64_clicked()
{
    int id= ui->lineEdit_28->text().toInt();
    QString nom=ui->lineEdit_29->text();
    QString prenom=ui->lineEdit_30->text();
    QString adressem=ui->lineEdit_31->text();
    int num= ui->lineEdit_32->text().toInt();



        Partenaire f;
        bool test=f.modifier(id,nom,prenom,adressem,num);

        if(test)
        {   QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->setIcon(QIcon("icone.png"));

            notifyIcon->showMessage("GESTION PARTENAIRE ","partenaire Modifié",QSystemTrayIcon::Information,15000);


            QMediaPlayer * erreur = new QMediaPlayer ;
            erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/partmodif.mp3")) ;
                erreur->setVolume(100) ;
                erreur->play() ;

            QMessageBox::information(nullptr, QObject::tr("modifie une partenaire"),
                              QObject::tr("partenaire modifiée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tabpartenaire->setModel(tmppartenaire.afficher());
        }
        else{
            QMediaPlayer * erreur = new QMediaPlayer ;
            erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/erreur.mp3")) ;
                erreur->setVolume(100) ;
                erreur->play() ;

            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tabpartenaire->setModel(tmppartenaire.afficher());
        }
}

void MainWindow::on_pushButton_63_clicked()
{
    int id = ui->lineEdit_27->text().toInt();
    bool test=tmppartenaire.supprimer(id);
    if(test)
    {
        ui->tabpartenaire->setModel(tmppartenaire.afficher());//refresh
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("icone.png"));

                notifyIcon->showMessage("GESTION PARTENAIRE ","partenaire Suprimé",QSystemTrayIcon::Information,15000);

        QMediaPlayer * erreur = new QMediaPlayer ;
       erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/partsup.mp3")) ;
           erreur->setVolume(100) ;
           erreur->play() ;
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Partenaire"),
                    QObject::tr("Partenaire supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else{
        QMediaPlayer * erreur = new QMediaPlayer ;
       erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/erreur.mp3")) ;
           erreur->setVolume(100) ;
           erreur->play() ;
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Partenaire"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_55_clicked()
{
    int id;

        id=ui->lineEdit_26->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabpartenaire->setModel(tmppartenaire.rechercher(id));
}
}

void MainWindow::on_pushButton_62_clicked()
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

void MainWindow::on_tabpartenaire_activated(const QModelIndex &index)
{
    QString idd = ui->tabpartenaire->model()->data(index).toString() ;
   QSqlQuery qry;
   qry.prepare("SELECT * from partenaire where id = '"+idd+"'") ;
   if (qry.exec())
   {
       while (qry.next()) {
           ui->lineEdit_28->setText(qry.value(0).toString()) ;
          ui->lineEdit_29->setText(qry.value(1).toString()) ;
          ui->lineEdit_30->setText(qry.value(2).toString()) ;
          ui->lineEdit_31->setText(qry.value(3).toString()) ;
          ui->lineEdit_32->setText(qry.value(4).toString()) ;

       }
   }
   QSqlQuery qry1;
   qry1.prepare("SELECT * from partenaire where id = '"+idd+"'") ;
   if (qry1.exec())
   {
       while (qry1.next()) {
           ui->lineEdit_27->setText(qry1.value(0).toString()) ;
       }
   }
   ui->tabpartenaire->setModel(tmppartenaire.afficher());
   ui->tabpartenaire->setModel(tmppartenaire.afficher());//refresh
}

void MainWindow::on_pb_ajouter_6_clicked()
{
int id = ui->comboBox_5->currentText().toInt();
QString nom= ui->lineEdit_20->text();
    QString type= ui->lineEdit_21->text();
    QString status= ui->lineEdit_22->text();
    QString adresse= ui->lineEdit_23->text();
    QString datedebut= ui->lineEdit_24->text();
    int budget = ui->lineEdit_25->text().toInt();
    srand (time(NULL));
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="ajouter" ;
    QString nom1 = ui->lineEdit_7->text();
  projeth pp(nom1,datee,fn) ;
  bool test1=pp.ajoutehis() ;

  Projet e(id,nom,type,status,adresse,datedebut,budget);
  if(verifNOM()&&verifTYPE()&&verifSTATUS()&&verifADRESSE()&&verifDATE()&&verifBUDGET()){
  bool test=e.ajouter();

  if(test)
{
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
      notifyIcon->show();
      notifyIcon->setIcon(QIcon("icone.png"));

      notifyIcon->showMessage("GESTION PROJET ","projet Ajouté",QSystemTrayIcon::Information,15000);
      ui->tabprojet->setModel(tmpprojet.afficher());//refresh
      QMediaPlayer * erreur = new QMediaPlayer ;
     erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/projetajoute.mp3")) ;
         erreur->setVolume(100) ;
         erreur->play() ;
}
}
  else
  {
       QMediaPlayer * erreur = new QMediaPlayer ;
      erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/erreur.mp3")) ;
          erreur->setVolume(100) ;
          erreur->play() ;

  }
}

void MainWindow::on_pushButton10_clicked()
{
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="modifier" ;
int id = ui->comboBox_5->currentText().toInt();
     QString nom=ui->lineEdit_20->text();
    QString type=ui->lineEdit_21->text();
    QString status=ui->lineEdit_22->text();
    QString adresse=ui->lineEdit_23->text();
    QString datedebut=ui->lineEdit_24->text();
    int budget= ui->lineEdit_25->text().toInt();
    QString nom1 = ui->lineEdit_15->text();
    projeth pp(nom1,datee,fn) ;
    bool test1=pp.modifierhis() ;


        Projet f;
        bool test=f.modifier(id,nom,type,status,adresse,datedebut,budget);

        if(test)
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("icone.png"));

                    notifyIcon->showMessage("GESTION PROJET ","projet Modifié",QSystemTrayIcon::Information,15000);


            QMediaPlayer * erreur = new QMediaPlayer ;
            erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/projetmodif.mp3")) ;
                erreur->setVolume(100) ;
                erreur->play() ;
            QMessageBox::information(nullptr, QObject::tr("modifie une projet"),
                              QObject::tr("projet modifiée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tabprojet->setModel(tmpprojet.afficher());
        }
        else
        {QMediaPlayer * erreur = new QMediaPlayer ;
                    erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/erreur.mp3")) ;
                        erreur->setVolume(100) ;
                        erreur->play() ;
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tabprojet->setModel(tmpprojet.afficher());}
}

void MainWindow::on_pb_supprimer_5_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    bool test=tmpprojet.supprimer(id);
    srand (time(NULL));
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="supprimer" ;
    QString nom1 = ui->lineEdit_7->text();
  projeth pp(nom1,datee,fn) ;
  bool test1=pp.modifierhis() ;
    if(test)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("icone.png"));

                notifyIcon->showMessage("GESTION PROJET ","projet Suprimé",QSystemTrayIcon::Information,15000);


        QMediaPlayer * erreur = new QMediaPlayer ;
        erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/projetsup.mp3")) ;
            erreur->setVolume(100) ;
            erreur->play() ;
ui->tabprojet->setModel(tmpprojet.afficher());
    }
    else{
        QMediaPlayer * erreur = new QMediaPlayer ;
       erreur->setMedia(QUrl("C:/Users/Lenovo/Desktop/projet qt/Atelier_Connexion/sounds/erreur.mp3")) ;
           erreur->setVolume(100) ;
           erreur->play() ;

    }

}

void MainWindow::on_pb_ajouter_5_clicked()
{

    int id;

        id=ui->lineEdit_12->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabprojet->setModel(tmpprojet.rechercher(id));
}
}

void MainWindow::on_pushButton_54_clicked()
{
    ui->tabprojet->setModel( tmpprojet.afficher_tri());
    ui->tabprojet->setModel( tmpprojet.afficher_tri());
}

void MainWindow::on_pushButton_53_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      //
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}

void MainWindow::on_tabprojet_activated(const QModelIndex &index)
{
    QString idd = ui->tabprojet->model()->data(index).toString() ;
   QSqlQuery qry;
   qry.prepare("SELECT * from projet where id = '"+idd+"'") ;
   if (qry.exec())
   {
       while (qry.next()) {
           ui->lineEdit_15->setText(qry.value(0).toString()) ;
          ui->lineEdit_20->setText(qry.value(1).toString()) ;
          ui->lineEdit_21->setText(qry.value(2).toString()) ;
          ui->lineEdit_22->setText(qry.value(3).toString()) ;
          ui->lineEdit_23->setText(qry.value(4).toString()) ;
          ui->lineEdit_24->setText(qry.value(5).toString()) ;
          ui->lineEdit_25->setText(qry.value(6).toString()) ;
       }
   }
   QSqlQuery qry1;
   qry1.prepare("SELECT * from projet where id = '"+idd+"'") ;
   if (qry1.exec())
   {
       while (qry1.next()) {
           ui->lineEdit_id_4->setText(qry1.value(0).toString()) ;
       }
   }
   ui->tabprojet->setModel(tmpprojet.afficher());
   ui->tabprojet->setModel(tmpprojet.afficher());//refresh
}
/*bool MainWindow::verifID()
{
    if (ui->lineEdit_15->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_15->text().isEmpty())
    {
        ui->lineEdit_15->clear();

        ui->lineEdit_15->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}*/
bool MainWindow::verifNOM()
{
    if (ui->lineEdit_20->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_20->text().isEmpty())
    {
        ui->lineEdit_20->clear();
        ui->lineEdit_20->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifTYPE()
{
    if (ui->lineEdit_21->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_21->text().isEmpty())
    {
        ui->lineEdit_21->clear();
        ui->lineEdit_21->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifSTATUS()
{
    if (ui->lineEdit_22->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_22->text().isEmpty())
    {
        ui->lineEdit_22->clear();
        ui->lineEdit_22->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifADRESSE()
{
    if (ui->lineEdit_23->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_23->text().isEmpty())
    {
        ui->lineEdit_23->clear();
        ui->lineEdit_23->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifDATE()
{
    if (ui->lineEdit_24->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_24->text().isEmpty())
    {
        ui->lineEdit_24->clear();

        ui->lineEdit_24->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifBUDGET()
{
    if (ui->lineEdit_25->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_25->text().isEmpty())
    {
        ui->lineEdit_25->clear();

        ui->lineEdit_25->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}





bool MainWindow::verifID2()
{
    if (ui->lineEdit_28->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_28->text().isEmpty())
    {
        ui->lineEdit_28->clear();

        ui->lineEdit_28->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifNOM2()
{
    if (ui->lineEdit_29->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_29->text().isEmpty())
    {
        ui->lineEdit_29->clear();
        ui->lineEdit_29->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifPRENOM()
{
    if (ui->lineEdit_30->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_30->text().isEmpty())
    {
        ui->lineEdit_30->clear();
        ui->lineEdit_30->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifadressem()
{
    if (ui->lineEdit_31->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_31->text().isEmpty())
    {
        ui->lineEdit_31->clear();
        ui->lineEdit_31->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifnum()
{
    if (ui->lineEdit_32->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_32->text().isEmpty())
    {
        ui->lineEdit_32->clear();

        ui->lineEdit_32->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
//historique
void MainWindow::on_pushButton_66_clicked()
{
    ui->tabhis->setModel(tmph.afficherhis()) ;
    ui->tabhis->setModel(tmph.afficherhis());//refresh
}
//crud mahdi
void MainWindow::on_pb_ajouter_8_clicked()
{
    int id = ui->lineEdit_34->text().toInt();
    QString nom= ui->lineEdit_38->text();
    QString adresse= ui->lineEdit_35->text();
    QString mail= ui->lineEdit_36->text();
    QString produit= ui->lineEdit_37->text();
    QString convention= ui->lineEdit_39->text();
    int numtel = ui->lineEdit_40->text().toInt();



  Sponsor e(id,nom,adresse,mail,produit,convention,numtel);
  if(verifID3()&&verifNOM3()&&verifADRESSE3()&&verifMAIL3()&&verifPRODUIT3()&&verifCONV3()&&verifNUMTEL3()){
  bool test=e.ajouter();
  if(test)
{QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
      notifyIcon->show();
      notifyIcon->setIcon(QIcon("icone.png"));
      notifyIcon->showMessage("GESTION Sponsor   ","Sponsor Ajouté",QSystemTrayIcon::Information,15000);

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
}

void MainWindow::on_pushButton10_2_clicked()
{
    int id = ui->lineEdit_34->text().toInt();
    QString nom= ui->lineEdit_38->text();
    QString adresse= ui->lineEdit_35->text();
    QString mail= ui->lineEdit_36->text();
    QString produit= ui->lineEdit_37->text();
    QString convention= ui->lineEdit_39->text();
    int numtel = ui->lineEdit_40->text().toInt();



            Sponsor f;
            bool test=f.modifier(id,nom,adresse,mail,produit,convention,numtel);

            if(test)
            {
                QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                      notifyIcon->show();
                      notifyIcon->setIcon(QIcon("icone.png"));
                      notifyIcon->showMessage("GESTION Sponsor   ","Sponsor Modifié",QSystemTrayIcon::Information,15000);




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

void MainWindow::on_pb_supprimer_6_clicked()
{
    int id = ui->lineEdit_id_5->text().toInt();
    bool test=tmpsponsor.supprimer(id);
    if(test)
    {  QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));
        notifyIcon->showMessage("GESTION Sponsor   ","Sponsor Supprimé",QSystemTrayIcon::Information,15000);



        ui->tabsponsor->setModel(tmpsponsor.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un sponsor"),
                    QObject::tr("sponsor supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un sponsor"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_ajouter_7_clicked()
{
    int id;

        id=ui->lineEdit_33->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabsponsor->setModel(tmpsponsor.rechercher(id));
}
}

void MainWindow::on_pushButton_70_clicked()
{
    ui->tabsponsor->setModel( tmpsponsor.afficher_tri());

}

void MainWindow::on_pushButton_74_clicked()
{
    int id = ui->lineEdit_43->text().toInt();
    QString nom= ui->lineEdit_44->text();
    QString type= ui->lineEdit_45->text();
    QString date= ui->lineEdit_46->text();
    int num = ui->lineEdit_47->text().toInt();
    srand (time(NULL));
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="ajouter" ;
    QString nom1 = ui->lineEdit_20->text();
  Marketingh pp(nom1,datee,fn) ;
  bool test1=pp.ajoutehis() ;




  Marketing e(id,nom,type,date,num);
if(verifID4()&&verifNOM4()&&verifTYPE4()&&verifDATE4()&&verifNUM4()){
  bool test=e.ajouter();
  if(test)
{QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
      notifyIcon->show();
      notifyIcon->setIcon(QIcon("icone.png"));
      notifyIcon->showMessage("GESTION Marketing   ","Marketing Ajouté",QSystemTrayIcon::Information,15000);

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
}

void MainWindow::on_pushButton_73_clicked()
{

    int id = ui->lineEdit_43->text().toInt();
    QString nom= ui->lineEdit_44->text();
    QString type= ui->lineEdit_45->text();
    QString date= ui->lineEdit_46->text();
    int num = ui->lineEdit_47->text().toInt();
        srand (time(NULL));
        QDate d = QDate::currentDate() ;
         QString datee =d.toString("dd / MM / yyyy ") ;
         QString fn="modifié" ;
        QString nom1 = ui->lineEdit_20->text();
      Marketingh pp(nom1,datee,fn) ;
      bool test1=pp.modifierhis() ;



            Marketing f;
            bool test=f.modifier(id,nom,type,date,num);

            if(test)
            {QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("icone.png"));
                notifyIcon->showMessage("GESTION Marketing   ","Marketing Modifié",QSystemTrayIcon::Information,15000);


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

void MainWindow::on_pushButton_72_clicked()
{
    int id = ui->lineEdit_42->text().toInt();
    bool test=tmpmarketing.supprimer(id);
    srand (time(NULL));
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="supprimer" ;
    QString nom1 = ui->lineEdit_20->text();
  Marketingh pp(nom1,datee,fn) ;
  bool test1=pp.modifierhis() ;
    if(test)
    {QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));
        notifyIcon->showMessage("GESTION Marketing   ","Marketing Supprimé",QSystemTrayIcon::Information,15000);


        ui->tabmarketing->setModel(tmpmarketing.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer marketing"),
                    QObject::tr("marketing supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Marketing"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_71_clicked()
{
    int id;

        id=ui->lineEdit_41->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabmarketing->setModel(tmpmarketing.rechercher(id));
}
}

void MainWindow::on_pushButton_75_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabmarketing->model()->rowCount();
        const int columnCount = ui->tabmarketing->model()->columnCount();

        out <<  "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"

               //     "<align='right'> " << datefich << "</align>"
               "<center> <H1>GESTION MARKETING </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabmarketing->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabmarketing->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabmarketing->isColumnHidden(column)) {
                    QString data = ui->tabmarketing->model()->data(ui->tabmarketing->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
               "</body>\n"
               "</html>\n";

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void MainWindow::on_pushButton_76_clicked()
{
    ui->tableView_3->setModel(tph.afficherhis()) ;
    ui->tableView_3->setModel(tph.afficherhis());//refresh
}
bool MainWindow::verifID3()
{
    if (ui->lineEdit_34->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_34->text().isEmpty())
    {
        ui->lineEdit_34->clear();

        ui->lineEdit_34->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifNOM3()
{
    if (ui->lineEdit_38->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_38->text().isEmpty())
    {
        ui->lineEdit_38->clear();
        ui->lineEdit_38->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifADRESSE3()
{
    if (ui->lineEdit_35->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_35->text().isEmpty())
    {
        ui->lineEdit_35->clear();
        ui->lineEdit_35->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}

bool MainWindow::verifMAIL3()
{
    if (ui->lineEdit_36->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_36->text().isEmpty())
    {
        ui->lineEdit_36->clear();
        ui->lineEdit_36->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}




bool MainWindow::verifPRODUIT3()
{
    if (ui->lineEdit_37->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_37->text().isEmpty())
    {
        ui->lineEdit_37->clear();
        ui->lineEdit_37->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}

bool MainWindow::verifCONV3()
{
    if (ui->lineEdit_39->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_39->text().isEmpty())
    {
        ui->lineEdit_39->clear();
        ui->lineEdit_39->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifNUMTEL3()
{
    if (ui->lineEdit_40->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_40->text().isEmpty())
    {
        ui->lineEdit_40->clear();

        ui->lineEdit_40->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifID4()
{
    if (ui->lineEdit_43->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_43->text().isEmpty())
    {
        ui->lineEdit_43->clear();

        ui->lineEdit_43->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifNOM4()
{
    if (ui->lineEdit_44->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_44->text().isEmpty())
    {
        ui->lineEdit_44->clear();
        ui->lineEdit_44->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifTYPE4()
{
    if (ui->lineEdit_45->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_45->text().isEmpty())
    {
        ui->lineEdit_45->clear();
        ui->lineEdit_45->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}

bool MainWindow::verifDATE4()
{
    if (ui->lineEdit_46->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_46->text().isEmpty())
    {
        ui->lineEdit_46->clear();
        ui->lineEdit_46->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifNUM4()
{
    if (ui->lineEdit_47->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_47->text().isEmpty())
    {
        ui->lineEdit_47->clear();

        ui->lineEdit_47->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
//hazem
void MainWindow::on_pb_ajouter_9_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/hazem/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }

        QString id= ui->lineEdit_id_6->text();
        QString nom= ui->lineEdit_nom_3->text();
        QString prenom= ui->lineEdit_prenom_3->text();
        QString numtel= ui->lineEdit_numtel_2->text();
        QString mail= ui->lineEdit_mail_2->text();
        QString type= ui->lineEdit_type_3->text();
        QString competence= ui->lineEdit_competence->text();


      adherant a(id,nom,prenom,numtel,mail,type,competence);
      if(verifIdh1()&&verifNomh1()&&verifPrenomh1()&&verifNumtelh1()&&verifMailh1()&&verifTypeh1()&&verifCompetenceh1()){

      bool test=a.ajouter();
      if(test)
    {

          ui->tabadherant->setModel(tmpadherant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un adherant"),
                      QObject::tr("adherant ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un adherant"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_6_clicked()
{
    QString id= ui->lineEdit_id_6->text();
    QString nom= ui->lineEdit_nom_3->text();
    QString prenom= ui->lineEdit_prenom_3->text();
    QString numtel= ui->lineEdit_numtel_2->text();
    QString mail= ui->lineEdit_mail_2->text();
    QString type= ui->lineEdit_type_3->text();
    QString competence= ui->lineEdit_competence->text();

   adherant a(id,nom,prenom,numtel,mail,type,competence);
   if(verifIdh1()&&verifNomh1()&&verifPrenomh1()&&verifNumtelh1()&&verifMailh1()&&verifTypeh1()&&verifCompetenceh1()){

    if(a.modifier(id))
    {
          ui->tabadherant->setModel(tmpadherant.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un acivité"),
                          QObject::tr("acivité modifié.\n"), QMessageBox::Cancel);

    }
   }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un acivité"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }


}

void MainWindow::on_pb_supprimer_7_clicked()
{
    QString id= ui->lineEdit_titres_2->text();
   bool test=tmpadherant.supprimer(id);
   if(test)
   {ui->tabadherant->setModel(tmpadherant.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Supprimer un activité"),
                   QObject::tr("activité.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un activité"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_rechercher_7_clicked()
{
    QString rech =ui->lineEditrech_5->text();
   ui->tabadherant->setModel(tmpadherant.rechercher(rech));
}

void MainWindow::on_pb_tri_6_clicked()
{
      ui->tabadherant->setModel(tmpadherant.tri());
}

void MainWindow::on_pb_tri_7_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tabadherant->model()->rowCount();
                    const int columnCount = ui->tabadherant->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des adherants </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tabadherant->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tabadherant->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tabadherant->isColumnHidden(column)) {
                                QString data = ui->tabadherant->model()->data(ui->tabadherant->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table> </center>\n"
                        "</body>\n"
                        "</html>\n";

              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

               QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
               //printer.setPaperSize(QPrinter::A4);
               //printer.setpap
              printer.setOutputFileName(fileName);

               QTextDocument doc;
                doc.setHtml(strStream);
                //doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
}

void MainWindow::on_pb_tri_10_clicked()
{
    //imprimer

        QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void MainWindow::on_pb_ajouter_10_clicked()
{
    QString nom= ui->lineEdit_nom2->text();
    QString type= ui->lineEdit_type2->text();
    QString duree= ui->lineEdit_duree2->text();
    QString nbr= ui->lineEdit_nbr2->text();
    QDate date= ui->dateEdit_2->date();

  activite a(nom,type,duree,nbr,date);
  if(verifNomh()&&verifTypeh()&&verifDureeh()&&verifNbrh()){

  bool test=a.ajouter();
  if(test)
{

      ui->tabactivite->setModel(tmpactivite.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un adherant"),
                  QObject::tr("adherant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un adherant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_7_clicked()
{
    QString nom= ui->lineEdit_nom2->text();
    QString type= ui->lineEdit_type2->text();
    QString duree= ui->lineEdit_duree2->text();
    QString nbr= ui->lineEdit_nbr2->text();
    QDate date= ui->dateEdit_2->date();

    activite a(nom,type,duree,nbr,date);
    if(verifNomh()&&verifTypeh()&&verifDureeh()&&verifNbrh()){

    if(a.modifier(nom))
    {
          ui->tabactivite->setModel(tmpactivite.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un adherant"),
                          QObject::tr("adherant modifié.\n"), QMessageBox::Cancel);

    }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un adherant"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_supprimer2_3_clicked()
{
    QString nom= ui->lineEdit_noms_2->text();
   bool test=tmpactivite.supprimer(nom);
   if(test)
   {ui->tabactivite->setModel(tmpactivite.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Supprimer un adherant"),
                   QObject::tr("adherant supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un adherant"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_rechercher_8_clicked()
{
    QString rech =ui->lineEditrech_6->text();
   ui->tabactivite->setModel(tmpactivite.rechercher(rech));
}

void MainWindow::on_pb_tri_9_clicked()
{
    ui->tabactivite->setModel(tmpactivite.tri());

}

bool MainWindow::verifNomh()
{
    if (ui->lineEdit_nom2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_nom2->text().isEmpty())
    {
        ui->lineEdit_nom2->clear();

        ui->lineEdit_nom2->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifTypeh()
{
    if (ui->lineEdit_type2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_type2->text().isEmpty())
    {
        ui->lineEdit_type2->clear();
        ui->lineEdit_type2->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifDureeh()
{
    if (ui->lineEdit_duree2->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_duree2->text().isEmpty())
    {
        ui->lineEdit_duree2->clear();
        ui->lineEdit_duree2->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifNbrh()
{
    if (ui->lineEdit_nbr2->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_nbr2->text().isEmpty())
    {
        ui->lineEdit_nbr2->clear();
        ui->lineEdit_nbr2->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}


bool MainWindow::verifIdh1()
{
    if (ui->lineEdit_id_6->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_id_6->text().isEmpty())
    {
        ui->lineEdit_id_6->clear();

        ui->lineEdit_id_6->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifNomh1()
{
    if (ui->lineEdit_nom_3->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_nom_3->text().isEmpty())
    {
        ui->lineEdit_nom_3->clear();
        ui->lineEdit_nom_3->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifPrenomh1()
{
    if (ui->lineEdit_prenom_3->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_prenom_3->text().isEmpty())
    {
        ui->lineEdit_prenom_3->clear();
        ui->lineEdit_prenom_3->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifNumtelh1()
{
    if (ui->lineEdit_numtel_2->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_numtel_2->text().isEmpty())
    {
        ui->lineEdit_numtel_2->clear();
        ui->lineEdit_numtel_2->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifMailh1()
{
    if (ui->lineEdit_mail_2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_mail_2->text().isEmpty())
    {
        ui->lineEdit_mail_2->clear();
        ui->lineEdit_mail_2->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifTypeh1()
{
    if (ui->lineEdit_type_3->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_type_3->text().isEmpty())
    {
        ui->lineEdit_type_3->clear();
        ui->lineEdit_type_3->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifCompetenceh1()
{
    if (ui->lineEdit_competence->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_competence->text().isEmpty())
    {
        ui->lineEdit_competence->clear();
        ui->lineEdit_competence->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
/************************************************NAVV***************************************************************/
void MainWindow::on_menu_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_38_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_menu_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_42_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_pushButton_37_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_pushButton_39_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_pushButton_34_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_35_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_36_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(10);
}
void MainWindow::on_pushButton_43_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_77_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_80_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_83_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_84_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_85_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(0);
}
/*******************************************NAV************************************************/

void MainWindow::on_pushButton_22_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_23_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_24_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_pushButton_27_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_pushButton_26_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(21);
}
void MainWindow::on_pushButton_29_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
 ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_30_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_pushButton_28_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
     ui->stackedWidget->setCurrentIndex(21);
}

/*void MainWindow::on_pushButton_12_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(6);

}*/
//true
void MainWindow::on_pushButton_32_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_31_clicked()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_33_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(4);
}

/*void MainWindow::on_pushButton_34_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(5);
}*/

void MainWindow::on_pushButton_45_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_44_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_48_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_47_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_58_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_56_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_86_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_87_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_67_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_68_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_88_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_89_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_78_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_90_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_82_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_81_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_79_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_pushButton_91_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_12_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_pushButton_13_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_15_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_21_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_92_clicked()
{
    dialog = new Dialog1(this);
    dialog->show();
}

void MainWindow::on_pushButton_93_clicked()
{
    //open file name
      QString filename=QFileDialog::getOpenFileName(this
                                                    ,tr("Open File"),
                                                    "C://", "All files (*.*);;Text File(*.txt);;Music file(*.mp3)" );
      QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
     // QMessageBox::information(this,tr("File Name"),filename);
}

void MainWindow::on_pushButton_94_clicked()
{
    //open file name
      QString filename=QFileDialog::getOpenFileName(this
                                                    ,tr("Open File"),
                                                    "C://", "All files (*.*);;Text File(*.txt);;Music file(*.mp3)" );
      QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
     // QMessageBox::information(this,tr("File Name"),filename);
}

void MainWindow::on_actionSe_Deconnecter_triggered()
{QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Desktop/sound/aurevoir_f_01.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

    close();
}

void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::information(nullptr, QObject::tr("Informations"),
                      QObject::tr("Notre Application <strong> Club Master </strong> consiste à : <br>"
"-Oragniser les tâches <br>"
"-Faciliter les Transactions <br>"
"-Maintenir la sécurité ,la productivité et la discipline <br>"
"Afin de gerer <i> les personnels ,les projets ,les adherants , les événements, les materiels ,les actions marketing </i> <br>"
                                  "Click Cancel to exit."), QMessageBox::Ok);
}

void MainWindow::on_actionNous_Contactez_triggered()
{QMessageBox::information(nullptr, QObject::tr("Question"),
                          QObject::tr("<strong> Numéro: </strong>:99874563 <br>"
"<strong>Site Web :</strong> www.clubmaster.tn <br>"
                                      "Click Cancel to exit."), QMessageBox::Ok);

}
//imprimer zeineb
void MainWindow::on_pushButton_95_clicked()
{
    //click
        QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
          //
        QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

//chat server

/*void MainWindow::on_pushButton_96_clicked()
{
    chat = new mainwindo(this);
    chat->show();
}*/
//screenshot

void MainWindow::on_pushButton_97_clicked()
{
    dialo = new Dialo(this);
   dialo->show();
}

void MainWindow::on_pushButton_98_clicked()
{
    dial= new Dial(this);
    dial->show();
}

void MainWindow::on_pushButton_49_clicked()
{ lng="ANG";
    // page biblo

    ui->pb_ajouter_6->setText("ADD");
    ui->pb_ajouter_5->setText("FIND");

    ui->pushButton10->setText("EDIT");
    ui->pb_supprimer_5->setText("REMOVE");
    ui->pushButton_53->setText("PRINT");
    ui->label_170->setText("enter the project ID");

}

void MainWindow::on_pushButton_99_clicked()
{
    lng="FR";
                    // page biblo

                    ui->pb_ajouter_6->setText("AJOUTER");
                    ui->pb_ajouter_5->setText("RECHERCHER");

                    ui->pushButton10->setText("MODIFIER");
                    ui->pb_supprimer_5->setText("SUPPRIMER");
                    ui->pushButton_53->setText("IMRIMER");
                    ui->label_170->setText("entrer l'ID du projet");
}

void MainWindow::on_pushButton_100_clicked()
{
    QTableView *table;
                           table = ui->tabprojet;
                           QString filters("CSV files (.csv);;All files (.*)");
                           QString defaultFilter("CSV files (*.csv)");
                           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                              filters, &defaultFilter);
                           QFile file(fileName);
                           QAbstractItemModel *model =  table->model();
                           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                               QTextStream data(&file);
                               QStringList strList;
                               for (int i = 0; i < model->columnCount(); i++) {
                                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") << "\n";
                               for (int i = 0; i < model->rowCount(); i++) {
                                   strList.clear();
                                   for (int j = 0; j < model->columnCount(); j++) {
                                       if (model->data(model->index(i, j)).toString().length() > 0)
                                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") + "\n";
                               }
                               file.close();
                               //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");


                           }
}
void MainWindow::afficherStatistiqueM(){


    QSqlQuery query;


        //nombre de dons
                QString nb_pub="";
                query.prepare("SELECT COUNT(*) FROM sponsor");
                query.exec();
                while(query.next()){
                nb_pub= query.value(0).toString();}

         //nombre de famille

                QString nb_eve="";
                query.prepare("SELECT COUNT(*) FROM marketing");
                query.exec();
                while(query.next()){
                nb_eve= query.value(0).toString();}



            QBarSet *set0 = new QBarSet("Jane");


               *set0 << nb_pub.toInt()  << nb_eve.toInt()   ;
            QBarSeries *series = new QBarSeries();
             series->append(set0);
             QChart *chart = new QChart();
                 chart->addSeries(series);
                 chart->setTitle("statistique ");
                 chart->setAnimationOptions(QChart::SeriesAnimations);

                 QStringList categories;
                    categories << "nombre pub" <<  "nombre eve" ;
                    QBarCategoryAxis *axisX = new QBarCategoryAxis();
                    axisX->append(categories);
                    chart->addAxis(axisX, Qt::AlignBottom);
                    series->attachAxis(axisX);



                    chart->legend()->setVisible(true);
                        chart->legend()->setAlignment(Qt::AlignBottom);

                        QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->setParent(ui->horizontalFrame_2);


}

void MainWindow::on_pushButton_101_clicked()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);

       QUrl url("https://AC448119ef82f78297b322e43d379ddee6:20900042d763e02de9871ef3308afa34@api.twilio.com/2010-04-01/Accounts/AC448119ef82f78297b322e43d379ddee6/Messages.json");

       QNetworkRequest request(url);

       request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");


       QUrlQuery params;
      params.addQueryItem("From", "+12093088508");

       params.addQueryItem("To",ui->lineEdit_49->text() );//"+21690101450"
       params.addQueryItem("Body", ui->textEdit_2->toPlainText());
      // params.addQueryItem("Body", "test");

       // etc

       connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply*)));

       manager->post(request, params.query().toUtf8());

}

/*void MainWindow::on_pushButton_102_clicked()
{
    QTableView *table;
                           table = ui->tabsponsor;
                           QString filters("CSV files (.csv);;All files (.*)");
                           QString defaultFilter("CSV files (*.csv)");
                           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                              filters, &defaultFilter);
                           QFile file(fileName);
                           QAbstractItemModel *model =  table->model();
                           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                               QTextStream data(&file);
                               QStringList strList;
                               for (int i = 0; i < model->columnCount(); i++) {
                                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") << "\n";
                               for (int i = 0; i < model->rowCount(); i++) {
                                   strList.clear();
                                   for (int j = 0; j < model->columnCount(); j++) {
                                       if (model->data(model->index(i, j)).toString().length() > 0)
                                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") + "\n";
                               }
                               file.close();
                               //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");

}*/

void MainWindow::on_pushButton_103_clicked()
{
    QTableView *table;
                           table = ui->tabsponsor;
                           QString filters("CSV files (.csv);;All files (.*)");
                           QString defaultFilter("CSV files (*.csv)");
                           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                              filters, &defaultFilter);
                           QFile file(fileName);
                           QAbstractItemModel *model =  table->model();
                           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                               QTextStream data(&file);
                               QStringList strList;
                               for (int i = 0; i < model->columnCount(); i++) {
                                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") << "\n";
                               for (int i = 0; i < model->rowCount(); i++) {
                                   strList.clear();
                                   for (int j = 0; j < model->columnCount(); j++) {
                                       if (model->data(model->index(i, j)).toString().length() > 0)
                                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") + "\n";
                               }
                               file.close();
                               //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
}}

void MainWindow::on_pushButton_102_clicked()
{
   main= new  MainWindow1 (this);
   main->show();
}

void MainWindow::on_pushButton_104_clicked()
{
    lng="ANG";
        // page biblo

        ui->pushButton_74->setText("ADD");
        ui->pushButton_71->setText("FIND");

        ui->pushButton_73->setText("EDIT");
        ui->pushButton_72->setText("REMOVE");
        ui->pushButton_75->setText("PRINT");
        ui->label_215->setText("enter the action ID");
}

void MainWindow::on_pushButton_105_clicked()
{
    lng="FR";
                       // page biblo

                       ui->pushButton_74->setText("AJOUTER");
                       ui->pushButton_71->setText("RECHERCHER");

                       ui->pushButton_73->setText("MODIFIER");
                       ui->pushButton_72->setText("SUPPRIMER");
                       ui->pushButton_75->setText("IMRIMER");
                       ui->label_215->setText("entrer l'ID de l'action");
}
