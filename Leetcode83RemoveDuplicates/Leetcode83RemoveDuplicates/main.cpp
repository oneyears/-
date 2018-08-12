//
//  main.cpp
//  Leetcode83RemoveDuplicates
//
//  Created by Neworigin on 18/5/15.
//  Copyright © 2018年 Neworigin. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode * new_head = new ListNode (0);
        new_head->next = head;
        if(head == NULL) return new_head->next;
        ListNode * cur = new_head->next;
        ListNode * Next = cur->next;
        while ( Next!=NULL) {
            ListNode * move = Next->next;
            if (cur->val != Next->val)
            {
                cur = Next;
                Next = move;
            }else{
                cur->next = Next->next;
                Next = move;
            }
        }
        return new_head->next;
    }
};
//========================================
//5、测试数据
int main(int argc, const char * argv[]) {
    int arr[] = {1,1,1};
    int n = sizeof(arr)/(sizeof(int));
    
    ListNode * head = createLinkedList(arr, n);
    
    printLinkedList(head);
    
    ListNode * head2 = Solution().deleteDuplicates(head);//调用 class (leetcode 测试函数方式)
    
    printLinkedList(head2);
    deleteLinkedList(head2);
    return 0;
}


