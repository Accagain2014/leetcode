// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example, [1,2,3] have the following permutations:
 * [
 *  [1,2,3],
 *  [1,3,2],
 *  [2,1,3],
 *  [2,3,1],
 *  [3,1,2],
 *  [3,2,1]]
 *
 * 做法：
 *      dfs
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

    bool vis[12000];

    void dfs(vector<int> nums, vector<vector<int>> &ans, int now, vector<int>hav)
    {
        if(now == nums.size())
        {
//            for(int i=0; i<hav.size(); i++)
//                printf("%d ", hav[i]);
//            printf("\n");

            ans.push_back(hav);
            return ;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(!vis[nums[i]])
            {
                vis[nums[i]] = 1;
                hav.push_back(nums[i]);
                dfs(nums, ans, now+1, hav);
                hav.pop_back();
                vis[nums[i]] = 0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        memset(vis, 0, sizeof(vis));
        vector<vector<int>> ans;
        vector<int>hav;
        dfs(nums, ans, 0, hav);
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 2, 3};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->permute(x);
    return 0;
}

//
// Created by cms on 17/3/26.
//

