//
//  main.cpp
//  Leetcode92ReverseLinkedList2
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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //1、新定义一个空结点new_head
        ListNode * new_head = new ListNode(0);
        //2、将new_head的next指针 指向 head 使得new_head与head链表连接
        //成一条链表
        new_head->next = head;
        
        //3、新定义结点Pre 移动到结点new_head位置
        ListNode * pre = new_head;//pre为头结点
        
        for(int i = 0; i < m-1; i ++) {
            //4、移动pre的位置m-1次
            pre = pre->next;
            
        }
            //5、 新定义结点cur ，并把它移动到pre的next结点上（把cur指针 移动到 pre的next结点的位置上）
            ListNode * cur = pre->next;

       
        for (int i = 0; i < n - m; i++) {
            //6、新定义move结点 ，把它移动到的cur的next结点上
            ListNode * move = cur->next;
            //7、将cur的next指针 指向move的next结点的位置上
            cur->next = move->next;
            //8、将move的next指针指向 pre的next结点的位置上
            move->next = pre->next;
            //9、将pre的next指针指向 move结点位置上
            pre->next = move;
            
        }
        
        return  new_head->next;
    }
};

int main(int argc, const char * argv[]) {

    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/(sizeof(int));
    
    ListNode * head = createLinkedList(arr, n);
    
    printLinkedList(head);
    
    ListNode * head2 = Solution().reverseBetween(head,2,4);
    //调用 class (leetcode 测试函数方式)
    
    printLinkedList(head2);
    
    
}



