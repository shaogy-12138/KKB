/*************************************************************************
	> File Name: OJ_481.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Mar 2022 11:21:02 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


int ans[15][2], r;

void print(int n){
    int i, ans1 = 0, ans2 = 0;
    for(i = 0; i < n; i++){
        cout<< ans[i][0]<<":"<<ans[i][1]<<endl;
        ans1 += ans[i][0];
        ans2 += ans[i][1];
    }


    cout<<ans1<<":"<<ans2<<endl;
    return;
}
int main(void){


    cin>>r;
    int i;
    for(i = 0; i < 10; i ++){  // 对局数

        int num1[10],  num2[10]; // 每轮的距离
        int j=0, k=0;

        for(j = 0; j < 8; j++){   // A队
            cin>>num1[j];
            if(num1[j] == -1){
                print(i);
                return 0;
            }
        }

        for(j = 0; j < 8; j++){
            cin>>num2[j];
        }

        sort(num1, num1 + 8);
        sort(num2, num2 + 8);

        if(num1[0] < num2[0]){
            for(k = 0; k < 8; k++){
                if(num1[k] > r || num1[k] >= num2[0]){ //小于半径 、 比另一个最近的要远
                    break;
                }
                ans[i][0]++;
            }
        } else {
            for(k = 0; k < 8; k++){
                if(num2[k] > r || num2[k] >= num1[0]){
                    break;
                }
                ans[i][1]++;
            }
        }

    }


    print(10);

    return 0;
}
