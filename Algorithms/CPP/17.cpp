// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 *
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 * 做法：
 *     直接DFS枚举
 *
 * 时间复杂度：
 *
 *
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string MAP[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        ans.clear();
        if(digits == "")
            return ans;
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string digits, int pos, string now)
    {
        //printf("** %d\n", pos);

        if(pos > digits.size() - 1)
        {
            ans.push_back(now);
            return;
        }

        //printf("%s\n", MAP[digits[pos]-].c_str());
        for(int i=0; i<MAP[digits[pos]-'0'].size(); i++)
        {
            dfs(digits, pos+1, now+MAP[digits[pos]-'0'][i]);
        }
    }
};

int main() {
    Solution *test = new Solution();
    vector<string> ans = test->letterCombinations("23");
    printf("%d\n", ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%s\n", ans[i].c_str());
    return 0;
}



