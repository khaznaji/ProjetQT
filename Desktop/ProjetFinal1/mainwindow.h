#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Membre.h"
#include <QMainWindow>
#include"fonction.h"
#include"smtp.h"

#include<QMediaPlayer>
namespace Ui {
class MainWindow;
}
class QMediaPlayer;

class MainWindow : public QMainWindow{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    Membre tmpmembre;
    fonction tmpfonction;
    QMediaPlayer*mMediaPlayer;
    QStringList files;

};

#endif // MAINWINDOW_H
