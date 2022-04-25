/*************************************************************************
	> File Name: OJ_281.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 25 Apr 2022 11:46:51 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<sstream>
#include<ctime>

using namespace std;


// 数组实现字典树
//
const int maxn = 1e6 + 10;
const int base = 26;


struct Node{
    int cnt;
    int next[base];  // 地址 转变为 下标

}tree[maxn];

int root = 0, node_cnt = 1;
char str[maxn];

int getNode(){
    return node_cnt++;
}

void insert(const char *str){
    int p = root;
    int i;
    for(i = 0; str[i]; i++){
        int ind = str[i] - 'a';
        if(tree[p].next[ind] == 0){
            tree[p].next[ind] = getNode();
        }
        p = tree[p].next[ind];
    }
    tree[p].cnt += 1;
    return ;
}

int find(const char*str){

    int p = root;
    int i;
    int ans = 0;
    for(i = 0; str[i]; i++){
        int ind = str[i] - 'a';
        p = tree[p].next[ind];
        if(p == 0) return ans;
        ans += tree[p].cnt;
    }

    return ans;
}
int main(){

    int n, m;
    scanf("%d%d", &n, &m);
    int i = 0;
    for(; i < n; i++){
        scanf("%s",str);
        insert(str);
    }

    for(i = 0; i < m; i ++){
        scanf("%s", str);
        printf("%d\n", find(str));
    }


    return 0;
}
