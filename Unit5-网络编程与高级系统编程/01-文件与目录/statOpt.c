/*************************************************************************
	> File Name: statOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 26 Feb 2022 12:30:58 AM CST
 ************************************************************************/

#include "../file.h"

int main(int argc, char *argv[]){

    struct stat st;
    if(argc < 2){
        printf("usage: cmd filename\n");
        exit(1);
    }

    stat(argv[1], &st);
    if(S_ISDIR(st.st_mode)){
        printf("is dir\n");
    }else{
        printf("is other file\n");
    }

    switch(st.st_mode & S_IFMT){
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFDIR:
            printf("dir file\n");
            break;
        case S_IFCHR:
            printf("char  file\n");
            break;
        default:
            printf("other file type\n");
    }

    return 0;
}
