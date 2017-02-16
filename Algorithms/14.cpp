// Author :  Accagain
// Date   :  17/2/15
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * 做法：
 *      暴力
 *
 * 时间复杂度：
 *      o(nm) n为字符串的个数，m为字符串的长度
 *
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
            return "";
        string ans = strs[0];
        for(int i=1; i<strs.size(); i++)
        {
            for(int j=0; j<ans.size(); j++)
            {
                if(strs[i][j] != ans[j])
                {
                    ans = ans.substr(0, j);
                    break;
                }

            }
        }
        return ans;
    }
};


int main() {
    Solution * test = new Solution();

    vector<string> myv;
    myv.push_back("abcd");
    myv.push_back("abce");
    myv.push_back("abd");

    printf("%s\n", test->longestCommonPrefix(myv).c_str());
    return 0;
}

//
// Created by cms on 17/2/15.
//

