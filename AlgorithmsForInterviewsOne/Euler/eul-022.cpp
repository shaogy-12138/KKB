/*************************************************************************
	> File Name: eul-022.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Feb 2022 11:47:26 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(const string &a, const string &b){
    return a < b;
}

string name[10000];
int n = 1, ans;

int main(){

    while(cin>>name[n]){ //linux: ctrl + d = end input
        n++;
    }

    sort(name + 1, name + n + 1, cmp);
    int i;
    for(i = 1; i <= n; i++){
        int sum = 0, j;
        for(j = 0; j < name[i].size(); j++){
            sum += name[i][j] - 'A' + 1;
        }
        cout<<i<<": "<<name[i]<<"  "<<sum * i<<endl;
    }

    return 0;
}
