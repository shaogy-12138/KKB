/*************************************************************************
	> File Name: eul-4.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Fri 18 Feb 2022 11:23:04 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int is_palindrome(int n){

    int raw = n, temp = 0;
    while(n){
        temp = temp * 10 + n % 10;
        n /= 10;
    }

    return temp == raw;
}

int func_one(){
    int i, j, ans = 1;
    for(i = 100; i < 1000; i++){
        for(j = i + 1; j < 1000; j++){
            if(is_palindrome(i * j)){
                ans = max(ans, (i * j));
            }
        }
    }

    return ans;
}


int main(){

    cout<<func_one()<<endl;
    return 0;
}
