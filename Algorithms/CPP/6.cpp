// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
****************************************************************************************/

/*
 * 题意：
 *      竖着看是Z字，按行来
 */
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string ans = "";
        int sumLen = s.size();

        for(int i=1; i<=numRows; i++)
        {
            int pos=i;
            if((i == 1) || (i == numRows))
            {
                while(pos <= sumLen)
                {
                    ans += s[pos-1];
                    pos += 2*numRows - 2;
                }
            }
            else
            {
                ans += s[pos -1];
                while(true)
                {
                    pos += 2*numRows - 2*i;
                    if(pos <= sumLen)
                        ans += s[pos-1];
                    else
                        break;
                    pos += 2*i - 2;
                    if(pos <= s.size())
                        ans += s[pos-1];
                    else
                        break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution * test = new Solution();
    printf("%s\n", test->convert("A", 1).c_str());
    return 0;
}