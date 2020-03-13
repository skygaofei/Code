//
//  输油管道问题.cpp
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
#define maxn 10005
#define re register
using namespace std;
int n,a[maxn],ans;
int main()
{
    scanf("%d",&n);
    int x;
    for(re int i=1;i<=n;++i)
        scanf("%d%d",&x,&a[i]);
    sort(a+1,a+n+1);
    int length=n/2;
    for(re int i=1;i<=length;++i)
        ans+=a[n-i+1]-a[i];
    printf("%d",ans);
    return 0;
}
