//
//  SPFA.cpp
//  CSP RP++
//
//  Created by skygao on 2019/11/15.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#define maxn 2005
using namespace std;
int n,m;
vector<int> son[maxn],v[maxn];
bool vis[maxn];
int dis[maxn],cnt[maxn];
inline void addedge(int x,int y,int z)
{
    son[x].push_back(y);
    v[x].push_back(z);
}
inline bool SPFA(int S)
{
    for(int i=1;i<=n;++i)
        vis[i]=false,dis[i]=2147483647,cnt[i]=0;
    queue<int> q;
    q.push(S);
    vis[S]=true;dis[S]=0;
    while(!q.empty())
    {
        int rt=q.front();q.pop();vis[rt]=false;
        if(cnt[rt]>=n)
            return true;
        for(int i=0;i<son[rt].size();++i)
        {
            int to=son[rt][i];
            if(dis[to]>dis[rt]+v[rt][i])
            {
                dis[to]=dis[rt]+v[rt][i];
                if(!vis[to])
                {
                    q.push(to);
                    vis[to]=true;
                    cnt[to]++;
                    if(cnt[to]>=n)
                        return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int t,x,y,z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(z<0)
                addedge(x,y,z);
            else
                addedge(x,y,z),addedge(y,x,z);
        }
        puts(SPFA(1)?"YE5":"N0");
        for(int i=1;i<=n;++i)
            son[i].clear(),v[i].clear();
    }
    return 0;
}
