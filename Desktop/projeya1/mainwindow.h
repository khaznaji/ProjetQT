#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Membre.h"
#include <QMainWindow>
#include"fonction.h"
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

private:
    Ui::MainWindow *ui;
    Membre tmpmembre;
    fonction tmpfonction;
};

#endif // MAINWINDOW_H
