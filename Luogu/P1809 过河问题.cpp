//
//  main.cpp
//  过河问题
//
//  Created by 高飞 on 2018/8/9.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
int a[100005],dp[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[1]=a[1];dp[2]=a[2];dp[3]=a[1]+a[2]+a[3];
    for(int i=4;i<=n;i++)
        dp[i]=min(dp[i-1]+a[i]+a[1],dp[i-2]+a[i]+a[1]+(a[2]<<1));
    printf("%d",dp[n]);
    return 0;
}
