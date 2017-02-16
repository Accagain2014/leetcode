// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * Given a string s, find the longest palindromic substring in s.
 *
 * You may assume that the maximum length of s is 1000.
 *
 * Example:
 *      Input: "babad"
 *      Output: "bab"
 *      Note: "aba" is also a valid answer.
 *
 * Example:
 *      Input: "cbbd"
 *      Output: "bb"
 *
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

/*
 * 注意将字符串翻转，然后求最长公共子串的做法不对，反例 abcdefdcba
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return 0;

        int ans = 0;
        int begin, end;

        for(int i=0; i<s.size(); i++)
        {
            int temp = 1;
            //begin = i; end = i;
            if(ans < 1)
            {
                ans = 1;
                begin = i;
                end = i;
            }
            for(int j=1; (i-j>=0) && ((i+j)<s.size()); j++)
            {
                if(s[i-j] == s[i+j])
                {
                    temp += 2;
                    if(temp > ans)
                    {
                        begin = i-j;
                        end = i+j;
                        ans = temp;
                    }

                }
                else
                    break;
            }

            temp = 0;
            for(int j=0; (i>=j) && ((i+j+1)<s.size()); j++) {
                if (s[i - j] == s[i + j + 1])
                {
                    temp += 2;
                    if (temp > ans) {
                        begin = i - j;
                        end = i + j + 1;
                        ans = temp;
                    }
                }
                else
                    break;
            }
        }
        //printf("%d %d %d\n", begin, end, ans);
        return s.substr(begin, ans);
    }
};

int main()
{
    Solution * test = new Solution();
    printf("%s\n", test->longestPalindrome("aaaa").c_str());
    return 0;
}