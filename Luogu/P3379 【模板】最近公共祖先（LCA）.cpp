// luogu-judger-enable-o2
//
//  P3379 [模板]最近公共祖先(LCA).cpp
//  7.20集训
//
//  Created by skygao on 2019/7/20.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define re register
#define maxn 500005
using namespace std;
vector<int> son[maxn];
int fa[maxn][20],depth[maxn];
int n,m,s;
inline void add(int x,int y)
{
    son[x].push_back(y);
}
void dfs(int x,int S)
{
    depth[x]=depth[S]+1;
    fa[x][0]=S;
    for(re int i=0;i<son[x].size();++i)
    {
        int rt=son[x][i];
        if(rt==S)
            continue;
        dfs(rt,x);
    }
}
inline int go_up(int x,int d)
{
    for(re int j=19;j>=0;--j)
        if((1<<j)&d)
            x=fa[x][j];
    return x;
}
int main()
{
    int x,y;
    scanf("%d%d%d",&n,&m,&s);
    for(re int i=1;i<n;++i)
        scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(s,s);
    for(re int j=1;j<=19;++j)
        for(re int i=1;i<=n;++i)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    for(re int i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        if(depth[x]>depth[y])
            x=go_up(x,depth[x]-depth[y]);
        if(depth[x]<depth[y])
            y=go_up(y,depth[y]-depth[x]);
        for(re int j=19;j>=0;--j)
            if(fa[x][j]!=fa[y][j])
                x=fa[x][j],y=fa[y][j];
        if(x!=y)
            x=fa[x][0];
        printf("%d\n",x);
    }
    return 0;
}
