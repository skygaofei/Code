//
//  main.cpp
//  NASA的食物计划
//
//  Created by 高飞 on 2018/8/7.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int f[505][505];
int w[55],c[55],k[55];
int m,n,p;
int main()
{
    scanf("%d%d%d",&m,&n,&p);
    for(int i=1;i<=p;i++)
        scanf("%d%d%d",&w[i],&c[i],&k[i]);
    for(int i=1;i<=p;i++)
        for(int j=m;j>=w[i];j--)
            for(int z=n;z>=c[i];z--)
                f[j][z]=max(f[j][z],f[j-w[i]][z-c[i]]+k[i]);
    printf("%d",f[m][n]);
    return 0;
}
