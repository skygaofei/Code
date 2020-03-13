//
//  P3375 【模板】KMP字符串匹配.cpp
//  Algorithm
//
//  Created by skygao on 2019/10/11.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define maxn 1000005
using namespace std;
int kmp[maxn],lena,lenb;
char a[maxn],b[maxn];
int k;
int main()
{
    scanf("%s%s",a+1,b+1);
    lena=strlen(a+1),lenb=strlen(b+1);
    for(re int i=2;i<=lenb;++i)
    {
        while(k&&b[i]!=b[k+1])
            k=kmp[k];
        if(b[k+1]==b[i])
            k++;
        kmp[i]=k;
    }
    k=0;
    for(re int i=1;i<=lena;++i)
    {
        while(k&&b[k+1]!=a[i])
            k=kmp[k];
        if(b[k+1]==a[i])
            k++;
        if(k==lenb)
            printf("%d\n",i-lenb+1),k=kmp[k];
    }
    for(re int i=1;i<=lenb;++i)
        printf("%d ",kmp[i]);
    return 0;
}
