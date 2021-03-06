//
//  main.cpp
//  LeetCodeAdd Two Number
//
//  Created by Neworigin on 18/5/17.
//  Copyright © 2018年 Neworigin. All rights reserved.
//
#include<iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * first = l1;
        ListNode * second = l2;
        
        ListNode * head = new ListNode(0);
        ListNode * cur = head;
        
        int carry = 0;
        
        while(first || second || carry) {
            int sum = (first?first->val:0)+(second?second->val:0)+carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            if(first)
                first = first->next;
            if(second)
                second = second->next;
        }
        return head->next;
    }
};
//========================================
//5、测试数据
int main(int argc, const char * argv[]) {
    int arr[] = {2,4,3};
    int arr2[] = {5,6,4};
    int n = sizeof(arr)/(sizeof(int));
    
    ListNode * head = createLinkedList(arr, n);
    ListNode * head2 = createLinkedList(arr2, n);
    printLinkedList(head);
    printLinkedList(head2);
    ListNode * head3 = Solution().addTwoNumbers(head,head2);//调用 class (leetcode 测试函数方式)
    
    printLinkedList(head3);
    deleteLinkedList(head3);
    return 0;
}
