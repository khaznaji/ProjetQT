#include "mainwindo.h"
#include "ui_mainwindo.h"

mainwindo::mainwindo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindo)
{
    ui->setupUi(this);
    connect(&m_socket,&QTcpSocket::connected,this,&mainwindo::connected);
    connect(&m_socket,&QTcpSocket::disconnected,this,&mainwindo::disconnected);
    connect(&m_socket,&QTcpSocket::readyRead,this,&mainwindo::readyRead);
    connect(&m_socket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&mainwindo::error);
    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);
    m_model.setStringList(m_list);
    ui->listView->setModel(&m_model);
}

mainwindo::~mainwindo()
{
    delete ui;
}
void mainwindo::on_btnConnect_clicked()
{
    if(m_socket.isOpen()) m_socket.close();

    m_name = QInputDialog::getText(this,"Name","What is your name?",QLineEdit::EchoMode::Normal, m_name);

    bool ok;
    quint16 port = static_cast<quint16>(ui->txtPort->text().toInt(&ok));
    if(!ok)
    {
        QMessageBox::critical(this,"Error","Please enter a valid port number!");
        return;
    }

    m_socket.connectToHost(ui->txtServer->text(),port);
    ui->btnConnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);

    if(!m_socket.waitForConnected(3000))
    {
        on_btnDisconnect_clicked();
        QMessageBox::critical(this,"Error","Could not connect to server!");
        return;
    }

}

void mainwindo::on_btnDisconnect_clicked()
{
    m_socket.close();
    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);
}

void mainwindo::on_btnSend_clicked()
{
    if(!m_socket.isOpen()) return;

    QByteArray data;
    data.append(m_name);
    data.append(QString(" "));
    data.append(ui->txtMessage->text());

    m_socket.write(data);
    ui->txtMessage->setText(QString());
}

void mainwindo::connected()
{
    ui->btnConnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(true);
    ui->btnSend->setEnabled(true);
}

void mainwindo::disconnected()
{
    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);
}

void mainwindo::readyRead()
{
    QByteArray data = m_socket.readAll();
    QString message(data);
    m_list.append(message);
    m_model.setStringList(m_list);
    ui->listView->scrollToBottom();
}

void mainwindo::error(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError)
    QMessageBox::critical(this,"Error", m_socket.errorString());
}
