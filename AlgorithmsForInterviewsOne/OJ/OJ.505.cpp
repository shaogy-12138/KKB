/*************************************************************************
	> File Name: OJ.505.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Mar 2022 10:32:05 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int n;
string num[100000];


bool cmp(const string &a, const string &b){
    return a + b > b + a; // 如果ab > ba, 则返回1
}
int main(void){

    
    cin>>n;

    int i;
    for(i = 0; i < n; i ++){
        cin>>num[i];
    }

    sort(num, num + n, cmp);
    for(i = 0; i < n; i ++){
        cout<<num[i];
    }


    cout<<endl;

    return 0;
}


// sort : 12 96 121 
// 1:  1296 < 9612 ,cmp return 0, swap 12 96  => 96 12 121 
// 2.  12121 > 12112, cmp return 1, => 96 12 121 
//  96 12 121 
//
//  sort: 12 96 123
//  1: 1296 < 9612 => 96 12 123 
//  2: 12123 < 12312 => 96 123 12 
//  3: 96123 > 12396 => 96 123 12 
