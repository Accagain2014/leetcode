// Author :  Accagain
// Date   :  17/6/5
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * 题目：
 *  有一个集合由A-Z这26个字母组成,打印这个集合的所有子集,每个子集一行,写C代码实现,不能使用递归
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

void get_subset(char * ori_set, int len)
{
    int ALPHA_NUM = len;
    int all_set = 1 << ALPHA_NUM;

    for(int i=0; i<all_set; i++)
    {
        string ans = "";
        for(int j=0; j<ALPHA_NUM; j++)
        {
            if(i & (1<<j))
                ans += ori_set[j];
        }
        printf("%s\n", ans.c_str());
    }
}

int main() {
    char save[4] = {'A', 'B', 'C', 'D'};
    get_subset(save, 4);
    return 0;
}

//
// Created by cms on 17/6/5.
//

