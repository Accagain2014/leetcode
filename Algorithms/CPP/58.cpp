// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 *
 * return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, Given s = "Hello World", return 5.
 * 
 * 做法：
 *      从后往前扫计算
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

    int lengthOfLastWord(string s) {
        while(s[s.size()-1] == ' ')
            s = s.substr(0, s.size()-1); //去掉尾部的空

        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
                return s.size()-1 - i;
        }
        return s.size();
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->lengthOfLastWord("addd  "));
    return 0;
}

//
// Created by cms on 17/3/28.
//

