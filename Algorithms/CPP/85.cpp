// Author :  Accagain
// Date   :  17/5/13
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * 题意：
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 6.
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
#include <stack>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        stack<int> mys;
        int ans = 0;
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for(int i=1; i<=n; i++)
        {
            vector<int> height(m, 0);
            for(int j=1; j<=m; j++)
            {
                int temp = i;
                while((temp>=1) && (matrix[temp-1][j-1] == '1'))
                {
                    temp--;
                    height[j-1] ++;
                }
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;

    }

};

int main() {
    Solution *test = new Solution();
    char data[] = {'1', '0', '1', '0', '0'};
    vector<vector<char>> myv;
    myv.push_back(vector<char> (data, data + sizeof(data) / sizeof(data[0])));

    //vector<char> x(data, data + sizeof(data) / sizeof(data[0]));

    return 0;
}

//
// Created by cms on 17/5/13.
//

