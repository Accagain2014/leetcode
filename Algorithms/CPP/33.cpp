// Author :  Accagain
// Date   :  17/2/17
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * 做法：
 *      
 * 时间复杂度：
 *          O(N)
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

    int search(vector<int>& nums, int target) {
        int ans = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(target == nums[i])
                ans = i;
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {4,5,6,7,8,1,2,3};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->search(x, 8));
    return 0;
}

//
// Created by cms on 17/2/17.
//

