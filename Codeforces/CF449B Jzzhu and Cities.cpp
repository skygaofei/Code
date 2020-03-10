//
//  CF449B Jzzhu and Cities.cpp
//  7.21集训
//
//  Created by skygao on 2019/7/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 100005
#define inf 0x3f3f3f3f3f3f3f3f
#define re register
#define int long long
using namespace std;
int n,m,k;
vector<long long> son[maxn],v[maxn];
void addedge(int prt,int to,int val)
{
    son[prt].push_back(to);
    v[prt].push_back(val);
}
struct Node
{
    int x;
    long long dis;
    bool operator < (const Node &a)const
    {
        return dis>a.dis;
    }
};priority_queue<Node> q;
bool vis[maxn],mark[maxn];
long long dis[maxn];int ans;
void Dijkstra(int S)
{
    dis[S]=0,q.push((Node{S,0}));
    while(!q.empty())
    {
        Node prt=q.top();q.pop();
        int rt=prt.x;
        if(vis[rt])
            continue;
        vis[rt]=true;
        for(re int i=0;i<son[rt].size();++i)
        {
            int to=son[rt][i];
            if(dis[to]>=dis[rt]+v[rt][i])
            {
                if(mark[to])
                    mark[to]=false;
                if(dis[to]>dis[rt]+v[rt][i])
                    dis[to]=dis[rt]+v[rt][i],q.push((Node){to,dis[to]});
            }
        }
    }
}
signed main()
{
    memset(dis,0x3f,sizeof(dis));
    scanf("%lld%lld%lld",&n,&m,&k);
    for(re int i=1;i<=m;++i)
    {
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        addedge(x,y,z),addedge(y,x,z);
    }
    for(re int i=1;i<=k;++i)
    {
        int y,z;
        scanf("%lld%lld",&y,&z);
        if(z<dis[y])
            dis[y]=z,mark[y]=true,q.push((Node){y,z});
    }
    Dijkstra(1);
    for(re int i=1;i<=n;++i)
        if(mark[i])
            ans++;
    printf("%lld",k-ans);
    return 0;
}
