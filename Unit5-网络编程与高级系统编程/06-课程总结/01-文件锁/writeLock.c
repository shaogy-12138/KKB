/*************************************************************************
	> File Name: writeLock.c
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


    int fd = open("./test.txt", O_WRONLY);

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
    while(fcntl(fd, F_SETLK, &lock) < 0){
        perror("fcntl");

        struct flock lockinfo;
        lockinfo = lock;
        lockinfo.l_type = F_WRLCK;
        fcntl(fd, F_GETLK, &lockinfo);
        switch(lockinfo.l_type){
            case F_UNLCK:
            printf("get no lock\n"); 
            break;
            case F_RDLCK:{
                printf("get read lock of pid = %d\n", lockinfo.l_pid);
            }break;
            case F_WRLCK:{
                printf("get write lock of pid = %d\n", lockinfo.l_pid);
            }break;
        }


        sleep(1);
    }

    printf("set write lock successfully\n");
    getchar();
    
    close(fd);

    return 0;
}
