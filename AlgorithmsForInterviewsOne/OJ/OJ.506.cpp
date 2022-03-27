/*************************************************************************
	> File Name: OJ.506.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Mar 2022 11:26:14 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node{
    int num, ind;
};


node stu[35];
int n;


bool cmp(const node &a, const node &b){
    return a.num < b.num;
}
int main(void){


    cin >> n;
    int i;
    for(i = 0; i < n; i++){
        cin>>stu[i].num;
        stu[i].ind = i + 1;
    }

    sort(stu, stu + n, cmp); // 按照打水时间从小到大进行排序， 如果需要从大到小进行排序， 更改cmp函数， 需要return a > b 就可以 


    int sum = 0, now = 0;
    for(i = 0; i < n; i ++){
        sum += now;
        now += stu[i].num;
        if(i != 0){

            cout<<" ";
        }
        cout<<stu[i].ind;
    }

    printf("\n%.2f\n", (double)sum / n);
    return 0;
}


