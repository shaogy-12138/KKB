/*************************************************************************
	> File Name: OJ_479.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 05 Mar 2022 11:26:43 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


int ans11[10005][2], ans21[5005][2], cnt11, cnt21;


void print(){

    int i;
    for(i = 0; i <= cnt11; i++){
        printf("%d:%d\n", ans11[i][0], ans11[i][1]);
    }
    printf("\n");
    for(i = 0; i <= cnt21; i++){
        printf("%d:%d\n", ans21[i][0], ans21[i][1]);
    }
}
int main(){
    char str[30];
    int i;
    while(cin>>str){
        for(i = 0; str[i]; i++){
            if(str[i] == 'E'){
                print();
                return 0;
            }

            if(str[i] == 'W'){
                ans11[cnt11][0]++;
                ans21[cnt21][0]++;
            }
            
            if(str[i] == 'L'){
                ans11[cnt11][1]++;
                ans21[cnt21][1]++;
            }


            if((ans11[cnt11][0] >= 11 || ans11[cnt11][1] >= 11) && (abs(ans11[cnt11][0] - ans11[cnt11][1]) >= 2)){
                cnt11++;
            }
            if((ans21[cnt21][0] >= 21 || ans21[cnt21][1] >= 21) && (abs(ans21[cnt21][0] - ans21[cnt21][1]) >= 2)){
                cnt21++;
            }
        }
    }

    return 0;
}
