// Author :  Accagain
// Date   :  17/6/5
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * 题目：
 *  介于0到1000000之间的n个整数, 请对他们进行排序, 要求时间复杂度为O(n), 写c代码实现
 * 
 * 做法：
 *      基数排序
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

int * sort_n(int save[], int len)
{
    /*
     * 桶排序
     */

    int MAX_VALUE = 1000000+10;
    int bucket[MAX_VALUE];
    memset(bucket, 0, sizeof(bucket));

    for(int i=0; i<len; i++)
    {
        bucket[save[i]]++;
    }
    for(int i=1; i<MAX_VALUE; i++)
    {
        bucket[i] = bucket[i-1] + bucket[i];
    }
    int cu = 0;
    int ans[len];
    for(int i=len-1; i>=0; i--)
    {

        ans[bucket[save[i]]-1] = save[i];
        bucket[save[i]]--;
    }
    return ans;
}

int main() {

    int data[] = {1, 6, 2, 3, 4, 8, 4, 4, 5};
    int * ans;
    ans = sort_n(data, 9);

    for(int i=0; i<9; i++)
        printf("%d\n", ans[i]);
    return 0;
}

//
// Created by cms on 17/6/5.
//

