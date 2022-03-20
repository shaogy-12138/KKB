/*************************************************************************
	> File Name: binary_search.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 19 Mar 2022 09:48:00 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define P(func) {\
                printf("%s = %d\n", #func, func);\
                }

// 1 3 5 7 9

int binary_search(int *num, int n, int x){
    int i, mid;
    int head = 0, tail = n - 1;
    while(head <= tail){
        mid = (head + tail) >> 1;
        if(num[mid] == x) return mid;
        if(num[mid] < x){
            head = mid + 1;
        }else{
            tail = mid - 1;
        }
    }

    return -1;
}

//  111111111000000000
int binary_search_1(int *num, int n){
    int head = -1, tail = n -1, mid;

    while(head < tail){
        mid = (head + tail + 1) >> 1;
        if(num[mid] == 1){
            head = mid;
        }else{
            tail = mid - 1;
        }
    }

    return head;
}
//  0000000000000111111111
int binary_search_2(int *num, int n){
    int head = 0, tail = n, mid;

    while(head < tail){
        mid = (head + tail) >> 1;
        
        if(num[mid] == 1){
            tail = mid;
        }else{
            head = mid + 1;
        }
    }

    return head == n ? -1 : head;
}

void output(int *num, int n){
    int i;
    printf("[");
    for(i = 0; i < n; i++){
        i && printf(" ");
        printf("%d", num[i]);
    }
    printf("]\n");
    return ;
}
//
int main(){


    int arr1[10] = {1, 3, 5, 6, 8, 9, 10, 12, 22, 25};
    int arr2[10] = {1, 1, 1, 1, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    
    P(binary_search(arr1, 10, 6));
    P(binary_search_1(arr2, 10));
    P(binary_search_2(arr3, 10));

    return 0;
}
