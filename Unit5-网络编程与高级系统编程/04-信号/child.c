/*************************************************************************
	> File Name: child.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 30 Mar 2022 10:52:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/typedef.h>
#include<sys/wait.h>
void sig_child(int signo){

    int sts;

    wait(&sts);

    if(WIFEXITED(sts)){
        printf(" exit wirth code %d\n", sts);
    }else{
        printf("Lemon\n", WEXITSTATUS(sts));
    }
    return ;
}
int main(void){


    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }


    if(pid){
        struct sigaction newact, oldact;
        newact.sa_halder =sig_child;
        sigempty(&newact.sa_mask);
        newact.sa_flags = 0;
        sigaction(SIGCHLD, &newact, &oldact);

        int n = 10;
        while(n--){
            printf("work sometime\n");
            sleep(1);
        }

    }else{

        sleep(3);
        exit(2);
    }
    return 0;
}
