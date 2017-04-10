// Author :  Accagain
// Date   :  17/3/31
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
#include <vector>

#define INF 0x3fffffff

using namespace std;




int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    {
        int dis[210][210];

        int deep[210];
        int leaf[210];
        int ans[210];
        int isleaf[210];
        int son[210];

        memset(isleaf, 0, sizeof(isleaf));
        vector<int> layer[210];
        for(int i=0; i<=n; i++)
            son[i] = i;

        for(int i=1; i<=m; i++)
        {
            scanf("%d", &deep[i]);
            //layer[i].clear();
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=0; j<deep[i]; j++) {
                int tmp;
                scanf("%d", &tmp);
                layer[i].push_back(tmp);
            }
        }
        for(int i=1; i<=k; i++)
        {
            scanf("%d", &leaf[i]);
            isleaf[leaf[i]] = 1;
        }

        memset(dis, 0, sizeof(dis));
        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<=k; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                dis[leaf[i]][leaf[j]] = tmp;
                dis[leaf[j]][leaf[i]] = tmp;
            }
        }
        memset(ans, -1, sizeof(ans));
        ans[layer[1][0]] = 0;

        for(int i=m; i>1; i--)
        {
            //printf("%d %d\n", layer[i][0], layer[i-1][0]);
            int tmp = 0;

            ans[layer[i][0]] = layer[i-1][tmp];
            son[layer[i-1][tmp]] = layer[i][0];

            for(int j=0; j<layer[i].size()-1; j++)
            {
                //printf("%d\n", tmp);
                if(dis[layer[i][j]][layer[i][j+1]] == 2)
                {
                    ans[layer[i][j+1]] = layer[i-1][tmp];
                    son[layer[i-1][tmp]] = layer[i][j+1];
                }
                else
                {
                    tmp ++;
                    while(isleaf[layer[i-1][tmp]])
                        tmp++;
                    ans[layer[i][j+1]] = layer[i-1][tmp];
                    son[layer[i-1][tmp]] = layer[i][j+1];
                }
            }

            if(i != m)
            {
                for(int j=0; j<layer[i].size(); j++)
                {
                    for(int kk=j+1; kk<layer[i].size(); kk++)
                    {
                        int tmp1 = layer[i][j];
                        int tmp2 = layer[i][kk];
                        if(isleaf[tmp1])
                        {
                            if(isleaf[tmp2])
                            {
                                continue;
                            }
                            else
                                dis[tmp1][tmp2] = dis[son[tmp1]][son[tmp2]] - 1;
                        }
                        else
                        {
                            if(isleaf[tmp2])
                            {
                                dis[tmp1][tmp2] = dis[son[tmp1]][son[tmp2]] - 1;
                            }
                            else
                                dis[tmp1][tmp2] = dis[son[tmp1]][son[tmp2]] - 2;
                        }

                    }
                }
            }


        }

        for(int i=1; i<=n; i++)
        {
            printf("%d", ans[i]);
            if(i!=n)
                printf(" ");
            else
                printf("\n");
        }

    }
    return 0;
}

//
// Created by cms on 17/3/31.
//
/*
 *
 *
 8 3 5
1 3 4
1
2 3 4
5 6 7 8
3 5 6 7 8
0 3 3 3 3
3 0 2 4 4
3 2 0 4 4
3 4 4 0 2
3 4 4 2 0
*/

/*
3 2 2
1 2
1
2 3
2 3
0 2
2 0
*/

/*
 *
4 2 3
1 3
1
2 3 4
2 3 4
0 2 2
2 0 2
2 2 0

 */

/*
 *

 3 3 1
 1 1 1
 2
 1
 3
 3
 0

 */

/*
 *

 10 3 7
 1 4 5
 1
 2 4 5 3
 6 7 8 9 10
 2 6 7 8 9 10 3
 0 3 3 3 3 3 2
 3 0 4 4 4 4 3
 3 4 0

 */

/*

7 4 2
1 2 2 2
1
2 3
4 5
6 7
6 7
0 6
6 0

 */

