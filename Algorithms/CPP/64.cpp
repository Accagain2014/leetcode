// Author :  Accagain
// Date   :  17/3/29
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a m x n grid filled with non-negative numbers,
 *
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 * 
 * 做法：
 *      dp
 *
 * 时间复杂度：
 *      O(mn)
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
    int dp[510][510];
    int dir[2][2] = {{0, 1}, {1, 0}};

    int dfs(int m, int n, int x, int y, vector<vector<int>> matrix)
    {
        if(dp[x][y] != -1)
            return dp[x][y];

        if((x == m-1) && (y == n-1))
        {
            return matrix[x][y];
        }

        int res = INF;
        for(int i=0; i<2; i++)
        {
            int x_ne = x + dir[i][0];
            int y_ne = y + dir[i][1];

            if(x_ne >= m || y_ne >= n)
            {
                continue;
            }
            res = min(res, dfs(m, n, x_ne, y_ne, matrix));
        }
        dp[x][y] = res + matrix[x][y];
        return dp[x][y];
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size();
        int n = grid[0].size();

        dp[0][0] = grid[0][0];
        for(int i=1; i<n; i++)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i=1; i<m; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
        return dp[m-1][n-1];

        /*
         * 逆向居然不行
         */
        //return dfs(grid.size(), grid[0].size(), 0, 0, grid);
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    return 0;
}

//
// Created by cms on 17/3/29.
//

