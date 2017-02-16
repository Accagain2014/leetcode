// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given an array S of n integers, find three integers in S such that the sum is closest to
 *
 * a given number, target. Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 * 做法：
 *
 * 时间复杂度：
 *          O(n^2)
 *
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#define  INF 0x3fffffff

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sub = INF;
        int ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            int now = nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > target)
                    r--;
                else
                    l++;
                int tmp = abs(sum - target);
                if(tmp < sub)
                {
                    sub = tmp;
                    ans = sum;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {-1, 2, 1, -4};
    vector<int> x(data, data+sizeof(data)/sizeof(data[0]));
    printf("%d\n", test->threeSumClosest(x, 1));
    return 0;
}

//
// Created by cms on 17/2/16.
//

