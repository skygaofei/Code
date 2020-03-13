//
//  计算器.cpp
//  12.21
//
//  Created by skygao on 2019/12/27.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#define re register
#define ll long long
using namespace std;
inline long long quickpow(long long a,long long b,long long p)
{
    long long res=1;
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
inline ll baby_step_giant_step(ll a,ll b,ll p)
{
    map<long ,long>hash;
    hash.clear();
    b%=p;
    int t=(int)sqrt(p)+1;
    for(int j=0;j<t;j++)
    {
        int val=(long long)b*quickpow(a,j,p)%p;
        hash[val]=j;
    }
    a=quickpow(a,t,p);
    if(a==0)
    {
        if(b==0)
            return 1;
        else
            return -1;
    }
    for(int i=0;i<=t;i++)
    {
        int val=quickpow(a,i,p);
        int j=hash.find(val)==hash.end()?-1:hash[val];
        if(j>=0&&i*t-j>=0){
            return i*t-j;
        }
    }
    return -1;
}
inline ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    re ll gcd=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return gcd;
}
inline int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int t,type;
    ll a,b,p,Gcd;
    ll ans;
    scanf("%d%d",&t,&type);
    while(t--)
    {
        if(type==1)
        {
            scanf("%lld%lld%lld",&a,&b,&p);
            ans=quickpow(a,b,p)%p;
            printf("%lld\n",ans);
        }
        else if(type==2)
        {
            ll x,y;
            scanf("%lld%lld%lld",&a,&b,&p);
            Gcd=exgcd(a,p,x,y);
            if(b%Gcd!=0)
                printf("Orz, I cannot find x!\n");
            else
            {
                re int tmp=p/Gcd;
                while(x<0)
                    x+=tmp;
                printf("%lld\n",((x*b/Gcd)%tmp+tmp)%tmp);
            }
        }
        else if(type==3)
        {
            scanf("%lld%lld%lld",&a,&b,&p);
            ans=baby_step_giant_step(a,b,p);
            if(ans==-1)
                printf("Orz, I cannot find x!\n");
            else
                printf("%lld\n",ans);
        }
    }
    return 0;
}
