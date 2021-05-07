#ifndef MAINWIND_H
#define MAINWIND_H

#include <QWidget>


#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>

namespace Ui {
class mainwind;
}

class mainwind : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwind(QWidget *parent = 0);
    ~mainwind();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::mainwind *ui;
    QString mFileName;
    QLabel *statusLabel;
};

#endif // MAINWIND_H
