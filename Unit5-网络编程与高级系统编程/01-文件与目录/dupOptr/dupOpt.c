/*************************************************************************
	> File Name: dupOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 05 Mar 2022 07:31:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>


int main(){

    int fd, save_fd;
    fd = open("test.txt", O_RDWR);
    if(fd < 0){
        perror("OPEN");
        exit(1);
    }

    save_fd = dup(1);

    dup2(fd, 1);
    close(fd);
    write(1, "hello", 6);
    dup2(save_fd, 1);
    write(1, "hello", 6);
    close(save_fd);

    return 0;
}
