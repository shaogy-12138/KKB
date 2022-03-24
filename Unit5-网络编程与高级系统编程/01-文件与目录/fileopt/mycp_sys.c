/*************************************************************************
	> File Name: mycp_sys.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Feb 2022 11:42:14 AM CST
 ************************************************************************/

#include"file.h"


int main(int argc, char *argv[]){

    if(argc < 2){
        printf("usage: cmd src dst\n");
        exit(-1);
    }

    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 < 0){
        perror("open source file");
        exit(-1);
    }

    int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if(fd2 < 0){
        perror("open dst file");
        close(fd1);
        exit(-1);
    }

    char buf[1024] = {0};
    ssize_t count;
    while((count = read(fd1, buf, sizeof(buf))) > 0){
        write(fd2, (const char*)buf, count);
    }
    

    return 0;
}
