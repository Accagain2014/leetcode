// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false;
        x = abs(x);
        int rev = 0;
        int temp = x;
        while(temp)
        {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return (x == rev ? 1 : 0);
    }
};

int main()
{
    Solution * test = new Solution();
    printf("%d\n", test->isPalindrome(-1321));
    return 0;
}