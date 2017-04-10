// Author :  Accagain
// Date   :  17/4/10
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Follow up for "Remove Duplicates":
 *
 * What if duplicates are allowed at most twice?
 *
 * For example,Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 *
 * It doesn't matter what you leave beyond the new length.
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
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return  0;
        int last = nums[0], cnt = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == last)
            {
                cnt++;
                if(cnt >= 3)
                {
                    nums.erase(nums.begin()+i);
                    i--;
                    cnt--;
                }
            } else
            {
                cnt = 1;
            }
            last = nums[i];

        }
        for(int i=0; i<nums.size(); i++)
            printf("%d ", nums[i]);
        return nums.size();
    }
};


int main() {
    Solution *test = new Solution();
    int data[] = {1, 1, 1, 2, 2, 3};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->removeDuplicates(x);
    return 0;
}

//
// Created by cms on 17/4/10.
//

