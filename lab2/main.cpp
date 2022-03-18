#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
using namespace std;

#define LED1 393
#define LED2 389
#define LED3 398
#define LED4 427

int gpio_export(unsigned int pin){
    fstream gpio;
    gpio.open("/sys/class/gpio/export",ios::out);
    if(!gpio.is_open()){
        cout << "Export Fail! " << pin << endl;
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
        cout << "Export Fail! " << pin << endl;
        return 0;
    }
    else{
        gpio << pin;
        gpio.close();
        return 1;
    }
}

int gpio_set_dir(unsigned int pin,unsigned dir){
    string filename = "/sys/class/gpio/gpio" + to_string(pin) + "/direction";
    fstream gpio;
    gpio.open(filename,ios::out);
    if(!gpio.is_open()){
        cout << "Set Pin Dir Fail! " << endl;
        return 0;
    }
    else{
        gpio << dir;
        return 1;
    }
}

int gpio_set_value(unsigned int pin,unsigned value){
    string filename = "/sys/class/gpio/gpio" + to_string(pin) + "/value";
    fstream gpio;
    gpio.open(filename,ios::out);
    if(!gpio.is_open()){
        cout << "Set Pin Dir Fail! " << endl;
        return 0;
    }
    else{
        gpio << value;
        return 1;
    }
}


int main(int argc,char *argv[]){
    unsigned int arr[4] = {LED1,LED2,LED3,LED4};
    if(argc != 3){
        cout << "Input Fail!" << endl;
        return 1;
    }
    else{
        for(int i = 0;i < 4;i++){
            gpio_export(arr[i]);
            gpio_unexport(arr[i]);
        }
        string mode(argv[1]);
        if(mode == "Mode_shine"){
            unsigned int value = 1;
            for(int i = 0;i < stoi(argv[2]);i++){
                cout << value << " " << endl;
                gpio_set_value(LED1,value);
                gpio_set_value(LED2,value);
                gpio_set_value(LED3,!value);
                gpio_set_value(LED4,!value);
                value = !value;
                sleep(1);
            }
            gpio_set_value(LED1,0);
            gpio_set_value(LED2,0);
            gpio_set_value(LED3,0);
            gpio_set_value(LED4,0);
        }
        else if (mode.substr(0,3) == "LED"){
            unsigned int value;
            if(std::string(argv[2]) == "on"){
                value = 1;
            }
            else if (std::string(argv[2]) == "off"){
                value = 0;
            }
            else{
                cout << "undefine!!" << endl;
                return 0;
            }
            cout << "LED" << int(mode.at(3)-'1') << " is " << value << endl;
            gpio_set_value(arr[int(mode.at(3)-'1')],value);
        }
        else{
            cout << "no function!" << endl;
        }

    }
    return 0;
}
