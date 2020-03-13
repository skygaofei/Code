//
//  P1495 曹冲养猪.cpp
//  12.21
//
//  Created by skygao on 2019/12/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define ull long long
using namespace std;
ull m[15],a[15];
int n;
long long M=1,ans=0;
pair<ull,ull> exgcd(ull a,ull b)
{
    if(a==1&&b==0)
        return make_pair(1,0);
    pair<int,int> tmp=exgcd(b,a%b);
    return make_pair(tmp.second,tmp.first-(a/b)*tmp.second);
}
ull inv(ull x,ull mod)
{
    pair<ull,ull> ans=exgcd(x,mod);
    return (ans.first%mod+mod)%mod;
}
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d%d",&m[i],&a[i]),M*=m[i];
    for(re int i=1;i<=n;++i)
        ans+=a[i]*(M/m[i])*inv(M/m[i],m[i]);
    ans=(ans%M+M)%M;
    printf("%llu",ans);
    return 0;
}
