// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 *
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note: The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * [-1,  0, 0, 1],
 * [-2, -1, 1, 2],
 * [-2,  0, 0, 2]
 * ]
 * 
 * 做法：
 *      
 * 时间复杂度：
 *         O(n^3)
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if((i > 0) && (nums[i] == nums[i-1]))
                continue;
            int now = nums[i];

            for(int j=i+1; j<nums.size(); j++)
            {
                int next = nums[j];
                if((j-i>=2) && (nums[j] == nums[j-1]))
                    continue;

                int l = j+1;
                int r = nums.size() - 1;
                while(l < r)
                {
                    int sum = now + next + nums[l] + nums[r];
                    if(sum > target)
                        r--;
                    else if( sum < target)
                        l++;
                    else
                    {
                        int tmp[] = {now, next, nums[l], nums[r]};
                        vector<int> x(tmp, tmp+sizeof(tmp)/sizeof(tmp[0]));
                        ans.push_back(x);
                        while((l+1 < r) && (nums[l] == nums[l+1]))
                        {
                            l++;
                            continue;
                        }
                        while((l < r-1) && (nums[r] == nums[r-1]))
                        {
                            r--;
                            continue;
                        }
                        l++;
                        r--;
                    }

                }
            }
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1,-2,-5,-4,-3,3,3,5};

    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    vector<vector<int>> ans = test->fourSum(x, -11);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            printf("%d ", ans[i][j]);
        putchar('\n');
    }
    return 0;
}



