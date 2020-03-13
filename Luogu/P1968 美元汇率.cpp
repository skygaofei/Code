//
//  P1968 美元汇率.cpp
//  Algorithm
//
//  Created by skygao on 2019/10/11.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define maxn 1005
using namespace std;
int a[maxn],n;
double f[maxn][2];
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    f[1][0]=100;f[1][1]=a[1];
    for(re int i=2;i<=n;++i)
    {
        f[i][0]=max(f[i-1][0],f[i-1][1]/a[i]*100);
        f[i][1]=max(f[i-1][1],f[i-1][0]*a[i]/100);
    }
    printf("%.2lf",max(f[n][0],f[n][1]/a[n]*100));
    return 0;
}
