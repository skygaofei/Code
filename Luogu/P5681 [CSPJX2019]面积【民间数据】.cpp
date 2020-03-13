//
//  江西CSP-JT1.cpp
//  11.23
//
//  Created by skygao on 2019/11/24.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
long long a,b,c,tmp1,tmp2;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    tmp1=a*a,tmp2=b*c;
    if(tmp1>tmp2)
        printf("Alice");
    else
        printf("Bob");
    return 0;
}
