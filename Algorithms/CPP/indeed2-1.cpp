// Author :  Accagain
// Date   :  17/5/13
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
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

#define INF 0x7fffffff

using namespace std;

int h, w, a, b;

#define Maxn 110

char save1[Maxn][Maxn];
char save2[Maxn][Maxn];

int main() {

    while(~scanf("%d%d%d%d", &h, &w, &a, &b))
    {
        for(int i=0; i<h; i++)
        {
            scanf("%s", save1[i]);
        }
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                for(int k=0; k<h; k++)
                {
                    for(int m=0; m<w; m++)
                    {
                        save2[i*h+k][j*w+m] = save1[k][m];
                    }
                }
            }
        }
        for(int i=0; i<h*a; i++)
        {
            for(int j=0; j<w*b; j++)
                printf("%c", save2[i][j]);
            putchar('\n');
        }

    }
    return 0;
}

//
// Created by cms on 17/5/13.
//

