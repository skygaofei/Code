//
//  AT240 算盤の書.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/14.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
using namespace std;
long long f[47];
int main()
{
    int n;
    scanf("%d",&n);
    f[0]=1,f[1]=1,f[2]=2;
    for(re int i=3;i<=n;++i)
        f[i]=f[i-1]+f[i-2];
    printf("%lld\n",f[n]);
    return 0;
}
