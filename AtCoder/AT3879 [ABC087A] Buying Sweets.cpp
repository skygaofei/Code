//
//  AT3879 [ABC087A] Buying Sweets.cpp
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
    int x,a,b;
    scanf("%d%d%d",&x,&a,&b);
    printf("%d",(x-a)%b);
    return 0;
}
