/*************************************************************************
	> File Name: leetcode19.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Feb 2022 07:13:05 PM CST
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    // 1. 获取链表长度
    // 2. 倒数第n个节点转换为删除第ind个节点
    // 3. 遍历删除
    // 注意：如果删除的是首节点：直接p = p->next即可；
    int sz = 0, ind = 0;

    struct ListNode *p = head, *q;
    while(p != NULL){
        p = p->next;
        sz++;
    }
    p = head;
    ind = sz - n;
    if(ind == 0){
        p = p->next;
        return p;
    }

    ind --;
    while(ind --){
        p = p->next;
    }
    q = p->next;
    p->next = q->next;

    return head;
}
