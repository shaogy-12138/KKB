/*************************************************************************
	> File Name: pipe.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 21 Mar 2022 10:39:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void){


    pid_t pid;
    int fd[2];
    char buf[20];
    int n;
    
    // 管道建立
    if(pipe(fd) < 0){
        perror("pipe");
        exit(1);
    }
   
    // 进程创建
    pid_t p = fork();
    if(p < 0){
        perror("fork");
        exit(1);
    }


    // 父进程关闭 读， 写信息， 然后等待
    // 子进程关闭 写， 读信息， 然后输出
    if(p > 0){
        close(fd[0]);
        write(fd[1], "hello pipe\n", 11);
        close(fd[1]);
        wait(NULL);
    }else{
        close(fd[1]);
        sleep(1);
        n = read(fd[0], buf, 20);
        write(1, buf, n);
        printf("%d\n", n);
        n = read(fd[0], buf, 20);
        write(1, buf, n);
        printf("%d\n", n);

    }

    return 0;
}
