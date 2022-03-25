#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
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
    printf("Be fine.");
    cout->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_switchbutton_clicked()
{
    int cou = ui->input_text->text().toInt();
    t = cou*2;
    LEDswitch = 0;
}
void MainWindow::update(){
    QLabel *LED_arr[] = {ui->LED1,ui->LED2,ui->LED3,ui->LED4};
    printf("%d",t);
    if(t == 0){
        for(int i = 0;i < 4;i++){
            LED_arr[i]->hide();
        }
        ui->checkBox_1->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);
        return;
    }
    else if(LEDswitch == 0){
        LEDswitch = 1;
        LED_arr[0]->show();
        LED_arr[1]->show();
        LED_arr[2]->hide();
        LED_arr[3]->hide();
        ui->checkBox_1->setChecked(true);
        ui->checkBox_2->setChecked(true);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);
        t--;
    }
    else if(LEDswitch == 1){
        LEDswitch = 0;
        LED_arr[0]->hide();
        LED_arr[1]->hide();
        LED_arr[2]->show();
        LED_arr[3]->show();
        ui->checkBox_1->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(true);
        ui->checkBox_4->setChecked(true);
        t--;
    }

}

void MainWindow::on_shinebutton_clicked()
{
    bool b1 = ui->checkBox_1->checkState();
    bool b2 = ui->checkBox_2->checkState();
    bool b3 = ui->checkBox_3->checkState();
    bool b4 = ui->checkBox_4->checkState();
    bool b_arr[] = {b1,b2,b3,b4};
    QLabel *LED_arr[] = {ui->LED1,ui->LED2,ui->LED3,ui->LED4};
    for(int i = 0;i < 4;i++){
        if(b_arr[i]){
            LED_arr[i]->show();
        }
        else{
            LED_arr[i]->hide();
        }
    }
}


