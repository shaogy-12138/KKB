/*************************************************************************
	> File Name: unStandSort.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 18 Mar 2022 10:08:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

#define TEST(arr, n, func, args...) {\
                                    int *num = (int *)malloc(sizeof(int) * n);\
                                    memcpy(num, arr, sizeof(int) * n);\
                                    output(num, n);\
                                    printf("%s = ", #func);\
                                    func(args);\
                                    output(num, n);\
                                    free(num);\
                                    printf("\n");\
                                    }


void select_sort(int *num, int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        int min = i;
        for(j = i + 1; j < n; j++){
            if(num[j] < num[min]){
                min = j;
            }
        }
        swap(num[i], num[min]);
    }

    return ;
}

void quick_sort(int *num, int l, int r){
    if(l > r) return;
    int x = l, y = r, z = num[x];
    while(x < y){
        while(x < y && num[y] > z) y--;
        if(x < y) num[x++] = num[y];
        while(x < y && num[x] < z) x++;
        if(x < y) num[y--] = num[x];
    }

    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
}
void randint(int *num, int n){
    while(n--) num[n] = rand() % 100;
    return;
}

void output(int *num, int n){
    int i;

    printf("[");
    for(i = 0; i < n; i++){
        i && printf(" ");
        printf("%d", num[i]);
    }
    printf("]\n");
    return;
}

int main(){

    #define MAX_N 20 
    srand(time(0));
    int i;

    int arr[MAX_N];
    randint(arr, MAX_N);
    TEST(arr, MAX_N, select_sort, num, MAX_N);
    TEST(arr, MAX_N, quick_sort, num, 0, MAX_N - 1);

    #undef MAX_N

    return 0;
}
