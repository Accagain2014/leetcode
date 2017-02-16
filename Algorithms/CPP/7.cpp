// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 *
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 *
 * Note:
 *  The input is assumed to be a 32-bit signed integer.
 *  Your function should return 0 when the reversed integer overflows.
 *
****************************************************************************************/

#include <cstdlib>
#include <cstdio>

#define  LL long long
using namespace std;

class Solution {
public:
    bool judge(int bits, LL value)
    {
        LL tmp = ((LL)1 << (LL)(bits-1));
        LL Max = tmp - 1;
        LL Min = -tmp;

        if((value > Max) || (value < Min))
            return false;
        return true;
    }

    int reverse(int x) {
        LL ans = 0;
        bool isp = (x >= 0 ? true : false);
        x = abs(x);
        while(x)
        {
           int now = x%10;
            ans = ans * 10 + now;
            x = x / 10;
        }
        ans = (isp ? ans : -ans);
        if(!judge(32, ans))
            return 0;
        return ans;
    }
};

int main()
{
    Solution * test = new Solution();
    //printf("%d\n", test->judge(32, -2147483649));
    printf("%d\n", test->reverse(1000));
    return 0;
}