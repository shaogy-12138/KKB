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
        printf("usage: cmd src dir");
        return -1;
    }

    FILE * fp1 = fopen(argv[1], "r+");
    if(!fp1){
        perror("open file1");
        exit(-1);
    }


    fseek(fp1, 0, SEEK_END);
    printf("file length = %d\n", ftell(fp1));
    rewind(fp1);
    fputc('a', fp1);
    fputc('b', fp1);
    fputc('X', fp1);
    fputc('Y', fp1);
   
    printf("current = %d\n", ftell(fp1));
    fseek(fp1, 0, SEEK_SET);
    printf("current = %d\n", ftell(fp1));
    fputc('y', fp1);
    fputc('X', fp1);
    fseek(fp1, -3, SEEK_END); 
    printf("current = %d\n", ftell(fp1));
    char c;
    //while((c = fgetc(fp1)) != EOF){
      //  putchar(c);
    //}
    
    fclose(fp1);
    //fclose(fp2);
    return 0;
}
