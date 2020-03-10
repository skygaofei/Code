//
//  三国游戏.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
#define maxn 505
using namespace std;
int a[maxn][maxn],n,ans;
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<n;++i)
        for(re int j=i+1;j<=n;++j)
        {
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    for(re int i=1;i<=n;++i)
    {
        sort(a[i]+1,a[i]+n+1);
        ans=max(ans,a[i][n-1]);
    }
    printf("1\n%d\n",ans);
    return 0;
}
