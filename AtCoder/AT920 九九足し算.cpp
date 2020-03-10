//
//  AT920 九九足し算.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/13.
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
int main()
{
    int n;
    scanf("%d",&n);
    n=2025-n;
    for(re int i=1;i<=9;++i)
        if(n%i==0&&n/i<=9)
            printf("%d x %d\n",i,n/i);
    return 0;
}
