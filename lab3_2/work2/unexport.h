#include<iostream>
#include<string.h>
#include<fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>

int gpio_unexport(unsigned int gpio){
	int fd, len;
	char buf[64];
	
	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if(fd<0){
		perror("gpio/unexport");
		return fd;
	}
	len = snprintf(buf,sizeof(buf),"%d",gpio);
	write(fd,buf,len);
	close(fd);
	return 0;
}
