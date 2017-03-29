// Author :  Accagain
// Date   :  17/3/29
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time.
 *
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 * 
 * 做法：
 *      dfs + dp
 *      dfs表示递推逆向
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

    int dfs(int m, int n, int x, int y)
    {
        if(dp[x][y] != -1)
            return dp[x][y];
        if((x == m-1) && (y == n-1))
            return 1;
        int res = 0;
        for(int i=0; i<2; i++)
        {
            int x_ne = x + dir[i][0];
            int y_ne = y + dir[i][1];

            if(x_ne>=m || y_ne >= n)
            {
                continue;
            }
            res += dfs(m, n, x_ne, y_ne);
        }
        dp[x][y] = res;
        return dp[x][y];
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, 0, 0);
    }

};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->uniquePaths(2, 2));
    return 0;
}

//
// Created by cms on 17/3/29.
//

