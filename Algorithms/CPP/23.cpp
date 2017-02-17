// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = new ListNode(INF);
        ListNode * ans = head;

        while(true)
        {
            //bool allTure = true;
            int now = INF;
            int rec;

            for(int i=0; i<lists.size(); i++)
            {
                if(lists[i] != NULL)
                {
                   if(lists[i]->val < now) {
                       rec = i;
                       now = lists[i]->val;
                   }
                }
            }
            //printf("%d %d\n", rec, now);
            if(now != INF)
            {
                ans->next = new ListNode(now);
                ans = ans->next;
                lists[rec] = lists[rec]->next;
            }
            else
                break;
        }
        return head->next;
    }

};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));

    ListNode * tmp = new ListNode(0);
    vector<ListNode*> myv;
    myv.push_back(tmp);

    printf("%d\n", test->mergeKLists(myv)->val);
    return 0;
}



