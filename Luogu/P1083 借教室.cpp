//
//  借教室.cpp
//  刷题专用
//
//  Created by 高飞 on 2018/10/20.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define maxn 1000005
using namespace std;
int n,m;
int r[maxn],s[maxn],t[maxn],d[maxn];
int sum[maxn],unsum[maxn];
bool doo()
{
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+unsum[i];
        if(sum[i]<0)
            return false;
    }
    return true;
}
bool judge(int x)
{
    for(int i=1;i<=x;i++)
    {
        unsum[s[i]]-=d[i];
        unsum[t[i]+1]+=d[i];
    }
    return doo();
}
void init()
{
    for(int i=1;i<=n;i++)
        unsum[i]=r[i]-r[i-1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&r[i]);
        unsum[i]=r[i]-r[i-1];
    }
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&d[i],&s[i],&t[i]);
    if(judge(m))
    {
        cout<<0;
        return 0;
    }
    init();
    int l,ri,mid;
    l=1;ri=m;
    while(l<ri)
    {
        mid=(l+ri)>>1;
        if(judge(mid))
            l=mid+1;
        else
            ri=mid;
        init();
    }
    cout<<-1<<endl<<l;
    return 0;
}
