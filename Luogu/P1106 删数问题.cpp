//
//  删数问题.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/7/3.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define re register
#define maxn 250
using namespace std;
int main()
{
    char s[maxn];int n;
    scanf("%s%d",s,&n);
    int len=strlen(s);
    while(n--)
    {
        for(re int i=0;i<len-1;++i)
            if(s[i]>s[i+1])
            {
                for(re int j=i;j<len-1;++j)
                    s[j]=s[j+1];
                break;
            }
        --len;
    }
    int k(0);
    while(k<len&&s[k]=='0')
        ++k;
    if(k==len)
        printf("0");
    else
        for(re int i=k;i<len;++i)
            printf("%c",s[i]);
    return 0;
}
