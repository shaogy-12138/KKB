/*************************************************************************
	> File Name: OJ_386.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 25 Feb 2022 10:25:52 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct xg{
    int ind, sum;
};

xg xz[1005];
int m, n, pe[1005];

bool cmp(const xg &a, const xg &b){
    return a.sum < b.sum;
}

int binary_search(xg arr[], int n, int x){
    int l = 1, r = n , mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(arr[mid].sum == x) return arr[mid].ind;
        if(arr[mid].sum < x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }

    
    }
        return 0;
}
int main(void){

    cin >> m >> n;
    int i;
    for(i = 1; i <= m; i++){
        cin>>xz[i].sum;
        xz[i].ind = i;
    }

    sort(xz + 1, xz + m + 1, cmp);
    for(i = 0; i < n; i++){
        cin>>pe[i];
    }

    for(i = 0; i < n; i++){
       int find = binary_search(&xz[1], m, pe[i]);
       cout<<find<<endl;
    }


    return 0;
}

