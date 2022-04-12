/*************************************************************************
	> File Name: ttyOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Tue 12 Apr 2022 11:08:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){


    int fd = open("./1.txt", O_RDONLY);


    printf("fd %d: %s\n", 0, ttyname(0));
    printf("fd %d: %s\n", 1, ttyname(1));
    printf("fd %d: %s\n", 2, ttyname(2));
    printf("fd %d: %s\n", fd, ttyname(fd));
    

    close(fd);

    return 0;
}
