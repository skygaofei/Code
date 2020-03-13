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
int a[101];
int main()
{
    int n;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    printf("%d",a[n]-a[1]);
    return 0;
}
