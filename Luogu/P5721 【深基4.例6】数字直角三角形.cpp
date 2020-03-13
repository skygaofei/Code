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
int main()
{
    int n,k=1;
    scanf("%d",&n);
    for(re int i=n;i>=1;--i)
    {
        for(re int j=1;j<=i;++j)
        {
            if(k<10)
                putchar('0');
            printf("%d",k);
            k++;
        }
        putchar('\n');
    }
    return 0;
}
