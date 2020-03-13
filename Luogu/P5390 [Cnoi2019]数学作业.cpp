//
//  P5390 [Cnoi2019]数学作业.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/3/1.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define re register
using namespace std;
long long quickpow(long long a,long long b,long long mod)
{
    long long res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    int t,n;long long x,s;
    scanf("%d",&t);
    while(t--)
    {
        s=0;
        scanf("%d",&n);
        for(re int i=1;i<=n;++i)
            scanf("%lld",&x),s|=x;
        s=(s*quickpow(2,n-1,998244353))%998244353;
        printf("%lld\n",s);
    }
    return 0;
}
