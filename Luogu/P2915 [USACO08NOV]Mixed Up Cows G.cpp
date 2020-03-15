//
//  P2915 [USACO08NOV]Mixed Up Cows G.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/3/15.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define re register
using namespace std;
int n,m;
int a[16];
long long f[1<<16][16],ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(re int i=0;i<n;++i)
        scanf("%d",&a[i]),f[1<<i][i]=1;
    for(re int i=0;i<(1<<n);++i)
        for(re int j=0;j<n;++j)
        {
            if(i>>j&1)
                for(re int k=0;k<n;++k)
                    if(~i>>k&1)
                        if(abs(a[j]-a[k])>m)
                            f[i|1<<k][k]+=f[i][j];
            if(i==(1<<n)-1)
                ans+=f[i][j];
        }
    printf("%lld",ans);
    return 0;
}
