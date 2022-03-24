/*************************************************************************
	> File Name: lseek.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Feb 2022 11:44:39 PM CST
 ************************************************************************/

#include"file.h"


int main(void){

    int fd = open("./hello.txt", O_RDONLY);
    if(fd < 0){
        perror("OPEN");
        exit(-1);
    }

    int flags;
    if((flags = fcntl(STDIN_FILENO, F_GETFL)) < 0){
        perror("fcntl set flags");
        exit(-1);
    }
    flags |= O_NONBLOCK;
    if((flags = fcntl(STDIN_FILENO, F_SETFL, flags)) < 0){
        perror("fcntl set flags");
        exit(-1);
    }
    

    char buf[10];
    ssize_t n ;
    while(1){
        n= read(0, buf, 5);
        if(n >= 0){
            break;
        }

        if(errno != EAGAIN){
            perror("read file");
            exit(-1);
        }
        
        write(1, "try, try again ?\n",17);
        sleep(1);

    }
    write(1, buf, n);
    

    
    close(fd);
    return 0;
}
