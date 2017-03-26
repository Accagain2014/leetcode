// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a collection of candidate numbers (C) and a target number (T),
 *
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note: All numbers (including target) will be positive integers.
 *
 * The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 *
 * A solution set is:
 * [
 *  [1, 7],
 *  [1, 2, 5],
 *  [2, 6],
 *  [1, 1, 6]]
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

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    bool vis[120000];
    void dfs(vector<vector<int>> & ans, vector<int> candidates, int target, int now_sum, int now, vector<int> hav)
    {
//        for(int i=0; i<hav.size(); i++)
//            printf("%d ", hav[i]);
//        printf("\n");

        if(now == candidates.size())
        {
            if(now_sum == target)
            {
                ans.push_back(hav);
                for(int i=0; i<hav.size(); i++)
                    printf("%d ", hav[i]);
                printf("\n");

            }
            return;
        }
        if(!((now >= 1) && hav.size() > 0 && (candidates[now] == hav[hav.size()-1])))
        {
            dfs(ans, candidates, target, now_sum, now+1, hav);
        }
        hav.push_back(candidates[now]);
        if(now_sum+candidates[now] <= target)
            dfs(ans, candidates, target, now_sum+candidates[now], now+1, hav);
        hav.pop_back();

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        //int vis[candidates.size()];
        memset(vis, 0, sizeof(vis));
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> hav;
        dfs(ans, candidates, target, 0, 0, hav);
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->combinationSum2(x, 8);
    return 0;
}

//
// Created by cms on 17/3/26.
//

