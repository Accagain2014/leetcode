// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 *
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 * 
 * 做法：
 *     根据读法，书写数字
 *     直接模拟
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
    string char2string(char c)
    {
        string tmp;
        stringstream ss;
        ss << c;
        ss >> tmp;
        return tmp;
    }
    string next(string now)
    {
        string ans = "";
        char before = now[0];
        int count = 1;
        for(int i=1; i<now.size(); i++)
        {
            if(now[i] == before) {
                count++;
                before = now[i];
            }
            else
            {
                string tmp = char2string(count + '0');
                ans = ans + tmp+before;
                count = 1;
                //cout << ans << endl;
                before = now[i];
            }

        }
        //printf("%d\n", count);
        //cout << ans;

        if(count)
            ans = ans + char2string(count+'0')+char2string(before);
        //cout << ans;
        return ans;
    }
    string countAndSay(int n) {
        string begin = "1";
        for(int i=1; i<n; i++)
            begin = next(begin);
        return begin;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%s\n", test->countAndSay(5).c_str());
    return 0;
}

//
// Created by cms on 17/3/26.
//

