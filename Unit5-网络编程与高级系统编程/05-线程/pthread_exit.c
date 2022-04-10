/*************************************************************************
	> File Name: pthread_exit.c
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

void *thr_fn1(void *);
void *thr_fn2(void *);
void *thr_fn3(void *);


void *thr_fn1(void *arg){
    printf("thread 1 returning\n");
    return (void *)1;
}

void *thr_fn2(void *arg){
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
    return NULL;
}

void *thr_fn3(void *arg){
    //printf("thread 3 canceling\n");

    while(1){
        printf("thread 3 is sleeping\n");
        sleep(1);
    }

    return NULL;
}
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


    pthread_t tid;
    void *sts;
    pthread_create(&tid, NULL, thr_fn1, NULL); // CLICK  3 + K, goto man 3 xxx
    pthread_join(tid, &sts);
    printf("thread 1 exit code %ld\n", ((long)sts));

    pthread_create(&tid, NULL, thr_fn2, NULL); // CLICK  3 + K, goto man 3 xxx
    pthread_join(tid, &sts);
    printf("thread 2 exit code %ld\n", ((long)sts));
    
    pthread_create(&tid, NULL, thr_fn3, NULL); // CLICK  3 + K, goto man 3 xxx
    sleep(1);
    pthread_cancel(tid);
    pthread_join(tid, &sts);
    printf("thread 3 exit code %ld\n", ((long)sts));
    /*
    if(ret){
        printf("create thread err:%s\n", strerror(ret)); // according to errno, return errinfo
        //perror("pthread_create");
        exit(1);
    }
    */

    

    
    sleep(1);

    return 0;
}
