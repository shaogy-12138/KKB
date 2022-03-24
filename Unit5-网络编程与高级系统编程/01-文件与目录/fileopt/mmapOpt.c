/*************************************************************************
	> File Name: mmapOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 25 Feb 2022 11:13:47 PM CST
 ************************************************************************/

#include"file.h"
#include<sys/mman.h>
int main(){
    
    int fd = open("test.txt", O_RDWR);
    if(fd < 0){
        perror("open");
        exit(-1);
    }

    int *p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    //p[0] = 0x30313233;//前四个字节数据进行修改
   ((int *)(((char *)p) + 1))[0] = 0x01020304;
    munmap(p, 6);
    return 0;
}

