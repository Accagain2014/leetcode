// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that
 *
 * no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
 *
 * both indicate a queen and an empty space respectively.
 *
 * For example,
 *
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 *
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]]
 * 
 * 做法：
 *      直接搜索
 *      八皇后问题
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
#include <sstream>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    int hav[110][110];

    string char2str(char c)
    {
        stringstream tmp;
        string res;
        tmp << c;
        res = tmp.str();
        return res;

    }
    void dfs(vector<vector<char>> & now, vector<vector<string> > & ans, int pos)
    {
        if(pos == now.size())
        {
            vector<string> tmp;

            for(int i=0; i<now.size(); i++)
            {
                string get = "";
                for(int j=0; j<now[i].size(); j++)
                {
                    get += char2str(now[i][j]);
                }
                tmp.push_back(get);
                //printf("%s\n", get.c_str());
            }
            ans.push_back(tmp);

            return ;
        }
        for(int j=0; j<now.size(); j++)
        {
            int i = pos;
            if(hav[0][i])
                continue;
            {
                /*
                 * 0表示行
                 * 1表示列
                 * 2~2n+1表示上斜
                 * 2n+2~4n表示下斜
                 */
                if(hav[1][j])
                    continue;
                int n = now.size();
                int up_x = n - 1 - i + j;

                int down_x = i + j;

                if(!hav[2][up_x] && !hav[3][down_x])
                {
                    now[i][j] = 'Q';
                    hav[0][i] = 1;
                    hav[1][j] = 1;
                    hav[2][up_x] = 1;
                    hav[3][down_x] = 1;
                    dfs(now, ans, pos+1);
                    now[i][j] = '.';
                    hav[0][i] = 0;
                    hav[1][j] = 0;
                    hav[2][up_x] = 0;
                    hav[3][down_x] = 0;
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int hav[4][2*n]; // 分别表示行、列、上斜、下斜，1/1/2n-1/2n-1
        memset(hav, 0, sizeof(hav));
        vector<vector<string>> ans;
        vector<vector<char>> now;
        for(int i=0; i<n; i++)
        {
            vector<char> tmp;
            for(int j=0; j<n ;j++)
                tmp.push_back('.');
            now.push_back(tmp);
        }
        dfs(now, ans, 0);
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    vector<vector<string>> ans;
    ans = test->solveNQueens(4);
    for(int i=0; i<ans.size(); i++)
    {
        printf("i: %d\n", i);
        for(int j=0; j<ans[i].size(); j++)
        {
            printf("%s\n", ans[i][j].c_str());
        }
    }
    return 0;
}

//
// Created by cms on 17/3/28.
//

