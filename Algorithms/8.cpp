// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases.
 *
 * If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 *
 * You are responsible to gather all the input requirements up front.
 *
 * Update (2015-02-10):
 *
 * The signature of the C++ function had been updated.
 *
 * If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
****************************************************************************************/

/*
 *
 * 注意数字越界
 * 注意收尾空
 * 注意中间夹杂着其他字符，取首
 * 注意有前置0
 *
 */

#include <cstdlib>
#include <cstdio>
#include <string>

#define  LL long long
using namespace std;

class Solution {
public:

    int max_min(int bits, LL value)
    {
        LL tmp = ((LL)1 << (LL)(bits-1));
        LL Max = tmp - 1;
        LL Min = -tmp;

        if(value > Max)
            return Max;
        else if(value < Min)
            return Min;
        return value;
    }

    bool judge(string &str)
    {
        int begin = 0;
        int end = str.size()-1;

        for(int i=0; i<str.size(); i++)
        {
            if((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
                begin++;
            else
                break;
        }
        for(int i=str.size()-1; i>=0; i--)
        {
            if((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
                end--;
            else
                break;
        }
        str = str.substr(begin, end - begin + 1);
        //printf("%s\n", str.c_str());
        if(str.size() == 0)
            return false;
        if((str[0] != '+') && (str[0] != '-') && (str[0]  < '0' || str[0] > '9'))
            return false;

        return true;
    }
    int myAtoi(string str) {
        if(!judge(str))
            return 0;

        LL ans = 0, i;
        bool isp = true;
        if(str[0] >= '0' && str[0] <= '9')
            i = 0;
        else
        {
            if(str[0] == '-')
                isp = false;
            i = 1;
        }
        for(; i<str.size(); i++)
        {
            if((str[i] < '0') || (str[i] > '9'))
                break;
            int now = str[i]-'0';
            ans = ans * 10 + now;
            if(ans >= 2147483648)
                ans = 2147483648;
        }
        ans = (isp ? ans : -ans);
        return max_min(32, ans);
    }
};

int main()
{
    Solution * test = new Solution();
    printf("%d\n", test->myAtoi("2147483648"));
    return 0;
}