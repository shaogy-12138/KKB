/*************************************************************************
	> File Name: dirOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 05 Mar 2022 05:19:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<unistd.h>

void printfDir(const char *);
int main(int argc, char *argv[]){

    if(argc < 2){
        printf("ysage: cmd filename\n");
        exit(1);
    }
    printfDir(argv[1]);
    return 0;
}

void printfDir(const char *dirname){
    struct stat st;
    DIR *dir;
    struct dirent *dp;
    char pathname[1024] = {0};
    
    dir = opendir(dirname);
    if(dir == NULL){
        perror("Open dir");
        exit(1);
    }

    while((dp = readdir(dir))){
        if((!strcmp(dp->d_name, ".")) || (!strcmp(dp->d_name, ".."))){
            continue;       
        }
        sprintf(pathname, "%s/%s", dirname, dp->d_name);
        int flag = stat(pathname, &st);
        if(flag < 0){
            perror("stat");
            exit(1);
        }
        if(S_ISDIR(st.st_mode)){
            printfDir(pathname);
        }

        printf("%s\t", pathname);
    
    }

    putchar(10);
    closedir(dir);

}
