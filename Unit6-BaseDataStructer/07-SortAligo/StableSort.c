/*************************************************************************
	> File Name: StandSort.c
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

int n, arr1[100];
void my_swap(int *, int *);
void insert_sort(int *, int );
void bubble_sort(int *, int);
void merge_sort(int *, int, int);
void output(int *, int);
void input();



int main(){

    scanf("%d", &n);
    input();
    TEST(arr1, n, insert_sort, num, n);
    TEST(arr1, n, bubble_sort, num, n);
    TEST(arr1, n, merge_sort, num, 0, n-1);

    return 0;
}

void input(){

    srand(time(0));

    int i;
    for(i = 0; i < n; i++){
        arr1[i] = rand() % 100;
    }
    return;

}
void output(int *num, int n){
    int i;
    for(i = 0; i < n; i ++){
        i && printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    return;
}
void merge_sort(int *num, int l, int r){
    if(r - l <= 1){
        if(r - l == 1 && num[r] < num[l]){
            swap(num[r], num[l]);
        }
        return ;
    }
    int mid = (l + r) >> 1;

    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);

    int *temp = (int *)malloc(sizeof(int) *(r - l + 1));
    int p1 = l, p2 = mid +1, k = 0;
    while(p1 <= mid || p2 <= r){
        if(p2 >r || (p1 <= mid && num[p1] <= num[p2])){
            temp[k++] = num[p1++];
        }else{
            temp[k++] = num[p2++];
        }
    }

    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return;
}
void insert_sort(int *num, int n){
    int i, j;
    for(i = 1; i < n; i++){
        for(j = i; j > 0 && num[j] < num[j - 1]; j--){
            swap(num[j], num[j-1]);
        }
    }
    return;
}

void bubble_sort(int *num, int n){
    int i, j, flag = 1;
    for(i = 1; i < n && flag; i++){
        flag = 0;
        for(j = 0; j < n-i; j++){
            if(num[j] < num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            flag = 1;
        }
    }
}
void my_swap(int *a, int *b){
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}
