/*************************************************************************
	> File Name: listTable.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Feb 2022 03:22:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include"../COLOR.h"
#include<stdlib.h>
#include<time.h>

// 1. 结构定义

// 节点定义
typedef struct Node{  
    int data;
    struct Node *next;
}Node;

typedef struct List{  
    int length;
    Node head; //采用定义虚拟头节点
}List;


Node *getNewNode(int);
List *init_list();
void clear_node(Node *);
void clear(List *);
int insert(List *, int, int);
int erase(List *, int);
void output_list(List *);



Node *getNewNode(int val){  
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}
    
List *init_list(){       
    List *l = (List *)malloc(sizeof(List));
    l->length = 0;
    l->head.next = NULL;   
    return l;
}

void clear_node(Node *n){
    if(n == NULL) return;
    free(n);
    return ;
}

void clear(List *l){
    if(l == NULL) return ;
    Node *p = l->head.next, *q;
    while(p != NULL){
        q = p->next;
        clear_node(p);
        p = q;
    }

    free(l);
    return ;
}

int insert(List *l, int ind, int val){
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *node = getNewNode(val);
    
    int i;
    while(ind --){
        p = p->next;
    }

    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;

}

int erase(List *l, int ind){
    if(l == NULL) return 0;
    if(ind < 0 || ind >= l->length) return 0;
    Node *p = &(l->head), *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);

    l->length -= 1;
    return 1;

}


void reverse(List *l){
    if(l == NULL) return ;
    Node *p = l->head.next, *q;
    l->head.next = NULL;
    while(p != NULL){
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return;

}

void output_list(List *l){

    if(l == NULL) return ;
    printf("List(%d): ", l->length);
    Node *p = (l->head.next);
    while(p != NULL){
        printf("%d->", p->data);
        p = p->next;
    }

    printf("NULL\n\n");
    return ;
}
int main(void){

    srand(time(0)); //以当前时间作为随机种子
    List *l = init_list();
    #define MAX_OP 20
    int i;
    for(i = 0; i < MAX_OP; i++){
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        int op = rand() % 4;

        printf("op = %d, ind = %d, val = %d \n", op, ind, val);
        switch(op){
            case 0:
                reverse(l);
                printf("reverse List\n");
                break;
            case 1:
            case 2:
                printf("Inser %d at %d to List [%d]\n", val, ind, insert(l, ind, val));
                break;
            case 3:
                printf("erase a item at %d [%d]\n", ind, erase(l, ind));
                break;
        }
        output_list(l);
    }

    #undef MAX_OP

    clear(l);

    return 0;
}
