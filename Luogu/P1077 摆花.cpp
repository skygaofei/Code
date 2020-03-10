//
//  摆花.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
#define maxn 105
#define mod 1000007
using namespace std;
int f[maxn][maxn],n,m;
int main()
{
    scanf("%d%d",&n,&m);
    int tmp;
    for(re int i=0;i<=n;++i)
        f[i][0]=true;
    for(re int i=1;i<=n;++i)
    {
        scanf("%d",&tmp);
        for(re int j=0;j<=tmp;++j)
            for(re int k=0;k<=m-j;++k)
            {
                if(j==0&&k==0)
                    continue;
                f[i][j+k]+=f[i-1][k];
                f[i][j+k]=f[i][j+k]%mod;
            }
    }
    printf("%d\n",f[n][m]%mod);
    return 0;
}
