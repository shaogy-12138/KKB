/*************************************************************************
	> File Name: nonBlockRead.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Feb 2022 09:27:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>


int main(void){


    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);

    if(fd < 0){
        perror("OPEN /dev/tty");
        exit(-1);
    }

    int count = 10;
    ssize_t n;
    char buf[10];
    while(count > 0){

        n = read(fd, buf, 10);
        if(~n){
            printf("read %d bytes\n", n);
            write(STDOUT_FILENO, buf, n);
            putchar(10);
            break;
        }
        if(errno != EAGAIN){
            perror("READ /dev/tty");
            exit(-1);
        }
        write(STDOUT_FILENO, "try, tyr again?", 16);
        putchar(10);
        count--;
        sleep(1);
    }
    close(fd);
    return 0;
}
