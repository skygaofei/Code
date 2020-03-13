//
//  P2613 有理数取余.cpp
//  12.14
//
//  Created by skygao on 2019/12/14.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
#define mod 19260817
using namespace std;
int a,b;
inline int get()
{
    int res=0;
    char ch=getchar();
    while(!isdigit(ch)&&ch!=EOF)
        ch=getchar();
    while(isdigit(ch))
        res=(res*10+(ch-'0'))%mod,ch=getchar();
    return res;
}
pair<int,int> exgcd(int a,int b)
{
    if(a==1&&b==0)
        return make_pair(1,0);
    pair<int,int> tmp=exgcd(b,a%b);
    return make_pair(tmp.second,tmp.first-(a/b)*tmp.second);
}
int main()
{
    int a,b;
    a=get();
    b=get();
    if(b==0)
    {
        printf("Angry!");
        return 0;
    }
    pair<int,int> ans=exgcd(b,mod);
    int tmp=(ans.first%mod+mod)%mod;
    printf("%lld",(tmp*(long long)a)%mod);
    return 0;
}
