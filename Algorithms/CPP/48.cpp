// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 * 
 * 做法：
 *      直接模拟
 * 时间复杂度：
 *      o(n^2)
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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int save[n][n];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                save[j][n-1-i] = matrix[i][j];
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                matrix[i][j] = save[i][j];

    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 2};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    vector<vector<int>> X;
    X.push_back(x);
    X.push_back(x);
    test->rotate(X);

    for(int i=0; i<X.size(); i++)
        for(int j=0; j<X.size(); j++)
            printf("%d\n", X[i][j]);
    return 0;
}

//
// Created by cms on 17/3/26.
//

