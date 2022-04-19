/*************************************************************************
	> File Name: binary_search_tree.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 13 Apr 2022 11:14:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



typedef struct Node{

    int data;
    struct Node *lchild, *rchild;
}Node;


Node *getNewNode(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int target){

    if(root == NULL) return getNewNode(target);

    if(root->data == target) return root;
    if(root->data > target){
        root->lchild =  insert(root->lchild, target);
    }else{
        root->rchild = insert(root->rchild, target);
    }

    return root;
}

void clear(Node *root){
    if(root==NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

int search(Node *root, int target){

    if(root == NULL) return 0;
    if(root->data == target) return 1;
    if(root->data > target){
        return search(root->lchild, target);
    }else{
        return search(root->rchild, target);
    }
}

Node *predecessor(Node *root){
    // 获取前驱节点
    Node *p = root ->lchild;
    while(p != NULL && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}
Node *erase(Node *root, int target){
    if(root == NULL) return root;
    if(root->data > target){
        // 当前节点值 > 待删除值， 待删除值存在的节点在当前节点的左边
        root->lchild = erase(root->lchild, target);
    }else if(root->data < target){
        root->rchild = erase(root->rchild, target);
    }else{
        if(root->rchild == NULL && root->lchild == NULL){
            // 叶子节点直接删除
            free(root);
            return NULL;
        }else if(root->lchild == NULL || root->rchild == NULL){
            // 度为一的节点，与叶子节点交换后删除
            Node *tmp = root->lchild != NULL ? root->lchild:root->rchild;
            free(root);
            return tmp;
        }else{
            Node *tmp = predecessor(root);
            root->data = tmp->data;
            root->lchild = erase(root->lchild, tmp->data);
        }
    }

    return root;

}

int find_k(Node *root, int k){
    if(root->rchild->size >= k){
        return find_k(root->rchild, k);
    }

    if(root->lchild->size + 1 == k){
        return root->data;
    }

    return find_k(root->lchild, k- root->rchild->size - 1);
}
void in_order(Node *root){
    if(root == NULL) return;
    in_order(root->lchild);
    printf("%d ", root->data);
    in_order(root->rchild);
    return ;
}
int main(){

    srand(time(0));

    Node *root = NULL;
    #define MAX_N 20 
    int i;
    for(i = 0; i < 20; i++){
        int val = rand()%100;
        root = insert(root, val);
        printf("%d ", val);
    }


    printf("\n");

    in_order(root);
    printf("\n");

    int n;
    while(scanf("%d", &n)!=EOF){
        printf("erase node is %d\n", n);

        root = erase(root, n);
        in_order(root); printf("\n");
        printf("erase successfully\n");
    }
    return 0;
}
