/*************************************************************************
	> File Name: ListQuene.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 05 Mar 2022 04:32:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>




typedef struct Node{

    int data;
    struct Node *next;
}Node;

typedef struct Quene{
    Node head, *tail;
    int length;
}Quene;

Node *getNewNode(int);
Quene *init_quene();
void clear_node(Node *);
void clear(Quene *);
int empty(Quene *);
int push(Quene *, int);
int pop(Quene * );
int front(Quene *);
void outpur(Quene *);


Node *getNewNode(int val){
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Quene *init_quene(){
    Quene *q = (Quene *)malloc(sizeof(Quene));
    q->head.next = NULL;
    q->tail = &(q->head);
    q->length = 0;
    return q;
}

int empty(Quene *q){
    return q->tail;
    //return q->length == 0;
}

int push(Quene *q, int val){
    if(q == NULL) return 0;
    Node *temp = getNewNode(val);
    q->tail->next = temp;
    q->tail = temp;
    q->length ++;
    return 1;
}

int pop(Quene *q){
    if(q == NULL) return 0;
    if(empty(q)) return 0;
    Node * temp = q->head.next;
    q->head.next = temp->next;
    clear_node(temp);
    q->length -= 1;
    if(q->length == 0) q->tail = &(q->head);
    return 1;
}
void clear_node(Node *n){
    if(n == NULL) return ;
    free(n);
    return ;
}



void clear(Quene *q){
    if(q == NULL) return ;
    Node *p = q->head.next, *temp;
    while(p != NULL){
        temp= p->next;
        clear_node(p);
        p = temp;
    }

    free(q);
    return ;
}


void outpur(Quene *q){
    if(q == NULL) return ;
    printf("Quene(%d):[ ", q->length);
    Node *p = q->head.next;
    for(; p!= NULL; p = p->next){
        (p != q->head.next) && printf(", ");

        printf("%d", p->data);
    }

    printf("]\n");
    return ;
}
int main(){
    srand(time(0));
    Quene *q = init_quene();
    #define MAX_N 20

    int i;
    for(i = 0; i < MAX_N; i++){
        int op = rand() % 4;
        int val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("push %d to the Quene[%d]\n", val, push(q, val));
            }break;
            case 3:{
                if(!empty){
                    printf("pop a val from Quene[%d]\n", pop(q));
                }
            }break;
        }

        outpur(q);
    }
    #undef MAX_N
    clear(q);
    return 0;
}
