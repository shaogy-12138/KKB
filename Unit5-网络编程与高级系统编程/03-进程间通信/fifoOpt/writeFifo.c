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


    int fd = open("./tube", O_WRONLY);
    if(fd < 0){
        perror("open");
        exit(1);
    }
    write(fd, "hello FIFO\n", 12);

    close(fd);
    return 0;
}
