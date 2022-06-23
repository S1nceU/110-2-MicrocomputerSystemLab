#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

pthread_mutex_t mutex;

void gpio_export(unsigned int gpio) {
    int fp, l;
	char buf[64];
 
	fp = open("/sys/class/gpio/export", O_WRONLY);
	if (fp < 0) {
		perror("gpio/export");
		return;
	}
	l = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fp, buf, l);
	close(fp);
}
void gpio_unexport(unsigned int gpio) {
    int fp, l;
	char buf[64];
 
	fp = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fp < 0) {
		perror("gpio/export");
		return;
	}
 
	l = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fp, buf, l);
	close(fp);
}
void gpio_set_dir(unsigned int gpio, unsigned int direction) {
    int fp, l;
	char buf[64];
 
	l = snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio);
 
	fp = open(buf, O_WRONLY);
	if (fp < 0) {
		perror("gpio/direction");
		return;
	}
 
	if (direction) {
        write(fp, "out", 4);
    }
	else {
        write(fp, "in", 3);
    }
    close(fp);
}
void gpio_set_value(unsigned int gpio, unsigned int value) {
    int fp, l;
	char buf[64];
 
	l = snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value", gpio);
 
	fp = open(buf, O_WRONLY);
	if (fp < 0) {
		perror("gpio/set-value");
		return;
	}
 
	if (value) {
        write(fp, "1", 2);
    }
	else {
        write(fp, "0", 2);
    }
	close(fp);
}



int led_pin[2] = { 466, 392};
char statu[5];
char negative[5];
int shine_times;

void* LED1() {
    int value = statu[0] - '0';
    for (int i = 0; i < shine_times * 2; i++) {
        pthread_mutex_lock(&mutex);
        if (i % 2 == 0) {
            if (statu[0] == '0'){
                printf("Status: %c\n",statu[1]);
            }
            else{
                printf("Status: %s\n", statu);
            }
        } 
        else {
            if (negative[0] == '0'){
                printf("Status: %c\n",negative[1]);
            }
            else{
                printf("Status: %s\n", negative);
            }
        }
        gpio_set_value(466, value);
        printf("GPIO: 466 status: %d\n", value);
        if (value == 0){
            value = 1;
        }
        else if (value == 1){
            value = 0;
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    
    pthread_exit(NULL);
}

void* LED2() {
    int value = statu[1] - '0';
    for (int i = 0; i < shine_times * 2; i++) {
        pthread_mutex_lock(&mutex);
        gpio_set_value(392, value);
        printf("GPIO: 392 status: %d\n", value);
        if (value == 0){
            value = 1;
        }
        else if (value == 1){
            value = 0;
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    shine_times = argv[2][0] - '0';
    for (int i = 0; i < 2; i++) {
        statu[i] = argv[1][i];
        if (statu[i] == '0'){
            negative[i] = '1';
        }
        else if (statu[i] == '1'){
            negative[i] = '0';
        }
    }
    

    for (int i = 0; i < 2; i++) {
        gpio_export(led_pin[i]);
        gpio_set_dir(led_pin[i], 1);
    }

    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, 0);

    pthread_t pthreadList[2];
    pthread_create(&pthreadList[0], NULL, LED1, NULL);
    usleep(100);
    pthread_create(&pthreadList[1], NULL, LED2, NULL);
    usleep(100);

    for (int i = 0; i < 2; i++) {
        pthread_join(pthreadList[i], NULL);
    }

    for (int i = 0; i < 2; i++) {
        gpio_set_value(led_pin[i], 0);
        gpio_unexport(led_pin[i]);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}