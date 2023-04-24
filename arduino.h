#ifndef ARDUINO_H
#define ARDUINO_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
class arduinoData;

class arduino
{
    Q_OBJECT
public:
    arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort *getserial();
    QString getarduino_port_name();


private:
    QSharedDataPointer<arduinoData> data;
     QSerialPort *serial;
     static const quint16 arduino_uno_vendor_id=9025;
         static const quint16 arduino_uno_product_id=67;
         QString arduino_port_name;
            bool arduino_is_available;
            QByteArray data;
};

#endif // ARDUINO_H
