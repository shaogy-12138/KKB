/*************************************************************************
	> File Name: eul-1.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Fri 18 Feb 2022 10:16:01 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int func_one(int n){
    int i, ans = 0;
    for( i = 3; i < n; i++ ){
        if((i % 3 == 0) || (i % 5 == 0)){
            ans += i;
        }
    }

    return ans;
}

int func_two(){
    int ans = 0, ans3 = 0, ans5 = 0, ans15 = 0;
    ans3  = (3 + 999) * 333 / 2;
    ans5  = (5 + 995) * 199 / 2;
    ans15 = (15 + 990) * 66 / 2;
    return ans3 + ans5 - ans15;
    /*
     Note: if have * and /, should first *, second /
    */
}

int main(){
    int n;
    cin>>n;
    cout<<func_one(n)<<endl;
    cout<<func_two()<<endl;
    return 0;
}

