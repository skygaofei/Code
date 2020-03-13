//
//  main.cpp
//  回家
//
//  Created by 高飞 on 2018/8/6.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int p,dis[305];
vector<int> son[305],val[305];
struct que
{
    char x;
    int dis;
    bool operator < (const que &a)const
    {
        return dis>a.dis;
    }
};priority_queue<que> q;
bool vis[305];
void Dijkstra(char s)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;q.push((que){s,0});
    while(!q.empty())
    {
        que prt=q.top();q.pop();
        int rt=(int)prt.x;
        if(vis[rt])
            continue;
        vis[rt]=true;
        for(int i=0;i<son[rt].size();i++)
        {
            int to=son[rt][i];
            if(dis[to]>dis[rt]+val[rt][i])
            {
                dis[to]=dis[rt]+val[rt][i];
                q.push((que){char(to),dis[to]});
            }
        }
    }
}
int main()
{
    scanf("%d",&p);
    char x[2],y[2];
    int z;
    for(int i=1;i<=p;i++)
    {
        scanf("%s%s%d",x,y,&z);
        int _x,_y;
        _x=x[0];
        _y=y[0];
        son[_x].push_back(_y);
        val[_x].push_back(z);
        son[_y].push_back(_x);
        val[_y].push_back(z);
    }
    Dijkstra('Z');
    int ans=999999999;
    char cow;
    for(int i='A';i<='Y';i++)
    {
        if(dis[i]<ans)
        {
            ans=dis[i];
            cow=char(i);
        }
    }
    printf("%c %d",cow,ans);
    return 0;
}
