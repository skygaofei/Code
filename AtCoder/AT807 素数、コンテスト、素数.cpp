//
//  AT807 素数、コンテスト、素数.cpp
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
#include <cmath>
#define re register
using namespace std;
bool is_prime(int x)
{
    if(x==1||x==0)
        return false;
    for(re int i=2;i<=sqrt(x);++i)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(is_prime(n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
