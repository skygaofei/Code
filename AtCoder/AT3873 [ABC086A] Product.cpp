//
//  AT3873 [ABC086A] Product.cpp
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
#define re regsiter
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    a=a&1,b=b&1;
    if(a&b)
        printf("Odd");
    else
        printf("Even");
    return 0;
}
