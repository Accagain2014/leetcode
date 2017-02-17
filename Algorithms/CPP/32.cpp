// Author :  Accagain
// Date   :  17/2/17
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a string containing just the characters '(' and ')',
 *
 * find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 * 做法：
 *      有点类似于KMP算法，保存(的位置，并且保存每一个）能达到的位置
 *      特殊样例：
 *          ()((()()()()()))
 *      
 * 时间复杂度：
 *      o(n)
 *          
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    struct Info
    {
        char c;
        int pos;
        Info(int c, int pos) : c(c), pos(pos) {};
    };

    int longestValidParentheses(string s) {
        int ans = 0;
        int next[s.size()];
        memset(next, -1, sizeof(next));
        stack<Info*> mys;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                Info * now = new Info(s[i], i);
                mys.push(now);
                next[i] = -1;
            } else
            {
                if(mys.empty())
                {
                    next[i] = -1;
                    continue;
                }
                Info * top = mys.top();
                mys.pop();
                if(top->c == '(')
                {
                    int tmp = top->pos;
                    while((tmp-1>=0) && (next[tmp-1] != -1))
                    {
                        tmp = next[tmp-1];
                    }
                    next[i] = tmp;
                    ans = max(ans, i-next[i]+1);
                } else
                {
                    next[i] = -1;
                    while(!mys.empty())
                        mys.pop();
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->longestValidParentheses(")()(())"));
    return 0;
}

//
// Created by cms on 17/2/17.
//

