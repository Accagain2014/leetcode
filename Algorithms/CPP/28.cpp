// Author :  Accagain
// Date   :  17/2/16
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
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
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int ans = -1;
        int sum = haystack.size() - needle.size();
        for(int i=0; i<=sum; i++)
        {
           //printf(".... %d\n", haystack.size() - needle.size() - 1);
            if(haystack.substr(i, needle.size()) == needle)
                return i;
        }
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->strStr("ab", "a"));
    return 0;
}



