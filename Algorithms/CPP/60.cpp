// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 *
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 * 
 * 做法：
 *      dfs 超时
 *      直接构造出第k个，假设一共有n位，首位去掉后，每一个首位后面都有(n-1)!个不同的排列，如此类推
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
#include <sstream>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    /*
    string map[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int hav[10];
    string ans ;
    int get = 1;
    string char2s(char c)
    {
        stringstream ss;
        ss << c;
        string ans = ss.str();
        return ans;
    }

    void dfs(int n, int k, string now_str)
    {
        //printf("%d\n", now);
        if(now_str.size()+1 == n + 1 )
        {
            //printf("%s\n", now_str.c_str());
            if(get == k)
            {
                ans = now_str;
                get ++;
                return ;
            }
            get ++;
            return ;
        }
        for(int i=1; i<=n; i++)
        {
            if(hav[i])
                continue;
            hav[i] = 1;
            dfs(n, k, now_str+map[i]);
            hav[i] = 0;
            if(get > k)
                return;
        }
    }
    */

    int n_order(int n)
    {
        int ans = 1;
        for(int i=2; i<=n; i++)
            ans *= i;
        return ans;
    }

    string getPermutation(int n, int k) {

        //int hav[n+1];
        /*
        memset(hav, 0, sizeof(hav));
        get = 1;

        dfs(n, k, "");
        printf("%s\n", ans.c_str());
        return ans;
        */
        string base[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

        vector<string> x(base, base + sizeof(base) / sizeof(base[0]));
        string ans = "";
        k --;
        while(n)
        {
            n--;
            int tmp = n_order(n);
            int remain = k/tmp;
            ans += x[remain];
            x.erase(x.begin() + remain);
            k = k % tmp;
        }
        cout << ans;
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {1, 2, 3, 4};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    test->getPermutation(3, 2);
//    x.erase(x.begin()+1);
//    for(int i=0; i<x.size(); i++)
//        printf("%d\n", x[i]);
    return 0;
}

//
// Created by cms on 17/3/28.
//

