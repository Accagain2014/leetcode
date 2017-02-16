// Author :  Accagain
// Date   :  17/2/15
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 *
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4], A solution set is:
 *      [[-1, 0, 1],
 *      [-1, -1, 2]]
 *
 * 做法：
 *     突破口在于找到一种序的结构，利用它减小时间复杂度。
 *     排完序后，先枚举其中一个数，然后相当于在一个有序的结构中，找和固定的组数。
 *     左右向中间枚举，l, r, 当save[l] + save[r] > 0时，r--, 因为此时l参与的结果中，r右边的只会更大，不会构成结果。
 *     同样的道理，当save[l] + save[r] < 0 时, l++, 此时r参与的结果中，l之前的加起来将会更小，不会构成结果。
 *
 * 时间复杂度：
 *      O(N^2)
 *          
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if((i > 0) && (nums[i] == nums[i-1]))
            {
                continue;
            }
            int l = i+1;
            int r = nums.size()-1;
            while(l < r)
            {
                int now = nums[i] + nums[l] + nums[r];
                if(now > 0)
                {
                    r--;
                }
                else if(now < 0)
                {
                    l++;
                }
                else
                {
                    int tmp[3] = {nums[i], nums[l], nums[r]};
                    vector<int> x(tmp, tmp+sizeof(tmp)/sizeof(tmp[0]));
                    ans.push_back(x);
                    while(((l+1)<r) && (nums[l] == nums[l+1])) //值导向
                    {
                        l++;
                    }
                    while(((r-1)>l) && (nums[r-1] == nums[r]))
                    {
                        r--;
                    }
                    l++, r--;
                }

            }
        }

        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {0, 0, 0, 0};
    vector<int> myv(data, data + sizeof(data) / sizeof(data[0]));

    vector<vector<int>> ans;
    ans = test->threeSum(myv);
    for(int i=0; i<ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}


