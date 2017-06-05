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

#define  Maxn 20

int h, w, d, r;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char save[Maxn][Maxn];
int dp[Maxn][Maxn][2];
int vis[Maxn][Maxn];

bool iscan(int i, int j)
{
    if(i<0 || i>= h || j<0 || j>=w)
        return false;
    return true;
}

int dfs(int x, int y , int hav)
{
    //printf("x:%d y:%d \n", x, y);
    if((x == (h-1)) && (y == (w-1)))
    {
        dp[x][y][hav] = 0;
        return dp[x][y][hav];
    }

   if(dp[x][y][hav] < INF)
   {
       return dp[x][y][hav];
   }
    int Max = INF;
    for(int i=0; i<4; i++)
    {
        int xx = x+dir[i][0];
        int yy = y+dir[i][1];

        if((iscan(xx, yy)) && (!vis[xx][yy]) && (save[xx][yy] == '.'))
        {
            vis[xx][yy] = 1;
            Max = min(Max, 1+dfs(xx, yy, hav));
            vis[xx][yy] = 0;
        }
    }
    dp[x][y][hav] = min(dp[x][y][hav], Max);

    if(hav == 0)
    {
        int xx = x+d;
        int yy = y+r;
        if((iscan(xx, yy)) && (!vis[xx][yy]) && (save[xx][yy] == '.'))
        {
            vis[xx][yy] = 1;
            Max = min(Max, 1+dfs(xx, yy, 1));
            vis[xx][yy] = 0;
        }
        dp[x][y][0] = min(dp[x][y][0], Max);

    }
    //printf("%d %d %d %d\n", x, y, dp[x][y][0], dp[x][y][1]);
    return dp[x][y][hav];

}

int main() {
    while(~scanf("%d%d%d%d", &h, &w, &d, &r))
    {
        //printf("%d %d\n", d, r);
        for(int i=0; i<h; i++)
        {
            scanf("%s", save[i]);
        }
        memset(vis, 0, sizeof(vis));
        vis[0][0] = 1;
        for(int i=0; i<=h; i++)
        {
            for(int j=0; j<=w; j++)
            {
                dp[i][j][0] = INF;
                dp[i][j][1] = INF;
            }
        }
        dfs(0, 0, 0);
        int ans = min(dp[0][0][0], dp[0][0][1]);
        //printf("%d\n", ans);
        if(ans == INF)
            ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
/*

 4 5 1 2
..*..
..**.
..**.
..*..


 */

