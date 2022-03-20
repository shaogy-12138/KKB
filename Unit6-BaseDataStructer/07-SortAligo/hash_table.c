/*************************************************************************
	> File Name: hash_table.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 19 Mar 2022 02:19:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// 哈希函数:Aphash
// 冲突处理方法： 拉链法

typedef struct Node{
    char *str;
    struct Node *next;
}Node;

typedef struct HashTable{
    Node **data;
    int size;
}HashTable;


Node *init_node(char *str, Node *head){
    Node *node = (Node *)malloc(sizeof(Node));
    node->str = strdup(str);//拷贝字符串，并将拷贝的字符串首地址返回  [深拷贝]   1. malloc 一段空间存储str， 2. 将开辟的空间首地址return
    node->next = head; //头插法
    return node;
}

HashTable *init_hash(int n){
    HashTable *hash = (HashTable *)malloc(sizeof(HashTable));
    hash->size = n<<1;
    hash->data = (Node **)calloc(hash->size, sizeof(Node *));//哈希表存储的是每个链表的头节点的地址, calloc 堆区申请空间 并初始化
    return hash;

}

int BKDRHash(char *str){
    int i, seed = 31, hash = 0;
    for(i = 0; str[i]; i++){
        hash = hash * seed + str[i];
    }
    return hash & 0x7fffffff; // 保证hash是一个正整数，避免出现负数 （首位是符号位 0表示+， 1表示-）
}


int insert(HashTable *h, char *str){
    //if(h == NULL) return 0;
    int hash = BKDRHash(str); // 哈希函数 BKDRHash， 通过哈希函数将st映射成一个整型值
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]); // 将str 插入到 哈希表 ind 处链表中
    return 1;

}

int search(HashTable *h, char *str){
    int hash = BKDRHash(str);
    int ind = hash % h->size;

    Node *p = h->data[ind];
    while(p != NULL && strcmp(p->str, str)){
        p = p->next;
    }

    return p != NULL;
}
void clear_node(Node *head){
    if(head == NULL) return;
    Node *p = head, *q;
    while(p != NULL){
        q = p->next;
        free(p->str); //  回收数据区
        free(p); //回收节点
        p = q;
    }
    return;
}

void clear(HashTable *h){
    if(h == NULL) return;
    int i;
    for(i = 0; i < h->size; i++){
        clear_node(h->data[i]);
    }

    free(h->data);
    free(h);
    return;
}



int main(){

    srand(time(0));
    #define MAX_N 100
    int opt;
    char str[MAX_N + 5] = {0};
    HashTable *h = init_hash(MAX_N);
    while(~scanf("%d%s", &opt, str)){
        switch(opt){
            case 0:
            printf("insert %s to HashTable\n", str);
                insert(h, str);
                break;
            case 1:
                printf("search %s from HashTable result = %d \n", str, search(h, str));
                break;
        }
    }

    #undef MAX_N

    return 0;
}
