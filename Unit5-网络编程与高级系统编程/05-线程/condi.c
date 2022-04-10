/*************************************************************************
	> File Name: condi.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 10 Apr 2022 04:08:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<time.h>
#include<unistd.h>

typedef struct Goods{
    int data;
    struct Goods *next;
}Goods;


Goods *head = NULL;
pthread_mutex_t headlock =  PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t hasGoods =  PTHREAD_COND_INITIALIZER;
void *producer(void *arg){

    Goods *ng;
    while(1){

        ng = (Goods *) malloc(sizeof(Goods));
        ng->data =rand()%100;



        pthread_mutex_lock(&headlock);
        // 头插法
        ng->next = head;
        head = ng;

        pthread_mutex_unlock(&headlock);
        //pthread_cond_signal(&hasGoods);
        pthread_cond_broadcast(&hasGoods);
        printf("produce %d \n", ng->data);
        sleep(rand()%3);
    }


    return NULL;

}


void *consumer(void *arg){
    Goods *k;
    while(1){

        pthread_mutex_lock(&headlock);
        while(!head){
            pthread_cond_wait(&hasGoods, &headlock);
        }
        k = head;
        head = head->next;
        pthread_mutex_unlock(&headlock);
        printf("consume %d\n", k->data);
        free(k);
        sleep(rand()%2);

    }

    return NULL;
}
int cnt = 0;
pthread_cond_t  add_lock = PTHREAD_MUTEX_INITIALIZER;

void *cntadd(void *arg){
    int val;
    int i;



    for(i = 0; i < 5000; i++){
        pthread_mutex_lock(&add_lock);
        val = cnt;
        printf("%p: %d\n", pthread_self(), val);
        cnt = val + 1;
        pthread_mutex_unlock(&add_lock);
    }

    return NULL;
}

int main(void){

    srand(time(0));

    pthread_t tid_p, tid_c, tid_c_1, tid_c_2, tid_c_3;
    pthread_create(&tid_p, NULL, producer, NULL);
    pthread_create(&tid_c, NULL, consumer, NULL);
    pthread_create(&tid_c_1, NULL, consumer, NULL);
    pthread_create(&tid_c_2, NULL, consumer, NULL);
    pthread_create(&tid_c_3, NULL, consumer, NULL);

    pthread_join(tid_p, NULL);
    pthread_join(tid_c, NULL);
    pthread_join(tid_c_1, NULL);
    pthread_join(tid_c_2, NULL);
    pthread_join(tid_c_3, NULL);


    return 0;
}
