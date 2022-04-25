/*************************************************************************
	> File Name: lesson1.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 24 Apr 2022 11:05:08 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<unordered_map>
#include<map>
using namespace std;


int main(){


    map<string, int>mmap;

    mmap["adds"] = 123;
    mmap["sad"] = 2;
    mmap["dsad"] = 312;
    mmap["qweq"] = 1;

    for(auto it = mmap.begin(); it != mmap.end(); it++){
        cout<<"key = "<< it->first <<", value = "<< it->second <<endl;
        
    }
    // 逆序遍历
    // for(map<int, int>::reverse_iterator it = mymap.begin; ......)  反向迭代器
    for(auto it = mmap.rbegin(); it != mmap.rend(); it++){
        cout<<"key = "<< it->first <<", value = "<< it->second <<endl;
        
    }
    return 0;
    // 有序map - 红黑树
    map<int, int>mymap;

    mymap[1] = 123;
    mymap[222] = 2;
    mymap[-897] = 312;
    mymap[9] = 1;

    // 从大到小遍历
    for(auto it: mymap){
        cout<<"key = "<< it.first <<", value = "<< it.second <<endl;
    }

    // for(map<int, int>::iterator it = mymap.begin; ......)  迭代器
    for(auto it = mymap.begin(); it != mymap.end(); it++){
        cout<<"key = "<< it->first <<", value = "<< it->second <<endl;
        
    }
    // 逆序遍历
    // for(map<int, int>::reverse_iterator it = mymap.begin; ......)  反向迭代器
    for(auto it = mymap.rbegin(); it != mymap.rend(); it++){
        cout<<"key = "<< it->first <<", value = "<< it->second <<endl;
        
    }




    return 0;
    // 哈希 - 无序map
    unordered_map<int, int>hashmap;
    // 哈希表使用索引下标插入/修改值
    hashmap[1] = 123;
    hashmap[222] = 2;
    hashmap[-897] = 312;
    hashmap[9] = 1;

    cout<< " size = "<< hashmap.size()<<endl;

    cout<<hashmap[9]<<endl;
    hashmap[9] = 110;
    cout<<hashmap[9]<<endl;

    hashmap[56] = 56;
    cout<<"size = "<<hashmap.size()<<endl;

    // 遍历哈希表， 此处it为hash的指针 
    // hashmap.first 表示的是key hashmap.second 表示的是value
    for(auto it=hashmap.begin(); it != hashmap.end(); it++){
        cout<<"key = "<<it->first << ", value = "<<it->second<<endl;
    }

    // 迭代哈希表， it为hash的引用变量
    for(auto it:hashmap){
        cout<<"key = "<<it.first << ", value = "<<it.second<<endl;
        
    }

    // 哈希查找
    auto it = hashmap.find(123);
    if(it != hashmap.end())
        cout<<"find key =" <<it->first<<", value = "<<it->second<<endl;
    return 0;
    // 字符串
    string s1, s2;
    s1 = "abcdefg46";
    s2 = "sadsawdaw";

    cout<< (s1 == s2)<<endl;
    cout<< (s1 > s2)<<endl;
    cout<< (s1 < s2)<<endl;

    cout<<s1[1]<<endl;
    s1[1] = 'K';
    s1[7] = 'l';
    cout<<s1<<"size = "<<s1.size()<<endl;
    s1 += "123456";
    cout<<s1<<"size = "<<s1.size()<<endl;
    cout<<"length = "<< s1.length()<<endl;


    int n = 100000;
    while(n--){
        s1 +="kkb";
    }


    n = 100000;
    cout<<"c++ begin clock = "<<clock()<<endl;
    while(n--){
        s1.length(); // 时间复杂度 O(1)
    }
    cout<<"c++ end clock = "<< clock()<<endl;
    n = 100000;
    cout<<"c++ begin clock = "<<clock()<<endl;
    while(n--){
        strlen(s1.c_str()); // 时间复杂度 O(n)
    }
    cout<<"c++ end clock = "<< clock()<<endl;
    return 0;
    // 队列
    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);
    cout<< "front = "<<q.front() << " back = "<< q.back()<<endl;
    q.pop();
    cout<< "front = "<<q.front() << " back = "<< q.back()<<endl;
    q.pop();
    cout<< "front = "<<q.front() << " back = "<< q.back()<<endl;
    q.pop();
    if(q.size() > 0)cout<< "front = "<<q.front() << " back = "<< q.back()<<endl;


    // 栈
    cout<<"===================stack======================="<<endl;
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<< "top = "<<s.top() << " size = "<< s.size()<<endl;
    s.pop();
    cout<< "top = "<<s.top() << " szie = "<< s.size()<<endl;
    s.pop();
    cout<< "top = "<<s.top() << " size = "<< s.size()<<endl;




    return 0;
}
