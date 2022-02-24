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


    if(argc < 3){
        printf("usage: cmd src dir");
        return -1;
    }

    FILE * fp1 = fopen(argv[1], "r");
    if(!fp1){
        perror("open file1");
        exit(-1);
    }
    FILE * fp2 = fopen(argv[2], "w");

    if(!fp2){
        perror("open file2");
        exit(-1);
    }


    char c;
    while((c = fgetc(fp1)) != EOF){
        fputc(c, fp2);
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}
