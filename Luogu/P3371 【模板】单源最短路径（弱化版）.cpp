//
//  main.cpp
//  em..
//
//  Created by 高飞 on 2018/10/3.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define maxn 100005
using namespace std;
int s,n,m,dis[maxn],w[maxn];
vector<int> son[maxn],v[maxn];
void Set(int prt,int to,int d)
{
    son[prt].push_back(to),v[prt].push_back(d);
}
struct Node
{
    int x,dis;
    bool operator < (const Node &a)const
    {
        return dis>a.dis;
    }
};priority_queue<Node> q;
int vis[maxn],tim=0;
void Dijkstra(int S)
{
    for(int i=1;i<=n;i++)
        dis[i]=2147483647;
    dis[S]=0,tim++,q.push((Node){S,0});
    while(!q.empty())
    {
        Node prt=q.top();q.pop();
        int rt=prt.x;
        if(vis[rt]==tim)
            continue;
        vis[rt]=tim;
        for(int i=0;i<son[rt].size();i++)
        {
            int to=son[rt][i];
            if(dis[to]>dis[rt]+v[rt][i])
                dis[to]=dis[rt]+v[rt][i],q.push((Node){to,dis[to]});
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        Set(x,y,z);
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;
}
