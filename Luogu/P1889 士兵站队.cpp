//
//  士兵站队问题.cpp
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
#include <cmath>
#define re register
#define maxn 10005
using namespace std;
int n,x[maxn],y[maxn];
int _x,_y,ans;
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d%d",&x[i],&y[i]);
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    for(re int i=1;i<=n;++i)
        x[i]-=i;
    sort(x+1,x+n+1);
    if(n%2==0)
    {
        _x=(x[n/2]+x[n/2+1])/2;
        _y=(y[n/2]+y[n/2+1])/2;
    }
    else
    {
        _x=x[n/2+1];
        _y=y[n/2+1];
    }
    for(re int i=1;i<=n;++i)
        ans+=abs(x[i]-_x)+abs(y[i]-_y);
    printf("%d",ans);
    return 0;
}

