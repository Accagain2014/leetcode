// Author :  Accagain
// Date   :  17/6/2
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * 题目：
 *  一共有m张牌，两个人轮流拿，每次最少拿1张，最多拿n张，拿到最后一张牌的人算输，假设两个人都足够聪明。
 *  写一段代码，对于输入的任意m和n，判断先拿的人是否能赢。
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

int main() {

    int n, m;
    /*
     * 分析先拿的必败点和必胜点
     * 很明显1为必败点，无论怎么拿都会输
     * 2，3，..., m, m+1, 为必胜点，因为先拿的人肯定能找到一种方式使得后者在必败点(留一个给对方)
     * m+2为必败点, 因为无论先拿者怎么拿，都会使对手在必胜点
     * 分析可知当n%(m+1) == 1时为必败点, 此时无论怎么拿，对手都能凑出使自己为n-(m+1)的必败格局
     */

    while(~scanf("%d%d", &n, &m))
    {
        if(n % (m+1) == 1)
            printf("Lose !\n");
        else
            printf("Win !\n");
    }


    return 0;
}

//
// Created by cms on 17/6/2.
//

