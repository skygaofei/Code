//
//  深基.cpp
//  Algorithm
//
//  Created by skygao on 2020/1/30.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#define re register
#define ll long long
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    if(x<=1)
        printf("Today, I ate %d apple.",x);
    else
        printf("Today, I ate %d apples.",x);
    return 0;
}
