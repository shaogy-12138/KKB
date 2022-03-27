/*************************************************************************
	> File Name: OJ.485.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 25 Mar 2022 12:10:31 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int n, num[105], sum, ans, avg;
int main(){


    int i;
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>num[i];
        sum += num[i];
    }


    avg = sum / n;
    for(i = 0; i < n; i ++){
        if(num[i] != avg){
            ans++;
            num[i + 1] += num[i] - avg;
            num[i] = avg; // ignore
        }
    }

    cout<<ans<<endl;
    return 0;
}
