/*************************************************************************
	> File Name: OJ_389.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Feb 2022 10:39:40 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


int m, n, num[100005];


int func(int x){
    int i, t = 1, last = num[0];
    for(i = 1; i < n; i++){
        if(num[i] - last >= x){
            t++;
            last = num[i];
        }
    
    }
    return t;

}
        

int bs(){


    int l = 1, r = num[n - 1] - num[0];
    while(l != r){
        int mid = (l + r + 1)/2;
        int t = func(mid);
        if(t >= m){
            l = mid;
        }else{
            r = mid - 1;
        }

    }

    return r;
}


int main(){

    cin>>n>>m;
    int i;
    for(i = 0; i < n; i++){
        cin>>num[i];
    }

    sort(num,  num + n);
    cout<<bs()<<endl;

    return 0;
}
