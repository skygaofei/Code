//
//  愤怒的牛.cpp
//  刷题专用
//
//  Created by 高飞 on 2018/11/3.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int x[100005];
inline bool check(int mid)
{
    int tmp=1,pos=1;
    for(int i=2;i<=n;i++)
    {
        if(x[i]-x[pos]>=mid)
            tmp++,pos=i;
        if(tmp>=m)
            return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    int l=0,r=x[n]-x[1],mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    cout<<l;
    return 0;
}
