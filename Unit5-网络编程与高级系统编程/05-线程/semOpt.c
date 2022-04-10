/*************************************************************************
	> File Name: semOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 10 Apr 2022 06:22:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>


#define NUM  5
int q[NUM]; // 未初始化的全局变量是0

sem_t blank_number, goods_number;

void *producer(void *arg){

    int i = 0;
    while(1){
        sem_wait(&blank_number);
        q[i] = rand()%100 + 1;
        printf("produce %d\n", q[i]);
        sem_post(&goods_number);
        i = (i + 1)%NUM;
        sleep(rand()%3);
    }


    return NULL;
}

void *consumer(void *argg){


    int i = 0;
    while(1){
        sem_wait(&goods_number);
        printf("consume %d\n", q[i]);
        q[i] = 0;
        sem_post(&blank_number);
        i = (i + 1)%NUM;
        sleep(rand()%3);
    }

    return NULL;
}


int main(void){

    srand(time(0));

    sem_init(&blank_number, 0, NUM);
    sem_init(&goods_number, 0, 0);

    pthread_t pid, cid;
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);


    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}

