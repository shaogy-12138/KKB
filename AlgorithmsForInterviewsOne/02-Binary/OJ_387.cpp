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
    int l = 0, r = n , mid;
    while(l != r){
        mid = (l + r) >> 1; //if (l + r) % 2 != 0, (l + r + 1) / 2 > (l + r) / 2
        if(arr[mid].sum < x){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
        return arr[l].ind;
}
int main(void){

    cin >> m >> n;
    int i;
    xz[0].ind = 0, xz[0].sum = 20000000;
    for(i = 1; i <= m; i++){
        cin>>xz[i].sum;
        xz[i].ind = i;
    }

    sort(xz, xz + m + 1, cmp);
    for(i = 0; i < n; i++){
        cin>>pe[i];
    }

    for(i = 0; i < n; i++){
       int find = binary_search(xz, m + 1, pe[i]);
       cout<<find<<endl;
    }


    return 0;
}

