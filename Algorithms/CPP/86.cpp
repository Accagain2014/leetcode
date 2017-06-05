// Author :  Accagain
// Date   :  17/5/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * 题意：
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * empty = new ListNode(0);
        empty->next = head;
        ListNode * pre = empty;

        ListNode * ans = new ListNode(0);
        ListNode * p = ans;
        while(head)
        {
            if(head->val < x)
            {
                p->next = new ListNode(head->val);
                p = p->next;
                pre->next = head->next;
                head = head->next;
            }
            else
            {
                head = head->next;
                pre = pre->next;
            }
        }
        p->next = empty->next;
        return ans->next;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 4, 3, 2, 5, 2};

    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    ListNode * ca = new ListNode(0);
    ListNode * p = ca;

    for(int i=0; i<x.size(); i++)
    {
        p->next = new ListNode(x[i]);
        p = p->next;
    }
    ListNode *ans = test->partition(ca->next, 3);
    while(ans)
    {
        printf("%d\n", ans->val);
        ans = ans->next;
    }
    return 0;
}

//
// Created by cms on 17/5/26.
//

