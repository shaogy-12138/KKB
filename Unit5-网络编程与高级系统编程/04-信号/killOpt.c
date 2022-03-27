/*************************************************************************
	> File Name: killOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Mar 2022 10:22:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>



int main(void){


    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }

    if(pid){
    
        sleep(3);
        if(kill(pid, SIGQUIT) < 0){
            perror("kill");
            exit(1);
        }

        int sts;
        wait(&sts);

        if(WIFSIGNALED(sts)){
            printf("child killed by signal %d\n", WTERMSIG(sts));
        }else{
            printf("child exit other reason\n");
        }

    }else{

        while(1){
            printf("child sleep one second\n");
            sleep(1);
        }
    }


    return 0;
}
