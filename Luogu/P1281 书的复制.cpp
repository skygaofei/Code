//
//  书的复制.cpp
//  7.20集训
//
//  Created by skygao on 2019/7/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 505
#define re register
using namespace std;
int n,k;
int book[maxn];
bool check(int x)
{
    int res=0,ans=0;
    for(re int i=n;i>=1;--i)
    {
        if(res+book[i]<=x)
            res+=book[i];
        else
            res=book[i],ans++;
    }
    ans++;
    return ans<=k;
}
int ans;
void print(int l,int r)
{
    int res=0;
    for(re int i=r;i>=l;--i)
    {
        if(res+book[i]>ans)
        {
            print(l,i);
            printf("%d %d\n",i+1,r);
            return;
        }
        res+=book[i];
    }
    printf("%d %d\n",1,r);
}
int main()
{
    int sum=0;
    scanf("%d%d",&n,&k);
    if(n==0)
        return 0;
    for(re int i=1;i<=n;++i)
        scanf("%d",&book[i]),sum+=book[i];
    int l=0,r=sum,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    print(1,n);
    return 0;
}
