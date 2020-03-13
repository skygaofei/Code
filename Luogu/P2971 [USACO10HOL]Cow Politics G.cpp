#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#define re register
#define maxn 200005
#define maxm 400005
using namespace std;
int n,k;
int x;
vector<int> party[100005];
int point[maxn],nxt[maxm],to[maxm],cnt;
int depth[maxn],fa[maxn][20];
inline void addedge(int x,int y)
{
    nxt[++cnt]=point[x];
    to[cnt]=y;
    point[x]=cnt;
}
void dfs(int x,int S)
{
    depth[x]=depth[S]+1;
    fa[x][0]=S;
    for(re int i=point[x];i;i=nxt[i])
    {
        int rt=to[i];
        if(rt==S)
            continue;
        dfs(rt,x);
    }
}
inline int go_up(int x,int d)
{
    for(re int j=19;j>=0;--j)
        if((1<<j)<=d)
            x=fa[x][j];
    return x;
}
inline int Dis(int x,int y)
{
    int tx=x,ty=y;
    if(depth[x]>depth[y])
        x=go_up(x,depth[x]-depth[y]);
    if(depth[x]<depth[y])
        y=go_up(y,depth[y]-depth[x]);
    for(re int j=19;j>=0;--j)
        if(fa[x][j]!=fa[y][j])
            x=fa[x][j],y=fa[y][j];
    if(x!=y)
        x=fa[x][0];
    return depth[tx]+depth[ty]-2*depth[x];
}
int main()
{
    int a;
    int root;
    scanf("%d%d",&n,&k);
    for(re int i=1;i<=n;++i)
    {
        scanf("%d%d",&a,&x);
        addedge(x,i);
        party[a].push_back(i);
        if(x==0)
            root=i;
    }
    dfs(root,0);
    for(re int j=1;j<=19;++j)
        for(re int i=1;i<=n;++i)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    int maxx,pos,f,s,_dis;
    for(re int i=1;i<=k;++i)
    {
        maxx=-0x7fffffff,pos=0;
        f=party[i][0];
        for(re int j=1;j<party[i].size();++j)
        {
            _dis=Dis(party[i][j],f);
            if(_dis>maxx)
                maxx=_dis,pos=party[i][j];
        }
        s=pos,maxx=-0x7fffffff,pos=0;
        for(re int j=0;j<party[i].size();++j)
        {
            if(j==s)
                continue;
            _dis=Dis(party[i][j],s);
            if(_dis>maxx)
                maxx=_dis,pos=party[i][j];
        }
        printf("%d\n",Dis(pos,s));
    }
    return 0;
}