//
//  CF484A Bits.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/3/1.
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
int main()
{
    long long t,l,r;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&l,&r);
        while((l|(l+1))<=r)
            l|=l+1;
        printf("%lld\n",l);
    }
    return 0;
}
