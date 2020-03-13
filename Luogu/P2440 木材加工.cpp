//
//  二分答案 切割木头.cpp
//  刷题专用
//
//  Created by 高飞 on 2018/11/3.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int n,k;
int a[100005];
inline bool check(int x)
{
    int tmp=0;
    for(register int i=1;i<=n;i++)
    {
        tmp+=a[i]/x;
        if(tmp>=k)
            return true;
    }
    return false;
}

int main()
{
    int tot=0;
    scanf("%d%d",&n,&k);
    for(register int i=1;i<=n;i++)
        scanf("%d",&a[i]),tot+=a[i];
    if(tot/k<1){cout<<0;return 0;}
    int l=0,r=tot/k,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%d",l);
    return 0;
}
