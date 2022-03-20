/*************************************************************************
	> File Name: TableToBtree.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Tue 15 Mar 2022 11:36:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COLOR(a, b)  "\033[" #b "m" #a "\033[m"
#define RED(a)   COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
char *str = "A(B(,D),C(E,))";
int   flag, l, r;

// 1. 栈
typedef struct Stack{
    Node **node;
    int length, count, top;
}Stack;

typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree{
    Node *root;
    int length;
}Tree;

// 1 .栈操作
Stack *init(int);
void clear_stack(Stack *);
int Stack_is_empty(Stack *);
int expand(Stack *);
int push(Stack *, int);1
int front(Stack *);
void pop(Stack *);
void output();
int test();


// 2. 树操作
Node *create_node(int);
Tree *create_tree();
void clear_node(Node *);
void clear_tree(Tree *);
Node *insert_node(Node *, int, int *);
void insert(Tree *, int);
void pre_order_mode(Node *);
void mid_order_mode(Node *);
void post_order_mode(Node *);
void scan_tree(Tree *);
void output_node(Node *);
void output_tree(Tree *);
int test2();

int main(){

    Stack *s = init(strlen(str));
    Tree  *t = create_tree();
    int i;
    insert(t, str[0]);
    Node *temp = NULL, *p = NULL;
    for(i = 1; str[i]; i++){
        switch(str[i]){
            case '(':
            case ')':
            case ',':
            case ' ':
            default :
                temp = create_node(str[i]);
            if(!Stack_is_empty(s) && flag == 0){
                   
            }
        }
    }
    



    return 0;
}

int test2(){

    #define MAX_T 10 
    int i;
    Tree *t = create_tree();
    srand(time(0));
    for(i = 0; i < MAX_T; i++){
        int val = rand() % 100;
        insert(t, val);
        scan_tree(t);
        output_tree(t);
        printf("\n");
    }
    #undef MAX_T

    clear_tree(t);
    return 0;
}


Node *create_node(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->lchild = n->rchild = NULL;
    return n;
}
Tree *create_tree(){
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    t->length = 0;
    return t;
}

void clear_node(Node *n){
    /*
    * 
    * */
    if(n == NULL) return;
    if((n->lchild == NULL) && (n->rchild == NULL)){
        free(n);
        return;
    }
    clear_node(n->lchild);
    clear_node(n->rchild);
    free(n);
    return ;
}

void clear_tree(Tree *t){
    if(t == NULL) return;
    clear_node(t->root);
    free(t);
    return;
}
Node *insert_node(Node *n, int val, int *flag){
    if(n == NULL){
        *flag += 1;
        return create_node(val);
    }

    if(n->data == val) return n;
    if(n->data > val){
        n->lchild = insert_node(n->lchild, val, flag);
    }else{
        n->rchild = insert_node(n->rchild, val, flag);
    }
    return n;

}
void insert(Tree *t, int val){
    if(t == NULL) return ;
    int flag = 0;
    t->root = insert_node(t->root, val, &flag);
    t->length += flag;
    return;
}
void pre_order_mode(Node *n){
    if(n == NULL) return;
    //printf(GREEN("pre_order_mode: "));
    printf("%d ", n->data);
    pre_order_mode(n->lchild);
    pre_order_mode(n->rchild);
    return;

} 
void mid_order_mode(Node *n){
    if(n == NULL) return;
    mid_order_mode(n->lchild);
    printf("%d ", n->data);
    mid_order_mode(n->rchild);
    return;
}
void post_order_mode(Node *n){
    if(n == NULL)return;
    post_order_mode(n->lchild);
    post_order_mode(n->rchild);
    printf("%d ", n->data);
    return ;
}
void scan_tree(Tree *t){
    if(t == NULL) return;
    printf("Pre_order_mode: ");
    pre_order_mode(t->root);
    printf("\n");
    printf("mid_order_mode: ");
    mid_order_mode(t->root);
    printf("\n");
    printf("post_order_mode: ");
    post_order_mode(t->root);
    printf("\n");
    return;
}

void output_node(Node *n){
    if(n == NULL) return;
    printf("%d", n->data);
    if(n->lchild == NULL  && n->rchild == NULL) return;
    printf("(");
    output_node(n->lchild);
    printf(",");
    output_node(n->rchild);
    printf(")");
    return;
}
void output_tree(Tree *t){
    if(t == NULL) return;
    printf("Tree [%d]: ", t->length);
    output_node(t->root);
    return ;
}

Stack *init(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data  = (int *)malloc(sizeof(int) * n);
    s->length = n;
    s->count = 0;
    s->top = -1;
    return s;
}

int front(Stack *s){
    return s->data[top];
}
void clear_stack(Stack *s){
    if(s == NULL) return;
    free(s->data);
    free(s);
    return;
}

int Stack_is_empty(Stack *s){
    return s->count == 0;
}
int expand(Stack *s){
    int sz = s->length;
    while(sz > 0){
        int *tmp = (int *)realloc(s->data, sizeof(int) * (s->length + sz));
        if(tmp != NULL){
            s->length += sz;
            s->data = tmp;
            return 1;
        }
        sz /= 2;
    }

    return 0;
}
int  push(Stack *s, int val){
    if(s == NULL) return 0;
    if(s->count == s->length){
        if(!expand(s)){
            printf(RED("Expand error!\n"));
            return 0;
        }
        printf(GREEN("Expand Success!Current length = %d\n"), s->length);
    }
    
    s->data[++(s->top)] = val;
    s->count += 1;
    return 1;
}

void pop(Stack *s){
    if(s == NULL) return;
    if(Stack_is_empty(s)) return;

    s->top -= 1;
    s->count -= 1;
    return;
}

void output(Stack *s){
    if(s == NULL) return;
    printf("stack[%d]: ", s->length);
    int i;
    for(i = 0; i < s->count; i++){
        i &&printf(", ");
        printf("%d", s->data[i]);
    }
    return;
}


int test(){


    int i;
    srand(time(0));
    Stack *s = init(5);
    #define MAX_N 20 
    for(i = 0; i < MAX_N; i++){
        int opt = rand() % 4;
        int val = rand() % 100;
        switch(opt){
            case 0:
            case 1:
            case 2:{
                printf("Push [%d] to stack. [%d]\n", val, push(s, val));
            }break;
            case 3:{
                pop(s);
                printf("Pop a item from Stack.\n");
            }break;
        }

        output(s);
        printf("\n");
    }
    #undef MAX_N

    clear_stack(s);
    return;
}


