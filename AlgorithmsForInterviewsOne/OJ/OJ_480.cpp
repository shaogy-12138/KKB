/*************************************************************************
	> File Name: OJ_480.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 14 Mar 2022 10:32:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


typedef struct node{

    char s[4];
    int num1, num2, flag;
}node;


node bl[15];
int n, ans;

int main(void){

    // cin一直输入到bl.s中
    while(cin>>bl[n].s){
    
        if(bl[n].s[0] == '/'){
            bl[n].num1 = 10;
            bl[n].num2 = 10;
            bl[n].flag = 2;
        }else if(bl[n].s[1] == '/'){
            bl[n].num1 = bl[n].s[0] - '0';
            bl[n].num2 = 10;
            bl[n].flag = 1;
        }else{
            bl[n].num1 = bl[n].s[0] - '0';
            bl[n].num2 = bl[n].num1 + bl[n].s[1] - '0';
            bl[n].flag = 0;
        }

        n++;
    }

    int i;
    for(i = 0; i < 10; i++){
        ans += bl[i].num2;

        if(bl[i].flag == 1){
            ans += bl[i + 1].num1;
        }else if(bl[i].flag == 2){
            if(bl[i + 1].flag  == 2){
                ans += 10 + bl[i + 2].num1;
            }else{
                ans += bl[i + 1].num2;
            }
        }
    }


    cout<<ans<<endl;




    return 0;
}
