/*************************************************************************
	> File Name: 1.hello.c
	> Author: Jason.shao
	> Mail: 
	> Created Time: Mon 21 Feb 2022 10:27:01 PM CST
 ************************************************************************/

#include<stdio.h>


int main(){

    int i;
    // 利用循环测试行缓冲触发：缓冲区满触发
    for(i = 0; i < 1025; i++){

        fputc('A', stdout);//stdout就是标准输出(屏幕)
    }
    // stdout 默认位行缓冲：遇到换行触发
    //fputc('A', stdout);//stdout就是标准输出(屏幕)
    //fputc('\n', stdout);// 本环境默认为行缓冲，如果不加换行，A不会输出

    // strerr 为无缓冲，可以直接输出
    //fputc('a', stderr);
    //fputc('b', stderr);
    //fputc('c', stderr);
    while(1){
        ;
    }
    
    return 0;
}
