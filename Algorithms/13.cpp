// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * 我的做法：
 *          找到位对应的进制字母，比如百位的话就是，肯定是以C或者D开头
 *          C / CC / CCC / CD / D / DC / DCC / DCCC / C
 * 更简单的方法，直接利用加减，当当前字符表示的数小于后面时减，否则加，最后一个永远是加
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    char Value[4] = {'I', 'X', 'C', 'M'};
    char Middle[3] = {'V', 'L', 'D'};
    map<char, int> mymap;

    int romanToInt(string s) {
        mymap['I'] = 0, mymap['V'] = 0, mymap['X'] = 1, mymap['L'] = 1;
        mymap['C'] = 2, mymap['D'] = 2, mymap['M'] = 3;
        int ans = 0;

        for(int i=0; i<s.size(); i++)
        {
            int now = mymap[s[i]];

            int base = pow(10, now);
            if(s[i] == Value[now])
            {
                if(((i+1) < s.size()) && ((now < 3) && (s[i+1] == Middle[now])))
                {
                    ans += 4*base;
                    i++;
                }
                else if(((i+1) < s.size()) && ((now+1) < 4 && s[i+1] == Value[now+1]))
                {
                    ans += 9*base;
                    i++;
                }
                else
                {
                    for(; i<s.size(); i++)
                    {
                        if(s[i] == Value[now])
                            ans += base;
                        else
                            break;
                    }
                    i--;

                }

            }
            else
            {
                ans += 5*base;

                for(i++; i<s.size(); i++)
                {
                    if(s[i] == Value[now])
                        ans += base;
                    else
                        break;
                }
                i--;
            }

        }
        return ans;
    }
};

int main() {
    Solution * test = new Solution();
    printf("%d\n", test->romanToInt("DCXXI"));
    return 0;
}

//
// Created by cms on 17/2/14.
//

