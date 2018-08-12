//
//  main.cpp
//  Leetcode234_PalindromeLinkedList
//
//  Created by Neworigin on 18/5/19.
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
    bool isPalindrome(ListNode* head) {
        ListNode * L_head = NULL,* L_tail = NULL;
        ListNode * R_head = NULL,* R_tail = NULL;
        ListNode * p = head;
        ListNode * cnode = head;
        int count = 0;
        while(cnode != NULL) {
            
            count++;
            cnode = cnode->next;
            
        }
        // if() 括号里定义的变量
        int mid = count / 2;
    
        
        for(int i = 0 ; i < mid; i++) {
            if(L_tail == NULL)
            {
               L_head = L_tail = p;
            }
            else{
                L_tail = L_tail->next;
            }
            p = p ->next;
        }
        if(count % 2 == 1) {
            p = p->next;
        }
        for(int i = mid; i < count;i++){
            if(R_tail != NULL)
            {
                R_tail = R_tail->next;
                
            }else{
                R_head = R_tail = p;
            }
            p = p->next;
        }
        R_tail->next = NULL;
        L_tail->next = NULL;
        
        while(R_head != NULL && L_head != NULL) {
            if(R_head->val != L_head->val) {
                return false;
            }
            R_head = R_head->next;
            L_head = L_head->next;
        }
        return true;
    }
};
//========================================
//测试数据
int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/(sizeof(int));
    
    ListNode * head = createLinkedList(arr, n);
    
    printLinkedList(head);
    
    ListNode * head2 = Solution().isPalindrome(head);//调用 class (leetcode 测试函数方式)
    
    printLinkedList(head2);
    deleteLinkedList(head2);
    return 0;
}
