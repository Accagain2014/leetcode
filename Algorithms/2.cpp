// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/************************************************************************
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 *
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 *
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4
 *
 * Output: 7 -> 0 -> 8
 *
*************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int gain = 0;
        ListNode * ans = (ListNode *)malloc(sizeof(ListNode));
        ListNode * head = ans;
        while((l1 != NULL) && (l2 != NULL))
        {
            ListNode * now = (ListNode * )malloc(sizeof(ListNode));
            now->val = ((l1->val + l2->val + gain) % 10);
            now->next = NULL;
            gain = (l1->val + l2->val + gain) / 10;
            ans->next = now;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            ListNode * now = (ListNode *)malloc(sizeof(ListNode));
            now->val = ((l1->val + gain) % 10);
            now->next = NULL;
            gain = (l1->val + gain) / 10;
            ans->next = now;
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            ListNode * now = (ListNode *)malloc(sizeof(ListNode));
            now->val = ((l2->val + gain) % 10);
            now->next = NULL;
            gain = (l2->val + gain) / 10;
            ans->next = now;
            ans = ans->next;
            l2 = l2->next;
        }
        while(gain)
        {
            ListNode * now = (ListNode *)malloc(sizeof(ListNode));
            now->val = (gain % 10);
            now->next = NULL;
            gain = gain / 10;
            ans->next = now;
            ans = ans->next;
        }
        return head->next;
    }
};

int main()
{
    int testN;
    scanf("%d", &testN);
    for(int i=1; i<=testN; i++)
    {
        int n;
        scanf("%d", &n);
        ListNode * l1 = (ListNode *)malloc(sizeof(ListNode));
        l1->next = NULL;
        ListNode * cur = l1;

        for(int j=1; j<=n; j++)
        {
            int temp;

            scanf("%d", &temp);
            //printf("%d", temp);
            ListNode *  now = (ListNode * ) malloc(sizeof(ListNode));
            now->next = NULL;
            now->val = temp;
            cur->next = now;
            cur = cur->next;
        }

        ListNode * l2 = (ListNode *)malloc(sizeof(ListNode));
        l2->next = NULL;
        cur = l2;
        scanf("%d", &n);
        for(int j=1; j<=n; j++)
        {
            int temp;
            scanf("%d", &temp);
            ListNode * now = (ListNode * ) malloc(sizeof(ListNode));
            now->next = NULL;
            now->val = temp;
            cur->next = now;
            cur = cur->next;
        }
        //printf("%d ** %d\n", l1->next->val, l2->next->val);

        Solution* test = new Solution();
        ListNode * ans = test->addTwoNumbers(l1->next, l2->next);
        while(ans != NULL)
        {
            printf("%d ", ans->val);
            ans = ans->next;
        }
    }
}
