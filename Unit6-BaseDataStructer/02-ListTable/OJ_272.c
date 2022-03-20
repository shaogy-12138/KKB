/*************************************************************************
	> File Name: doubleList.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 17 Mar 2022 10:36:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



typedef struct Node{
    int data;
    struct Node *pre, *next;
}Node;

typedef struct DList{
    Node head;
    int length;
}Dlist;
// 插入删除避免出现内存泄露的结果


Node *getNewNode(int);
Dlist *init_list();
void clear(Dlist *);
int insert(Dlist *, int, int);
int delete(Dlist *, int);
void output(Dlist *);


int arr[100005], ans, p;

int main(){

    int i, n;
    scanf("%d", &n);
    Dlist *dl = init_list();
    
    clear(dl);
    return 1;
}

Node *getNewNode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p-> pre = p->next = NULL;
    return p;
}

Dlist *init_list(){
    Dlist *dl = (Dlist *)malloc(sizeof(Dlist));
    dl->head.next = dl->head.pre = NULL;
    dl->length = 0;
    return dl;
}

void clear(Dlist *dl){
    if(dl == NULL) return;
    Node *p = dl->head.next, *q;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }

    free(dl);
    return ;
}

int insert(Dlist *dl, int ind, int val){
    if(dl == NULL) return 0;
    if(ind < 0 || ind > dl->length) return 0;
    Node *tmp = getNewNode(val), *p = &(dl->head);
    
    while(ind--) p = p->next;

    if(p->next == NULL){
        p->next = tmp;
        tmp->pre = p;
    }else{
        tmp->next = p->next;
        tmp->pre = p;
        p->next = tmp;
        tmp->next->pre = tmp;
    }
    
    dl->length += 1;
    return 1;
}

int delete(Dlist *dl, int ind){
    if(dl == NULL) return 0;
    if(ind < 0 || ind >= dl->length) return 0;

    Node *p = dl->head.next, *q;
    while(ind--) p = p->next;
    
    q = p->pre;
    if(p->next == NULL){
        q->next = NULL;
        // free(q);
        dl->length -= 1;
    }else{
        q->next = p->next;
        p->next->pre = q;
        dl->length -= 1;
    }
    return 1;
}

void output(Dlist *dl){
    if(dl == NULL) return;
    printf("DList [%d]: ", dl->length);
    Node *p = dl->head.next;
    for(;p; p = p->next){
        p != dl->head.next && printf(" ");
        printf("%d", p->data);
    }
    printf("\n");
    return;
}
