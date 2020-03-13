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
#include <stack>
#define re register
#define ll long long
using namespace std;
int main()
{
    int a[4];
    scanf("%d%d%d",&a[1],&a[2],&a[3]);
    sort(a+1,a+4);
    printf("%d %d %d",a[1],a[2],a[3]);
    return 0;
}
