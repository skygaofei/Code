//
//  P4391 [BOI2009]Radio Transmission 无线传输.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/3/8.
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
char a[1000005];
int n,kmp[1000005],k;
int main()
{
    scanf("%d%s",&n,a+1);
    int lena=strlen(a+1);
    for(re int i=2;i<=lena;++i)
    {
        while(k&&a[i]!=a[k+1])
            k=kmp[k];
        if(a[k+1]==a[i])
            k++;
        kmp[i]=k;
    }
    printf("%d",n-kmp[n]);
    return 0;
}
