//
//  main.cpp
//  子串
//
//  Created by 高飞 on 2018/9/15.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define mod 1000000007
using namespace std;
int n,m,K;
char a[1005],b[1005];
int dp[2][205][205][2];
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    scanf("%s",a+1);
    scanf("%s",b+1);
    dp[0][0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=K;k++)
            {
                dp[i%2][j][k][0]=dp[i%2][j][k][1]=0;
            }
        }
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=K;k++)
            {
                if(j>0&&k>0&&a[i]==b[j])
                {
                    dp[i%2][j][k][1]=((dp[(i+1)%2][j-1][k][1]+dp[(i+1)%2][j-1][k-1][0])%mod+dp[(i+1)%2][j-1][k-1][1])%mod;
                }
                dp[i%2][j][k][0]=(dp[(i+1)%2][j][k][0]+dp[(i+1)%2][j][k][1])%mod;
                
            }
        }
    }
    printf("%d",(dp[n%2][m][K][0]+dp[n%2][m][K][1])%mod);
    return 0;
}
