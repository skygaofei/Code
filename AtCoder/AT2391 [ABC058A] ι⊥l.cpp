//
//  AT2391 [ABC058A] ι⊥l.cpp
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
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(b-a==c-b)
        printf("YES");
    else
        printf("NO");
    return 0;
}
