//
//  Home on the Range.cpp
//  USACO刷题(xuezhan.org)
//
//  Created by skygao on 2019/8/15.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define maxn 305
using namespace std;
int n,cnt[maxn*maxn];
int dp[maxn][maxn];
char mp[maxn][maxn];
int main()
{
    scanf("%d",&n);
    for(re int i=0;i<n;++i)
        scanf("%s",mp[i]);
    for(re int i=0;i<n;++i)
        dp[i][0]=(mp[i][0]=='1');
    for(re int i=0;i<n;++i)
        dp[0][i]=(mp[0][i]=='1');
    for(re int i=1;i<n;++i)
        for(re int j=1;j<n;++j)
            if(mp[i][j]=='1')
            {
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                cnt[dp[i][j]]++;
            }
    for(re int i=n;i>0;--i)
        cnt[i-1]+=cnt[i];
    for(re int i=2;i<=n;++i)
        if(cnt[i])
            printf("%d %d\n",i,cnt[i]);
    return 0;
}
