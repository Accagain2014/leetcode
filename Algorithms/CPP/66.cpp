// Author :  Accagain
// Date   :  17/3/30
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
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
    vector<int> plusOne(vector<int>& digits) {
        int get = 1;
        for(int i=digits.size()-1; i>=0; i--)
        {
            digits[i] += get;
            get = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if(get)
            digits.insert(digits.begin(), get);
        for(int i=0; i<digits.size(); i++)
            printf("%d ", digits[i]);
        printf("\n");
        return digits;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {9, 9, 9, 9};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->plusOne(x);
    return 0;
}

//
// Created by cms on 17/3/30.
//

