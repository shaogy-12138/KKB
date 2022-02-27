/*************************************************************************
	> File Name: OJ_380.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Feb 2022 11:19:28 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

struct zt{
    int num;
    char sum[1005];
};

struct zt1{
    int num;
    string s;
};

int n;
zt str[105];
zt1 z[105];

bool cmp(const zt &a, const zt &b){
    if(strlen(a.sum) == strlen(b.sum)){
        return strcmp(a.sum, b.sum);
    }
    return strlen(a.sum) > strlen(b.sum);
}

bool cmp1(const zt1 &a, const zt1 &b){

    if(a.s.size() == b.s.size()){
        return a.s > b.s;
    }
    return a.s.size() > b.s.size();
}
int main(){


    cin>>n;
    int i;


    for(i = 1; i <= n; i++){
        cin>>z[i].s;
        z[i].num = i;
    }
    sort(z + 1, z + n + 1, cmp1);
    cout<<z[1].num<<" "<<z[1].s<<endl;
    return 0;
    for(i = 0; i < n; i++){
        cin>>str[i].sum;
        str[i].num = i;
    }
    sort(str, str + n, cmp);

    cout<<str[0].num<<" "<<str[i].sum<<endl;
    
    return 0;
}
