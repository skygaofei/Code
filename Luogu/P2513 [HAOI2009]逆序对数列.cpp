//
//  main.cpp
//  逆序对数列
//
//  Created by 高飞 on 2018/10/4.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define mod 10000
using namespace std;
int n,m;
int f[1005][1005];
int s[1005];
int main()
{
    scanf("%d%d",&n,&m);
    f[1][0]=1;
    for(int i=2;i<=n;i++)
    {
        s[0]=f[i-1][0];
        for(int j=1;j<=m;j++)
            s[j]=(s[j-1]+f[i-1][j])%mod;
        for(int j=0;j<=m;j++)
            if(j-i+1<=0)
                f[i][j]=s[j];
            else
                f[i][j]=(s[j]-s[j-i]+mod)%mod;
    }
    printf("%d",f[n][m]);
    return 0;
}
