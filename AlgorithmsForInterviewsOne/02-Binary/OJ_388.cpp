/*************************************************************************
	> File Name: OJ_388.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 25 Feb 2022 10:03:19 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;



int m, n, X[1000], Y[1000], ans = 0;

int bin_search(int arr[], int n, int x){
    int l = 0, r = n - 1, mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(arr[mid] == x) return 1;
        if(arr[mid] < x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    return 0;
}

int main(){

    int i;
    cin>>m>>n;

    for(i = 0; i < m; i++){
        cin>>X[i];
    }
    sort(X, X + m);

    for(i = 0; i < n; i++){
        cin>>Y[i];
    }

    for(i = 0; i < n; i++){
        int find = bin_search(X, m, Y[i]);
        if(find){
            ans += Y[i];
            cout<<Y[i];
            (i < (n -1)) && (cout<<" ");
        }
    }
    cout <<endl<<ans<<endl;
    

    return 0;
}
