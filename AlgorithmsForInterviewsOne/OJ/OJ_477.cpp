/*************************************************************************
	> File Name: OJ_477.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 05 Mar 2022 10:57:34 PM CST
 ************************************************************************/


#include<iostream>
#include<cstring>
using namespace std;


char str[105];
int ans;

int main(){

    cin>>str;
    int i = 0, last = -1;
    int len = strlen(str);
    for(i = 0; i < len; i++){
        switch(str[i]){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':{
                if(last == -1){
                    last = i;
                }else{
                    ans = max(ans, i - last);
                    last = i;
                }
            }break;
        }
    }

    cout<<ans<<endl;

    return 0;
}
