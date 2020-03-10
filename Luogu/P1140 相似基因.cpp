//
//  相似基因.cpp
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
#define re register
#define maxn 105
using namespace std;
const int mp[5][5]=
{
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};
int na,nb;
char sa[maxn],sb[maxn];
int a[maxn],b[maxn];
int dp[maxn][maxn];
int main()
{
    scanf("%d%s%d%s",&na,sa,&nb,sb);
    for(re int i=1;i<=na;++i)
        for(re int j=1;j<=nb;++j)
            dp[i][j]=-0x7fffffff;
    for(re int i=1;i<=na;++i)
        switch(sa[i-1])
        {
            case 'A':
                a[i]=0;break;
            case 'C':
                a[i]=1;break;
            case 'G':
                a[i]=2;break;
            case 'T':
                a[i]=3;break;
        }
    for(re int i=1;i<=nb;++i)
        switch(sb[i-1])
        {
            case 'A':
                b[i]=0;break;
            case 'C':
                b[i]=1;break;
            case 'G':
                b[i]=2;break;
            case 'T':
                b[i]=3;break;
        }
    for(re int i=1;i<=na;++i)
        dp[i][0]=dp[i-1][0]+mp[a[i]][4];
    for(re int i=1;i<=nb;++i)
        dp[0][i]=dp[0][i-1]+mp[b[i]][4];
    for(re int i=1;i<=na;++i)
        for(re int j=1;j<=nb;++j)
        {
            dp[i][j]=max(dp[i][j],dp[i][j-1]+mp[b[j]][4]);
            dp[i][j]=max(dp[i][j],dp[i-1][j]+mp[a[i]][4]);
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+mp[a[i]][b[j]]);
        }
    printf("%d",dp[na][nb]);
    return 0;
}
