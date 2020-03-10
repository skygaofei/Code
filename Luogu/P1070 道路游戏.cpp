//
//  道路游戏.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define maxn 1005
using namespace std;
const int N=1010;
int n,m,p;
int f[maxn][maxn],cost[maxn],cnt[maxn][maxn];
int pos[maxn][maxn],l[maxn],r[maxn],add[maxn],dp[maxn];
int get_id(int i,int j)
{
    return ((j-i)%n+n)%n;
}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&f[j][i]);
            f[j][i]+=f[j-1][i-1];
        }
    for(int i=0;i<n;i++)
    {
        scanf("%d",cost+i);
        cnt[i][++r[i]]=-cost[i],l[i]++;
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int id=get_id(i,j);
            while(l[id]<=r[id]&&pos[id][l[id]]+p<i)
                l[id]++;
            if(j==0)
                add[id]+=f[i][n];
            if(l[id]<=r[id])
                dp[i]=max(dp[i],cnt[id][l[id]]+add[id]+f[i][j]);
        }
        for(int j=0;j<n;j++)
        {
            int id=get_id(i,j);
            int tmp=dp[i]-add[id]-f[i][j]-cost[j];
            while(l[id]<=r[id]&&cnt[id][r[id]]<=tmp)
                r[id]--;
            pos[id][++r[id]]=i;
            cnt[id][r[id]]=tmp;
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}
