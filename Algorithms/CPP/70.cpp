// Author :  Accagain
// Date   :  17/3/30
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
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
    int climbStairs(int n) {
        int dp[n+1];
        if(n == 1)
            return 1;
        dp[n] = 1;
        dp[n-1] = 1;
        for(int i=n-2; i>=0; i--)
            dp[i] = dp[i+1] + dp[i+2];
        return dp[0];
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    return 0;
}

//
// Created by cms on 17/3/30.
//

