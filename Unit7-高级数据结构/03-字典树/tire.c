/*************************************************************************
	> File Name: tire.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 23 Apr 2022 09:54:01 PM CST
 ************************************************************************/
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define base 26

typedef struct Node{
    int flag;
    struct Node *next[base]; // [0]->a [1]->b
}Node;


Node *getNode(){
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(Node *)* base);
    return p;
}

void clear(Node *root){

    if(root == NULL) return ;
    int i= 0;
    for(; i < base; i++){
        clear(root->next[i]);
    }

    free(root);
    return ;
    
}

void insert(Node *root, const char *str){
    Node *p = root;
    int i = 0;
    for(; str[i]; i++){
        int ind = str[i] - 'a';
        if(p->next[ind] == NULL) p->next[ind] = getNode();
        p = p->next[ind];
    }

    p->flag = 1;
    return ;
}


int find(Node *root, const char*str){
    Node *p = root;
    int i = 0;
    for(; str[i]; i++){
        int ind = str[i] - 'a';
        p = p->next[ind];
        if(p == NULL) return 0;
    }
    return p->flag;
}

void ouput(Node *root, int k, char*buf){
    if(root == NULL) return ;
    buf[k] = '\0';
    if(root->flag){
        printf("%s\n", buf);
    }
    int i = 0;
    for(; i < base; i++){
        buf[k] = 'a' + i;
        ouput(root->next[i],k+1, buf);
    }
}
int main(){

    int op;
    char str[100];
    Node *root = getNode();
    while((scanf("%d", &op) != EOF)){
        switch(op){

            case 1:{scanf("%s", str);
                   printf("inser %s to tire\n", str);
                   insert(root, str);}break;
            case 2:{
                scanf("%s", str);
                printf("find %s in tire = %d\n", str, find(root, str));
            }break;
            case 3:{
                char buf[100];
                ouput(root, 0, buf);
            }break;
        }
    }

    clear(root);
    return 0;
}
