//
//  火柴排队.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/15.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define maxn 100005
#define mod 99999997
#define re register
using namespace std;
int n,c[maxn],d[maxn],ans;
struct Node
{
    int x,pos;
}a[maxn],b[maxn];
bool cmp(Node a,Node b)
{
    return a.x<b.x;
}
void work(int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)>>1;
    work(l,mid);
    work(mid+1,r);
    re int i,j,k;
    for(i=l,j=mid+1,k=l;i<=mid&&j<=r;)
    {
        if(c[i]>c[j])
            ans=(ans+r-j+1)%mod,d[k]=c[i],++i,++k;
        else
            d[k]=c[j],++k,++j;
    }
    for(;i<=mid;++i,++k)
        d[k]=c[i];
    for(;j<=r;++j,++k)
        d[j]=c[j];
    for(i=l;i<=r;++i)
        c[i]=d[i];
}
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d",&a[i].x),a[i].pos=i;
    for(re int i=1;i<=n;++i)
        scanf("%d",&b[i].x),b[i].pos=i;
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    for(re int i=1;i<=n;++i)
        c[b[i].pos]=a[i].pos;
    work(1,n);
    printf("%d",ans);
    return 0;
}
