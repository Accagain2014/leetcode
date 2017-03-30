// Author :  Accagain
// Date   :  17/3/29
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Validate if a given string is numeric.
 *
 * Some examples:
 *
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 *
 * Update (2015-02-10):
 *
 * The signature of the C++ function had been updated.
 *
 * If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
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
    bool judgeSmallDigit(string s)
    {
        int pos = -1;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '.')
            {

            }

        }

    }
    bool isNumber(string s) {
        if(!s.size())
            return false;
        while(s[0] == ' ' || s[0] == '\t' || s[0] == '\n')
        {
            s = s.substr(1);
        }
        while(s[s.size()] == ' ' || s[s.size()] == '\t' || s[s.size()] == '\n')
            s = s.substr(0, s.size()-1);


    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    return 0;
}

//
// Created by cms on 17/3/29.
//

