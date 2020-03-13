//
//  yyy2015c01的U盘.cpp
//  7.20集训
//
//  Created by skygao on 2019/7/20.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define maxn 1005
using namespace std;
int n,p,S;
int v[maxn],w[maxn];
int f[maxn];
bool flag;
bool check(int x)
{
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;++i)
    {
        if(w[i]<=x)
            for(int j=S;j>=w[i];--j)
                f[j]=max(f[j],f[j-w[i]]+v[i]);
    }
    if(f[S]<p)
        return false;
    return true;
}
int main()
{
    scanf("%d%d%d",&n,&p,&S);
    for(int i=1;i<=n;++i)
        scanf("%d%d",&w[i],&v[i]);
    int l=0,r=S,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check(mid))
            r=mid,flag=true;
        else
            l=mid+1;
    }
    if(flag)
        printf("%d",l);
    else
        printf("No Solution!");
    return 0;
}
