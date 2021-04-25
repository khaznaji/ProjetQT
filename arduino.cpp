#include "arduino.h"
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>
#include <QMessageBox>

arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;

}

QString arduino::get_arduino_port_name()
{
    return arduino_port_name;
}

QSerialPort* arduino::getserial()
{
    return serial;
}


int arduino::connnect_arduino()
{
    foreach(const QSerialPortInfo &serial_port_info,QSerialPortInfo::availablePorts())
    {
        qDebug()<<"test";
        if(serial_port_info.hasVendorIdentifier()&& serial_port_info.hasProductIdentifier())
        {
            qDebug()<<"vendor:"<<serial_port_info.vendorIdentifier();
            qDebug()<<"vendor:"<<serial_port_info.productIdentifier();
            if(serial_port_info.vendorIdentifier()==arduino_uno_vender_id && serial_port_info.productIdentifier()==arduino_uno_producy_id)
            {
                arduino_is_available=true;
                arduino_port_name=serial_port_info.portName();
            }
        }
    }
    qDebug()<<"arduino_port_name is:"<<arduino_port_name;
    qDebug()<<"arduino_port_name is:"<<arduino_is_available;
    if(arduino_is_available)
    {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite))//readwrite
        {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            return 0;
        }
        return 1;
    }
    return -1;
}



int arduino::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}


QByteArray arduino::read_from_arduino()
{

        data=serial->readAll();
        serialbuffer += QString::fromStdString(data.toStdString());
      //  qDebug() <<serialbuffer;
        return data;


}



int arduino::write_to_arduino(QByteArray m)
{
    if(serial->isWritable())
    {
        serial->write(m);

    }
    else
    {
        qDebug()<<"couldn't write to serial!";
    }

}






