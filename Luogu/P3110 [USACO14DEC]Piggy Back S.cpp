//
//  main.cpp
//  驮运
//
//  Created by 高飞 on 2018/8/6.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define inf 1000000000000000000ll
using namespace std;
long long b, e, p, n, m;
long long point[100010], nex[100010], to[100010], cnt;
long long dis1[100010], dis2[100010], dis3[100010];
bool vis[100010];
queue<long long> q;
void add(long long x, long long y)
{
    nex[++cnt] = point[x];
    to[cnt] = y;
    point[x] = cnt;
}
void Bfs(long long dis[], long long s)
{
    memset(vis, 0, sizeof(vis));
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    while (!q.empty())
    {
        long long x = q.front();
            q.pop();
        for(long long i = point[x]; i; i = nex[i])
        {
            if (!vis[to[i]])
            {
                vis[to[i]] = true;
                q.push(to[i]);
                dis[to[i]] = dis[x] + 1;
            }
        }
    }
}
int main()
{
    //freopen("testdata.in","r",stdin);
    scanf("%lld%lld%lld%lld%lld",&b,&e,&p,&n,&m);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        add(x, y);
        add(y, x);
        //printf("%d\n",i);
    }
    memset(dis1,-1,sizeof(dis1));
    memset(dis2,-1,sizeof(dis2));
    memset(dis3,-1,sizeof(dis3));
    Bfs(dis1, 1);
    Bfs(dis2, 2);
    Bfs(dis3, n);
    long long ans = inf;
    for (int i = 1; i <= n; i++)
    {
        if(dis1[i]==-1||dis2[i]==-1||dis3[i]==-1)
            continue;
        ans = min(ans, (long long)b*dis1[i] + (long long)e * dis2[i] + (long long)p * dis3[i]);
    }
    printf("%lld",ans);
    return 0;
}
