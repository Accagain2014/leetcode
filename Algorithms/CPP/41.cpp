// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 * 
 * 做法：
 *      维护和，没有考虑到重复的情况，可以记录个数，和Max-Min+1比较，可以算出重复的数的个数
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
    int firstMissingPositive(vector<int>& nums) {
        // 将nums[i]放到nums[i]-1的位置，最后扫描哪个位置空
        for(int i=0; i<nums.size(); i++)
        {
            while(nums[i] > 0 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != i+1)
                return i+1;
        return nums.size()+1;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 2, 4, 2};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->firstMissingPositive(x));
    return 0;
}

//
// Created by cms on 17/3/26.
//

