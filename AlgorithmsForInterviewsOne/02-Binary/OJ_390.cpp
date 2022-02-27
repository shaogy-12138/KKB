/*************************************************************************
	> File Name: OJ_390.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Feb 2022 10:20:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int n, m, num[100005], tr;


int func(int n){
    int t = 0, i;
    for(i = 0; i < n; i++){
        t += num[i] / n;
    }

    return t;
}

int bs(){

    int l = 1, r = tr;
    while(l != r){
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if(s >= m){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}
int main(){

    cin>>n>>m;
    int i;
    for(i = 0; i < n; i++){
        cin>>num[i];
        tr = max(tr, num[i]);
    }

    cout<<bs()<<endl;


    return 0;
}
