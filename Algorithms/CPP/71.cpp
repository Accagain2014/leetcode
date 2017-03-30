// Author :  Accagain
// Date   :  17/3/30
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 *
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
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
#include <stack>
#include <vector>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:

    string simplifyPath(string path) {
        vector<string> mys;
        string now = "";
        if(path[path.size()-1] != '/')
            path = path + "/";
        for(int i=1; i<path.size(); i++)
        {
            if(path[i] == '/')
            {
                //printf(":::%s\n", now.c_str());
                if(now == "..")
                {
                    if(!mys.empty())
                        mys.erase(mys.end()-1);
                }
                else if(now != "." && now != "")
                    mys.push_back(now);
                now = "";
            }
            else
                now = now + path.substr(i, 1);
        }
        string ans = "";
        for(int i=0; i<mys.size(); i++)
            ans = ans + "/" + mys[i];
        if(ans == "")
            ans = "/";
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%s\n", test->simplifyPath("/...").c_str());
    return 0;
}

//
// Created by cms on 17/3/30.
//

