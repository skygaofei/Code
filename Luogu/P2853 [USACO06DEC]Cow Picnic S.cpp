//
//  main.cpp
//  牛 野餐
//
//  Created by 高飞 on 2018/8/6.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
int k,n,m,t,to,ans;
int cow_pos[105];
vector<int> edge[10005];
bool vis[1005];
int cnt[1005];
int judge()
{
    int anss=0;
    for(int i=1;i<=n;i++)
        if(cnt[i]==k)
            ans++;
    return ans;
}
void bfs(int s)
{
    memset(vis,0,sizeof(vis));
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        t=q.front();q.pop();
        for(int i=0;i<edge[t].size();i++)
        {
            to=edge[t][i];
            if(!vis[to])
            {
                vis[to]=true;
                q.push(to);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i=1;i<=k;i++)
        scanf("%d",&cow_pos[i]);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
    }
    for(int i=1;i<=k;i++)
    {
        bfs(cow_pos[i]);
        for(int j=1;j<=n;j++)
            if(vis[j])
                cnt[j]++;
    }
    printf("%d",judge());
    return 0;
}
