// Author :  Accagain
// Date   :  17/2/17
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 *
 * 做法：
 *      先减去大块头，再慢慢减去小块头
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
#include <math.h>

#define INF 0x3fffffff
#define LL long long

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        //printf("%d\n", dividend);

        LL ans = 0;
        bool pos = ((dividend > 0) && (divisor > 0) || ((dividend < 0) && (divisor < 0))) ? 1 : 0;

        LL tmp1 = abs((LL)dividend);
        //printf("%lld\n", tmp1);
        LL tmp2 = abs((LL)divisor);

        /*
        if(tmp2 == 1)
            ans = tmp1;
        else*/
        {
            LL time = 1;
            LL first = tmp2;
            while(tmp1 >= (tmp2+tmp2))
            {

                //ans++;
                if((LL)ans >= (LL)2147483648)
                    break;
                ans += (time + time);
                tmp1 -= (tmp2+tmp2);
                tmp2 += tmp2;
                time += time;
            }

            while(tmp1 >= first)
            {
                if(tmp1 >= tmp2)
                {
                    ans += time;
                    if((LL)ans >= (LL)2147483648)
                        break;
                    tmp1 -= tmp2;
                }
                else
                {
                    if(tmp2>first)
                    {
                        tmp2 = tmp2>>1;
                        time = time>>1;
                    }
                }
            }
        }

        if(!pos)
            ans = -ans;
        if((LL)ans == (LL)2147483648)
            ans -= 1;
        return ans;
    }
};



int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));

    printf("%d\n", test->divide(2147483647, 2));
    return 0;
}



