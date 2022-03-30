#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
using namespace std;

#define LEDA 393
#define LEDB 389
#define LEDC 398
#define LEDD 427

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *LED_arr[] = {ui->LED1,ui->LED2,ui->LED3,ui->LED4};
    for(int i = 0;i < 4;i++){
        LED_arr[i]->hide();
    }
    connect(cout, SIGNAL(timeout()), this, SLOT(update()));
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_switchbutton_clicked()
{

    int progressBarValue = ui->progressBar->value();
    cout->stop();
    cout->start(1000 - 7 * progressBarValue);
}

void MainWindow::update(){
    QLabel *LED_arr[] = {ui->LED1,ui->LED2,ui->LED3,ui->LED4};
    if(LEDswitch == 0){
        LED_arr[0]->show();
        LED_arr[1]->show();
        LED_arr[2]->hide();
        LED_arr[3]->hide();
        ui->checkBox_1->setChecked(true);
        ui->checkBox_2->setChecked(true);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);

        gpio_set_value(LEDA,1);
        gpio_set_value(LEDB,1);
        gpio_set_value(LEDC,0);
        gpio_set_value(LEDD,0);
    }
    else if(LEDswitch == 1){
        LED_arr[0]->hide();
        LED_arr[1]->hide();
        LED_arr[2]->show();
        LED_arr[3]->show();
        ui->checkBox_1->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(true);
        ui->checkBox_4->setChecked(true);

        gpio_set_value(LEDA,0);
        gpio_set_value(LEDB,0);
        gpio_set_value(LEDC,1);
        gpio_set_value(LEDD,1);
    }
    LEDswitch = !LEDswitch;
}


void MainWindow::on_shinebutton_clicked()
{
    bool b1 = ui->checkBox_1->checkState();
    bool b2 = ui->checkBox_2->checkState();
    bool b3 = ui->checkBox_3->checkState();
    bool b4 = ui->checkBox_4->checkState();
    bool b_arr[] = {b1,b2,b3,b4};
    QLabel *LED_arr[] = {ui->LED1,ui->LED2,ui->LED3,ui->LED4};
    unsigned int gpio_arr[4] = {LEDA,LEDB,LEDC,LEDD};
    for(int i = 0;i < 4;i++){
        if(b_arr[i]){
            LED_arr[i]->show();
            gpio_set_value(gpio_arr[i],1);
        }
        else{
            LED_arr[i]->hide();
            gpio_set_value(gpio_arr[i],0);
        }
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(cout->isActive()){
        cout->stop();
        cout->start(1000 - 7 * value);
    }
}

void MainWindow::on_switchbutton_off_clicked()
{
    cout->stop();
}



