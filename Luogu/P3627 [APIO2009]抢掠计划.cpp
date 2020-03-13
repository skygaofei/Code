// luogu-judger-enable-o2
//
//  P3627 [APIO2009]抢掠计划.cpp
//  7.22作业
//
//  Created by skygao on 2019/7/22.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 500005
#define re register
using namespace std;
int dfsn[maxn],lowlink[maxn],dfs_clock;
int stack[maxn],top,scc[maxn],scc_cnt;
vector<int> son[maxn],v[maxn];
int val[maxn],sum[maxn];
int dis[maxn],ans;
int x[maxn],y[maxn];
int n,m,s,p;
bool vis[maxn];
inline void dfs_scc(int x)
{
    dfsn[x]=lowlink[x]=++dfs_clock;
    stack[++top]=x;
    for(re int i=0;i<son[x].size();++i)
    {
        int now=son[x][i];
        if(!dfsn[now])
        {
            dfs_scc(now);
            lowlink[x]=min(lowlink[x],lowlink[now]);
        }
        else if(!scc[now])
            lowlink[x]=min(lowlink[x],lowlink[now]);
    }
    if(lowlink[x]==dfsn[x])
    {
        scc_cnt++;
        while(stack[top+1]!=x)
        {
            scc[stack[top]]=scc_cnt;
            sum[scc_cnt]+=val[stack[top--]];
        }
    }
}
inline void addedge(int x,int y)
{
    son[x].push_back(y);
}
inline void _addedge(int x,int y,int val)
{
    son[x].push_back(y);
    v[x].push_back(val);
}
queue<int> q;
void spfa()
{
    memset(dis,0x7f,sizeof(dis));
    int tmp=scc[s];
    dis[tmp]=-sum[tmp];
    q.push(tmp);vis[tmp]=true;
    while(!q.empty())
    {
        int prt=q.front();
        q.pop();
        for(re int i=0;i<son[prt].size();++i)
        {
            int rt=son[prt][i];
            if(dis[prt]+v[prt][i]<dis[rt])
            {
                dis[rt]=dis[prt]+v[prt][i];
                if(!vis[rt])
                {
                    q.push(rt);
                    vis[rt]=true;
                }
            }
        }
        vis[prt]=false;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=m;++i)
    {
        scanf("%d%d",&x[i],&y[i]);
        addedge(x[i],y[i]);
    }
    for(re int i=1;i<=n;++i)
        scanf("%d",&val[i]);
    for(re int i=1;i<=n;++i)
        if(!dfsn[i])
            dfs_scc(i);
    for(re int i=1;i<=n;++i)
        son[i].clear();
    for(re int i=1;i<=m;++i)
        if(scc[x[i]]!=scc[y[i]])
            _addedge(scc[x[i]],scc[y[i]],-sum[scc[y[i]]]);
    scanf("%d%d",&s,&p);
    spfa();
    for(re int i=1;i<=p;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        if(-dis[scc[tmp]]>ans)
            ans=-dis[scc[tmp]];
    }
    printf("%d",ans);
    return 0;
}
