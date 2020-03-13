//
//  main.cpp
//  easy
//
//  Created by 高飞 on 2018/8/8.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define mod 1000000007
#define maxn 100005
#define ll long long
using namespace std;
ll number[maxn],answer,temp;
int n,m,k,counter;
struct Mystruct
{
    ll x,y;
    bool operator < (const Mystruct a) const
    {
        if(a.x==x)
            return a.y<y;
        else
            return a.x<x;
    }
}num[maxn];
ll Pow(ll a,ll b,ll c)
{
    ll ans=1;
    while(b!=0)
    {
        if(b%2==1)
            ans=ans*a%c;
        a=a*a%c;
        b/=2;
    }
    return ans;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    temp=((ll)1*n*(n+1)>>1)%mod;
    for(int i=1;i<=k;i++)
        scanf("%lld%lld",&num[i].x,&num[i].y);
    sort(num+1,num+k+1);
    for(int i=1;i<=k;i++)
    {
        if(num[i].x!=num[i-1].x)
            number[++counter]=temp;
        else
        {
            if(num[i].y==num[i-1].y)
                continue;
        }
        number[counter]=(number[counter]-num[i].y+mod)%mod;
    }
    answer=Pow(temp,m-counter,mod);
    for(int i=1;i<=counter;i++)
        answer=(answer*number[i]+mod)%mod;
    printf("%lld",answer);
    return 0;
}
