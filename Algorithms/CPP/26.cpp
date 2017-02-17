// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example, Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
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

using  namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> & nums) {
        int ans = 0;
        int last = INF;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != last)
            {
                ans++;
                last = nums[i];
            }
            else
            {
                nums.erase(nums.begin()+i);
                i--;
            }

        }
        return ans;
    }
};

using namespace std;

int main() {
    Solution *test = new Solution();
    int data[] = {1, 1, 2};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->removeDuplicates(x));
    for(int i=0; i<x.size(); i++)
        printf("%d ", x[i]);
    return 0;
}



