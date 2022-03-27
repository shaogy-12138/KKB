/*************************************************************************
	> File Name: OJ.504.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 25 Mar 2022 08:16:00 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;



int main(){

    string s;
    int n;
    cin>>s>>n;


    int i;

    for(i = 0; i < n; i++){
        int ind = s.size() - 1;
        int j;
        for(j = 0; j < s.size() -1; j++){
            if(s[j] > s[j + 1]){
                ind = j;
                break;
            }
        }

        s.replace(ind, 1, ""); // s 的 第ind 处起 1一个字符替换为“”
    }

    int flag = 0;
    for(i = 0; i < s.size(); i++){
        
        if(s[i] != '0'){
            cout<<s[i];
            flag = 1;
        }else if(flag == 1){
            cout<<0;
        }
    }


    if(flag == 0){
        cout<<0;
    }

    cout<<endl;
    return 0;
}
