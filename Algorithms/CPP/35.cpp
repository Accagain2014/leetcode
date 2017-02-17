// Author :  Accagain
// Date   :  17/2/17
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a sorted array and a target value, return the index if the target is found.
 *
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 *
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 * 做法：
 *      二分
 *
 * 时间复杂度：
 *      olog(n)
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
    int searchInsert(vector<int>& nums, int target) {

        int l=0, r=nums.size()-1, mid;
        int ans = nums.size();

        while(l<=r)
        {
            mid = (l+r)>>1;
            //printf("...%d\n", nums[mid]);
            if(target == nums[mid])
            {
                ans = mid;
                break;
            }
            else if(target < nums[mid])
            {
                ans = min(ans, mid);
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }

    int searchInsertN(vector<int>& nums, int target) {

        int ans = nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            if(target <= nums[i])
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->searchInsert(x, 7));
    return 0;
}

//
// Created by cms on 17/2/17.
//

