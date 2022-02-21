/*************************************************************************
	> File Name: eul-6.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Fri 18 Feb 2022 01:50:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main(){

    int i, psum = 0, sump = 0, sum = 0;

    for(i = 1; i < 101; i++){
        psum += i * i;
        sum += i;
    }
    
    sump = sum * sum;
    cout<< sump - psum <<endl;

    return 0;
}
