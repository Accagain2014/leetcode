// Author :  Accagain
// Date   :  17/4/10
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a set of distinct integers, nums, return all possible subsets.
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * For example,
 *
 * If nums = [1,2,3], a solution is:
 * [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []]
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
    void dfs(int now, vector<int> nums, vector<vector<int>> & ans, vector<int>hav)
    {
        if(now == nums.size())
        {
            ans.push_back(hav);
            return ;
        }
        dfs(now+1, nums, ans, hav);
        hav.push_back(nums[now]);
        dfs(now+1, nums, ans, hav);
        hav.pop_back();
        /*
        for(int i=now; i<nums.size(); i++)
        {
            dfs(now+1, nums, ans, hav);
            hav.push_back(nums[i]);
            dfs(i+1, nums, ans, hav);
            hav.pop_back();
        }
         */
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> hav;
        dfs(0, nums, ans, hav);
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=0; j<ans[i].size(); j++)
            {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 2, 3};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->subsets(x);
    return 0;
}

//
// Created by cms on 17/4/10.
//

