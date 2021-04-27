#ifndef ARDUIN_H
#define ARDUIN_H
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QString>
#include<QDebug>
#include<iostream>
using namespace std;
class Arduino
{
public:
    Arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino( QByteArray );
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();
    void clear();
private:
QSerialPort * serial;
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;
};
#endif // ARDUIN_H
