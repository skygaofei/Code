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
#define re register
#define ll long long
using namespace std;
ll sum[4000005];
int n,m,x;
inline ll find(int l,int r,int i)
{
    int mid;
    ll res,ans=0;
    while(l<=r)
    {
        mid=(l+r)>>1;
        res=sum[mid]-sum[i-1];
        if(res<=m)
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    return ans;
}
int main()
{
    ll maxx=-0x7ffffffffff,tmp;int l = 0,r = 0;
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=n;++i)
        scanf("%d",&x),sum[i]=sum[i-1]+x;
    for(re int i=1;i<=n;++i)
    {
        x=find(i,n,i);
        tmp=sum[x]-sum[i-1];
        if(tmp>maxx)
            maxx=tmp,l=i,r=x;
    }
    printf("%d %d %lld",l,r,maxx);
    return 0;
}
