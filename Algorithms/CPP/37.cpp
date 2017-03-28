// Author :  Accagain
// Date   :  17/3/27
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 *
 * A sudoku puzzle...
 *
 * ...and its solution numbers marked in red.
 * 
 * 做法：
 *      基本的模拟，注意行、列、单元格的去重
 * 时间复杂度：
 *          
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    map<char, int> hav[30];
    bool ans = false;
    struct Info
    {
        int x, y;

        Info(int a, int b): x(a), y(b) {}
        Info(){}
    };

    int calCell(int x, int y)
    {
        x = x/3;
        y = y/3;
        return x*3+y;
    }

    void dfs(vector<vector<char>> & board, vector<Info> myv, int pos)
    {
        if(pos == myv.size())
        {
            ans = true;
            return ;
        }
        for(int i=1; i<=9; i++)
        {
            int x = myv[pos].x;
            int y = myv[pos].y;
            int cell = calCell(x, y);
            char now = i + '0';

            if(!hav[x][now] && !hav[y+9][now] && !hav[cell+18][now])
            {
                hav[x][now] = 1;
                hav[y+9][now] = 1;
                hav[cell+18][now] = 1;
                board[x][y] = now;
                dfs(board, myv, pos+1);
                if(ans)
                    return ;
                hav[x][now] = 0;
                hav[y+9][now] = 0;
                hav[cell+18][now] = 0;
                board[x][y] = '.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<27; i++)
            hav[i].clear();
        vector<Info> myv;
        ans = false;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    char now = board[i][j];
                    hav[i][now] = 1;
                    hav[j+9][now] = 1;
                    int cell = calCell(i, j);
                    hav[cell+18][now] = 1;
                }
                else
                {
                    myv.push_back(Info(i, j));
                }
            }
        }
        dfs(board, myv, 0);
    }
};

int main() {
    Solution *test = new Solution();
    //char a[2][2] = {{'1', '2'}, {'3', '4'}};

    char data[9][9] = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
                };

    //vector<char> x(data, data + sizeof(data) / sizeof(data[0]));
    vector<vector<char> > x;
    for(int i=0; i<9; i++)
    {
        vector<char> y(data[i], data[i]+sizeof(data[i])/sizeof(data[i][0]));
        x.push_back(y);
    }
    test->solveSudoku(x);
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            printf("%c", x[i][j]);
        putchar('\n');
    }

    return 0;
}

//
// Created by cms on 17/3/27.
//

