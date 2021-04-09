#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

#include <QMessageBox>

#include  <QDebug>

#include <QRadioButton>

#include<QtPrintSupport/QPrinter>

#include<QPdfWriter>

#include <QPainter>

#include<QFileDialog>

#include<QTextDocument>

#include <QTextEdit>

#include <QtSql/QSqlQueryModel>

#include<QtPrintSupport/QPrinter>

#include <QVector2D>

#include <QVector>

#include <QSqlQuery>

#include<QDesktopServices>

#include <QMessageBox>

#include<QUrl>

#include <QPixmap>

#include <QTabWidget>

#include <QValidator>

#include <QPrintDialog>

#include<QtSql/QSqlQuery>

#include<QVariant>
#include<QDate>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);


ui->tabadherant->setModel(tmpadherant.afficher());
ui->tabactivite->setModel(tmpactivite.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{


        QString id= ui->lineEdit_id->text();
        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        QString numtel= ui->lineEdit_numtel->text();
        QString mail= ui->lineEdit_mail->text();
        QString type= ui->lineEdit_type->text();
        QString competence= ui->lineEdit_competence->text();


      adherant a(id,nom,prenom,numtel,mail,type,competence);
      bool test=a.ajouter();
      if(test)
    {

          ui->tabadherant->setModel(tmpadherant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un activité"),
                      QObject::tr("adherant ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un activité"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_supprimer_clicked()
{
    QString id= ui->lineEdit_titres->text();
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

void MainWindow::on_pb_modifier_clicked()
{
    QString id=ui->lineEdit_titre_2->text();
    QString nom=ui->lineEdit_type_2->text();
    QString prenom=ui->lineEdit_lieu_2->text();
    QString numtel=ui->lineEdit_datedebut_2->text();
    QString mail=ui->lineEdit_datefin_2->text();
    QString type=ui->lineEdit_typee->text();
    QString competence=ui->lineEdit_competence_2->text();
   adherant a(id,nom,prenom,numtel,mail,type,competence);
    if(a.modifier(id))
    {
          ui->tabadherant->setModel(tmpadherant.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un acivité"),
                          QObject::tr("acivité modifié.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un acivité"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }


}


void MainWindow::on_pb_tri_clicked()
{
    ui->tabadherant->setModel(tmpadherant.tri());
}

void MainWindow::on_pb_rechercher_clicked()
{
    QString rech =ui->lineEditrech->text();
   ui->tabadherant->setModel(tmpadherant.rechercher(rech));
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    QString nom= ui->lineEdit_nom2->text();
    QString type= ui->lineEdit_type2->text();
    QString duree= ui->lineEdit_duree2->text();
    QString nbr= ui->lineEdit_nbr2->text();
    QDate date= ui->dateEdit->date();

  activite a(nom,type,duree,nbr,date);
  bool test=a.ajouter();
  if(test)
{

      ui->tabactivite->setModel(tmpactivite.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un adherant"),
                  QObject::tr("adherant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un adherant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_2_clicked()
{
    QString nom=ui->lineEdit_nom_3->text();
    QString type=ui->lineEdit_type_3->text();
    QString duree=ui->lineEdit_duree_3->text();
    QString nbr=ui->lineEdit_nbr_3->text();
    QDate date=ui->dateEdit_2->date();

    activite a(nom,type,duree,nbr,date);
    if(a.modifier(nom))
    {
          ui->tabactivite->setModel(tmpactivite.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un adherant"),
                          QObject::tr("adherant modifié.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un adherant"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_supprimer2_clicked()
{
    QString nom= ui->lineEdit_noms->text();
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


void MainWindow::on_pb_rechercher_2_clicked()
{
    QString rech =ui->lineEditrech_3->text();
   ui->tabactivite->setModel(tmpactivite.rechercher(rech));
}

void MainWindow::on_pb_tri_2_clicked()
{
     ui->tabactivite->setModel(tmpactivite.tri());
}



void MainWindow::on_pb_tri_4_clicked()
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

void MainWindow::on_pb_tri_5_clicked()
{
    //imprimer

        QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}



void MainWindow::on_pushButton_2_clicked()
{
     ui->tabadherant->setModel(tmpadherant.afficher());
}

void MainWindow::on_pb_tri_7_clicked()
{
    ui->tabactivite->setModel(tmpactivite.afficher());
}
