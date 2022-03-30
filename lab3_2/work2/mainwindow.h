#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int gpio_set_value(unsigned int pin,unsigned value){
        string filename = "/sys/class/gpio/gpio" + to_string(pin) + "/value";
        fstream gpio;
        gpio.open(filename,ios::out);
        if(!gpio.is_open()){
            return 0;
        }
        else{
            gpio << value;
            return 1;
        }
    }

private slots:

    void on_switchbutton_clicked();

    void on_shinebutton_clicked();

    void update();

    void on_horizontalSlider_valueChanged(int value);

    void on_switchbutton_off_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *cout = new QTimer();
    int LEDswitch,t = 0;
    int che = 1;
};

#endif // MAINWINDOW_H
