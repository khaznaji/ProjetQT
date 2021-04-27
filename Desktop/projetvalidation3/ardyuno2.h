#ifndef ARDYUNO2_H
#define ARDYUNO2_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>
namespace Ui {
class ardyuno2;
}

class ardyuno2 : public QDialog
{
    Q_OBJECT

public:
    explicit ardyuno2(QWidget *parent = nullptr);
    ~ardyuno2();
private slots:
    void updateRamp(QString);
     void readSerial();

private:
    Ui::ardyuno2 *ui;
    QSerialPort *arduino;
        static const quint16 arduino_uno_vendor_id = 9025;
        static const quint16 arduino_uno_product_id = 67;
        QByteArray serialData;
            QString serialBuffer;
            QString parsed_data;
            int car_count;
        QString arduino_port_name;
        bool arduino_is_available;
 int counter;
};

#endif // ARDYUNO2_H
