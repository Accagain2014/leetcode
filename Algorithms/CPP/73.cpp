// Author :  Accagain
// Date   :  17/4/10
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
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
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> columns;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!matrix[i][j])
                {
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        for(int i=0; i<rows.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                matrix[rows[i]][j] = 0;
            }
        }

        for(int i=0; i<columns.size(); i++)
        {
            for(int j=0; j<m; j++)
            {
                matrix[j][columns[i]] = 0;
            }
        }
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

