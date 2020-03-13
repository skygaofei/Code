//
//  幸运数字Lucky Number.cpp
//  12.14
//
//  Created by skygao on 2019/12/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#define re register
#define _Min(a,b) a>b?b:a
using namespace std;
inline long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
inline long long Euler(long long x)
{
    long long q=sqrt(x),res=x;
    for(re int i=2;i<=q;++i)
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    if(x!=1)
        res=res/x*(x-1);
    return res;
}
long long quickmul(long long a,long long b,long long p)
{
    long long res=0;
    if(b==0)
        return 0;
    while(b)
    {
        if(b&1)
            res=(res+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return res;
}
long long quickpow(long long a,long long b,long long p)
{
    long long res=1;
    if(b==0)
        return 1%p;
    while(b)
    {
        if(b&1)
            res=quickmul(res,a,p);
        a=quickmul(a,a,p);
        b>>=1;
    }
    return res;
}
long long ans=0x7fffffffffffffff;
int main()
{
    long long l;
    int ca=0;
    while(scanf("%lld",&l)!=EOF)
    {
        ans=0x7fffffffffffffff;
        if(l==0)
            return 0;
        long long d=gcd(l,8);
        long long phi=Euler(9*l/d);
        long long tmp=9*l/d;
        long long q=sqrt(phi);
        for(re int i=1;i<=q;++i)
            if(phi%i==0)
            {
                if(quickpow(10,i,tmp)==1)
                    ans=_Min(ans,i);
                if(quickpow(10,phi/i,tmp)==1)
                    ans=_Min(ans,phi/i);
            }
        if(ans==0x7fffffffffffffff)
            printf("Case %d: 0\n",++ca);
        else
            printf("Case %d: %lld\n",++ca,ans);
    }
    return 0;
}