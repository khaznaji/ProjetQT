#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "marketing.h"
#include "sponsor.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

   // void on_button_ajouter_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton10_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pushButton_9_clicked();

    //void on_radioButton_clicked();

   // void on_tabmarketing_activated(const QModelIndex &index);

    //void on_pushButton_8_clicked();

    void on_pushButton10_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    Marketing tmpmarketing;
    Sponsor tmpsponsor;
};

#endif // MAINWINDOW_H
