/*************************************************************************
	> File Name: eul-8.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Fri 18 Feb 2022 02:07:28 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define MAX_N 1000
#define LEN 13
char str[MAX_N + 5];

long long func_one(){

    int i, zero_count = 0;
    long long ans = 0, mul = 1;
    for(i = 0; i < strlen(str); i++){
        if(i < LEN){
            mul *= str[i] - '0';
        }
        else{
            // in
            if(str[i] - '0' != 0){
                mul *= str[i] - '0';
            }
            else{
                zero_count++;
            }
            // out
            if(str[i - LEN] - '0' == 0){
                zero_count --;
            }
            else{
                mul /= str[i - LEN] - '0';
            }
        }

        if(zero_count == 0){
            ans = max(ans, mul);
        
        } 
    }
    return ans;
}

long long func_two(){
    
    int i, zero_count = 0;
    long long now = 1, ans = 0;
    for(i = 0; i < strlen(str); i++){
        if(i < LEN){
            //now *= str[i] - '0';
            if(str[i] == '0'){
                zero_count ++;
            }
            else{
                now *= str[i] - '0';
            }
        }

        else{
            // in
            if(str[i] != '0'){
                now *= str[i] - '0';
            }
            else{
                zero_count ++;
            }
            // out
            if(str[i - LEN] - '0' == 0){
                zero_count --;
            }
            else{
                now /= str[i - LEN] - '0';
            }

        }

        if(zero_count == 0){
            ans = max(ans, now);
        } 
    }

    return ans;
}

int main(){
    cin>>str;
    cout<<func_one()<<endl;
    cout<<func_two()<<endl;
    return 0;
}
