// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T),
 *
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note: All numbers (including target) will be positive integers.
 *
 * The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set [2, 3, 6, 7] and target 7,
 *
 * A solution set is:
 *
 * [
 *  [7],
 *  [2, 2, 3]
 * ]
 * 
 * 做法：
 *      直接dfs
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
    void dfs(vector<vector<int>> & ans, vector<int> candidates, int target, int now_sum, int now, vector<int> hav)
    {
        if(now == candidates.size())
        {
            if(now_sum == target)
            {
                ans.push_back(hav);
//                for(int i=0; i<hav.size(); i++)
//                    printf("%d ", hav[i]);
                printf("\n");

            }
            return;
        }

        int tmp = now_sum;
        int time = 0;
        dfs(ans, candidates, target, now_sum, now+1, hav);

        while(tmp + candidates[now] <= target)
        {
            time ++;
            for(int i=1; i<=time; i++)
                hav.push_back(candidates[now]);
            dfs(ans, candidates, target, tmp + candidates[now], now+1, hav);
            for(int i=1; i<=time; i++)
                hav.pop_back();
            tmp += candidates[now];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> hav;
        dfs(ans, candidates, target, 0, 0, hav);
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {2, 3, 6, 7};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->combinationSum(x, 7);
    return 0;
}

//
// Created by cms on 17/3/26.
//

