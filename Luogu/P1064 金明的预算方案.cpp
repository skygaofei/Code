//
//  多重背包.cpp
//  刷题专用
//
//  Created by 高飞 on 2018/10/27.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m;
int f[40000],g[40000];
struct pricwe
{
    int price,value,team;
}
a[100];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].price,&a[i].value,&a[i].team);
        a[i].value*=a[i].price;
    }
    for(int i=1;i<=m;i++)
        if(!a[i].team)
        {
            for(int j=1;j<a[i].price;j++)
                g[j]=0;
            for(int j=a[i].price;j<=n;j++)
                g[j]=f[j-a[i].price]+a[i].value;
            for(int j=1;j<=m;j++)
                if(a[j].team==i)
                    for(int k=n;k>=a[i].price+a[j].price;k--)
                        g[k]=max(g[k],g[k-a[j].price]+a[j].value);
            for(int j=a[i].price;j<=n;j++)
                f[j]=max(f[j],g[j]);
        }
    cout<<f[n];
    return 0;
}
