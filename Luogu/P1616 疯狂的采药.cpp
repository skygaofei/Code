//
//  完全背包.cpp
//  刷题专用
//
//  Created by 高飞 on 2018/10/27.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int v,n;
int c[10005],w[10005];
int f[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>v;
    swap(n,v);
    for(int i=1;i<=n;i++)
        cin>>c[i]>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=c[i];j<=v;j++)
            f[j]=max(f[j-c[i]]+w[i],f[j]);
    cout<<f[v];
    return 0;
}
