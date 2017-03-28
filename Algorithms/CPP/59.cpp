// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example, Given n = 3,
 *
 * You should return the following matrix:
 *
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

 * 
 * 做法：
 *      直接dfs模拟
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
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<int>> & ans, int x, int y, int now, int sum, int dir)
    {
        if(now == sum)
            return ;

        ans[x][y] = now+1;

        int x_ne = x + dirs[dir][0];
        int y_ne = y + dirs[dir][1];

        if (x_ne == ans.size() || x_ne < 0 || y_ne == ans[0].size() || y_ne < 0 || ans[x_ne][y_ne] != 0)
        {
            dir = (dir + 1) % 4;
            x_ne = x + dirs[dir][0];
            y_ne = y + dirs[dir][1];
        }
        dfs(ans, x_ne, y_ne, now+1, sum, dir);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            vector<int> tmp;
            for(int j=0; j<n; j++)
            {
                tmp.push_back(0);
            }
            ans.push_back(tmp);
        }
        if(n == 0)
            return ans;
        dfs(ans, 0, 0, 0, n*n, 0);
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=0; j<ans[i].size(); j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->generateMatrix(5);

    return 0;
}

//
// Created by cms on 17/3/28.
//

