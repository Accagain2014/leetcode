// Author :  Accagain
// Date   :  17/3/25
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 *
 * Return:
 * [
 *  ["ate", "eat","tea"],
 *  ["nat","tan"],
 *  ["bat"]
 * ]
 *
 * Note: All inputs will be in lower-case.
 * 
 * 做法：
 *      直接模拟，先排序并记录排序的序号，然后按照顺序输出不同的组
 *      
 * 时间复杂度：
 *      o(nlg(n))
 *          
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

#include <string>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    struct Info
    {
        string str;
        int location;
        bool operator < (const Info &a) const
        {
            if(a.str.compare(str)>0)
                return true;
            return false;
        }
        Info(string a, int b): str(a), location(b) {}
        Info(){}
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<Info> now;
        for(int i=0; i<strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            now.push_back(Info(tmp, i));
        }
        sort(now.begin(), now.end());
        vector<vector<string>> ans;
        vector<string> tmp;
        string now_str = "";
        for(int i=0; i<now.size(); i++)
        {
            if(now[i].str.compare(now_str))
            {
                if(!tmp.empty())
                    ans.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(strs[now[i].location]);
            now_str = now[i].str;
        }
        if(!tmp.empty())
            ans.push_back(tmp);
//        for(int i=0; i<ans.size(); i++)
//            for(int j=0; j<ans[i].size(); j++)
//                printf("%s\n", ans[i][j].c_str());
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    string data[] = {"eat", "eat"};
    vector<string> x(data, data + sizeof(data) / sizeof(data[0]));
    test->groupAnagrams(x);
    return 0;
}

//
// Created by cms on 17/3/25.
//

