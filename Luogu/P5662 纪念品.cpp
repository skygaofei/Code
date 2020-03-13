//
//  T3纪念品.cpp
//  CSP-J
//
//  Created by skygao on 2019/11/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
using namespace std;
int dp[10005],t,n,m;
int price[105][105];
int ans,maxx=-0x7fffffff;
int main()
{
    scanf("%d%d%d",&t,&n,&m);
    ans=m;
    for(re int i=1;i<=t;++i)
        for(re int j=1;j<=n;++j)
            scanf("%d",&price[i][j]);
    for(re int i=1;i<=t;++i)
    {
        memset(dp,~0x7f,sizeof(dp));
        dp[ans]=ans;
        for(re int j=1;j<=n;++j)
            for(int k=ans;k>=price[i][j];--k)
                dp[k-price[i][j]]=max(dp[k-price[i][j]],dp[k]+price[i+1][j]-price[i][j]);
        maxx=-0x7fffffff;
        for(re int j=0;j<=ans;++j)
            maxx=max(maxx,dp[j]);
        ans=maxx;
    }
    printf("%d",ans);
    return 0;
}
