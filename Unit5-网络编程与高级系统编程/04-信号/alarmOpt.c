/*************************************************************************
	> File Name: raiseOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Mar 2022 10:41:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(){



    alarm(5);

    sleep(3);
    unsigned int left = alarm(5);
    printf("left = %ld\n", left);
    sleep(100);



    return 0;
}
