//
//  P4071 [SDOI2016]排列计数.cpp
//  7.20集训
//
//  Created by skygao on 2019/7/20.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define maxn 1000005
#define ull unsigned long long
#define mod 1000000007
#define re register
using namespace std;
int n,m;
ull fac[maxn];
ull f[maxn],prepow[maxn];
ull quickmulti(ull a,ull b)
{
    ull ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans%mod;
}
void init()
{
    fac[0]=0,fac[1]=1;
    for(re int i=2;i<maxn;++i)
        fac[i]=(fac[i-1]*i)%mod;
    f[0]=0,f[1]=0,f[2]=1;
    for(re int i=3;i<maxn;++i)
        f[i]=(i-1)*(f[i-1]+f[i-2])%mod;
    prepow[0]=prepow[1]=1;
    for(re int i=2;i<maxn;++i)
        prepow[i]=quickmulti(fac[i],mod-2);
}
ull C(int n,int m)
{
    return (fac[n]*prepow[n-m]%mod*prepow[m]%mod)%mod;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n==m)
            printf("1\n");
        else
            printf("%llu\n",(C(n,m)*f[n-m])%mod);
    }
    return 0;
}
