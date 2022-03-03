/*************************************************************************
	> File Name: stack.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 04 Mar 2022 12:01:39 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COLOR(a, b) "\033[" #b "m" #a "\033[0m"
#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
typedef struct stack{
    int size, top;
    int *data;
}Stack;


Stack *init(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int * )malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1; //top始终指向栈顶元素，最开始空栈没有元素，因此指向-1
    return s;
}

void clear(Stack *s){
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return;
}

int expand(Stack *s){
    if(s == NULL) return 0;
    int sz = s->size, *t;
    while(sz){
        t = (int *)realloc(s->data, sizeof(int) * ((s->size) + sz));
        if(t != NULL){
            s->data = t;
            s->size += sz;
            return 1;
        }
        sz >>= 1;
    }

    return 0;
}
int top(Stack *s){ //获取栈顶元素
    return s->data[s->top];
}

int empty(Stack *s){
    return (s->top == -1);
}

int push(Stack *s, int val){
    if(s == NULL) return 0;
    if(s->top == s->size -1){
        if(!expand(s)){
            printf("-----------------expand failed!!!--------------\n");
            return 0;
        }
        printf("**************expand successfuli, new stack[%d] *****************\n", s->size);
    }
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s){
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void output(Stack *s){
    if(s == NULL) return;
    printf("Stack[%d]:[ ", (s->top) + 1);

    int i = 0;
    for(; i <= (s->top); i++){
        (i) && printf(" ");
        printf("%d", s->data[i]);
    }

    printf(" ]\n");
    return;
}
int main(){

    #define MAX_N 20
    srand(time(0));
    int i;
    Stack *s = init(5);
    for(i = 0; i < MAX_N; i++){
        int op = rand() % 4;
        int val = rand() % 100;
        switch(op){
            case 1:
            case 2:
            case 0:{
                printf(RED("Push %d to stack [%d]\n"), val, push(s, val));
            }break;
            case 3:{
                if(!empty(s)){
                    printf(GREEN("Pop %d  from stack [%d]\n"), top(s), pop(s));
                }
            }break;
        }
        output(s), printf("\n");
    }

    #undef MAX_N
    clear(s);

    return 0;
}
