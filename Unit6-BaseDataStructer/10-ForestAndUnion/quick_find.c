/*************************************************************************
	> File Name: quick_aligo.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 20 Mar 2022 03:54:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct UnionSet{
    int *color;
    int n;
}UnionSet;



UnionSet *init(int n){
    UnionSet *u = (UnionSet *) malloc(sizeof(UnionSet));
    u->color = (int *)malloc(sizeof(int) * (n + 1)); // 默认将0的位置空出来
    int i = 1;
    for(; i < n; i ++){
        u->color[i] = i;
    }
    u->n = n;
    return u;
}

int find(UnionSet *u, int x){
    return u->color[x];
}

int merge(UnionSet *u, int a, int b){
    if(find(u, a) == u->color[b]) return 0;
    int color_a = u->color[a];
    int i;
    for(i = 1; i <= u->n; i++){
        if(u->color[i] - color_a) continue;
        u->color[i] = u->color[b];
    }
}
void clear(UnionSet *u){
    if(u == NULL) return ;
    free(u->color);
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
