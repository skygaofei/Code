//
//  深基.cpp
//  Algorithm
//
//  Created by skygao on 2020/1/30.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define re register
#define ll long long
using namespace std;
int n,t;
struct Coins
{
    int m,v;
    double radio;
}c[105];
bool cmp(Coins a,Coins b)
{
    return a.radio>b.radio;
}
int main()
{
    scanf("%d%d",&n,&t);
    for(re int i=1;i<=n;++i)
        scanf("%d%d",&c[i].m,&c[i].v),c[i].radio=(double)c[i].v/(double)c[i].m;
    sort(c+1,c+n+1,cmp);
    double ans=0;
    for(re int i=1;i<=n;++i)
    {
        if(c[i].m>t)
        {
            ans+=(double)t*c[i].radio;
            break;
        }
        t-=c[i].m;
        ans+=c[i].v;
    }
    printf("%.2lf",ans);
    return 0;
}
