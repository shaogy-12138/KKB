/*************************************************************************
	> File Name: linkStack.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 17 Mar 2022 09:55:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
    int length;
}Stack;



Node *getNewNode(int);
Stack *init_stack();
void clear_node(Node *);
void clear(Stack *);
int empty(Stack *);
int push(Stack *, int);
int pop(Stack *);
int top(Stack *);
void output(Stack *);




int main(){

    #define MAX_N 20 
    Stack *s = init_stack();
    int i;
    for(i = 0; i < MAX_N; i++){
        int opt = rand() % 4;
        int val = rand() % 100;
        switch(opt){
            case 0:
            case 1:
            case 2:{
                printf("push %d to the Stack = %d\n", val, push(s, val));
            }break;
            case 3:{
                if(!empty(s)){
                    printf("pop %d from Stack = ", top(s));
                    printf("%d\n", pop(s));
                }
            }break;
        }

        output(s);
    }


    #undef MAX_N
    clear(s);
    return 0;


}

Node *getNewNode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Stack *init_stack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->length = 0;
    return s;
}

void clear(Stack *s){
    if(s == NULL) return;
    Node *p = s->top, *q;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }

    free(s);
    return;
}

int empty(Stack *s){
    return s->top == NULL;
}

int top(Stack *s){
    return s->top->data;
}

int push(Stack *s, int val){
    if(s == NULL) return 0;
    Node *p = getNewNode(val);
    p->next = s->top;  // 注意：1 <- 2 <- 3 <- top, 入栈时需要新的node指向3即 node->next = top, 然后 top再指向新的node top = node  
    s->top = p;
    s->length += 1;
    return 1;
}

int pop(Stack *s){
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    Node *p = s->top;
    s->top = p->next;
    free(p);
    s->length -= 1;
    return 1;
}

void output(Stack *s){
    if(s == NULL) return;

    printf("Stack[%d]: ", s->length);
    Node *p = s->top, *q;
    for(; p; p = p->next){
        p != s->top && printf(" ");
        printf("%d", p->data);
    }

    printf("\n");
    return ;
}





