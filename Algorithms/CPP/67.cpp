// Author :  Accagain
// Date   :  17/3/30
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 *
 * a = "11"
 * b = "1"
 *
 * Return "100".
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
#include <sstream>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    string char2s(char c)
    {
        stringstream ss;
        ss << c;
        return ss.str();
    }
    string addBinary(string a, string b) {
        string ans = "";
        int get = 0;
        while((a != "") || (b != ""))
        {
            int tmp;
            if(a.size() && b.size())
                tmp = a[a.size()-1]-'0' + b[b.size()-1] - '0' + get;
            else if (a.size())
                tmp = a[a.size()-1]-'0'+get;
            else
                tmp = b[b.size()-1]-'0'+get;
            ans = char2s(tmp%2 + '0') + ans;
            get = tmp / 2;
            if(a.size())
                a = a.substr(0, a.size()-1);
            if(b.size())
                b = b.substr(0, b.size()-1);
        }
        if(get)
            ans = char2s('1') + ans;
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%s\n", test->addBinary("100", "110010").c_str());
    return 0;
}

//
// Created by cms on 17/3/30.
//

