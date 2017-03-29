// Author :  Accagain
// Date   :  17/3/29
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 *      Given 1->2->3->4->5->NULL and k = 2,
 *      return 4->5->1->2->3->NULL.
 * 
 * 做法：
 *      构造空头节点，直接模拟
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode empty_head(0) ;
        empty_head.next = head;
        ListNode * now = &empty_head;
        int num = 0;
        while(k)
        {
            now = now->next;
            k--;
            num++;

            if((now->next == NULL))
            {
                if(k)
                {
                    now = &empty_head;
                    k = k % num;
                }
                else
                    return head;
            }

        }
        ListNode * pre = &empty_head;
        while(now->next != NULL)
        {
            now = now->next;
            pre = pre->next;
        }
        now->next = head;
        ListNode * ans = pre->next;
        pre->next = NULL;
        return ans;

    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    return 0;
}

//
// Created by cms on 17/3/29.
//

