#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 1005
#define re register
#define INF 0x3f3f3f3f
using namespace std;
vector<int> son[maxn],v[maxn];
int n,m,t,dis[maxn];
queue<int> q;
bool vis[maxn];
int cnt[maxn];
void add(int x,int y,int z)
{
    son[x].push_back(y);
    v[x].push_back(z);
}
bool SPFA(int S)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    dis[S]=0,q.push(S),cnt[S]=1,vis[S]=true;
    while(!q.empty())
    {
        int rt=q.front();q.pop();vis[rt]=false;
        for(re int i=0;i<son[rt].size();++i)
        {
            int to=son[rt][i];
            if(dis[to]>dis[rt]+v[rt][i])
            {
                dis[to]=dis[rt]+v[rt][i];
                if(!vis[to])
                {
                    cnt[to]++;
                    if(cnt[to]>n)
                        return true;
                    q.push(to);
                    vis[to]=true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int x,y,z;
    scanf("%d%d%d",&n,&m,&t);
    for(re int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    for(re int i=1;i<=t;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(y,x,-z);
    }
    for(re int i=2;i<=n;++i)
        add(i,i-1,0);
    for(re int i=1;i<=n;++i)
        add(0,i,0);
    bool flag=SPFA(0);
    if(flag)
    {
        printf("-1");
        return 0;
    }
    flag=SPFA(1);
    if(flag)
    {
        printf("-1");
        return 0;
    }
    if(dis[n]==INF)
        printf("-2");
    else
        printf("%d",dis[n]);
    return 0;
}
