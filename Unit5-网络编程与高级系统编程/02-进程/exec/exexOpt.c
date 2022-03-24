/*************************************************************************
	> File Name: exexOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 14 Mar 2022 10:21:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    execlp("ls", "ls", "-a", "-l", NULL);

    perror("exec");
    return 0;
}
