// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 *
 * Given n will always be valid.
 *
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * ans = head;
        ListNode * now = head;
        ListNode * ne = head;

        for(int i=0; i<=n; i++)
        {
            if(ne == NULL) //注意头部情况
                return head -> next;
            ne = ne->next;
        }
        while(ne != NULL)
        {
            now = now -> next;
            ne = ne -> next;
        }

        now->next = now->next-next;
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("\n", test->);
    return 0;
}


