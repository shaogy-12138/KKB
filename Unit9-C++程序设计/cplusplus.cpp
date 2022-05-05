/*************************************************************************
	> File Name: cplusplus.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Fri 29 Apr 2022 05:50:28 PM CST
 ************************************************************************/

#include<iostream>
#include<array>
using namespace std;

array<int , 5>glb; // {0, 0, 0, 0, 0}

int main(){

    // array
    // array<type, length>array_name;
    array<int , 5>arr1; // {“rand”+}
    array<char , 5>arr2;// 

    for(auto it:glb){
        cout<<it<<endl;
    }

    for(auto it:arr1){
        cout<<it<<endl;
    }

    for(auto it:arr2){
        cout<<it<<endl;
    }


    return 0;
}
