/*************************************************************************
	> File Name: MyBtree.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 14 Mar 2022 11:58:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COLOR(a, b) "\033[" #b "m" #a "\033[0m"
#define GREEN(a)    COLOR(a, 32)

// 1. 结构定义
typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree{
    Node *root;
    int length;
}Tree;

// 2. 结构操作
// 2.1 GetNewNode
Node *getNewNode(int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->lchild = node->rchild = NULL;
    return node;
}

// 2.2 GetNewTree
Tree *getNewTree(){
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->length = 0;
    tree->root = NULL;
    return tree;
}

// 2.3 clear_node
void clear_node(Node *n){
    if(n == NULL) return;
    clear_node(n->lchild);
    clear_node(n->rchild);
    free(n);
    return ;
}

// 2.4 clear 
void clear(Tree *t){
    if(t == NULL) return;
    clear_node(t->root);
    free(t);
    return;
}

// 2.5 insert_node
Node *insert_node(Node *n, int val, int *flag){
    if(n == NULL){
        flag++;
        return getNewNode(val);
    }
    if(n->data == val) return n;
    if(n->data > val){
        n->lchild = insert_node(n->lchild, val, flag);
    }else{
        n->rchild = insert_node(n->rchild, val, flag);
    }

    return n;
}

// 2.6 insert 
void insert(Tree *t, int val){
    if(t == NULL) return;
    int flag = 0;
    t->root = insert_node(t->root, val, &flag);
    t->length += flag;
    return ;
}

// 2.7 先序遍历（中左右）
void pre_order_mode(Node *n){
    if(n == NULL) return;
    printf("%d ", n->data);
    pre_order_mode(n->lchild);
    pre_order_mode(n->rchild);
    return;
}
// 2.8 中序遍历（左中右）
void mid_order_mode(Node *n){
    if(n == NULL) return ;
    mid_order_mode(n->lchild);
    printf("%d ", n->data);
    mid_order_mode(n->rchild);
    return;
}

// 2.9 后序遍历（左右中）
void post_order_mode(Node *n){
    if(n == NULL) return ;
    mid_order_mode(n->lchild);
    mid_order_mode(n->rchild);
    printf("%d ", n->data);
    return;
}

void pre_mid_post_order(Tree *t){
    if(t == NULL) return;
    printf("Pre_order: ");
    pre_order_mode(t->root);
    printf("\n");
    printf("Mid_order: ");
    mid_order_mode(t->root);
    printf("\n");
    printf("Post_order: ");
    post_order_mode(t->root);
    printf("\n");
    return ;
}

// 2.10 广义表输出
void output_node(Node *n){
    if(n == NULL) return ;
    printf("%d", n->data);
    if(n->lchild == NULL && n->rchild == NULL) return;
    printf("(");
    output_node(n->lchild);
    printf(", ");
    output_node(n->rchild);
    printf(")");
    return;
}


void output(Tree *t){
    if(t == NULL) return;
    printf("tree[%d]: ", t->length);
    output_node(t->root);
    printf("\n");
    return ;
}


int main(void){
    
    int i = 0;
    srand(time(0));
    Tree *t = getNewTree();
    #define MAX_N 10
    for(i = 0; i < MAX_N; i++){
        int val = rand() % 100;
        printf("\nInsert [%d] to Tree.\n", val);
        insert(t, val);
        pre_mid_post_order(t);
        output(t);
        printf(GREEN("============================================"));
    }
    #undef MAX_N
    clear(t);
    return 0;
}
