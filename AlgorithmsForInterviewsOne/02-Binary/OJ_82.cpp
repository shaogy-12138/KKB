/*************************************************************************
	> File Name: OJ_82.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Feb 2022 11:30:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int m, n, num[1000005], tr;

long long func(int x){
    long long t = 0, i;
    for(i = 0; i < n; i++){
        if(num[i] >= x){
            t += num[i] - x;
        }
    }
    return t;
}
int bs(){
    int l = 0, r = tr;
    cout<<"l = "<<l<<" r = "<<r<<endl;
    while(l != r){
        int mid = ((long long)l + r + 1) / 2;
        cout<<"l = "<<l<<" r = "<< r<<" mid = "<<mid<<endl;
        long long s = func(mid);
        if(s >= m){
            l = mid;
        }else{
            r = mid - 1;
        }
        cout<<"l = "<<l<<" r = "<< r<<" mid = "<<mid<<endl;
    }
    return r;
}
int main(){

    cin>>n>>m;
    int i;
    for(i = 0; i < n; i ++){
        cin>>num[i];
        tr = max(tr, num[i]);
    }


    cout<<bs()<<endl;
    return 0;
}
