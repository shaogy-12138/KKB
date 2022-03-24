/*************************************************************************
	> File Name: readFifo.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Tue 22 Mar 2022 09:48:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>


int main(void){


    int fd = open("./tube", O_RDONLY);
    if(fd < 0){
        perror("open");
        exit(1);
    }


    perror("open");
    char buf[20] = {0};
    ssize_t n = read(fd, buf, 20);
    printf("read %d bytes\n", n);
    write(1, buf, 20);

    close(fd);
    return 0;
}
