//
//  AT266 迷子のCDケース.cpp
//  Algorithm
//
//  Created by skygao on 2019/10/10.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
using namespace std;
int n,m;
int a[105];
int now;
int main()
{
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=n;++i)
        a[i]=i;
    int x;
    for(re int i=1;i<=m;++i)
    {
        scanf("%d",&x);
        for(re int j=1;j<=n;++j)
            if(a[j]==x)
            {
                swap(a[j],now);
                break;
            }
    }
    for(re int i=1;i<=n;++i)
        printf("%d\n",a[i]);
    return 0;
}
