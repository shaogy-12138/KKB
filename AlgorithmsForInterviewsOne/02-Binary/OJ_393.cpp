/*************************************************************************
	> File Name: OJ_393.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Feb 2022 11:12:36 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;




int m, n;
double num[100005], tr;


int func(double x){
    int t =0;
    int i;
    for(i = 0; i < n; i ++){
        t += num[i] / x;
    }

    return t;
}
double bs(){

    double l = 0, r = tr;
    while(r - l > 1E-5){
        double mid = (l + r)/2;
        int t = func(mid);
        if(t >= m){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;


}

int main(){

    cin >>n >>m;
    int i;
    for(i = 0; i < n; i++){
        cin>>num[i];
        tr = max(tr, num[i]);
    }

    double t = bs();
    // 小数处理
    // 1.2356 -> 123.56 -> 123 -> 1.23
    // 1.2356 -> 1.2306 -> 1.23 （四舍五入）
    printf("%.2f\n",((int)(t * 100 )) / 100.0);
    printf("%.2f\n", t - 0.005);
    return 0;
}
