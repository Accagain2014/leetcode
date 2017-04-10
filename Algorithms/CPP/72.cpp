// Author :  Accagain
// Date   :  17/3/30
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
 *
 * (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 *
 * b) Delete a character
 *
 * c) Replace a character
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
    int minDistance(string word1, string word2) {
        int dp[word1.size() + 5][word2.size() + 5];

        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=word1.size(); i++)
            dp[i][0] = i;
        for(int i=1; i<=word2.size(); i++)
            dp[0][i] = i;

        for(int i=1; i<=word1.size(); i++)
        {
            for(int j=1; j<=word2.size(); j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->minDistance("abc", "aaa"));
    return 0;
}

//
// Created by cms on 17/3/30.
//

