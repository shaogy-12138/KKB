/*************************************************************************
	> File Name: 2.std.c
	> Author: Jason.shao
	> Mail: 
	> Created Time: Mon 21 Feb 2022 10:48:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>


int main(){
    
    printf("%d \n", STDIN_FILENO);
    printf("%d \n", STDOUT_FILENO);
    printf("%d \n", STDERR_FILENO);
    return 0;
}
