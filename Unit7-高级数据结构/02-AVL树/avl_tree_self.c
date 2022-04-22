/*************************************************************************
	> File Name: avl_tree_self.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 22 Apr 2022 01:14:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max(a, b) (a > b ? a: b)
typedef struct Node{
    int val, h;
    struct Node *left, *right;
}Node;


#define NIL (&__NIL)

Node __NIL;
__attribute__((constructor))
void init(){
    NIL->val = -1;
    NIL->h = 1;
    NIL->left = NIL->right = NIL;
    return;
}

// 1. 创建节点
Node *getNode(int target){

    Node *p = (Node *)malloc(sizeof(Node));
    p->val = target;
    p->h = 1;
    p->left = p->right = NIL;

    return p;
}

// 2. 回收树
void clear(Node *root){
    if(root == NIL) return ;
    clear(root->left);
    clear(root->right);
    free(root);
    return;
}
// 3. 更新树高
void update_h(Node *root){
    if(root == NIL) return ;
    int l = root->left->h;
    int r = root->right->h;
    // 树高 = max(左子树树高， 右子树树高) + 1；
    root->h = max(l, r) + 1;
    return ;
}
// 4. 旋转
Node *left_r(Node *root){
    Node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    update_h(root);
    update_h(tmp);
    return tmp;

}
Node *right_r(Node *root){
    Node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    update_h(root);
    update_h(tmp);
    return tmp;
}

const char*str[5] = {"", "LL", "LR", "LR", "RR"};
int main_type = 0;
Node *maintain(Node *root){
    if(abs(root->left->h - root->right->h) <= 0) return root;
    if(root->left->h > root->right->h){
        // 左子树高于右子树 =》LL / LR
        if(root->left->right->h > root->left->left->h){
            // LR
            root->left = left_r(root->left);
            main_type = 2;
        }else{
            main_type = 1;
        }
        // LL
        root = right_r(root);
    }else{
        if(root->right->left->h > root->right->left->h){
            // RL
            root->right = right_r(root->left);
            main_type = 3;
        }else{
            main_type = 4;
        }
        // RR
        root = left_r(root);
    }

    printf("%s type \n", str[main_type]);
    return root;
}
// 5. 节点插入
Node *insert(Node *root, int target){
    if(root == NIL) return getNode(target);
    if(root->val == target) return root;
    if(root->val > target){
        // 根节点值 > 目标值 ， 在左子树查找
        root->left = insert(root->left, target);
    }else{
        root->right = insert(root->right, target);
    }

    update_h(root);
    return maintain(root);
}

// 6. 查找 
int search(Node *root, int target){
    if(root == NIL) return 0;
    if(root->val == target) return 1;
    if(root->val > target){
        return search(root->left, target);
    }else{
        return search(root->right, target);
    }
}

// 7. 获取前驱节点- 前一个节点
Node *getPreNode(Node *root){
    // 左子树的最右边的节点是根节点前一个节点
    Node *tmp = root->left;
    while(tmp->right != NIL){
        tmp = tmp->right;
    }

    return tmp;
}

// 8. 获取后继节点 - 后一个节点
Node *getNextNode(Node *root){
    Node *tmp = root->right;
    while(tmp != NIL && tmp->left != NIL){
        tmp = tmp->left;
    }

    return tmp;
}

// 9. 删除一个节点
Node *erase(Node *root, int target){
    if(root == NIL) return NIL;
    if(root->val > target){
        root->left = erase(root->left, target);
    }else if(root->val < target){
        root->right = erase(root->right, target);
    }else{
        if(root->left == NIL || root->right == NIL){
            Node *tmp = (root->left != NIL)? root->left : root->right;
            //free(root);
            return tmp;
        }else{
            Node *nextNode = getNextNode(root);
            root->val = nextNode->val;
            root->right = erase(root->right, nextNode->val);
        }

    }
        return root;
}

// 10. 遍历
void in_order(Node *root){
    if(root == NIL) return;

    in_order(root->left);
    printf("[%d:%d (%d, %d)]\n", root->val, root->h, root->left->val, root->right->val);
    in_order(root->right);

    return;
}


int main(void){
    
    srand(time(0));

    Node *root = NIL;

    int i = 10;
    while(i--){
        int data = rand() % 100;
        root = insert(root, data);
        in_order(root);
        printf("\n\n");
    }

    int n = 0;
    while((scanf("%d", &n) != EOF)){
        erase(root, n);
        in_order(root);
        printf("\n\n");
    }


    return 0;
}
