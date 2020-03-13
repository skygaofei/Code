//
//  P2155 [SDOI2008]沙拉公主的困惑.cpp
//  Algorithm
//
//  Created by skygao on 2019/12/22.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define maxn 10000005
#define ll long long
using namespace std;
int t,n,m;ll mod;
bool is_prime[maxn];
ll fac[maxn],f1[maxn],f2[maxn];
void prime(int n)
{
    is_prime[1]=false;
    for(int i=2;i<=n;i++)
        is_prime[i]=true;
    for(int i=2;i*i<=n;i++)
        if(is_prime[i])
            for(int j=i*i;j<=n;j+=i)
                is_prime[j]=false;
}
ll quickpow(ll a,ll b,ll p)
{
    ll res=1;
    if(b==0)
        return 1%p;
    while(b)
    {
        if(b&1)
            res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d%lld",&t,&mod);
    prime(maxn-1);
    fac[1]=f1[1]=f2[1]=1;
    for(re int i=2;i<maxn;++i)
    {
        fac[i]=(fac[i-1]*i)%mod;
        if(is_prime[i])
            f1[i]=(f1[i-1]*(i-1))%mod,f2[i]=(f2[i-1]*i)%mod;
        else
            f1[i]=f1[i-1],f2[i]=f2[i-1];
    }
    ll ans;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=(((fac[n]*f1[m])%mod)*quickpow(f2[m],mod-2,mod))%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
