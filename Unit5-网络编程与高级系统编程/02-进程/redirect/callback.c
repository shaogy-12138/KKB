/*************************************************************************
	> File Name: callback.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 21 Mar 2022 08:59:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char *argv[]){


    if(argc < 2){
        printf("%d\n", argc);
        printf("usage: cmd + file\n");
        return 1;
    }

    // 1. 输入重定向： 将标准输入 0 重定向到文件 argv[1]
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        perror("open");
        exit(1);
    }

    dup2(fd, 0); // 重定向: 将0 重定向 到 fd
    close(fd); // 关闭文件
    
    
    // 2. 输出重定向： 将标准输出重定向到argv[2]
    int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if(fd2 < 0){
        perror("open");
        exit(1);
    }

    dup2(fd2, 1); // 重定向
    close(fd2);
    
    // 3. 
    execl("./upper", "./upper", NULL); // 调度exec函数运行， 这里的意思是运行./upper , ./upper为命令， NULL表示命令行参数终止了  execl(命令， 命令， 参数1， 参数2， ... ， NULL)

    perror("execl");
    exit(1);
    
    
    
    return 0;
}
