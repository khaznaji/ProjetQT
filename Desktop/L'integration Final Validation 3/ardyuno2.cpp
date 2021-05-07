#include "ardyuno2.h"
#include "ui_ardyuno2.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <string>
#include <QMessageBox>
ardyuno2::ardyuno2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ardyuno2)
{

        counter = 0;
    ui->setupUi(this);
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
           if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
               if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                   if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                       arduino_port_name = serialPortInfo.portName();
                       arduino_is_available = true;
                   }
               }
           }
       }

       if(arduino_is_available){
           // open and configure the serialport
           arduino->setPortName(arduino_port_name);

           arduino->setBaudRate(QSerialPort::Baud9600);
           arduino->setDataBits(QSerialPort::Data8);

           arduino->setParity(QSerialPort::NoParity);
           arduino->setStopBits(QSerialPort::OneStop);
           arduino->setFlowControl(QSerialPort::NoFlowControl);
           arduino->open(QSerialPort::ReadWrite);

             QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
       }else{
           // give error message if not available
           QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
       }

}

ardyuno2::~ardyuno2()
{
    delete ui;
}
void ardyuno2::readSerial(){


QStringList buffer_split = serialBuffer.split("\r\n");
        // no parsed value yet so continue accumulating bytes from serial in the buffer.
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
                qDebug() <<buffer_split;
ui->bienvenue->setText("Bienvenue");
}
void ardyuno2::updateRamp(QString command)
{
if(arduino->isWritable()){
    arduino->write(command.toStdString().c_str());
}else{
    qDebug() << "Couldn't write to serial!";
}}
