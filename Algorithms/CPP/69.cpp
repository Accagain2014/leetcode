// Author :  Accagain
// Date   :  17/3/30
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
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
    int mySqrt(int x) {
        long long ans = 0;
        while(ans*ans <= x)
        {
            ans ++;
        }
        return ans-1;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->mySqrt(2147395600));
    return 0;
}

//
// Created by cms on 17/3/30.
//

