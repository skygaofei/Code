//
//  main.cpp
//  飞行路线
//
//  Created by 高飞 on 2018/8/6.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Node
{
    int x,dis,cs;
    bool operator > (const Node &a)const
    {
        return dis>a.dis;
    }
};priority_queue<Node,vector<Node>,greater<Node> > q;
int n,m,k,s,t;
vector<int> edge[100005],v[100005];
bool vis[100005][20];
int dis[100005][20];
void Dijkstra()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dis[i][j]=21474836;
    memset(vis,0,sizeof(vis));
    dis[s][0]=0;q.push((Node){s,0,0});
    while(!q.empty())
    {
        Node prt=q.top();q.pop();
        int rt=prt.x;
        int cs=prt.cs;
        if(vis[rt][cs])
            continue;
        vis[rt][cs]=true;
        for(int i=0;i<edge[rt].size();i++)
        {
            int to=edge[rt][i];
            if(dis[to][cs]>dis[rt][cs]+v[rt][i])
            {
                dis[to][cs]=dis[rt][cs]+v[rt][i];
                q.push((Node){to,dis[to][cs],cs});
            }
            if(cs<k)
            {
                if(dis[to][cs+1]>dis[rt][cs])
                {
                    dis[to][cs+1]=dis[rt][cs];
                    q.push((Node){to,dis[to][cs+1],cs+1});
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        edge[x].push_back(y);
        v[x].push_back(z);
        edge[y].push_back(x);
        v[y].push_back(z);
    }
    Dijkstra();
    printf("%d",dis[t][k]);
    return 0;
}
