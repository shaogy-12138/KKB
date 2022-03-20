/*************************************************************************
	> File Name: heap_sort.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 19 Mar 2022 09:42:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}


void downUpdate(int *arr, int n, int ind){
    while((ind << 1) <= n){
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if(arr[l] > arr[temp]) temp = l;
        if(r <= n && arr[r] > arr[temp]) temp = r;
        if(ind == temp) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }

    return ;
}


void heap_sort(int *arr, int n){
    arr -= 1;
    int i;
    // 从n-1层开始，进行自上向下的更新， 构建一个堆
    for(i = n >> 1; i >= 1; i--){
        downUpdate(arr, n, i);
    }

    // 先将根节点元素放到最后， 再自上向下更新
    for(i = n; i > 1; i--){
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }

    return ;
}

void output(int *arr, int n){
    int i;
    printf("[");
    for(i = 0; i < n; i++){
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}
// 线性建堆法: 时间复杂度O(N)


int main(){

    srand(time(0));
    #define MAX_N 20 

    int arr[MAX_N] = {0};
    int i;
    for(i = 0; i < MAX_N; i++){
        arr[i] = rand() % 100;
    }

    output(arr, MAX_N);
    heap_sort(arr, MAX_N);
    output(arr, MAX_N);
    #undef MAX_N 


    return 0;
}
