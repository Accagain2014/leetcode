// Author :  Accagain
// Date   :  17/4/10
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [[2,4],
 * [3,4],
 * [2,3],
 * [1,2],
 * [1,3],
 * [1,4],]
 * 
 * 做法：
 *
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
    void dfs(int n, int now, int k, vector<vector<int>> & ans, vector<int> hav, int pre)
    {
        if(now == k)
        {
            ans.push_back(hav);
            return ;
        }
        for(int i=pre+1; i<=n; i++)
        {
            hav.push_back(i);
            dfs(n, now+1, k, ans, hav, i);
            hav.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> hav;
        dfs(n, 0, k, ans, hav, 0);
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=0; j<ans[i].size(); j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->combine(4, 2);
    return 0;
}

//
// Created by cms on 17/4/10.
//

