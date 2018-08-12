//
//  main.cpp
//  Leetcode206ReverseLinkedList
//
//  Created by Neworigin on 18/5/14.
//  Copyright © 2018年 Neworigin. All rights reserved.
//

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

struct ListNode {
    int val;
    ListNode * next;
    ListNode (int x) : val(x),next(NULL) {}
};

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

void printLinkedList(ListNode * head) {
    ListNode * curNode = head;
    
    while (curNode != NULL) {
        cout<<curNode->val<<" "<<"->";
        curNode = curNode->next;
    }
    cout<<"NULL"<<endl;
    return;
    
}

void deleteLinkedList(ListNode * head) {
    ListNode * curNode = head;
    while (curNode != NULL) {
        ListNode * delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *  pre = NULL;//pre为新定义的指针，用来作为返向链表的指针
        ListNode *  cur = head;
        
        while (cur != NULL) {
            ListNode * next  = cur -> next;
            
            cur -> next = pre;
            
            pre = cur;
            
            cur = next;
        }
        
        return pre;
    }
};

int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/(sizeof(int));
    
    ListNode * head = createLinkedList(arr, n);
    
    printLinkedList(head);
    
    ListNode * head2 = Solution().reverseList(head);
    
    printLinkedList(head2);
    deleteLinkedList(head2);
    return 0;
}



