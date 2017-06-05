// Author :  Accagain
// Date   :  17/5/2
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * 题意：
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 *
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 *
 * Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *emptyH = new ListNode(INF);
        emptyH->next = head;
        ListNode * ans = emptyH;
        if((head == NULL) || (head->next == NULL))
            return head;
        ListNode * p = head->next;
        while(p != NULL)
        {
            if((p->val) != (head->val))
            {
                emptyH->next = head;
                emptyH = head;
                head = p;
                p = p->next;
            }
            else
            {
                while((p != NULL) && ((p->val) == (head->val)))
                {
                    p = p->next;
                }

                head = p;
                if(p != NULL)
                    p = p->next;
                else
                    emptyH->next = NULL;
            }
        }

        if(head)
        {
            printf("****");
            emptyH->next = head;
        }

        return ans->next;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 1, 3, 3, 3, 3,3 , 4, 5, 5};
    ListNode * head = new ListNode(INF);
    ListNode * p = head;
    for(int i=0; i<sizeof(data) / sizeof(data[0]); i++)
    {
        ListNode * now = new ListNode(data[i]);
        p->next = now;
        p = now;
    }
    head = test->deleteDuplicates(head->next);
    while(head)
    {
        printf("%d\n", head->val);
        head = head->next;
    }

    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    return 0;
}

//
// Created by cms on 17/5/2.
//

