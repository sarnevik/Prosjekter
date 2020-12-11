#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <QString>

QSerialPort serial;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //QWidget setStyleSheet("background-color: #f40d30;")
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("font: bold;font-size: 14px;");
    int sn[ 6 ]= { 12345, 23456, 34567, 45678, 56789, 678910 };
    QString SerialNumber1 = QString::number(sn[0]);
    QString SerialNumber2 = QString::number(sn[1]);
    QString SerialNumber3 = QString::number(sn[2]);
    QString SerialNumber4 = QString::number(sn[3]);
    QString SerialNumber5 = QString::number(sn[4]);
    QString SerialNumber6 = QString::number(sn[5]);
    ui->textEdit_1->setPlaceholderText(SerialNumber1);
    ui->textEdit_2->setPlaceholderText(SerialNumber2);
    ui->textEdit_3->setPlaceholderText(SerialNumber3);
    ui->textEdit_4->setPlaceholderText(SerialNumber4);
    ui->textEdit_5->setPlaceholderText(SerialNumber5);
    ui->textEdit_6->setPlaceholderText(SerialNumber6);
    ui->textEdit_1->setFrameStyle(QFrame::NoFrame);
    ui->textEdit_2->setFrameStyle(QFrame::NoFrame);
    ui->textEdit_3->setFrameStyle(QFrame::NoFrame);
    ui->textEdit_4->setFrameStyle(QFrame::NoFrame);
    ui->textEdit_5->setFrameStyle(QFrame::NoFrame);
    ui->textEdit_6->setFrameStyle(QFrame::NoFrame);

    //for(int i=0;i<6;i++){
        //QString SerialNumber = QString::number(sn[i]);
        //std::string text = "textEdit_";
        //text += std::to_string(i);
        //text += "->setPlaceholderText(";
        //text += std::to_string(sn[i]);
        //text += ")";
        //QString te = QString::fromStdString("ui->textEdit_" + i + "->setPlaceholderText(" + SerialNumber + ")");
        //ui->textEdit_1->setPlaceholderText(SerialNumber);
        //ui->text;
    //}

    arduino_is_available = false;
        arduino_port_name = "";

        arduino = new QSerialPort;

        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
            {
                if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
                {
                    if(serialPortInfo.vendorIdentifier() == arduino_mega_vendor_id)
                    {
                        if(serialPortInfo.productIdentifier() == arduino_mega_product_id)
                        {
                            arduino_port_name = serialPortInfo.portName();
                            arduino_is_available = true;
                        }
                    }
                }
                if(arduino_is_available)
                {
                    // open and configure the port
                    arduino->setPortName(arduino_port_name);
                    arduino->open(QSerialPort::WriteOnly);
                    arduino->setBaudRate(QSerialPort::Baud9600);
                    arduino->setDataBits(QSerialPort::Data8);
                    arduino->setParity(QSerialPort::NoParity);
                    arduino->setStopBits(QSerialPort::OneStop);
                    arduino->setFlowControl(QSerialPort::NoFlowControl);
                }
                else
                {
                    // give error message
                    QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
                }
            }




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->isChecked()) {
        ui->widget_1->setStyleSheet("background-color: #f40d30;");
        ui->widget_2->setStyleSheet("background-color: #f40d30;");
        ui->widget_3->setStyleSheet("background-color: #f40d30;");
        ui->widget_4->setStyleSheet("background-color: #f40d30;");
        ui->widget_5->setStyleSheet("background-color: #f40d30;");
        ui->widget_6->setStyleSheet("background-color: #f40d30;");

        //ui->textEdit_1->viewport()->setAutoFillBackground(false);
        //ui->label_1->setStyleSheet("QLabel {color: #f40d30;}");
    }else{
        ui->widget_1->setStyleSheet("background-color: #232629;");
        ui->widget_2->setStyleSheet("background-color: #232629;");
        ui->widget_3->setStyleSheet("background-color: #232629;");
        ui->widget_4->setStyleSheet("background-color: #232629;");
        ui->widget_5->setStyleSheet("background-color: #232629;");
        ui->widget_6->setStyleSheet("background-color: #232629;");
        //ui->textEdit_1->viewport()->setAutoFillBackground(true);
        //ui->label_1->setStyleSheet("QLabel {color: #FFFFFF;}");
    }
}



void MainWindow::on_pushButton_up_clicked()
{
    std::string var = std::string("font: bold;font-size: ");
    var += std::to_string((ui->widget_1->font().pixelSize()+4));
    var += std::string("px;");
    QString qvar = QString::fromStdString(var);
    ui->centralwidget->setStyleSheet(qvar);
}


void MainWindow::on_pushButton_down_clicked()
{
    std::string var = std::string("font: bold;font-size: ");
    var += std::to_string((ui->textEdit_1->font().pixelSize()-4));
    var += std::string("px;");
    QString qvar = QString::fromStdString(var);
    ui->centralwidget->setStyleSheet(qvar);
}
