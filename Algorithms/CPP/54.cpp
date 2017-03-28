// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example, Given the following matrix:
 *
 * [[ 1, 2, 3 ],
 * [ 4, 5, 6 ],
 * [ 7, 8, 9 ]]
 *
 * You should return [1,2,3,6,9,8,7,4,5].
 *
 * 做法：
 *      dfs模拟, 不行调换方向
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

    void dfs(vector<int> & ans, vector<vector<int>> &matrix, int x, int y, int now, int sum, int dir)
    {
        if(now == sum)
            return ;
        ans.push_back(matrix[x][y]);
        matrix[x][y] = INF;

        int x_ne = x + dirs[dir][0];
        int y_ne = y + dirs[dir][1];

        if (x_ne == matrix.size() || x_ne < 0 || y_ne == matrix[0].size() || y_ne < 0 || matrix[x_ne][y_ne] == INF)
        {
            dir = (dir + 1) % 4;
            x_ne = x + dirs[dir][0];
            y_ne = y + dirs[dir][1];
        }
        dfs(ans, matrix, x_ne, y_ne, now+1, sum, dir);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;

        int sum = matrix.size() * matrix[0].size();
        dfs(ans, matrix, 0, 0, 0, sum, 0);
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 2, 3};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    vector<vector<int>> myv;
    myv.push_back(x);
    myv.push_back(x);
    vector<int> ans = test->spiralOrder(myv);
    for(int i=0; i<ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}

//
// Created by cms on 17/3/28.
//

