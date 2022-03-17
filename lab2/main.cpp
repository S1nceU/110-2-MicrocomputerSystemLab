#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
using namespace std;

#define led1 393
#define led2 389
#define led3 398
#define led4 427

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
    string filename = "/sys/class/gpio/gpio" + to_string(pin) + "/direction";
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
    unsigned int arr[4] = {led1,led2,led3,led4};
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
                gpio_set_value(led1,value);
                gpio_set_value(led2,value);
                gpio_set_value(led3,!value);
                gpio_set_value(led4,!value);
                value = !value;
                sleep(1);
            }
        }
        else if (mode.substr(0.3) == "LED"){
            unsigned int value;
            if(std::string(argv[2] == "on"){
                value = 1;
            }
            else{
                value = 0;
            }
            cout << value << " " << int(mode.at(3)-'1') << endl;
            gpio_set_value(arr[int(mode.at(3)-'1'],val);
        }
    }


    return 0;
}
