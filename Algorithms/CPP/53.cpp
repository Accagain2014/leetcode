// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 *
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * 
 * 做法：
 *      简单dp, dp[i]表示到i截止能达到的最大连续子序列
 *
 * 时间复杂度：
 *    O(n)
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
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int ans = sum;

        for(int i=1; i<nums.size(); i++)
        {
           sum = max(sum + nums[i], nums[i]);
           ans = max(ans, sum);
        }
        //printf("%d\n", ans);
        return ans;

    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->maxSubArray(x));
    return 0;
}

//
// Created by cms on 17/3/28.
//

