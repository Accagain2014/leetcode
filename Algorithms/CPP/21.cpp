// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Merge two sorted linked lists and return it as a new list.
 *
 * The new list should be made by splicing together the nodes of the first two lists.
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

/**
 * Definition for singly-linked list. */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode * ans = new ListNode(INF);
        ListNode * head = ans;

        while((l1) || (l2))
        {
            ListNode * now;
            if(!l1)
            {
                now = new ListNode(l2->val);
                l2 = l2->next;
            }
            else if(!l2)
            {
                now = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                if((l1->val) > (l2->val))
                {
                    now = new ListNode(l2->val);
                    l2 = l2->next;
                }
                else
                {
                    now = new ListNode(l1->val);
                    l1 = l1->next;
                }
            }

            ans->next = now;
            ans = ans -> next;
        }
        return head->next;
    }
};

using namespace std;

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

