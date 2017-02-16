// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * 做法：
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * emptyNode = new ListNode(INF);
        emptyNode->next = head;
        ListNode * now = emptyNode;

        while(true)
        {
            if(now == NULL)
                break;
            ListNode * tmp = now;
            ListNode * ne;
            for(int i=1; i<=k; i++)
            {
                ne = now->next;
                if(ne == NULL)
                    break;
                now = ne;
            }
            if(ne == NULL)
                break;

            now = tmp;
            ListNode *t1 = now->next;
            tmp = t1;
            ListNode *t2 = t1->next;

            for(int i=1; i<k; i++)
            {
               ListNode * next = t2->next;
               t2->next = t1;
                t1 = t2;
                t2 = next;
            }

            now->next = ne;
            tmp->next = t2;
            now = tmp;
        }
        return emptyNode->next;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 2, 3, 4, 5};
    ListNode * emptyHead = new ListNode(INF);
    ListNode * cur = emptyHead;

    for(int i=0; i<5; i++)
    {
        ListNode * now = new ListNode(data[i]);
        cur->next = now;
        cur = cur->next;
    }

    ListNode * ans = test->reverseKGroup(emptyHead->next, 1);

    while(ans)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }

    return 0;
}

//
// Created by cms on 17/2/16.
//

