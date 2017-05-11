// Author :  Accagain
// Date   :  17/4/22

/***************************************************************************************
 * 
 * 
 * 做法：
 *      
 * 时间复杂度：
 *          
 * 
****************************************************************************************/

#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<list>
#include<queue>
#define eps 1e-6
#define INF (1<<30)
#define PI acos(-1.0)
using namespace std;

int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


int hav[1100][1100];

int main() {
    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF) {
        int x = 1;
        int y = 1;

        memset(hav, 0, sizeof(hav));
        int dir = 0;
        int x_t = x, y_t = y;

        hav[1][1] = 1;
        for (int i = 2; i <= m; i++) {
            x_t = x + dirs[dir][0];
            y_t = y + dirs[dir][1];

            while (x_t > n || y_t > n || x_t < 1 || y_t < 1 || hav[x_t][y_t]) {
                dir = (dir + 1) % 4;
                x_t = x + dirs[dir][0];
                y_t = y + dirs[dir][1];
            }
            x = x_t;
            y = y_t;
            hav[x][y] = 1;
        }
        printf("%d %d\n", x_t, y_t);
    }
    return 0;
}



