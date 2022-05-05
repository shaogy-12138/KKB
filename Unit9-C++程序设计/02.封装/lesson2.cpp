/*************************************************************************
	> File Name: lesson2.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 27 Apr 2022 10:36:55 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

//#pragma pack(1)  // 指定对齐字节
struct People{
    public:

    string name;
    int age;


    double weight;
    double height;
    int abc;

    static void get();
    void say(string word);
    void run();
};

struct People2{
    public:

    string name;
    int age;
    int abc;


    double weight;
    double height;
    

    static void get();
    void say(string word);
    void run();
};

class A{
    public:
        int a;
    protected:
        int b = 1;
    private:
        int c = 0;
    
    public:
    void show(){
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
        cout<<"c = "<<c<<endl;
    }
};

class B:public A{
    public:
    void shows(){
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
        //cout<<"c = "<<c<<endl;
    }
};



int main(){

    A a;
    B b;
    a.a = 1;
    b.shows();


    return 0;
    // 字节对齐

    struct People p = {"shaogy", 18};
    struct People2 p2 = {"shaogy", 18};

    //cout<<"sizeof string = "<<sizeof(string)<<endl;
    cout<<"sizeof class  = "<<sizeof(People)<<endl;
    cout<<"sizeof class  = "<<sizeof(People2)<<endl;
    //cout<<"sizeof object = "<<sizeof(p)<<endl;


    cout<<"address of name = "<< &p.name<<endl;
    cout<<"address of age = "<< &p.age<<endl;
    cout<<"address of weight = "<< &p.weight<<endl;
    cout<<"address of height = "<< &p.height<<endl;

    return 0;
    // 
    multimap<int, int>mymap; // key可以对应多个值

    mymap.insert(pair<int, int>(1,2));
    mymap.insert(pair<int, int>(1,2));
    mymap.insert(pair<int, int>(1,2));

    for(auto it:mymap){
        cout<<"key = "<<it.first<<",value = "<<it.second<<endl;
    }
    return 0;
    // map 
    map<int, int>mmap;

    // 1. []添加元素
    mmap[1] = 123;
    // 2. insert 插入元素
    mmap.insert(pair<int, int>(2, 3)); // map[2] = 3
    
    // 3. []修改值
    cout<<"mmap[1] = "<<mmap[1]<<endl;
    mmap[1] = 0;
    cout<<"mmap[1] = "<<mmap[1] <<endl;


    // 4. 查找 & 自动增加
    cout<<"size = "<<mmap.size()<<endl;
    auto it = mmap.find(5);
    if(it != mmap.end()){
        cout<<"find the target val"<<endl;
    }else{
        cout<<"not found target val"<<endl;
    }

    cout<<"size = "<<mmap.size()<<endl;
    cout<<mmap[10]<<endl;  // 如果key-value不存在， 会自动增加key-0到mmap中，长度++
    cout<<"size = "<<mmap.size()<<endl;

    // 5. mmap复制
    map<int, int>mmap2 = mmap; // = 运算符重载

    // mmap3.swap(mmap) // 速度快于 =运算符重载
    for(auto it:mmap){
        cout<<"key = "<<it.first<<", value = "<<it.second<<endl;
    }

    cout<<"==================================="<<endl;
    for(auto it = mmap2.begin(); it != mmap2.end(); it++){
        cout<<"key = "<<it->first<<", value = "<<it->second<<endl;
    }


    return 0;
}
