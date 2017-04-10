// Author :  Accagain
// Date   :  17/4/8
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
#include <map>

#define INF 0x3fffffff

using namespace std;

#define N 110000
struct Info {
    long long r, c;
}myp[N];

bool cmp(struct Info a, struct Info b)
{
    if(a.r != b.r)
        return a.r < b.r;
    return a.c < b.c;
}

int R[N], C[N], dig1[2*N+1], dig2[2*N+1];
map<long  long , long long>ha[5];

int main() {
    int n;

    while(~scanf("%d", &n))
    {
        for(int i=1; i<=4; i++)
            ha[i].clear();
        long long row_max = 0;
        long long col_max = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d", &myp[i].r, &myp[i].c);
            row_max = max(row_max, myp[i].r);
            col_max = max(col_max, myp[i].c);
            ha[1][myp[i].r]++;
            ha[2][myp[i].c]++;
        }
        for(int i=1; i<=n; i++)
        {
            ha[3][row_max-myp[i].r+myp[i].c]++;
            ha[4][myp[i].r+myp[i].c]++;
        }

        long long ans = 0;
        for(int i=1; i<=4; i++)
        {
            map<long  long , long long> :: iterator it = ha[i].begin();
            for(; it != ha[i].end(); it++)
            {
                int now = it->second;
                if(now > 1)
                    ans += now * (now-1) /2;
            }
            //printf("%d\n", ans);
        }
        printf("%lld\n", ans);

    }
    return 0;
}

//
// Created by cms on 17/4/8.
//

