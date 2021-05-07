#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include "dialo.h"
#include "mainwindo.h"
#include "dial.h"
#include "Membre.h"
#include <QMainWindow>
#include"fonction.h"
#include"smtp.h"
#include"article.h"
#include <QPropertyAnimation>
#include"arduino.h"
#include"mainwindowvideo.h"
#include<QMediaPlayer>
#include<QTimer>
#include"note.h"
#include"publicite.h"
#include"evenement.h"
#include"participant.h"
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMouseEvent>
#include <QtWidgets/QMessageBox>
#include "materiel.h"
#include"fournisseur.h"
#include "projet.h"
#include "partenaire.h"
#include "marketing.h"
#include "sponsor.h"
#include<QDate>
#include "adherant.h"
#include "activite.h"
namespace Ui {
class MainWindow;
}
class QMediaPlayer;

class MainWindow : public QMainWindow{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void clockTimer();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_10_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_horizontalSlider_valueChanged(int value);


    void on_pushButton_20_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_avance_3_valueChanged(int value);

    void on_pushButton_19_clicked();
    void sendMail();
    void mailSent(QString);
    void browse();
    void sendMail2();
    void browse2();
    void on_browseBtn_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_toolButton_clicked();

    void on_tabmembre_activated(const QModelIndex &index);

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_26_clicked();

    void on_tableView_activated(const QModelIndex &index);
    void digit_pressed();
    void on_pushButton_point_released();
    void unary_operation_pressed();
    void on_pushButton_C_released();
    void on_pushButton_equal_released();
    void binary_operation_pressed();

    void on_pushButton_ajouterartcile_clicked();

    void on_pushButton_modifierarticle_clicked();

    void on_pushButton_supparticle_clicked();

    void on_tabarticle_activated(const QModelIndex &index);

    void on_comboBox_4_activated(const QString &arg1);

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_pushButton_rechercharticle_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_menu_2_clicked();

    void on_pb_ajout_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_tri_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer2_clicked();

    void on_pb_rechercher_2_clicked();

    void on_pb_tri_2_clicked();

    void on_pb_ajouter_4_clicked();

    void on_pb_modifier_3_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_rechercher_4_clicked();

    void on_pb_tri_3_clicked();

    void on_tabevenement_activated(const QModelIndex &index);

    void on_tabparticipant_activated(const QModelIndex &index);

    void on_tabpublicite_activated(const QModelIndex &index);

    void on_pb_imprimer_clicked();

    void on_pb_imprimer_2_clicked();

    void on_pb_pdf_clicked();

    void on_pb_pdf_2_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();
void replyFinished(QNetworkReply* reply);
void on_menu_clicked();

void on_pushButton_38_clicked();

void on_pushButton_42_clicked();

void on_pushButton_37_clicked();

void on_pushButton_39_clicked();

void on_pushButton_35_clicked();

void on_pushButton_36_clicked();

void on_pushButton_43_clicked();
//zeineb
void on_dateTimeEdit_dateChanged(const QDate &date);

void on_pushButton_60_clicked();

void on_pushButton_59_clicked();

void on_pb_ajouter_2_clicked();

void on_pb_modifier_5_clicked();

void on_pb_supprimer_4_clicked();

void on_pb_rechercher_5_clicked();

void on_pb_tri_5_clicked();

void on_pushButton_57_clicked();

void on_pushButton_46_clicked();

void on_pb_modifier_4_clicked();

void on_pb_supprimer2_2_clicked();

void on_pb_rechercher_3_clicked();

void on_pb_tri_4_clicked();

void on_pushButton_50_clicked();

void on_pushButton_51_clicked();

void on_pushButton_61_clicked();

void on_tabmateriel_activated(const QModelIndex &index);

void on_tabfournisseurs_activated(const QModelIndex &index);

void on_pushButton_52_clicked();

void on_pushButton_65_clicked();

void on_pushButton_64_clicked();

void on_pushButton_63_clicked();

void on_pushButton_55_clicked();

void on_pushButton_62_clicked();

void on_tabpartenaire_activated(const QModelIndex &index);

void on_pb_ajouter_6_clicked();

void on_pushButton10_clicked();

void on_pb_supprimer_5_clicked();

void on_pb_ajouter_5_clicked();

void on_pushButton_54_clicked();

void on_pushButton_53_clicked();

void on_tabprojet_activated(const QModelIndex &index);
//ctrl de sais aboud
bool verifNOM();
bool verifID();
bool verifTYPE();
bool verifSTATUS();
bool verifADRESSE();
bool verifDATE();
bool verifBUDGET();


bool verifNOM2();
bool verifID2();
bool verifPRENOM();
bool verifadressem();
bool verifnum();


void on_pushButton_66_clicked();

void on_pb_ajouter_8_clicked();

void on_pushButton10_2_clicked();

void on_pb_supprimer_6_clicked();

void on_pb_ajouter_7_clicked();

void on_pushButton_70_clicked();

void on_pushButton_74_clicked();

void on_pushButton_73_clicked();

void on_pushButton_72_clicked();

void on_pushButton_71_clicked();

void on_pushButton_75_clicked();

void on_pushButton_76_clicked();
// cntr saisie mahdi
bool verifID3();
bool verifNOM3();
bool verifADRESSE3();
bool verifMAIL3();
bool verifPRODUIT3();
bool verifCONV3();
bool verifNUMTEL3();
bool verifID4();
bool verifNOM4();
bool verifTYPE4();
bool verifDATE4();
bool verifNUM4();

void on_pb_ajouter_9_clicked();

void on_pb_modifier_6_clicked();

void on_pb_supprimer_7_clicked();

void on_pb_rechercher_7_clicked();

void on_pb_tri_6_clicked();

void on_pb_tri_7_clicked();

void on_pb_tri_10_clicked();

void on_pb_ajouter_10_clicked();

void on_pb_modifier_7_clicked();

void on_pb_supprimer2_3_clicked();

void on_pb_rechercher_8_clicked();

void on_pb_tri_9_clicked();

void on_pushButton_78_clicked();

void on_pushButton_83_clicked();

void on_buttonBox_accepted();

void on_pushButton_80_clicked();

void on_pushButton_84_clicked();

void on_pushButton_85_clicked();

private:
    QPropertyAnimation *animation ;
    Ui::MainWindow *ui;
    Membre tmpmembre;
    fonction tmpfonction;
    article tmparticle;
    QMediaPlayer*mMediaPlayer;
    QStringList files;
        arduino ard;
        MainWindowvideo *video;
        QString filename;
        Dialog *dialog;
        Dialo *dialo;
        mainwindo *chat ;
        Dial *dial;
        //Mainwindo *mainwindo;
QTimer timer;
//zeineb
QTimer timer2;
note *notepad;
//Yassine
evenement tmpevenement; //creer un objet(temporaire dans mainwindow.cpp) de type evenement
participant tmpparticipant;

publicite tmppub;
//Zeineb
Materiel tmpmateriel ;
Fournisseur tmpfournisseur;
//aboud
Projet tmpprojet;
Partenaire tmppartenaire;
projeth tmph;
//mahdi
Marketing tmpmarketing;
Sponsor tmpsponsor;
Marketingh tph;
//hazem
adherant tmpadherant;
activite tmpactivite;

};

#endif // MAINWINDOW_H
