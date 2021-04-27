#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Membre.h"
#include"fonction.h"
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
#include<stat.h>
#include"arduino.h"
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include "mainwindowvideo.h"
#include"note.h"
#include"ardyuno2.h"
#include "arduin.h"
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
//CRUD
ui->tabmembre->setModel(tmpmembre.afficher());
ui->tableView->setModel(tmpfonction.afficher());
ui->tabarticle->setModel(tmparticle.afficher());
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


//Importation de l'image
ui->progressBar->setValue(0);
//Affectation
ui->comboBox->setModel(tmpfonction.affecter_membre());
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
/******************************************Animation2****************************************/

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
}
//Clock
void MainWindow::clockTimer()
{
    QTime time=QTime::currentTime();
  QString time_text =time.toString ("hh : mm :ss ");
  ui->Clocklabel->setText(time_text);
ui->clock2->setText(time_text);
ui->clock3->setText(time_text);

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
    ui->stackedWidget->setCurrentIndex(5);
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
{  Arduino1 =new ardyuno2(this);
    Arduino1->show();
    /*int x=0;
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
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->stackedWidget->setCurrentIndex(2);
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
    ui->stackedWidget->setCurrentIndex(5);
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
     ui->stackedWidget->setCurrentIndex(5);
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
    ui->stackedWidget->setCurrentIndex(4);
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
 ui->stackedWidget->setCurrentIndex(4);
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
     ui->stackedWidget->setCurrentIndex(5);
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
     ui->stackedWidget->setCurrentIndex(4);
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
        ui->stackedWidget->setCurrentIndex(1);
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
