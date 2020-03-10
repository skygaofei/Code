//
//  AT277 たこ焼き買えるかな？.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/14.
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
    int n;
    scanf("%d",&n);
    if(n%10<7)
        printf("%d",n/10*100+n%10*15);
    else
        printf("%d",n/10*100+100);
    return 0;
}
