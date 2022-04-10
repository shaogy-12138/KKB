/*************************************************************************
	> File Name: pthreadOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 07 Apr 2022 11:14:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

void *thr_fn(void *);
void printid(char *);
void printid(char *tip){
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("%s pid:%u tid:%u (%p)\n", tip, pid, tid, tid );
}

void *thr_fn(void *arg){
    // to 
    //
    printid(arg);
    return NULL;
}

int main(void){


    pthread_t ntid;
    int ret;
    ret = pthread_create(&ntid, NULL, thr_fn, "new thread"); // CLICK  3 + K, goto man 3 xxx

    if(ret){
        printf("create thread err:%s\n", strerror(ret)); // according to errno, return errinfo
        //perror("pthread_create");
        exit(1);
    }

    
    sleep(2);
    printid("maint thread");

    return 0;
}
