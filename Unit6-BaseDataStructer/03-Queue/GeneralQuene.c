/*************************************************************************
	> File Name: Queue.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 28 Feb 2022 11:18:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//结构定义
//
typedef struct Quene{
    int length, head, tail;
    int *data;
}Quene;


Quene *init(int);
void clear(Quene *);
int push(Quene *, int);
int front(Quene *);
int pop(Quene *);
int empry(Quene *);
void output(Quene *);


int main(){


    #define MAX_N 20
    int i;
    srand(time(0));
    Quene *q = init(10);
    for(i = 0; i < MAX_N; i++){
        int op = rand() % 4;
        int val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("Push %d to Quene [%d]\n", val, push(q, val));
            }
            break;
            case 3:
                printf("Pop a val from Quene [%d]\n", pop(q));
                break;
        }
        output(q);
    }

    #undef MAX_N
    clear(q);
    return 0;
}

void output(Quene *q){
    if(q->head == q->tail) return;
    printf("[");

    int i = q->head;
    for(; i < q->tail; i++){
        (i != q->head) && printf(", ");
        printf("%d", q->data[i]);
    }
    
    printf("]\n");

}
Quene *init(int n){
    Quene *q = (Quene *)malloc(sizeof(Quene));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;
    return q;
}

void clear(Quene *q){
    if(q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int empry(Quene *q){
    return q->head == q->tail;
}

int front(Quene *q){
    return q->data[q->head];
}

int push(Quene *q, int val){
    if(q == NULL) return 0;
    if(q->tail == q->length) return 0;
    q->data[q->tail++] = val;
    return 1;
}

int pop(Quene *q){
    if(q == NULL) return 0;
    if(!empry(q)) return 0;
    q->head ++;
    return 1;


}
