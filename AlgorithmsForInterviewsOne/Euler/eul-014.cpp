/*************************************************************************
	> File Name: eul-014.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Feb 2022 04:38:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000


long long ans = 0, step = 0, n;
long long func_one(long long n){
    
    if(n == 1){
        return 1;
    }
    if(n % 2 == 0){
        return func_one(n / 2) + 1;
    }else{
        return func_one(3 * n + 1) + 1;
    }
}
int main(){

    for(n = 1; n < MAX_N; n++){
        step = func_one(n);
        ans = max(ans, step);
    }
    cout<<ans<<endl;
    return 0;
}
