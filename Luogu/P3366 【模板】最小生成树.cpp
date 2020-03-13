//
//  Kruscal.cpp
//  模版
//
//  Created by skygao on 2019/11/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#define maxn 110000
#define maxm 510000
using namespace std;
struct edge
{
    int x,y,val;
}e[maxm];
int n,m,fa[maxn],ans;
bool cmp(edge a,edge b)
{
    return a.val<b.val;
}
int find(int x)
{
    if (fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].val);
    sort(e+1,e+m+1,cmp);
    for (int i=1;i<=n;++i)
        fa[i]=i;
    for (int i=1;i<=m;++i)
    {
        int f1=find(e[i].x);
        int f2=find(e[i].y);
        if (f1!=f2)
        {
            fa[f1]=fa[f2];
            ans+=e[i].val;
        }
    }
    printf("%d",ans);
    return 0;
}
