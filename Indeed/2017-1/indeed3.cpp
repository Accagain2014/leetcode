#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n,m;
int a[10][10];
int pre[7],cnt;
vector<pair<int,int> >edge;

int Find(int x)
{
    if(pre[x]==x) return x;
    pre[x]=Find(pre[x]);
    return pre[x];
}
void Merge(int u,int v)
{
    int x,y;
    x=Find(u);
    y=Find(v);
    if(x!=y)
    {
        pre[x]=y;
        cnt--;
    }
}
bool isok(int status){
    for(int i=1; i<=n; i++)
    {
        pre[i]=i;
    }
    cnt=n;
    for(int i=0;i<edge.size();i++){
        if(status&(1<<i)){
            Merge(edge[i].first,edge[i].second);
        }
    }
    return cnt==1;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        int u,v;
        for (int i = 0; i <m ; ++i) {
            scanf("%d%d",&u,&v);
            a[u][v]=a[v][u]=1;
        }
        edge.clear();
        for (int i = 1; i <=n ; ++i) {
            for (int j = i+1; j <=n ; ++j) {
                if(a[i][j]==0) edge.push_back(make_pair(i,j));
            }
        }
        int sz=edge.size();
        int tot=(1<<sz)-1;
        int ans=0;
        for (int i = 0; i <=tot ; ++i) {
            if(isok(i)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}