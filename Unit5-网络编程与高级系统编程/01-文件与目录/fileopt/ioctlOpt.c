/*************************************************************************
	> File Name: ioctlOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Feb 2022 09:44:44 PM CST
 ************************************************************************/

#include"file.h"


int main(void){


    struct winsize size;

    if(!isatty(1)){
        printf("is not tty\n");
        exit(1);
    }

    if(ioctl(1, TIOCGWINSZ, &size) < 0){
        perror("ioctl");
        exit(1);
    }

    printf("%d rows, %d colums\n", size.ws_row, size.ws_col);

    return 0;
}
