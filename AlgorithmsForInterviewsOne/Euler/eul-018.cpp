/*************************************************************************
	> File Name: eul-018.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Mon 21 Feb 2022 11:30:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int ans, num[20][20], dp[20][20];


int main(){

    int i, j;
    for(i = 1; i <= 15; i++){
        for( j = 1; j <= i; j++ ){
            cin>>num[i][j];
        }
    }
    // 从下向上，计算最大路径和
    for(i = 15; i > 0; i--){
        for(j = 1; j <= i; j++){
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + num[i][j];
            ans = max(ans, dp[i][j]);
        }
    }

    cout<<ans<<endl;
    return 0;
    // 从上向下，计算最大路径和
    for(i = 0; i < 16; i++){
        for(j = 0; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + num[i][j];
            ans = max(ans, dp[i][j]);
        }
    }

    cout<<ans<<endl;
    return 0;
}
