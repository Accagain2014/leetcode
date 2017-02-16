// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *  "((()))",
 *  "(()())",
 *  "(())()",
 *  "()(())",
 *  "()()()"
 * ]
 *
 * 做法：
 *      dfs
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

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        ans.clear();
        dfs(0, n, "");
        return ans;
    }

    void dfs(int hav, int sum, string now)
    {
        int tmp = now.size();
        if(tmp == sum*2)
        {
            ans.push_back(now);
            return ;
        }

        if(hav < sum)
            dfs(hav+1, sum, now+"(");
        if(hav > (tmp - hav))
            dfs(hav, sum, now+")");
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    vector<string> ans = test->generateParenthesis(1);
    for(int i=0; i<ans.size(); i++)
        printf("%s\n", ans[i].c_str());
    return 0;
}

//
// Created by cms on 17/2/16.
//

