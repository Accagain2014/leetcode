// Author :  Accagain
// Date   :  17/4/11
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 *
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

    int search(vector<int> &nums, int target) {
        if(nums.size() == 0)
        {
            return false;
        }

        int l = 0, r = nums.size() - 1;
        int ans = -1;
        int same[nums.size()];
        int last = -INF, re = -1;

        for(int i=0; i<r; i++)
        {
            if (nums[i] != last)
            {
                last = nums[i];
                re = i;
                same[i] = i;
            }
            else
            {
                same[i] = re;
            }
            printf("%d ", same[i]);
        }

        while (l <= r) {

            int mid = (l + r) / 2;

            //printf("%d %d\n", mid, nums[mid]);

            if (target == nums[mid]) {
                ans = mid;
                break;
            } else if ((nums[l] < nums[mid])  || ((nums[l] == nums[mid]) && (same[mid] <= l))) {  //怎样确定是左边
                // 2 2 2 2 1 1 2 的情况确定

                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }

        }
        return ans == -1 ? false : true;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 1, 3, 1, 1, 1, 1};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->search(x, 3));
    return 0;
}

//
// Created by cms on 17/4/11.
//

