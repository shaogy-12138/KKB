/*************************************************************************
	> File Name: 01.orderlist.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 25 Feb 2022 09:01:30 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m]"
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
// 结构定义
typedef struct Vector{
    int size, length;
    int *data;
}Vec;

// 结构操作

// 1. 初始化生成顺序表
Vec * init(int n){
    Vec *v = (Vec *)malloc(sizeof(Vec));//malloc开辟的内存在堆区 ； 动态申请 - 主动释放（free）
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;

    return v;
}

// 2.顺序表销毁
void clear(Vec *v){
    if(v == NULL) return ;
    free(v->data);
    free(v);
    return;
}


// 5.顺序表扩容
int expand(Vec *v){
    int sz = v->size;
    int *p;
    while(sz){
        p = (int *)realloc(v->data, (v->size + sz) * sizeof(int));
        if(v != NULL){
            v->data = p;
            v->size += sz;
            return 1;
        }
        sz /= 2;
    }
    return 0;
}

// 3.插入元素
int insert(Vec *v, int ind, int val){
    if(v == NULL) return 0;
    if(ind < 0 || ind > v->length) return 0;
    if(v->length == v->size) {
        if(!expand(v)) {
            printf(RED("Failed to expand\n"));
            return 0;
        }
        printf(GREEN("Success to expand\n"));
    }

    int i;
    for(i = v->length; i > ind; i--){
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

// 4. 删除元素
int erase(Vec *v, int ind){
    if(v == NULL) return 0;
    if(ind < 0 || ind >= v->length) return 0;

    int i;
    for(i = ind + 1; i < v->length; i++){
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
    
}



void output(Vec *v){
    if(v == NULL) return;
    int i;
    printf("[");
    for(i = 0; i < v->length; i++){
        i && printf(" ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return;
}

int main(){
    #define MAX_N 30
    Vec *v = init(1);
    srand(time(0));
    int i;
    for(i = 0; i < MAX_N; i++){
        int op = rand() % 4;
        int ind = rand() % (v->length + 3) - 1;
        int val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:
                printf("insert %d at %d to Vec: %d\n", val, ind, insert(v, ind, val));
                break;
            case 3:
                printf("erase a item at %d: %d\n", ind, erase(v, ind));
                break;
        }
        output(v);
    }
    #undef MAX_N
    clear(v);
    return 0;
}
