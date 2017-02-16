// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * 我的做法是每一位每一位的考虑， 1 5 10 50 100 500 1000
 *
 * M = ["", "M", "MM", "MMM"];
 * C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
 * X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
 * I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];
 * return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
 *
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    char Value[4] = {'I', 'X', 'C', 'M'};
    char Middle[3] = {'V', 'L', 'D'};

    string intToRoman(int num) {
        string ans = "";
        vector<int> digits;
        while(num)
        {
            digits.push_back(num%10);
            num /= 10;
        }
        for(int i=digits.size()-1; i>=0; i--)
        {
            if(digits[i] == 0)
                continue;
            if(digits[i] <= 3)
            {
                for(int j=0; j<digits[i]; j++)
                    ans += Value[i];
            }
            else if(digits[i] == 4)
            {
                ans += Value[i];
                ans += Middle[i];
            }

            else if(digits[i] < 9)
            {
                ans += Middle[i];
                for(int j=0; j<digits[i]-5; j++)
                    ans += Value[i];
            }
            else
            {
                ans += Value[i];
                ans += Value[i+1];
                //printf("%c %c\n", Value[i], Value[i+1]);
            }

        }
        return ans;
    }
};


int main() {
    Solution * test = new Solution();
    printf("%s\n", test->intToRoman(1753).c_str());
    return 0;
}

//
// Created by cms on 17/2/14.
//

