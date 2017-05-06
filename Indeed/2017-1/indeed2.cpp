#include<iostream>
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

#define  LL long long
#define  Maxn 10

int n, t;
struct point
{
    int x, y;
}p[Maxn], q[Maxn];

int hav[Maxn];
LL ans_temp;

LL dis(int i, int j)
{
    return abs(p[i].x - q[j].x) + abs(p[i].y - q[j].y);
}

void cal(int i, LL sum)
{
    if(i > n)
    {
        if(sum < ans_temp)
            ans_temp = sum;
        return ;
    }
    for(int j=1; j<=n; j++)
    {
        if(!hav[j])
        {
            hav[j] = 1;
            cal(i+1, sum+dis(i, j));
            hav[j] = 0;
        }
    }
}

int main() {

    while(~scanf("%d%d", &n, &t))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
        }

        LL ans = 0;
        for(int i=1; i<=t; i++)
        {

            for(int j=1; j<=n; j++)
                scanf("%d%d", &q[j].x, &q[j].y);
            memset(hav, 0, sizeof(hav));
            ans_temp = INF;
            cal(1, 0);
            ans += ans_temp;
            for(int j=1; j<=n; j++)
                p[j] = q[j];
        }
        printf("%lld\n", ans);
    }

    return 0;
}