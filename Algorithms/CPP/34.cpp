// Author :  Accagain
// Date   :  17/2/17
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given an array of integers sorted in ascending order,
 *
 * find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
 *
 * 做法：
 *      
 * 时间复杂度：
 *      log(N)
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans[2] = {-1, -1};
        vector<int> myv(ans, ans+sizeof(ans)/sizeof(ans[0]));

        int l=0, r=nums.size()-1;
        int mid;
        int tmp = INF;

        while(l<=r)  //向右延伸最大位置
        {
            mid = (l+r)/2;
            if(nums[mid] == target)
            {
                tmp = mid;
                break;
            }
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(tmp == INF)
            return myv;
        else
        {
            l=tmp; r=nums.size()-1;
            myv[0] = tmp;
            myv[1] = tmp;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(nums[mid] == target)
                {
                    l=mid+1;
                    myv[1] = max(myv[1], mid);
                }
                else
                {
                    r=mid-1;
                }
            }

            l=0; r=tmp;
            while(l<=r) //向左延伸最大位置
            {
                mid = (l+r)/2;
                if(nums[mid] == target)
                {
                    r=mid-1;
                    myv[0] = min(myv[1], mid);
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        return myv;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {5, 7, 7, 8, 8, 10};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    vector<int> ans = test->searchRange(x, 8);
    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}

//
// Created by cms on 17/2/17.
//

