//
//  main.cpp
//  多项式系数
//
//  Created by 高飞 on 2018/5/18.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#define ll unsigned long long
using namespace std;
ll mod=10007;
ll r[1010][1010];
ll C(ll n,ll m)
{
    if(m==n||m==0)
        return r[n][m]=1;
    if(r[n][m])
        return r[n][m];
    return r[n][m]=(C(n-1,m)+C(n-1,m-1))%mod;
}
ll Pow_mod_xh(ll a,ll b){
    ll res=1,temp=a;
    for(;b;b/=2){
        if(b&1){
            res=res*temp%mod;
        }
        temp=temp*temp%mod;
    }
    return res;
}
int main()
{
    ll p,q,k,a,b;
    cin>>p>>q>>k>>a>>b;
    ll sum=C(k,b)*Pow_mod_xh(p,a)*Pow_mod_xh(q,b);
    cout<<sum%mod;
    return 0;
}
