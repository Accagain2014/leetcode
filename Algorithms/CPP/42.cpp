// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 *
 * compute how much water it is able to trap after raining.
 *
 * For example,
 *
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 * 
 * 做法：
 *     Max * O(n)的做法 超时；
 *     左右扫，补短的，维护左右最大值；
 *
 *
 * 时间复杂度：
 *      O(n^2)
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
    /*
    int trap(vector<int>& height) {
        int ans = 0;
        for(int he=1; he<INF; he++)
        {
            int be = -1;
            for(int i=0; i<height.size(); i++)
            {
                 if(height[i]>=he)
                 {
                     if(be != -1)
                         ans += (i-be-1);
                     be = i;
                 }
            }
            if(be == -1)
                break;
        }
        return ans;
    }
     */
    int trap(vector<int>& height)
    {
        int ans = 0;
        int left_most = 0, right_most = 0, left = 0, right = height.size()-1;
        while(left<=right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] < left_most)
                {
                    ans += left_most - height[left];
                }
                else
                    left_most = max(left_most, height[left]);
                left ++;
            }
            else
            {
                if(height[right] < right_most)
                {
                    ans += right_most - height[right];
                }
                else
                    right_most = max(right_most, height[right]);
                right --;
            }
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->trap(x));
    return 0;
}

//
// Created by cms on 17/3/26.
//

