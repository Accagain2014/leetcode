#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define maxn 10005
using namespace std;

int n,a,b,ma;
int h[maxn],hp[maxn];

bool isok(int mid){
    for (int i = 0; i <n ; ++i) {
        hp[i]=h[i];
    }
    int num=a;
    for (int i = n-1; i >=0 ; --i) {
        if(hp[i]>=mid&&num>0){
            int tmp=hp[i]/mid;
            if(tmp<num){
                num-=tmp;
                hp[i]%=mid;
            }
            else{
                hp[i]-=num*mid;
                num=0;
            }
        }
        else break;
    }
    int ci=a;
    if(num!=0){
        sort(hp,hp+n);
        for (int i = 0; i <n-num ; ++i) {
            ci+=hp[i];
            if(ci>b) return false;
        }
        return true;
    }
    else{
        for (int i = 0; i <n ; ++i) {
            ci+=hp[i];
            if(ci>b) return false;
        }
        return true;
    }
}
void solve(){
    sort(h,h+n);
    int le=1,ri=ma;
    int ans=-1;
    while(le<=ri){
        int mid=(le+ri)>>1;
        if(isok(mid)){
            ans=mid;
            ri=mid-1;
        }
        else le=mid+1;
    }
    printf("%d\n",ans);
}

int main()
{
    while(~scanf("%d%d%d",&n,&a,&b))
    {
        ma=0;
        for (int i = 0; i <n ; ++i) {
            scanf("%d",&h[i]);
            ma=max(ma,h[i]);
        }
        solve();
    }
    return 0;
}