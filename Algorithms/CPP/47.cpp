// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example, [1,1,2] have the following unique permutations:
 * [
 *  [1,1,2],
 *  [1,2,1],
 *  [2,1,1]
 * ]
 * 
 * 做法：
 *      dfs, 枚举的时候以不同的值开始枚举，开始先排个序
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
        int tmp = -INF;
        for(int i=0; i<nums.size(); i++)
        {
            if(!vis[i] && nums[i] != tmp)
            {
                vis[i] = 1;
                hav.push_back(nums[i]);
                tmp = nums[i];
                dfs(nums, ans, now+1, hav);
                hav.pop_back();
                vis[i] = 0;
            }

        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        memset(vis, 0, sizeof(vis));
        vector<vector<int>> ans;
        vector<int>hav;
        sort(nums.begin(), nums.end());
        dfs(nums, ans, 0, hav);
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 1, 3};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->permuteUnique(x);
    return 0;
}

//
// Created by cms on 17/3/26.
//

