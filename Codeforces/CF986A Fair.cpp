//
//  CF986A Fair.cpp
//  7.21集训
//
//  Created by skygao on 2019/7/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define re register
#define maxn 100005
using namespace std;
vector<int> son1[maxn],son2[maxn];
queue<int> q;
inline void addedge(int x,int y)
{
    son1[x].push_back(y);
}
inline void _addedge(int x,int y)
{
    son2[x].push_back(y);
}
int n,m,k,s;
int town[maxn],dis[maxn][110];
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&s);
    for(re int i=1;i<=n;++i)
        scanf("%d",&town[i]),addedge(town[i],i);
    for(re int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        _addedge(x,y),_addedge(y,x);
    }
    memset(dis,-1,sizeof(dis));
    for(re int i=1;i<=k;++i)
    {
        for(auto j:son1[i])
            q.push(j),dis[j][i]=0;
        while(!q.empty())
        {
            int prt=q.front();
            q.pop();
            for(auto j:son2[prt])
            {
                if(dis[j][i]==-1)
                {
                    dis[j][i]=dis[prt][i]+1;
                    q.push(j);
                }
            }
        }
    }
    int ans=0;
    for(re int i=1;i<=n;++i)
    {
        ans=0;
        sort(dis[i]+1,dis[i]+k+1);
        for(re int j=1;j<=s;++j)
            ans+=dis[i][j];
        printf("%d ",ans);
    }
    return 0;
}
