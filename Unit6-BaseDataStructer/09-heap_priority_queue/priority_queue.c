/*************************************************************************
	> File Name: priority_queue.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 19 Mar 2022 09:07:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define swap(a, b) {\
                   __typeof(a) __temp = a;\
                   a = b; b = __temp;\
                   }
// 1. 树形结构（较浪费空间）
//
// 2. 数组结构/顺序表结构实现
//


typedef struct priority_queue{
    int *data;
    int cnt, size;
}priority_queue;

// 当前维护一个大顶堆
priority_queue *init(int n){
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

void clear(priority_queue *q){
    if(q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int empty(priority_queue *q){
    return q->cnt == 0;
}

int push(priority_queue *q, int val){
    if(q == NULL) return 0;
    if(q->cnt == q->size)return 0; // 入堆需要判满
    q->data[++(q->cnt)] = val;
    // 调整: 自下向上
    int ind = q->cnt;
    while(ind >> 1 && (q->data[ind] > q->data[ind >> 1])){ // ind >> 1 确保父节点存在， 即有父节点且比父节点大进行调整
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q){
    if(q == NULL) return 0;
    if(empty(q)) return 0; // 出堆 需要判空

    q->data[1] = q->data[(q->cnt)--]; // 出堆 = 可覆盖
    // 向下调整
    int ind = 1;
    while((ind << 1) <= q->cnt){  // 先确保节点有孩子，如果没有孩子无需调节
        int tmp = ind, l = ind << 1, r = ind << 1  | 1;
        if(q->data[l] > q->data[tmp]) tmp = l;
        if(r < q->cnt && q->data[r] > q->data[tmp]) tmp = r; // 1. 确保有右孩子  2. 再调整
        if(tmp == ind) break;
        swap(q->data[tmp], q->data[ind]);
        ind = tmp;
    }
    return 1;
}
int top(priority_queue *q){
    return q->data[1];
}

int main(){

    srand(time(0));
    #define MAX_OP 20 
    priority_queue *q = init(MAX_OP);

    int i;
    for(i = 0; i < MAX_OP; i++){
        int val = rand() % 100;
        push(q, val);
        printf("push %d into the priority_queue!\n", val);
    }

    for(i = 0; i < MAX_OP; i++){
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    #undef MAX_OP
    clear(q);
    return 0;
}
