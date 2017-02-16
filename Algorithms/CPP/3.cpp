// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/************************************************************************
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *      Given "abcabcbb", the answer is "abc", which the length is 3.
 *      Given "bbbbb", the answer is "b", with the length of 1.
 *      Given "pwwkew", the answer is "wke", with the length of 3.
 *      Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
*************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        int ans = 1;
        int save[1000];
        memset(save, -1, sizeof(save));
        int begin = 0;
        save[s[0]-'a'+500] = 0;
        for(int i=1; i<s.size(); i++)
        {
            int now = s[i] - 'a' + 500;
            if(save[now] != -1)
                begin = max(begin, save[now] + 1);
            //printf("%c %d %d %d %d %d\n", s[i], i, now, save[now], begin, ans);
            save[now] = i;
            ans = max(ans, i - begin + 1);
        }
        return ans;
    }
};

int main()
{
    printf("%d\n", 'A' - 'a');
    Solution * a = new Solution();
    printf("%d\n", a->lengthOfLongestSubstring("abba"));
    return 0;
}