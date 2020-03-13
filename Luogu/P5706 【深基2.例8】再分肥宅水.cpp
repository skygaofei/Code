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
#include <vector>
#define re register
#define ll long long
using namespace std;
double n;int t;
int main()
{
    scanf("%lf%d",&n,&t);
    printf("%.3lf\n%d",n/(double)t,t*2);
    return 0;
}
