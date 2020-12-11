#include "mainwindow.h"
#include <QApplication>

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>

QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSerialPortInfo info("/dev/ttyACM4");

    // Check info of the port
    qDebug() << "Name: " << info.portName();
    qDebug() << "Manufacturer " << info.manufacturer();
    qDebug() << "Busy: " << info.isBusy() << Qt::endl;
    QSerialPort serial;
    MainWindow w;
    w.show();
    return a.exec();
}
