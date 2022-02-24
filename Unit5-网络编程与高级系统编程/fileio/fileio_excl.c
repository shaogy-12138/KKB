/*************************************************************************
	> File Name: fileio_trunc.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Feb 2022 01:22:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>


int main(int argc, char *argv[]){

    if(argc < 2){
        printf("usage: cmd filename\n");
        exit(-1);
    }

    int fd = open(argv[1], O_RDONLY | O_CREAT | O_EXCL, 0644);

    if(fd < 0){
        perror("OPEN");
        exit(-1);
    }

    printf("fd = %d\n", fd);
    close(fd);

    return 0;
}
