/*************************************************************************
	> File Name: popen_close.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Tue 22 Mar 2022 09:25:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void){



    FILE *fp = popen("./1.sh ", "w"); // 参数1： 执行的命令   参数2：di'x 读写模式   参数1相当于fp 从fp读取，就是读参数1输出的内容； 写的话相当于将内容写到fp即参数1命令中
    if(fp == NULL){
        perror("poepn");
        exit(1);
    }

    fprintf(fp, "popenR.c\n");


    pclose(fp);

    return 0;
}
