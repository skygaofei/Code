//
//  深基.cpp
//  Algorithm
//
//  Created by skygao on 2020/1/30.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
using namespace std;
int num[1000];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    int x;
    for(re int i=1;i<=m;++i)
        scanf("%d",&x),num[x]++;
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=num[i];++j)
            printf("%d ",i);
    return 0;
}
