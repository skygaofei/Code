//
//  泥泞的路.cpp
//  USACO刷题(xuezhan.org)
//
//  Created by skygao on 2019/8/15.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#define re register
#define maxn 10005
using namespace std;
struct Roads
{
    int l,r;
}a[maxn];
bool cmp(Roads a,Roads b)
{
    return a.l<b.l;
}
int n,l,ans;
int main()
{
    scanf("%d%d",&n,&l);
    for(re int i=1;i<=n;++i)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+n+1,cmp);
    int k=a[1].l;
    for(re int i=1;i<=n;++i)
    {
        while(k<a[i].r)
            k+=l,ans++;
        k=max(k,a[i+1].l);
    }
    printf("%d",ans);
    return 0;
}
