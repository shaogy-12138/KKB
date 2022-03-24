/*************************************************************************
	> File Name: fcntlGet.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Feb 2022 12:19:59 AM CST
 ************************************************************************/

#include"file.h"

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("usage: cmd fd\n");
        return -1;
    }


    int flags;
    if((flags = fcntl(atoi(argv[1]), F_GETFL)) < 0){
        perror("fcntl get flags");
        exit(-1);
    }


    switch(flags & O_ACCMODE){
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read and only");
            break;
        default:
            printf("not read or only");
    }

    if(flags & O_APPEND){
        printf(", append\n");
    }
    if(flags & O_NONBLOCK){
        printf(", nonblock\n");
    }
    putchar(10);
    printf("flags = %#x\n", flags);
    printf("O_RDONLY = %#x\n", O_RDONLY);
    printf("O_WRONLY = %#x\n", O_WRONLY);
    printf("O_RDWR = %#x\n", O_RDWR);
    printf("O_CREAT = %#x\n", O_CREAT);
    printf("O_APPEND = %#x\n", O_APPEND);
    printf("O_NONBLOCK = %#x\n", O_NONBLOCK);
    printf("O_EXCL = %#x\n", O_EXCL);
    printf("O_TRUNC = %#x\n", O_TRUNC);
    printf("O_ACCMODE = %#x\n", O_ACCMODE);//访问权限



    return 0;
}
