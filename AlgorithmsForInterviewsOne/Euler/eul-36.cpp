/*************************************************************************
	> File Name: eul-36.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Fri 18 Feb 2022 01:28:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 1000
int is_palindromes(int n, int x){
    int raw = n, temp = 0;
    while(n){
        temp = temp * x + n % x;
        n /= x;
    }

    return temp == raw;
}

int func(){
    int i, ans = 0;
    for(i = 0; i < MAX_N; i++){
        if((is_palindromes(i, 2)) && is_palindromes(i, 10)){
            ans += i;
            cout<<i<<endl;
        }
    }

    return ans;
}

int main(){
    

    cout<<func()<<endl;

    return 0;
}
