// Author :  Accagain
// Date   :  17/4/10
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 *
 * where "adjacent" cells are those horizontally or vertically neighboring.
 *
 * The same letter cell may not be used more than once.
 *
 * For example,
 * Given board = [
 * ['A','B','C','E'],
 * ['S','F','C','S'],
 * ['A','D','E','E']
 * ]
 *
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.

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
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int hav[210][210];

    bool dfs(int x, int y, int now, string word, vector<vector<char>> myv)
    {
        if(now == word.size())
        {
            return true;
        }
        for(int i=0; i<4; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(xx < 0 || xx >= myv.size() || yy < 0 || yy >= myv[0].size() || hav[xx][yy])
            {
                continue;
            }
            if(myv[xx][yy] == word[now])
            {
                hav[xx][yy] = 1;
                int ans = dfs(xx, yy, now+1, word, myv);
                if(ans)
                    return true;
                hav[xx][yy] = 0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        memset(hav, 0, sizeof(hav));
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                    hav[i][j] = 1;
                    bool ans = dfs(i, j, 1, word, board);
                    if(ans)
                        return true;
                    hav[i][j] = 0;
                }
            }
        }
        return false;

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

