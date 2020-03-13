//
//  code.cpp
//  CSP-S Day1
//
//  Created by skygao on 2019/11/16.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define ull unsigned long long
using namespace std;
ull n,k;
ull _Pow(ull a,ull b)
{
    ull res=1;
    while(b)
    {
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int main()
{
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    scanf("%llu%llu",&n,&k);
    ull prev,tmp;
    prev=(_Pow(2,n-1)-1)*2+1;
    tmp=_Pow(2,n-1)-1;
    while(n!=0)
    {
        if(k<=tmp)
            putchar('0');
        else
            putchar('1'),k=prev-k;
        n--;
        prev=tmp;
        tmp=(tmp+1)/2-1;
    }
    return 0;
}