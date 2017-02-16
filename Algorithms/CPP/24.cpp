// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example, Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 *
 * 做法：
 *      模拟
 *
 * 时间复杂度：
 *          
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 0x3fffffff

using namespace std;

/**
 * Definition for singly-linked list. */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode * emptyHead = new ListNode(INF);
        emptyHead->next = head;
        ListNode * now = emptyHead;

        while(true)
        {
            if(now == NULL)
                break;
            ListNode * first = now->next;
            if(first == NULL)
                break;
            ListNode * second = first->next;
            if(second == NULL)
                break;
            ListNode * tmp = second->next;
            now->next = second;
            second->next = first;
            first->next = tmp;
            now = first;
        }
        return head->next;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("\n", test->);
    return 0;
}

//
// Created by cms on 17/2/16.
//

