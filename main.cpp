#include "mainwindow.h"

#include <QApplication>

#include <QtSerialPort/QSerialPort>

#include <QtSerialPort/QSerialPortInfo>

#include <cstdio>

#include <QTextStream>

#include <iostream>

int main(int argc, char *argv[])
{

    QCoreApplication a{argc, argv};
        QTextStream in{stdin};
        QTextStream out{stdout};

        QSerialPort port;
        port.setPortName("COM6");
        port.setBaudRate(9600);
        port.setDataBits(QSerialPort::Data8);
        port.setParity(QSerialPort::NoParity);
        port.setStopBits(QSerialPort::OneStop);
        port.setFlowControl(QSerialPort::NoFlowControl);

        if (!port.open(QSerialPort::ReadWrite)) {
            out << "Error opening serial port: " << port.errorString() << Qt::endl;
            return 1;
        }

        while(true)
        {
            out << "> ";
            auto cmd = in.readLine().toLatin1();
            if (cmd.length() < 1)
                continue;

            port.write(cmd);

            while (!port.canReadLine())
                port.waitForReadyRead(-1);

            while (port.canReadLine())
                out << "< " << port.readLine(); // lines are already terminated
        }

    MainWindow w;
    w.show();
    return a.exec();

}
