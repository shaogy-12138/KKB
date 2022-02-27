/*************************************************************************
	> File Name: 1.sort.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 24 Feb 2022 10:11:38 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;



struct node{
    int x, y;
};

bool cmp(const int &a, const int &b){
    return a > b;
}

bool cmp2(const node &a, const node &b){
    // x从大到小排序；如果x相等，根据y从大到小排序
    return (a.x != b.x)?(a.x > b.x):(a.y > b.y);
}

int main(){

    

    struct node xyz[15];
    xyz[0].x = 5, xyz[0].y = 0;
    xyz[1].x = 8, xyz[1].y = -6;
    xyz[2].x = 6, xyz[2].y = 9;
    xyz[3].x = 6, xyz[3].y = 3;
    xyz[4].x = 5, xyz[4].y = 6;
    sort(xyz, xyz + 5, cmp2);
    int i;
    for(i = 0; i < 5; i++){
        cout<<"xyz["<<i<<"].x = "<< xyz[i].x<<", ";
        cout<<"xyz["<<i<<"].y = "<< xyz[i].y<<endl;
    }
    
    
    return 0;
    int num[105] = {9, 5, 1, 4, 6, 8, 4, 3, 25};
    //sort(num, num + 9);
    sort(num, num + 9, cmp);
    for(i = 0; i < 9; i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;

  

    return 0;
}
