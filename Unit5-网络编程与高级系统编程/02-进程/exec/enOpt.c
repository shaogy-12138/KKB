/*************************************************************************
	> File Name: enOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 14 Mar 2022 10:01:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(void){

    extern char **environ;
    int i;
    for(i = 0; environ[i]; i++){
        printf("%s\n", environ[i]);
    }

    return;
}
