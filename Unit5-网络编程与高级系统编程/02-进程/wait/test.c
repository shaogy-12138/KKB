/*************************************************************************
	> File Name: wait.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 21 Mar 2022 09:43:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>





int main(void){
    
    pid_t pid = fork();
    if(pid<0){
        perror("fork");
        exit(1);
    }

    if(pid){
        while(1){
            sleep(1);
        }
    }else{
        exit(3);
    }

    return 0;
}
