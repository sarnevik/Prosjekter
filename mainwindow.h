#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
        static const quint16 arduino_mega_vendor_id = 9025;
        static const quint16 arduino_mega_product_id = 66;
        QString arduino_port_name;
        bool arduino_is_available;
};
#endif // MAINWINDOW_H
