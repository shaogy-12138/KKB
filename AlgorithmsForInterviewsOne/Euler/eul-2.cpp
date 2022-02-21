/*************************************************************************
	> File Name: eul-2.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Fri 18 Feb 2022 10:58:16 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 4000000
int arr[MAX_N + 5] = {1, 2};

int func_one(){
    int ans = 2, i;
    for( i = 2; 1; i++ ){
        arr[i] = arr[i - 1] + arr[i - 2];
        if(arr[i] > MAX_N) break;
        if(arr[i] % 2 == 0) {
            ans += arr[i];
        }
    }
    return ans;
}

int func_two(){
    /*
     *1 2 3 5 8 13 21 ...
     *a b
     *  a b   (b = a + b 3 = 2 + 1)(a = b - a 2 = 3 - 1)
     *    a b
     *      a b ...
     */
    int a = 1, b = 2, ans = 0;
    while( b < MAX_N ){
        if(b % 2 == 0){
            ans += b;
        }
        b = b + a;
        a = b - a;
    }
    return ans;
}
int main(){

    cout<<func_one()<<endl;
    cout<<func_two()<<endl;
    return 0;
}
