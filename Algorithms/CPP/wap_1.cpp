// Author :  Accagain
// Date   :  17/5/29
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
#define LL long long


int get(int n, int m, int mod)
{
    LL nn = (LL)n;
    LL mm = (LL)m;

    LL ans = 1;
    while(mm)
    {
        if(mm%2) {
            ans = ans * nn % mod;
            mm--;
        }
        mm /= 2;
        nn = nn * nn % mod;
    }
    return ans;
}
/*
int get(int n, int m, int mod)
{
    int ans = 1;
    for(int i=1; i<=m; i++)
        ans = ans*n %mod;
    return ans;
}
*/

int solve(int m, int n) {

    LL mod = 100003;
    LL ans = get(m, n, mod);
    LL mm = (LL) m;
    LL temp = get(m-1, n-1, mod);

    return ((ans - mm*temp%mod)%mod+mod)%mod;
}

int main(){
    //printf("%d\n", get(3, 1, 100000));
    int m,n;
    scanf("%d%d", &m, &n);
    printf("%d\n", solve(m, n));
    return 0;
}

