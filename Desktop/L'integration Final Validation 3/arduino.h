#ifndef ARDUINO_H
#define ARDUINO_H
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QString>
#include<QDebug>
#include<QSqlQueryModel>

class arduino
{
public:
    arduino();
    int connnect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString get_arduino_port_name();
    QString getbuffer(){return serialbuffer;
                       }
private:
    QSerialPort* serial;
    static const quint16 arduino_uno_vender_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
    QString serialbuffer;

};

#endif // ARDUINO_H
