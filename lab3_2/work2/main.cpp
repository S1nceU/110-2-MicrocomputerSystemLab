#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
using namespace std;

#define LEDA 393
#define LEDB 389
#define LEDC 398
#define LEDD 427

int gpio_export(unsigned int pin){
    fstream gpio;
    gpio.open("/sys/class/gpio/export",ios::out);
    if(!gpio.is_open()){
        return 1;
    }
    else{
        gpio << pin;
        gpio.close();
        return 0;
    }
}

int gpio_unexport(unsigned int pin){
    fstream gpio;
    gpio.open("/sys/class/gpio/export",ios::out);
    if(!gpio.is_open()){
        return 0;
    }
    else{
        gpio << pin;
        gpio.close();
        return 1;
    }
}

int main(int argc, char *argv[])
{
    unsigned int arr[4] = {LEDA,LEDB,LEDC,LEDD};
    for(int i = 0;i < 4;i++){
                gpio_export(arr[i]);
                gpio_unexport(arr[i]);
            }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
