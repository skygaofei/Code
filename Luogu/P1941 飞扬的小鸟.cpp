//
//  main.cpp
//  飞扬的小鸟
//
//  Created by 高飞 on 2018/10/4.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 10005
using namespace std;
int n,m,k;
int x[maxn],y[maxn];
bool vis[maxn];
int down[maxn],up[maxn],dp[maxn][2005];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
    {
        up[i]=m;
        down[i]=1;
    }
    for(int i=1;i<=k;i++)
    {
        int tempa,tempb,tempc;
        scanf("%d%d%d",&tempa,&tempb,&tempc);
        vis[tempa]=1;
        down[tempa]=tempb+1;
        up[tempa]=tempc-1;
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=x[i]+1;j<=x[i]+m;j++)
            dp[i][j]=min(dp[i-1][j-x[i]]+1,dp[i][j-x[i]]+1);
        for(int j=m+1;j<=x[i]+m;j++)
            dp[i][m]=min(dp[i][m],dp[i][j]);
        for(int j=1;j<=m-y[i];j++)
            dp[i][j]=min(dp[i][j],dp[i-1][j+y[i]]);
        for(int j=1;j<down[i];j++)
            dp[i][j]=0x3f3f3f3f;
        for(int j=up[i]+1;j<=m;j++)
            dp[i][j]=0x3f3f3f3f;
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=m;i++)
        ans=min(ans,dp[n][i]);
    if(ans<0x3f3f3f3f)
    {
        printf("1\n%d",ans);
        return 0;
    }
    int i,j;
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=m;j++)
            if(dp[i][j]<0x3f3f3f3f)
                break;
        if(j<=m)
            break;
    }
    ans=0;
    for(j=1;j<=i;j++)
        if(vis[j])
            ans++;
    printf("0\n%d",ans);
    return 0;
}
