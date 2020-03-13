//
//  回文字串.cpp
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
#define re register
#define maxn 5005
using namespace std;
int n,dp[maxn][maxn];
char s1[maxn],s2[maxn];
int main()
{
    scanf("%s",s1+1);
    n=strlen(s1+1);
    for(re int i=1;i<=n;++i)
        s2[i]=s1[n-i+1];
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=n;++j)
        {
            if(s1[i]==s2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    printf("%d",n-dp[n][n]);
    return 0;
}
