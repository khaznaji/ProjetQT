#ifndef MAINWINDO_H
#define MAINWINDO_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTcpSocket>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractSocket>
#include <QInputDialog>

namespace Ui {
class mainwindo;
}

class mainwindo : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindo(QWidget *parent = nullptr);
    ~mainwindo();
private slots:
    void on_btnConnect_clicked();
    void on_btnDisconnect_clicked();
    void on_btnSend_clicked();
    void connected();
    void disconnected();
    void readyRead();
    void error(QAbstractSocket::SocketError socketError);

private:

Ui::mainwindo *ui;
    QTcpSocket m_socket;
    QStringList m_list;
    QStringListModel m_model;
    QString m_name;
private:

};

#endif // MAINWINDO_H
