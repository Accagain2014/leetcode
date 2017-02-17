// Author :  Accagain
// Date   :  17/2/17
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 * 做法：
 *      从右开始，
 *
 * 时间复杂度：
 *      O(n^2)
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
    void nextPermutation(vector<int>& nums) {
        int begin = 0;
        for(int i=nums.size()-1; i>=0; i--)
        {
            int tmp = INF;
            int rec;

            for(int k=i+1; k<nums.size(); k++)  //可以用优先队列搞一下，大于当前值的最小值
            {
                if(nums[k] > nums[i])
                {
                    if(nums[k] < tmp)
                    {
                        tmp = nums[k];
                        rec = k;
                    }
                }
            }

            if(tmp != INF)
            {
                nums[rec] = nums[i];
                nums[i] = tmp;
                //sort(nums.begin()+i+1, nums.end());
                //return ;
                begin = i+1;
                break;
            }

        }
        sort(nums.begin()+begin, nums.end());
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {4,2,0,2,3,2,0};


    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    /*
    sort(x.begin()+1, x.end());
    for(int i=0; i<x.size(); i++)
        printf("%d ", x[i]); */

    test->nextPermutation(x);
    for(int i=0; i<x.size(); i++)
        printf("%d ", x[i]);
    return 0;
}


