// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 *      Given nums = [2, 7, 11, 15], target = 9,
 *      Because nums[0] + nums[1] = 2 + 7 = 9,
 *      return [0, 1].
 *
***************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //int hav[110000];
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if((nums[i] + nums[j]) == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }
};



int main()
{
    std::cout << "Hello, World!" << std::endl;
    Solution * a = new Solution();
    vector<int> test;
    int testn, test_target;
    while(~scanf("%d", &testn))
    {
        test.clear();
        scanf("%d", &test_target);

        for(int i=1; i<=testn; i++)
        {
            int temp;
            scanf("%d", &temp);
            test.push_back(temp);
        }
        vector<int> ans = a->twoSum(test, test_target);
        for(int i=0; i<ans.size(); i++)
        {
            printf("%d ", ans[i]);
        }
    }

    return 0;
}
