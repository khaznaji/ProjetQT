#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenement.h"
#include "participant.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include<QSound>
#include<QPropertyAnimation>
#include "publicite.h"

namespace Ui {
class MainWindow;
}
class QMediaPlayer;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_clicked();

    void on_pb_tri_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer2_clicked();

    void on_pb_tri_2_clicked();

    void on_pb_rechercher_2_clicked();

    void on_pb_pdf_clicked();

    void on_pb_imprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_5_clicked();

    void on_event_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_menu_clicked();

    void on_pb_ajout_clicked();

    void on_tabevenement_activated(const QModelIndex &index);

    void on_tabparticipant_activated(const QModelIndex &index);

    void on_pb_ajouter_3_clicked();

    void on_pb_modifier_3_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_rechercher_3_clicked();

    void on_pb_tri_3_clicked();

    void on_tabpublicite_activated(const QModelIndex &index);

    void on_menu_2_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
    evenement tmpevenement; //creer un objet(temporaire dans mainwindow.cpp) de type evenement
    participant tmpparticipant;
    QMediaPlayer*mMediaPlayer;
    QPropertyAnimation *animation ;
    publicite tmppub;

};

#endif // MAINWINDOW_H
