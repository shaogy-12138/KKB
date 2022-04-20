/*************************************************************************
	> File Name: binary_tree.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Tue 19 Apr 2022 08:07:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *lchild, *rchild;
    int val, size;
}Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL(){
    NIL->val = 0;
    NIL->size = 0;
    NIL->lchild = NIL;
    NIL->rchild = NIL;
}


// 1. get new node 
Node *getNewNode(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = key;
    p->size = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

// 2. clear Node
void *clear(Node *root){
    if(root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}


// 3. insert val 
Node *insert_node(Node *root, int key){
    if(root == NIL)  return getNewNode(key);
    if(root->val == key) return root;
    if(root->val > key){
        root->lchild = insert_node(root->lchild, key);
    }else{
        root->rchild = insert_node(root->rchild, key);
    }
    return root;
}

// 4. find pre node : the rightest node of lchild 
Node *preNode(Node *root){
    if(root == NIL) return root;

    Node *p = root->lchild;
    while(p != NIL && p->rchild != NIL){
        p = p->rchild;
    }

    return p;
}


// 5. find next node : the leftest node of rchild
Node *nextNode(Node *root){
    Node *p = root->rchild;
    while(p!=NIL && p->lchild != NIL){
        p = p->lchild;
    }
    return p;
}

// 6. search key whether in tree
int search(Node *root, int key){
    if(root == NIL) return 0;
    if(root->val == key) return 1;
    if(root->val > key){
        return search(root->lchild, key);
    }else{
        return search(root->rchild, key);
    }
}

// 7. erase a node 
Node *erase(Node *root, int key){
    if(root == NIL) return NIL;
    if(root->val > key){
        root->lchild = erase(root->lchild, key);
    }else if(root->val < key){
        root->rchild = erase(root->rchild, key);
    }else{
        if(root->lchild == NIL || root->rchild == NIL){
            Node *tmp = (root->lchild != NIL)?root->lchild : root->rchild;
            // free(root);
            return tmp;
        }else{
            Node *pn = preNode(root);
            root->val = pn->val;
            root->lchild = erase(root->lchild, pn->val);
        }
    }

    return root;
}

// 8. in_order output
void in_order(Node *root){
    if(root == NIL) return;

    in_order(root->lchild);
    printf("%d ", root->val);
    in_order(root->rchild);
    return;
}

int main(void){


    srand(time(0));

    Node *root = NIL;
    int i = 20;
    while(i--){
        int val = rand()%100;
        root = insert_node(root, val);
        printf("%d ", val);
    }
    printf("\n");

    in_order(root);printf("\n");

    int n;
    while((scanf("%d",&n)) != EOF){
        printf("[%d]\n", search(root, n));
        if(n == 99) break;
    }

    printf("erase\n");

    while((scanf("%d",&n)) != EOF){
        root = erase(root, n);
        in_order(root);
        if(n == 99) break;
    }


    return 0;
}
