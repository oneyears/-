//
//  main.cpp
//  Leetcode143ReorderList
//
//  Created by Neworigin on 18/5/20.
//  Copyright © 2018年 Neworigin. All rights reserved.
//


//======================================
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//========================================
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
//5、获得链表长度,表示返回几个结点，head为NULL返回 0
int getLengthList(ListNode *head) {
    int count = 1;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

//========================================
//leetcode 函数
class Solution {
public:
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return;
        
        ListNode * cNode = head;
        int count = 0;
        while (cNode != NULL) {
            count++;
            cNode = cNode->next;
        }
        int mid = count / 2;
        ListNode * p = head;
        ListNode * L_head = head, *L_tail = new ListNode (0);
        L_tail->next = L_head;
        ListNode * R_head = head;
        
        for(int i = 0 ; i < mid; i++) {
            p = p->next;
            R_head = R_head->next;
            L_tail = L_tail->next;
        }
        L_tail->next = NULL;
        ListNode * pre = NULL;
        for(int i = mid ;i < count && R_head == NULL;i++){
            ListNode * Next = R_head->next;
            R_head->next = pre;
            pre = R_head;
            R_head = Next;
        }
        ListNode * R_pre = new ListNode (0);
        R_pre ->next = R_head;
        
        while(L_head != NULL && R_head != NULL) {
            ListNode * R_Next = R_head->next;
            ListNode * L_Next = L_head->next;
            
            R_head->next = L_head->next;
            L_head->next = R_head;
            R_pre = R_head;
            R_head = R_Next;
            L_head = L_Next;
        }
        
        if(R_head != NULL)
            R_pre->next = R_head;
    }
};
//========================================
//测试数据
int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/(sizeof(int));
    
    ListNode * head = createLinkedList(arr, n);
    
    printLinkedList(head);
    
     Solution().reorderList(head);//调用 class (leetcode 测试函数方式)
    
    printLinkedList(head);
    deleteLinkedList(head);
    return 0;
}



