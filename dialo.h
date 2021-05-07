#ifndef DIALO_H
#define DIALO_H

#include <QDialog>
#include <QScreen>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include <QFileInfo>
#include <QTimer>

#include <QDialog>

namespace Ui {
class Dialo;
}

class Dialo : public QDialog
{
    Q_OBJECT

public:
    explicit Dialo(QWidget *parent = nullptr);
    ~Dialo();
private slots:
    void on_btnScreen_clicked();
    void on_btnSave_clicked();
    void shoot();

private:
    Ui::Dialo *ui;
    QPixmap m_image;
    QTimer m_timer;


};

#endif // DIALO_H
