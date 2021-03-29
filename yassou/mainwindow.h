#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenement.h"
#include "participant.h"
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

private:
    Ui::MainWindow *ui;
    evenement tmpevenement;
    participant tmpparticipant;
};

#endif // MAINWINDOW_H
