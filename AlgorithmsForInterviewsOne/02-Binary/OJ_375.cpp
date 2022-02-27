/*************************************************************************
	> File Name: OJ_375.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Feb 2022 11:01:03 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct student{
    int ch, ma, en, num, sum;
};

struct student stu[305];
int n, ans;


bool cmp(const student &a, const student &b){
    if(a.sum == b.sum){
        return (a.ch == b.ch)?(a.num < b.num):(a.ch > b.ch);
    }
    return a.sum > b.sum;
}

void func(student &a){

    a.sum = a.ch + a.ma +a.en;

}

int main(){

    cin>>n;
    int i;
    for(i = 0; i < n; i++){
        cin>>stu[i].ch>>stu[i].ma>>stu[i].en;
        stu[i].num = i;
        func(stu[i]);
    }

    sort(stu, stu + n, cmp);
    for(i = 0; i < 5; i++){
        cout<<stu[i].num<<" "<<stu[i].sum<<endl;
    }

    return 0;
}
