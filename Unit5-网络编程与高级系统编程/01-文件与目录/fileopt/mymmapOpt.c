/*************************************************************************
	> File Name: mymmapOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 26 Feb 2022 09:51:05 AM CST
 ************************************************************************/

#include"file.h"

int main(){


    int fd1 = open("test1.txt", O_RDWR);
    if(fd1 < 0){
        perror("OPEN");
        exit(1);
    }
    int *ptr1 = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd1, 0);
    if(ptr1 == NULL){
        perror("MMAP");
        exit(1);
    }
    printf("ptr1 = %p\n", ptr1);
    ptr1[0] = 0x11232425;
    munmap(ptr1, 6);
    close(fd1);

    return 0;
}
