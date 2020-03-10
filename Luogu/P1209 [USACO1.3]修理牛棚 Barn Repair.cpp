//
//  修理牛棚.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define maxn 205
using namespace std;
int m,s,c,ans;
int a[maxn],tmpc[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    scanf("%d%d%d",&m,&s,&c);
    for(re int i=1;i<=c;++i)
        scanf("%d",&a[i]);
    if(m>c)
    {
        printf("%d",c);
        return 0;
    }
    sort(a+1,a+c+1);
    ans=a[c]-a[1]+1;
    for(re int i=2;i<=c;++i)
        tmpc[i-1]=a[i]-a[i-1];
    sort(tmpc+1,tmpc+c+1,cmp);
    for(re int i=1;i<m;++i)
        ans=ans-tmpc[i]+1;
    printf("%d",ans);
    return 0;
}
