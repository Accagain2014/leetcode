// Author :  Accagain
// Date   :  17/5/2
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
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
    int largestRectangleArea(vector<int>& heights) {
        if(!heights.size())
            return 0;
        if(heights.size() == 1)
            return heights[0];

        int n = heights.size();
        int l = n/2, r = n/2+1;
        int ans = max(heights[l], heights[r]);
        int num = 2, re=min(heights[l], heights[r]);
        while((l>=0) && (r<n))
        {

            if(heights[l] > heights[r])
            {
                l--;
                re = heights[r];
                ans = max(ans, re*num);
                ans = max(ans, heights[l]*(num-1));

            }
            else
            {
                r++;
                ans = max(ans, heights[l]*num);
                ans = max(ans, heights[l]*(num-1));
                re = heights[l];
            }
            printf("%d %d %d\n", l, r, ans);
            num++;
        }
        while(l>=0)
        {
            if(re < heights[l]) {
                re = heights[l];
            }
            l--;
            ans = max(ans, re*num);
            num++;

        }
        while(r < n)
        {
            if(re < heights[r]) {
                re = heights[r];
            }
            r++;
            ans = max(ans, re*num);
            num++;

        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {2, 1, 5, 6, 2, 3};

    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->largestRectangleArea(x));
    return 0;
}

//
// Created by cms on 17/5/2.
//

