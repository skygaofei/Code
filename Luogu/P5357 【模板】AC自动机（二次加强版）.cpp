//
//  P5357 【模板】AC自动机（二次加强版）.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/3/10.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define maxn 200005
#define re register
using namespace std;
int n;
int trie[maxn][26],cntt;
int fail[maxn],sum[maxn];
int book[maxn],que[maxn],h;
char c[maxn*10];
inline int insert(char *s)
{
    int pos=0;
    for(;*s;s++)
    {
        if(trie[pos][*s-'a']==0)
            trie[pos][*s-'a']=++cntt;
        pos=trie[pos][*s-'a'];
    }
    return pos;
}
int main()
{
    scanf("%d",&n);
    for(re int i=0;i<n;++i)
    {
        scanf("%s",c);
        book[i]=insert(c);
    }
    que[h++]=0;
    for(re int i=0;i<h;++i)
    {
        int u=que[i];
        for(re int j=0;j<26;++j)
        {
            if(trie[u][j])
            {
                fail[trie[u][j]]=u?trie[fail[u]][j]:0;
                que[h++]=trie[u][j];
            }
            else
                trie[u][j]=trie[fail[u]][j];
        }
    }
    scanf("%s",c);
    for(re int p=0,i=0;c[i];++i)
        p=trie[p][c[i]-'a'],sum[p]++;
    for(re int i=cntt;i>0;--i)
        sum[fail[que[i]]]+=sum[que[i]];
    for(re int i=0;i<n;++i)
        printf("%d\n",sum[book[i]]);
    return 0;
}
