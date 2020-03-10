//
//  AT765 真冬日？真夏日？.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/13.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define re register
using namespace std;
int book[7];
int main()
{
    int n;
    double h,l;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
    {
        scanf("%lf%lf",&h,&l);
        if(h>=35)
            book[1]++;
        if(h>=30&&h<35)
            book[2]++;
        if(h>=25&&h<30)
            book[3]++;
        if(l>=25)
            book[4]++;
        if(l<0&&h>=0)
            book[5]++;
        if(h<0)
            book[6]++;
    }
    for(re int i=1;i<6;++i)
        printf("%d ",book[i]);
    printf("%d",book[6]);
    printf("\n");
    return 0;
}
