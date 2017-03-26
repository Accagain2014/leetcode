// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 110.
 *
 * Both num1 and num2 contains only digits 0-9.
 *
 * Both num1 and num2 does not contain any leading zero.
 *
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * 
 * 做法：
 *      直接模拟，从末位往前计算、累加
 *
 * 时间复杂度：
 *      O(m*n)
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
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        int ans[num1.size()+num2.size()+10];
        memset(ans, 0, sizeof(ans));
        int sum_dig = 0;
        int max_dig = 0;
        for(int i=num1.size()-1; i>=0; i--)
        {
            int sum = 0;
            for(int j=num2.size()-1; j>=0; j--)
            {
                sum_dig = num1.size()-1-i + num2.size() - 1 - j;
                max_dig = max(max_dig, sum_dig);
                int tmp = ans[sum_dig];
                ans[sum_dig] = (tmp + (num1[i]-'0') * (num2[j]-'0') + sum)%10;
                sum = (tmp + (num1[i]-'0')*(num2[j]-'0') + sum)/10;
            }
            if(sum)
            {
                ans[sum_dig+1] = sum;
                max_dig = max(max_dig, sum_dig+1);
            }
        }
        string res = "";
        for(int i=max_dig; i>=0; i--)
            res += ans[i]+'0';
        return res;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%s\n", test->multiply("123", "456").c_str());
    return 0;
}

//
// Created by cms on 17/3/26.
//

