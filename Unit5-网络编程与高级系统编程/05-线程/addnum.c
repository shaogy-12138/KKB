/*************************************************************************
	> File Name: addnum.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 10 Apr 2022 04:08:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>


int cnt = 0;

void *cntadd(void *arg){
    int val;
    int i = 5000;
    for(i; i>0; i--){
        val = cnt;
        printf("%p: %d\n", pthread_self(), val);
        cnt = val + 1;
    }

    return NULL;
}

int main(void){


    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, cntadd, NULL);
    pthread_create(&tid2, NULL, cntadd, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
