//
//  小朋友的数字.cpp
//  qdojxyz刷题
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
#define maxn 1000005
using namespace std;
long long n,p,zdh[maxn],ans,a[maxn],dp[maxn],flag;
int main()
{
    scanf("%lld%lld",&n,&p);
    ans=-0x7fffffffffffffff;
    for(re int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    dp[1]=zdh[1]=a[1];
    for(re int i=2;i<=n;++i)
        dp[i]=max(dp[i-1]+a[i],a[i]);
    for(re int i=2;i<=n;++i)
        dp[i]=max(dp[i],dp[i-1]);
    zdh[2]=zdh[1]+dp[1];
    ans=zdh[1];
    for(re int i=3;i<=n;++i)
    {
        if(dp[i-1]+zdh[i-1]<0&&zdh[i-1]>0)
            flag=1;
        if(flag==1)
            zdh[i]=(zdh[i-1]%p+dp[i-1])%p;
        else
            zdh[i]=max(zdh[i-1]+dp[i-1],zdh[i-1]);
        ans=max(ans,zdh[i]);
    }
    if(flag==1)
        printf("%lld",zdh[n]%p);
    else
        printf("%lld",ans%p);
    return 0;
}
