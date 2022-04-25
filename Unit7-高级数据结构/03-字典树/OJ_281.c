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
#define maxn 1000000

//const int maxn = 1000000;
char str1[maxn];


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

    p->flag += 1;
    return ;
}


int find(Node *root, const char*str){
    Node *p = root;
    int ans = 0;
    int i = 0;
    for(; str[i]; i++){
        int ind = str[i] - 'a';
        p = p->next[ind];
        if(p == NULL) return ans;
        ans += p->flag;
    }
    
    return ans;
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

    Node *root = getNode();
    int n, m;
    scanf("%d %d", &n, &m);
    int i;
    for(i = 0; i < n; i++){
        scanf("%s", str1);
        insert(root,str1);
    }

    for(i = 0; i < m; i ++){
        scanf("%s", str1);
        printf("%d\n", find(root, str1));
    }
    
    
    clear(root);
    return 0;
}
