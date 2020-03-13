//
//  友好城市.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
#define maxn 200005
using namespace std;
struct City
{
    int north,south;
}a[maxn];
bool cmp(City a,City b)
{
    return a.north<b.north;
}
int LIS[maxn],ans,n;
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d%d",&a[i].north,&a[i].south);
    sort(a+1,a+n+1,cmp);
    for(re int i=1;i<=n;++i)
    {
        if(a[i].south>LIS[ans])
            LIS[++ans]=a[i].south;
        else
            *lower_bound(LIS+1,LIS+ans+1,a[i].south)=a[i].south;
    }
    printf("%d",ans);
    return 0;
}
