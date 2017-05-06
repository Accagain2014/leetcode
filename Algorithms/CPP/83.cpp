// Author :  Accagain
// Date   :  17/5/2
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
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
 * Definition for singly-linked list.*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * ans = new ListNode(INF);
        ListNode * p = ans;
        while(head)
        {
            if(head->val == p->val)
                head = head->next;
            else
            {
                p->next = head;
                p = head;
                head = head->next;
            }
        }
        p->next = NULL;
        return ans->next;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 1, 2, 2, 2, 2, 3, 3};
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

