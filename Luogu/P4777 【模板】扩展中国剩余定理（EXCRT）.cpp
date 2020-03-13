//
//  奇怪的数.cpp
//  12.21
//
//  Created by skygao on 2019/12/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define ll __int128
#define re register
using namespace std;
pair<ll,ll> exgcd(ll a,ll b)
{
    if(b==0)
        return make_pair(1,0);
    pair<ll,ll> tmp=exgcd(b,a%b);
    return make_pair(tmp.second,tmp.first-(a/b)*tmp.second);
}
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
inline __int128 read()
{
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void write(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int main()
{
    int n;
    ll a1,m1,a2,m2;
    while(scanf("%d",&n)!=EOF)
    {
        bool flag=false;
        a1=read(),m1=read();
        for(re int i=2;i<=n;++i)
        {
            a2=read(),m2=read();
            pair<ll,ll> k=exgcd(a1,a2);
            ll g=gcd(a1,a2);
            if((m2-m1)%g==0)
            {
                k.first=k.first*(m2-m1)/g;
                ll n1=a2/g;
                k.first=(k.first%n1+n1)%n1;
                m1=a1*k.first+m1;
                a1=(a1*a2)/g;
            }
            else
                flag=true;
        }
        if(flag)
            printf("-1\n");
        else
            write(m1),printf("\n");
    }
    return 0;
}
