/*************************************************************************
	> File Name: Btree.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 13 Mar 2022 07:33:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



#define COLOR(a, b)    "\033[" #b "m" #a "\033[0m"
#define RED(a)      COLOR(a, 31)
#define GREEN(a)    COLOR(a, 32)


typedef struct Node{

    int data;
    struct Node *lchild, *rchild;
}Node;


typedef struct Tree{
    Node *root;
    int length;
}Tree;


Node *getNewNode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree(){
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    t->length = 0;
    return t;
}

void clear_node(Node *node){
    if(node == NULL) return;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return;
}

void clear(Tree *tree){
    if(tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return ;
}

// 二叉排序树。 定义一种性质，维护此性质
//
Node *insert_node(Node *root, int val, int *flag){
    if(root == NULL){
        *flag = 1;
        return getNewNode(val);

    }
    if(root->data == val) return root;
    if(root->data > val) root->lchild = insert_node(root->lchild, val, flag);
    else root->rchild = insert_node(root->rchild, val, flag);
    return root;
}
void insert(Tree *t, int val){
    if(t == NULL) return;
    int flag = 0;
    t->root = insert_node(t->root, val, &flag);
    t->length += flag;
    return ;
}

void pre_order_node(Node *node){
    if(node == NULL) return;
    printf("%d ", node->data);
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
    return;
}
void in_order_node(Node *node){
    if(node == NULL) return;
    pre_order_node(node->lchild);
    printf("%d ", node->data);
    pre_order_node(node->rchild);
    return;
}
void post_order_node(Node *node){
    if(node == NULL) return;
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
    printf("%d ", node->data);
    return;
}
void pre_order(Tree *t){
    if(t == NULL) return;
    printf("pre_order: ");
    pre_order_node(t->root);
    printf("\n");
    return ;
}
void in_order(Tree *t){
    if(t == NULL) return;
    printf("in_order: ");
    in_order_node(t->root);
    printf("\n");
    return ;
}
void post_order(Tree *t){
    if(t == NULL) return;
    printf("post_order: ");
    post_order_node(t->root);
    printf("\n");
    return ;
}

void output_node(Node *node){
    if(node == NULL) return;
    printf("%d", node->data);
    if(node->lchild == NULL  && node->rchild == NULL) return;
    printf("(");
    output_node(node->lchild);

    printf(",");
    output_node(node->rchild);
    printf(")");
    return;

}
void output(Tree *tree){
    if(tree == NULL) return;
    printf("tree(%d) : ", tree->length);
    output_node(tree->root);
    printf("\n");
    return;

}
int main(){

    #define MAX_N 20 

    srand(time(0));
    Tree *tree = getNewTree();
    int i;
    for(i = 0; i < MAX_N; i ++){
        int val = rand() % 100;
        int op = rand() % 4;
        insert(tree, val);
        output(tree);
    }

    pre_order(tree);
    in_order(tree);
    post_order(tree);
    #undef MAX_N
    clear(tree);
    return 0;
}
