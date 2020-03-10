//
//  Jam的计数法.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
using namespace std;
int s,t,w,tmpc;
int cnt,a[55];
inline void Print()
{
    for(re int i=1;i<=w;++i)
        printf("%c",'a'+a[i]-1);
    printf("\n");
}
inline void dfs(int pos,int x)
{
    if(pos==0)
        return;
    if(x==6)
        return;
    if(a[pos]<t&&a[pos]<a[pos+1]-1)
    {
        a[pos]++;
        for(re int i=pos+1;i<=w;++i)
            a[i]=a[i-1]+1;
        Print();
        dfs(w,x+1);
    }
    else
        dfs(pos-1,x);
}
int main()
{
    scanf("%d%d%d",&s,&t,&w);
    while((tmpc=getchar())!=EOF)
    {
        int tmp=tmpc-'a'+1;
        if(tmp>=1&&tmp<=26)
            a[++cnt]=tmp;
    }
    a[w+1]=0x7f;
    dfs(w,1);
    return 0;
}
