// Author :  Accagain
// Date   :  17/2/17
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * You are given a string, s, and a list of words, words, that are all of the same length.
 *
 * Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once
 *
 * and without any intervening characters.
 *
 * For example, given:
 *
 * s: "barfoothefoobarman"
 *
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 *
 * (order does not matter).
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
#include <map>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        map<string, int> myp1;
        map<string, int> myp2;
        for(int i=0; i<words.size(); i++)
        {
            myp1[words[i]]++;
            myp2[words[i]]++;
        }
        int len = words[0].size();
        for(int i=0; (i+len*words.size()) <= s.size(); i++)
        {
            bool flag = 1;
            myp1 = myp2;
            for(int k=0; k<words.size(); k++)
            {
                string now = s.substr(i+k*len, len);
                if(myp1[now])
                    myp1[now]--;
                else
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    string data[] = {"foo", "bar"};
    vector<string> x(data, data + sizeof(data) / sizeof(data[0]));
    vector<int> hi = test->findSubstring("barfoothefoobarman", x);
    for(int i=0; i<hi.size(); i++)
    {
        printf("%d ", hi[i]);
    }
    return 0;
}


