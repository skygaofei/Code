//
//  main.cpp
//  没有上司的舞会
//
//  Created by 高飞 on 2018/9/15.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> son[6005];
int f[6005][2];
int r[6005],n;
bool vis[6005],notroot[6005];
void dfs(int x)
{
    f[x][1]=r[x];
    vis[x]=true;
    for(int i=0;i<son[x].size();i++)
    {
        int y=son[x][i];
        if(!vis[y])
        {
            dfs(y);
            f[x][0]+=max(f[y][1],f[y][0]);
            f[x][1]+=f[y][0];
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    int x,y;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        son[x].push_back(y);
        son[y].push_back(x);
        notroot[y]=true;
    }
    int i;
    for(i=1;i<=n;i++)
        if(!notroot[i])
        {
            dfs(i);
            break;
        }
    printf("%d",max(f[i][1],f[i][0]));
    return 0;
}
