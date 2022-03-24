/*************************************************************************
	> File Name: lseek.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Feb 2022 11:44:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>


int main(){


    off_t offset;
    int fd = open("./hello.txt", O_RDONLY);
    if(fd < 0){
        perror("OPEN");
        exit(-1);
    }
    char c;
    read(fd, &c, 1);
    write(STDOUT_FILENO, &c, 1);

    offset = lseek(fd, 3, SEEK_SET);
    printf("offset = %d\n", offset);


    close(fd);
    return 0;
}
