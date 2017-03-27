// Author :  Accagain
// Date   :  17/3/27
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 *      A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 * 
 * 做法：
 *      直接模拟
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
    bool judge(vector<vector<char>> board, int x1, int y1, int x2, int y2)
    {
        int hav[10];
        memset(hav, 0, sizeof(hav));
        for(int i=x1; i<=x2; i++)
            for(int j=y1; j<=y2; j++)
            {
                if(board[i][j] != '.')
                {
                    if(board[i][j] >= '1' && board[i][j] <= '9')
                    {
                        if(hav[board[i][j] - '0'])
                            return false;
                        hav[board[i][j] - '0'] = 1;
                    }
                    else
                        return false;
                }
            }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++)
        {
            bool tmp = judge(board, i, 0, i, 0+board.size()-1);
            if(!tmp)
                return false;
            tmp = judge(board, 0, i, board.size()-1, i);
            if(!tmp)
                return false;
            if(i%3 == 0)
            {
                for(int j=0; j<board.size(); j++)
                {
                    if(j%3 == 0)
                    {
                        int x = i+2;
                        int y = j+2;
                        if((x < board.size()) && (y < board.size()))
                        {
                            tmp = judge(board, i, j, x, y);
                            if(!tmp)
                                return false;
                        }
                    }

                }
            }

        }
        return  true;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    return 0;
}

//
// Created by cms on 17/3/27.
//

