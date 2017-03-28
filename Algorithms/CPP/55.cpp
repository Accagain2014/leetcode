// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 *
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 * 
 * 做法：
 *
 *      记录在首位置，并且在当前位置，能到达的最大的。
 *      不行就跳出来
 *
 * 时间复杂度：
 *      O(n)
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
    bool canJump(vector<int>& nums) {
        int canFarest = 0, nowStep = 0, ans = 0;
        for(int i=0; i<nums.size(); i++)
        {

            if(i == nowStep)
            {
                ans++;
                canFarest = max(canFarest, nums[i]+i);
                nowStep = canFarest;
            }
            else if(i > nowStep)
                break;
            canFarest = max(canFarest, nums[i]+i);
            //printf("i:%d %d %d\n", i, nowStep, canFarest);
        }
        if(canFarest >= nums.size()-1)
            return true;
        return false;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {0};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->canJump(x));
    return 0;
}

//
// Created by cms on 17/3/28.
//

