//
//  P3865 【模板】ST表.cpp
//  Algorithm
//
//  Created by skygao on 2019/10/11.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define re register
#define maxn 100005
using namespace std;
int n,m;
int ST[maxn][21];
inline int Query(int l,int r)
{
    int k=log2(r-l+1);
    return max(ST[l][k],ST[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=n;++i)
        scanf("%d",&ST[i][0]);
    for(re int j=1;j<=21;++j)
        for(re int i=1;i+(1<<j)-1<=n;++i)
            ST[i][j]=max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
    int l,r;
    for(re int i=1;i<=m;++i)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",Query(l,r));
    }
    return 0;
}
