#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDataStream>
#include <QDebug>

namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();
private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionAdd_triggered();

    void on_actionRemove_triggered();

    void on_actionClear_triggered();

    void on_actionSelect_All_triggered();

    void on_actionSelect_None_triggered();

    void on_actionChecked_triggered();

    void on_actionUnchecked_triggered();

    void on_actionPartially_triggered();
private:
    Ui::MainWindow1 *ui;
    QString m_filename;
    bool m_changed;
    void create();
    void open(QString path);
    void save(QString path);
    void checkSave();
    void createItem(Qt::CheckState state, QString name);

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // MAINWINDOW1_H
