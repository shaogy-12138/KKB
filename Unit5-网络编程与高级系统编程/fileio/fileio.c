/*************************************************************************
	> File Name: fileio.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Tue 22 Feb 2022 11:54:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv){

    
    if(argc < 2){
        printf("usage: cmd filename\n");
        return -1;
    }
    
    
    int fd1 = open(argv[1], O_WRONLY | O_CREAT, 0644);// 普通模式下按k可以查看open帮助手册
    //int fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);// 普通模式下按k可以查看open帮助手册
    if(fd1 < 0){
        perror("OPEN1");
        exit(-1);
    }else 
        printf("fd1 = %d\n", fd1);
     

    int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);// 普通模式下按k可以查看open帮助手册
    //int fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);// 普通模式下按k可以查看open帮助手册
    if(fd2 < 0){
        perror("OPEN2");
        exit(-1);
    }else  
        printf("fd2 = %d\n", fd2);
    close(fd1);
    int fd3 = open(argv[3], O_WRONLY | O_CREAT, 0644);// 普通模式下按k可以查看open帮助手册
    //int fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);// 普通模式下按k可以查看open帮助手册
    if(fd3 < 0){
        perror("OPEN3");
        exit(-1);
    }else 
        printf("fd3 = %d\n", fd3);
    

    close(fd2);
    close(fd3);

    return 0;
}
