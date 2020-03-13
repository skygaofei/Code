//
//  最长公共子序列LCS.cpp
//  Algorithm
//
//  Created by skygao on 2019/10/10.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define re register
#define inf 0x7fffffff
#define maxn 100005
using namespace std;
int n,a[maxn],b[maxn],mp[maxn],dp[maxn],length;
int l,r,mid;
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d",&a[i]),mp[a[i]]=i;
    for(re int i=1;i<=n;++i)
        scanf("%d",&b[i]),dp[i]=inf;
    for(int i=1;i<=n;++i)
    {
        l=0,r=length;
        if(mp[b[i]]>dp[length])
            dp[++length]=mp[b[i]];
        else
        {
            while(l<r)
            {
                mid=(l+r)>>1;
                if(dp[mid]>mp[b[i]])
                    r=mid;
                else
                    l=mid+1;
            }
            dp[l]=min(mp[b[i]],dp[l]);
        }
    }
    printf("%d",length);
    return 0;
}
