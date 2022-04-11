/*************************************************************************
	> File Name: readLock.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 11 Apr 2022 11:13:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>



int main(){


    int fd = open("./test.txt", O_RDONLY);

    if(fd<0){
        perror("open");
        exit(1);
    }

    struct stat sta;
    fstat(fd,&sta);


    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_pid = getpid();
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = sta.st_size;


    printf("pid : %d \n", lock.l_pid);
    if(fcntl(fd, F_SETLK, &lock) < 0){
        perror("fcntl");
        exit(1);
    }else{
        printf("add read lock successfully\n");
    }

    sleep(10);
    

    return 0;
}
