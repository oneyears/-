//
//  main.cpp
//  Leetcode21Merge
//
//  Created by Neworigin on 18/5/18.
//  Copyright © 2018年 Neworigin. All rights reserved.
//

//
//  main.cpp
//  Leetcode82_Remove_Duplicates_from_Sorted_list2
//
//  Created by Neworigin on 18/5/17.
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
//========================================
//leetcode 函数
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * L_tail = NULL, * R_tail = NULL;
        L_tail = l1;
        R_tail = l2;
        ListNode * dummyNode = new ListNode (0);
        ListNode * cur = dummyNode;
        int s = 0;
        while(L_tail != NULL && R_tail != NULL) {
            if(L_tail->val < R_tail->val) {
                s = L_tail->val;
                cur->next = new ListNode (s);
                cur = cur->next;
                L_tail = L_tail->next;
                cout<<"s L_t"<<endl;
            }else{
                s = R_tail->val;
                cur->next = new ListNode (s);
                cur = cur->next;
                R_tail = R_tail->next;
                cout<<"s R_t"<<endl;
            }
        }
        while (L_tail) {
            s = L_tail->val;
            cur->next = new ListNode (s);
            cur = cur->next;
            L_tail = L_tail->next;
        }
        while (R_tail) {
            s = R_tail->val;
            cur->next = new ListNode (s);
            cur = cur->next;
            R_tail = R_tail->next;
        }
        return dummyNode->next;
    }
};
//========================================
//5、测试数据
int main(int argc, const char * argv[]) {
    int arr[] = {1,2,4};
    int arr2[] = {1,3,4};
    int n = sizeof(arr)/(sizeof(int));
    
    ListNode * head = createLinkedList(arr, n);
    ListNode * head2 = createLinkedList(arr2, 3);
    printLinkedList(head);
    printLinkedList(head2);
    ListNode * head3 = Solution().mergeTwoLists(head,head2);//调用 class (leetcode 测试函数方式)
    
    printLinkedList(head3);
    deleteLinkedList(head3);
    return 0;
}
