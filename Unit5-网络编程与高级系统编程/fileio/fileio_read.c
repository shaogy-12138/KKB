/*************************************************************************
	> File Name: fileio_read.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Feb 2022 01:03:55 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]){

    if(argc < 2){
        printf("usage: cmd filename\n");
        exit(-1);
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        perror("OPEN");
        exit(-1);
    }

    printf("fd = %d\n", fd);
    char buf[20] = {0};
    ssize_t count = read(fd, buf, 10);
    if(count < 0){
        perror("READ");
        exit(-1);
    }

    printf("count = %d\n", count);
    //printf("buf = %s\n", buf);

    int i;
    for(i = 0; i < count; i++){
        printf("%c", buf[i]);
    }
    printf("\n");
    
    char buf1[20] = {0};
    ssize_t count1 = read(fd, buf1, 10);
    if(count < 0){
        perror("READ");
        exit(-1);
    }

    printf("count1 = %d\n", count1);
    //printf("buf = %s\n", buf);

    for(i = 0; i < count1; i++){
        printf("%c", buf1[i]);
    }
    printf("\n");
    close(fd);


    return 0;
}
