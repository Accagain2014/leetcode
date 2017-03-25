// Author :  Accagain
// Date   :  17/3/25
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Implement pow(x, n).
 * 
 * 做法：
 *      快速幂算法
 *
 * 时间复杂度：
 *      O(lg(n))
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
    double myPow(double x, int n) {
        double ans = 1;
        bool result = n >= 0 ? true : false;
        long long tmp = (long long)n;
        tmp = abs(tmp);

        while(tmp)
        {
            if (tmp%2 == 0)
            {
                x = x * x;
                tmp /= 2;
            }
            else
            {
                ans = ans * x;
                tmp--;
            }
        }
        if(!result)
            ans = 1.0/ans;
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%lf\n", test->myPow(1.00000, -2147483648));
    return 0;
}

//
// Created by cms on 17/3/25.
//

