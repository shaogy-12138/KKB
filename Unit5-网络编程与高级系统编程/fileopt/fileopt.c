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
    
    
    fputc('A', stdout);
    fputc('B', stdout);
    fputc('C', stdout);

    FILE *fp = fopen("./hellof.txt", "w");

    if(!fp){
        perror("open file");
        exit(-1);
    }
    fprintf(fp, "my age is %d\n", 10);
    fclose(fp);
    return 0;
}
