/*************************************************************************
	> File Name: fseek_opt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Feb 2022 09:57:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>



int main(int argc, char *argv[]){


    if(argc < 2){
        printf("usage: cmd filename");
        return -1;
    }

    FILE * fp = fopen(argv[1], "r");
    if(!fp){
        perror("open file");
        exit(-1);
    }


    char c;

    // 如果读到文件尾部， 返回-1 等价于EOF
    while( (c = fgetc(fp)) != EOF ){

        putchar(c);
        
    }
    fclose(fp);
    return 0;
}
