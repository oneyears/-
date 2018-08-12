//
//  main.cpp
//  LeetCode86Partition List
//
//  Created by Neworigin on 18/5/16.
//  Copyright © 2018年 Neworigin. All rights reserved.
//

#include <iostream>
using namespace std;

//1、定义链表结点
struct ListNode {
    int val;
    ListNode * next;
    ListNode (int x) : val(x),next(NULL) {}
};

//========================================
//2、创建链表函数
ListNode *createLinkedList(int arr[],int n) {
    if( n == 0)
        return NULL;
    
    ListNode * head = new ListNode(arr[0]);
    
    ListNode * curNode = head;
    
    for(int i = 1; i < n; i ++) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    
    return head;
}
//========================================
//3、打印链表的数据 函数
void printLinkedList(ListNode * head) {
    ListNode * curNode = head;
    
    while (curNode != NULL) {
        cout<<curNode->val<<" "<<"->";
        curNode = curNode->next;
    }
    cout<<"NULL"<<endl;
    return;
    
}
//========================================
//4、释放内存函数（c++需要自己释放内存）
void deleteLinkedList(ListNode * head) {
    ListNode * curNode = head;
    while (curNode != NULL) {
        ListNode * delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}
//========================================
//leetcode 函数
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL) return head;
        
        ListNode * L_head = NULL, *L_tail = NULL;
        ListNode * R_head = NULL, *R_tail = NULL;
        ListNode * p = head;
        
        while(p != NULL) {
        if(p->val < x){
            if(L_tail) {
            L_tail ->next= p;
            L_tail = L_tail->next;
            }
            else{
            L_head = L_tail = p;
            }
        }
        else{
            if(R_tail) {
                R_tail ->next= p;
                R_tail = R_tail->next;
            }else{
                R_head = R_tail = p;
            }
        }
            p = p->next;
        }
        if(R_tail) {
            R_tail->next =NULL;
        }
        if(L_tail) {
            L_tail->next = R_head;
        }
        return L_head ? L_head:R_head;
    }
};
//========================================
//5、测试数据
int main(int argc, const char * argv[]) {
    int arr[] = {1,4,3,2,5,2};
    int n = sizeof(arr)/(sizeof(int));
    
    ListNode * head = createLinkedList(arr, n);
    
    printLinkedList(head);
    
    ListNode * head2 = Solution().partition(head,3);//调用 class (leetcode 测试函数方式)
    
    printLinkedList(head2);
    deleteLinkedList(head2);
    return 0;
}
