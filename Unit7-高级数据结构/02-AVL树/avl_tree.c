/*************************************************************************
	> File Name: avl_tree.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 20 Apr 2022 10:54:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define max(a, b) (a > b ? a : b)
typedef struct Node{
    int val, h;
    struct Node *rchild, *lchild;
}Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL(){
    NIL->val = -1;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *getNode(int target){
    
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = target;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void clear(Node *root){
    if(root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

int search(Node *root, int target){

    if(root == NIL) return 0;
    if(root->val == target) return 1;
    if(root->val > target){
        return search(root->lchild, target);
    }else{
        return search(root->rchild, target);
    }

}

void update_h(Node *root){
    root->h = max(root->lchild->h, root->rchild->h) + 1;
    return ;
}

Node *left_rotate(Node *root){

    printf("[left rotate] %d\n", root->val);
    Node *tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;

    update_h(root);
    update_h(tmp);

    return tmp;
}

Node *right_rotate(Node *root){

    printf("[right rotate] %d\n", root->val);
    Node *tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;

    update_h(root);
    update_h(tmp);
    return tmp;
}

const char* maintian_str[5] = {"","LL", "LR", "RL", "RR"};
Node *maintain(Node *root){
    int maintain_type = 0;
    if(abs(root->lchild->h - root->rchild->h) <= 1) return root;
    if(root->lchild->h > root->rchild->h){
            // left child tree is higher than right L*

        if(root->lchild->rchild->h > root->lchild->lchild->h){
            // LR
            root->lchild = left_rotate(root->lchild);
            maintain_type = 2;
        }else{
            maintain_type = 1;
        }
        root = right_rotate(root);
    }else{
        // right child tree is higher than left R*
        if(root->rchild->lchild > root->rchild->rchild){
            root->rchild = right_rotate(root->rchild);
            maintain_type = 3;
        }else{
            maintain_type = 4;
        }
        root = left_rotate(root);
    }

    printf("[AVL maintain_type: %s] \n", maintian_str[maintain_type]);
    return root;
}
Node *insert(Node *root, int target){
    if(root == NIL) return getNode(target);
    if(root->val == target) return root;
    if(root->val > target){
        root->lchild = insert(root->lchild, target);
    }else{
        root->rchild = insert(root->rchild, target);
    }

    update_h(root);
    return maintain(root);

}

Node *get_pre(Node *root){
    Node *tmp = root->lchild;
    while(tmp->rchild != NIL){
        tmp = tmp->rchild;
    }
    return tmp;

}
Node *erase(Node *root, int target){

    if(root == NIL) return root;
    if(root->val > target){
        root->lchild = erase(root->lchild, target);
    }else if(root->val < target){
        root->rchild = erase(root->rchild, target);
    }else{
        if(root->lchild == NIL || root->rchild == NIL){
            Node *tmp = (root->lchild != NIL)? root->lchild:root->rchild;
            free(root);
            return tmp;
        }else{
            Node *preNode = get_pre(root);
            root->val  = preNode->val;
            root->lchild = erase(root->lchild, preNode->val);
        }
    }

    update_h(root);
    return maintain(root);
}

void in_order(Node *root){
    if(root == NIL) return;
    printf("(%d:%d)[%d, %d]\n", root->val, root->h, root->lchild->val, root->rchild->val);
    in_order(root->lchild);
    in_order(root->rchild);

    return;
}
int main(){


    srand(time(0));

    Node *root = NIL;
    int i = 10;
    while(i--){
        int data = rand() % 100;
        root = insert(root, data);
        printf("%d ", data);
    }

    printf("\n");

    in_order(root);printf("\n");

    

    return 0;
}
