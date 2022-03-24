/*************************************************************************
	> File Name: upper.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 21 Mar 2022 08:52:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>

int main(void){


    int ch;
    while((ch = getchar()) != EOF){  // 等价于1. != -1, 2. ~ 按位取反
        putchar(toupper(ch));
    }
    
    return 0;
}
