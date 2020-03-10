//
//  文化之旅.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define maxn 125
#define re register
using namespace std;
int n,k,m,s,t;
int a[maxn],mp[maxn][maxn],f[maxn][maxn];
int tmpa,tmpb,tmpc;
int main()
{
    scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=n;++j)
            f[i][j]=0x7ffffff;
    for(re int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(re int i=1;i<=k;++i)
        for(re int j=1;j<=k;++j)
            scanf("%d",&mp[i][j]);
    for(re int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&tmpa,&tmpb,&tmpc);
        if(!mp[a[tmpb]][a[tmpa]]&&a[tmpb]!=a[tmpa])
            f[tmpa][tmpb]=min(f[tmpa][tmpb],tmpc);
        if(!mp[a[tmpa]][a[tmpb]]&&a[tmpb]!=a[tmpa])
            f[tmpb][tmpa]=min(f[tmpb][tmpa],tmpc);
    }
    if(a[s]==a[t])
    {
        printf("-1");
        return 0;
    }
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=n;++j)
            if(i!=j)
                for(re int k=1;k<=n;++k)
                    if(j!=k&&i!=k)
                        if(f[i][k]+f[k][j]<f[i][j])
                            f[i][j]=f[i][k]+f[k][j];
    if(f[s][t]==0x7ffffff)
        printf("-1");
    else
        printf("%d",f[s][t]);
    return 0;
}
