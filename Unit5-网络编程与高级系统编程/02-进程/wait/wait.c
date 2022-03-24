/*************************************************************************
	> File Name: wait.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 21 Mar 2022 10:05:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(void){


    pid_t pid = fork();  // 创建n进程
    if(pid < 0){
        perror("fork");
        exit(1);
    }

    if(pid == 0){
        // 子进程 
        int n = 5;
        while(n){
            printf("this is child process~, %d\n", getpid());
            sleep(5);
            n--;
        }

        exit(3); // 退出状态码
    }else{
        int stat_val;
        waitpid(pid, &stat_val, 0); // 等待子进程退出， 状态存储在stat_val
        if(WIFEXITED(stat_val)){
            printf("Child exit  with code %d\n", WEXITSTATUS(stat_val));
        }else if(WIFSIGNALED(stat_val)){
            printf("child terminated abnormally , signal %d\n", WTERMSIG(stat_val));
        }
    }



    return  0;
}
