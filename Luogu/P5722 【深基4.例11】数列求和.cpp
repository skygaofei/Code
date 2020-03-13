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
#define re register
using namespace std;
int main()
{
    int n,s=0;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        s+=i;
    printf("%d",s);
    return 0;
}
