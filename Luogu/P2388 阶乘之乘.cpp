//
//  main.cpp
//  阶乘之乘
//
//  Created by 高飞 on 2018/9/22.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    long long n;
    scanf("%lld",&n);
    long long ans=0,s=0,t=0;
    for(long long i=1;i<=n;i++)
    {
        t=i;
        while(!(t%5))
        {
            s++;
            t/=5;
        }
        ans+=s;
    }
    printf("%lld",ans);
    return 0;
}
