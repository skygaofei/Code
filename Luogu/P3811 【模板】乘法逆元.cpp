//
//  P3811乘法逆元.cpp
//  7.20集训
//
//  Created by skygao on 2019/7/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define ull unsigned long long
#define re register
#define maxn 3000005
using namespace std;
ull f[maxn];
int main()
{
    ull n,p;
    scanf("%llu%llu",&n,&p);
    f[1]=1;
    printf("1\n");
    for(re int i=2;i<=n;++i)
    {
        f[i]=(p-p/i)*f[p%i]%p;
        printf("%llu\n",f[i]);
    }
    return 0;
}
