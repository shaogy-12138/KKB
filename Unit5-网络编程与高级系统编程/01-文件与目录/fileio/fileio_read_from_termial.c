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

    char buf[20] = {0};
    int n;
    //n = read(STDIN_FILENO, buf, 10);
    n = read(STDIN_FILENO, buf, 10);
    if(n < 0){
        perror("READ");
        exit(-1);
    }

    printf("read %d bytes\n", n);
    
    write(STDOUT_FILENO, buf, strlen(buf));
    /*int i;
    for(i = 0; i < n; i++){
        printf("%c", buf[i]);
    }
    putchar(10); // 相当于printf("\n");
    */

    return 0;
}
