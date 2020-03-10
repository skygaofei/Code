//
//  传球游戏.cpp
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
#define maxn 35
#define re register
using namespace std;
int n,m,dp[maxn][maxn];
int main()
{
    scanf("%d%d",&n,&m);
    dp[1][0]=1;
    for(re int i=1;i<=m;++i)
    {
        dp[1][i]=dp[2][i-1]+dp[n][i-1];
        for(re int k=2;k<=n-1;++k)
            dp[k][i]=dp[k-1][i-1]+dp[k+1][i-1];
        dp[n][i]=dp[n-1][i-1]+dp[1][i-1];
    }
    printf("%d",dp[1][m]);
    return 0;
}
