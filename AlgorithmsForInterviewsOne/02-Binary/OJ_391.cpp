/*************************************************************************
	> File Name: OJ_391.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Feb 2022 11:47:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int m, n;
long long l, r, num[100000000];

long long func(long long x){
    long long now = 0, t = 0;
    int i;
    for(i = 0; i < n; i++){
        if(now + num[i] > x){
            t++;
            now = num[i];
        }else if(now + num[i] == x){
            t++;
            now = 0;
        }else{
            now += num[i];
        }
    }

    if(now != 0){
        t++;
    }

    return t;
}
long long bs(){

    while( l != r ){
        long long mid = (l + r) / 2;
        long long s = func(mid);
        if(s <= m){
            r = mid;
        }else{
            l = mid + 1;
        }
    }

    return l;
}

int main(){
    cin>>n>>m;
    int i;
    for(i = 0; i < n; i ++){
        cin>>num[i];
        l = max(l, num[i]);
        r += num[i];
    }
    

    cout<<bs()<<endl;

    return 0;
}
