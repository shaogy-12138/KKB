/*************************************************************************
	> File Name: quick_aligo.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 20 Mar 2022 03:54:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}


typedef struct UnionSet{
    int *father, *size;
    int n;
}UnionSet;



UnionSet *init(int n){
    UnionSet *u = (UnionSet *) malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1)); // 默认将0的位置空出来
    u->size = (int *)malloc(sizeof(int) * (n + 1)); // 默认将0的位置空出来
    int i = 1;
    for(; i < n; i ++){
        u->father[i] = i;
        u->size[i] = 1;
    }
    u->n = n;
    return u;
}
// 路径压缩
int find(UnionSet *u, int x){
   if(u->father[x] == x) return x;
    return u->father[x] = find(u, u->father[x]);
}

int merge(UnionSet *u, int a, int b){
    int fa = find(u, a), fb = find(u, b);
    if(fa == fb) return 0;
    if(u->size[fa] < u->size[fb]) swap(fa, fb);
    u->father[fb] = fa;
    u->size[fa] += u->size[fb];
    
    return 1;
}
void clear(UnionSet *u){
    if(u == NULL) return ;
    free(u->father);
    free(u->size);
    free(u);
    return;
}

int main(){


    int n, m;
    scanf("%d%d", &n, &m);
    int i;
    UnionSet *u = init(n);
    for(i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        switch(a){
            case 1:{
                merge(u, b, c);
            }break;
            case 2:{
                printf("%s\n", find(u, b) == find(u, c) ? "Yes": "No");
            }break;
        }
    }

    clear(u);
    return 0;
}
