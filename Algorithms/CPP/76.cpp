// Author :  Accagain
// Date   :  17/4/10
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 *
 * S = "ADOBECODEBANC"
 *
 * T = "ABC"
 *
 * Minimum window is "BANC".
 *
 * Note:
 *
 * If there is no such window in S that covers all characters in T, return the empty string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 * 
 * 做法：
 *      扫两遍。
 *
 * 时间复杂度：
 *     O(N)
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int>myp;
        for(int i=0; i<t.size(); i++)
            myp[t[i]]++;
        int begin=0, end=0, cnt=t.size(), ans=INF, ans_be=0;
        while(end < s.size())
        {
            if(myp[s[end++]]-- > 0)
                cnt--;
            while(!cnt) //直到不可行的时候
            {
                if(end-begin < ans)
                {
                    ans = end-begin;
                    ans_be = begin;
                }
                if(myp[s[begin++]]++ == 0) //
                {
                    cnt++;
                }
            }
        }
        return (ans == INF) ? ("") : (s.substr(ans_be, ans));
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%s\n", test->minWindow("abcddd", "bd").c_str());
    return 0;
}



