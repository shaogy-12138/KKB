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



    int pdf[2];

    if(pipe(pdf) < 0){
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }


    if(pid){

        close(pfd[0]);
        close(pfd[1]);

        int sts;
        wait(&sts);

        if(WIFSIGNALED(sts)){
            printf("signal = %d\n", WTERMSIG(sts));
        }else{
            printf("exit ohter ways\n");
        }
    }else{
        sleep(3);
        close(pfd[0]);
        write(pdf[1], "hello\n", 6);
        sleep(10);
    }
    return 0;
}
