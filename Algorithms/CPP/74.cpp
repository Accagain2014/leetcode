// Author :  Accagain
// Date   :  17/4/10
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 *
 * The first integer of each row is greater than the last integer of the previous row.
 *
 * For example,
 * Consider the following matrix:
 *
 * [[1,   3,  5,  7],
 * [10, 11, 16, 20],
 * [23, 30, 34, 50]
 * ]
 *
 * Given target = 3, return true.
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
    int find(vector<vector<int>> matrix, int row_col, int target)
    {
        int l=0, mid, r, m=matrix.size(), n=matrix[0].size();
        if(row_col == -1)
            r = m-1;
        else
            r = n-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(row_col == -1)
            {
                if(matrix[mid][0] > target)
                    r = mid -1;
                else if(matrix[mid][n-1] < target)
                    l = mid + 1;
                else
                    return mid;
            }
            else
            {
                if(matrix[row_col][mid] > target)
                    r = mid - 1;
                else if(matrix[row_col][mid] < target)
                    l = mid + 1;
                else
                    return mid;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int row = find(matrix, -1, target);
        if(row == -1)
            return false;
        int col = find(matrix, row, target);
        if(col == -1)
            return false;
        return true;

    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    return 0;
}

//
// Created by cms on 17/4/10.
//

