//
//  转圈问题.cpp
//  刷题专用
//
//  Created by 高飞 on 2018/10/20.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
long long mod(long long a, long long b, long long c)
{
    long long ans=1;
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
    int n,k,x,m;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    long long temp,ans;
    temp=mod(10,k,n);
    ans=(x%n+m%n*temp%n)%n;
    printf("%lld",ans);
    return 0;
}
