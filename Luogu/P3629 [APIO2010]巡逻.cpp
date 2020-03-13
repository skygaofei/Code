#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define re register
#define maxn 100005
using namespace std;
vector<int> son[maxn],v[maxn];
int dis[maxn],maxx,max_id;
bool flag;
int _first,_second;
int rec[maxn];
map<int,bool> _map;
void dfs_find(int x,int fa,int val)
{
    if(val>=maxx)
        maxx=val,max_id=x;
    for(re int i=0;i<son[x].size();++i)
        if(son[x][i]!=fa)
            dfs_find(son[x][i],x,val+v[x][i]);
}
void record_points(int now,int fa,int tar)
{
    if(flag)
        return;
    for(re int i=0;i<son[now].size();++i)
    {
        if(flag)
            return;
        if(son[now][i]==fa)
            continue;
        if(son[now][i]==tar)
        {
            rec[now]=son[now][i];
            flag=true;
            return;
        }
        rec[now]=son[now][i];
        record_points(son[now][i],now,tar);
        if(flag)
            return;
    }
}
void dp_find(int now,int fa)
{
    for(re int i=0;i<son[now].size();++i)
    {
        if(son[now][i]==fa)
            continue;
        dp_find(son[now][i],now);
        _second=max(_second,dis[now]+dis[son[now][i]]+v[now][i]);
        dis[now]=max(dis[now],dis[son[now][i]]+v[now][i]);
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int x,y;
    for(re int i=1;i<n;++i)
    {
        scanf("%d%d",&x,&y);
        son[x].push_back(y);
        son[y].push_back(x);
        v[x].push_back(1);
        v[y].push_back(1);
    }
    dfs_find(1,0,0);
    int start,end;
    start=max_id,maxx=0;
    dfs_find(start,0,0);
    _first=maxx,end=max_id;
    if(k==1)
    {
        printf("%d",(2*(n-1)-_first+1));
        return 0;
    }
    record_points(start,0,end);
    _map[end]=1,_map[start]=1;
    for(re int i=start;i!=end;i=rec[i])
        _map[i]=1;

    for(re int i=1;i<=n;++i)
        if(_map.count(i)==1)
            for(re int j=0;j<son[i].size();++j)
                if(_map.count(son[i][j])==1)
                    v[i][j]=-1;
    dp_find(1,0);
    printf("%d",(2*n-_first-_second));
    return 0;
}
