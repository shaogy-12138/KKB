/*************************************************************************
	> File Name: enOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 14 Mar 2022 10:01:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){

    printf("path value = [%s]\n", getenv("PATH"));
   
    setenv("PATH", "HELLO", 1); //这里修改的是子进程a.out的环境变量PATH， zsh的环境变量不受其影响

    printf("path value = [%s]\n", getenv("PATH"));
    return;
}
