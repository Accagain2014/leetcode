// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 *
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 * 做法：
 *      栈的的处理
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
#include <stack>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:

    bool judgeL(char c)
    {
        if((c == '[') || (c == '(') || (c == '{'))
            return true;
        return false;
    }

    bool match(char a, char b)
    {
        if((a == '[') && (b == ']'))
            return true;
        if((a == '{') && (b == '}'))
            return true;
        if((a == '(') && (b == ')'))
            return true;
        return false;
    }

    bool isValid(string s) {
        stack<char> symbolStack;
        for(int i=0; i<s.size(); i++)
        {
            if(judgeL(s[i]))
                symbolStack.push(s[i]);
            else
            {
                if(symbolStack.empty())
                    return false;

                char now = symbolStack.top();
                symbolStack.pop();

                if(!match(now, s[i]))
                    return false;
            }
        }
        if(symbolStack.empty())
            return true;
        return false;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->isValid("([])"));
    return 0;
}



