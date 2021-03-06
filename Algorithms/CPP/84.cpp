// Author :  Accagain
// Date   :  17/5/2
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * 题意：
 *  Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 *
 *  find the area of largest rectangle in the histogram.
 *
 *  Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 *  The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 *  For example,
 *  Given heights = [2,1,5,6,2,3],
 *  return 10.
 * 
 * 做法：
 *      维护一个上升的栈，每一个元素出栈时，计算超过它的连续的最大右边和，超过它的连续最大左边
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
#include <stack>

#define INF 0x3fffffff

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        stack<int> mys;
        int ans = -INF;
        heights.push_back(0);
        int n = heights.size();
        for(int i=0; i<heights.size(); i++) {
            if(mys.empty() || heights[i] >= heights[mys.top()])
            {
                mys.push(i);
            }
            else
            {
                int tp = mys.top();
                mys.pop();
                ans = max(ans, heights[tp] * (mys.empty() ? i : (i - mys.top() -1 )));
                i--;
            }
        }
        //printf("%d\n", ans);
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {2, 1, 2};

    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->largestRectangleArea(x));
    return 0;
}

//
// Created by cms on 17/5/2.
//

