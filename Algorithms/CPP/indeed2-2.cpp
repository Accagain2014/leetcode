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

#define INF 0x3fffffff

using namespace std;

int n, k, m;

#define Maxn 100
int gain[Maxn][Maxn];

vector<int> myv[2];
int ans;
int vis[Maxn];

void dfs2(int hav)
{
    if(hav == k)
    {
        int tmp =0;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<myv[i].size(); j++)
            {
                for(int kk=j+1; kk<myv[i].size(); kk++)
                {
                    if(myv[i][j] < myv[i][kk])
                        tmp += gain[myv[i][j]][myv[i][kk]];
                    else
                        tmp += gain[myv[i][kk]][myv[i][j]];
                }
                //printf("i:%d j:%d %d\n", i, j, myv[i][j]);
            }
        }
        if(tmp > ans)
            ans = tmp;
        return ;
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            myv[1].push_back(i);
            dfs2(hav+1);
            vis[i] = 0;
            myv[1].pop_back();
        }
    }
}
void dfs1(int hav)
{
    if(hav == k)
    {
        dfs2(0);
        return ;
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            myv[0].push_back(i);
            dfs1(hav+1);
            vis[i] = 0;
            myv[0].pop_back();
        }
    }
}

int main() {
    while(~scanf("%d%d%d", &n, &k, &m))
    {
        ans = 0;
        myv[0].clear();
        myv[1].clear();
        memset(vis, 0, sizeof(vis));
        memset(gain, 0, sizeof(gain));
        for(int i=1; i<=m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(a < b)
                gain[a][b] = c;
            else
                gain[b][a] = c;
        }
        dfs1(0);
        printf("%d\n", ans);
    }
    return 0;
}

//
// Created by cms on 17/5/13.
//

