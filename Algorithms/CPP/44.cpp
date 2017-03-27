// Author :  Accagain
// Date   :  17/3/27
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 *
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 *
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 *
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 *
 * 做法：
 *      dp[n]表示，s[:n]是否匹配p[:i]
 *      扫描p, 再扫描s, 更新dp
 * 时间复杂度：
 *          O(n*m)
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
    bool isMatch(string s, string p) {
        int n = s.size();
        bool dp[n+10];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=0; i<p.size(); i++)
        {
            char now = p[i];
            if(now != '*')
            {
                for(int j=n-1; j>=0; j--)
                {
                    dp[j+1] = dp[j] && ((now == s[j]) || (now == '?'));
                }
            }
            else
            {
                for(int j=0; j<n; j++)
                    dp[j+1] = dp[j] || dp[j+1];
            }
//            printf("i: %d\n", i);
//            for(int j=1; j<=n; j++)
//                printf("%d ", dp[j]);
//            printf("\n");
            dp[0] = dp[0] && (now == '*'); //dp[0]表示空只匹配****
        }
        return dp[n];
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->isMatch("aab", "c*a*b"));
    return 0;
}

//
// Created by cms on 17/3/27.
//

