//
//  AT820 おいしいたこ焼きの食べ方.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/13.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
using namespace std;
int n,a[105];
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    printf("%d\n",a[1]);
    return 0;
}
