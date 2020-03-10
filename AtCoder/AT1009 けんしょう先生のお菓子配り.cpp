//
//  AT1009 けんしょう先生のお菓子配り.cpp
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
    int a,b,k;
    scanf("%d%d",&a,&b);
    k=b;
    while(b<a)
        b+=k;
    printf("%d\n",b-a);
    return 0;
}
