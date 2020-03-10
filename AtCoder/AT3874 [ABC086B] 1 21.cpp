//
//  AT3874 [ABC086B] 1 21.cpp
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
#include <cmath>
using namespace std;
int main()
{
    int a,b,k=1000;
    scanf("%d%d",&a,&b);
    if(b/10==0)
        k=10;
    else if(b/100==0)
        k=100;
    a=a*k+b;
    int tmp=sqrt(a);
    if(tmp*tmp!=a)
        printf("No");
    else
        printf("Yes");
    return 0;
}
