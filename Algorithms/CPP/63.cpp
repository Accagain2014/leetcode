// Author :  Accagain
// Date   :  17/3/29
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 *
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

 The total number of unique paths is 2.

 Note: m and n will be at most 100.
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
    int dp[110][110];
    int dir[2][2] = {{0, 1}, {1, 0}};

    int dfs(int m, int n, int x, int y, vector<vector<int>> matrix)
    {
        if(dp[x][y] != -1)
            return dp[x][y];
        if(matrix[x][y])
            return 0;

        if((x == m-1) && (y == n-1))
        {
            return 1;
        }

        int res = 0;
        for(int i=0; i<2; i++)
        {
            int x_ne = x + dir[i][0];
            int y_ne = y + dir[i][1];

            if(x_ne>=m || y_ne >= n || matrix[x_ne][y_ne] == 1)
            {
                continue;
            }
            res += dfs(m, n, x_ne, y_ne, matrix);
        }
        dp[x][y] = res;
        return dp[x][y];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        return dfs(obstacleGrid.size(), obstacleGrid[0].size(), 0, 0, obstacleGrid);
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

