#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 0x3fffffff

using namespace std;
#define LL long long


int m, mod;

int la = 0;

vector<int> re;

vector<int> pos;

void add(int x) {
    int temp = (la + x) % mod;
    int n = re.size();

    if(n == 0){
        pos.push_back(-1);
    }
    else
    {
        n = re.size();
        int p = n - 1;
        while(p != -1){
            if(re[p] > temp)
            {
                pos.push_back(p);
                break;
            }
            p = pos[p];
        }
        if(p == -1)
            pos.push_back(-1);
    }
    re.push_back(temp);
}

int query(int x) {
    int ans = -INF;
    int n = re.size();
    int temp = n - 1;


    while (temp >= n - x){
        if(re[temp] > ans)
            ans = re[temp];
        else
            ans = ans;
        temp = pos[temp];
    }

    return la = ans;
}


int main() {
    char ch[2];
    scanf("%d%d", &m, &mod);
    while(m--) {
        int x;
        scanf("%s%d", ch, &x);
        if (ch[0] == 'I')
            add(x);
        else
            printf("%d\n", query(x));
    }

    return 0;
}