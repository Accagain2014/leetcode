// Author :  Accagain
// Date   :  17/4/10
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an array with n objects colored red, white or blue,
 *
 * sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this problem.
 *
 * click to show follow up.
 *
 * Follow up:
 *
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 *
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 * 
 * 做法：
 *    从前往后扫，碰到0，往前面交换，碰到2，往后面交换；
 *
 * 时间复杂度：
 *    O(N) 扫一遍
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
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt2 = nums.size()-1, n = nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            if(i > cnt2 || i < cnt0)
                break;
            if(nums[i] == 0)
            {
                swap(nums[cnt0], nums[i]);
                cnt0 ++;
            }
            else if(nums[i] == 2)
            {
                swap(nums[cnt2], nums[i]);
                cnt2 --;
                i--;
            }
        }
        for(int i=0; i<nums.size(); i++)
            printf("%d ", nums[i]);
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {0, 2, 1};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->sortColors(x);
    return 0;
}

//
// Created by cms on 17/4/10.
//

