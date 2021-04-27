#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
#include"ardyuno2.h"
#include"arduin.h"
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

private:
    QPropertyAnimation *animation ;
    Ui::MainWindow *ui;
    Membre tmpmembre;
    fonction tmpfonction;
    article tmparticle;
    QMediaPlayer*mMediaPlayer;
    QStringList files;
        MainWindowvideo *video;
        QString filename;
QTimer timer;
note *notepad;
ardyuno2* Arduino1;
Arduino A1;


};

#endif // MAINWINDOW_H
