//
//  main.cpp
//  矩阵快速幂求斐波那契数列
//
//  Created by 高飞 on 2018/5/4.
//  Copyright ? 2018年 高飞. All rights reserved.
//

#include <iostream>
#define ll unsigned long long
using namespace std;
struct matric
{
    ll a[3][3];
};
matric mul_matric(matric a,matric b,ll mod)
{
    matric c;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            c.a[i][j]=0;
            for(int p=1;p<=2;p++)
            {
                c.a[i][j]+=a.a[i][p]*b.a[p][j];
                c.a[i][j]%=mod;
            }
        }
    return c;
}
matric re_unit()
{
    matric ans;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            if(i==j)
                ans.a[i][j]=1;
            else
                ans.a[i][j]=0;
        }
    return ans;
}
matric Pow_matric(matric a,ll y,ll mod)
{
    matric res=re_unit(),temp=a;
    for(;y;y/=2)
    {
        if(y&1)
            res=mul_matric(res, temp, mod);
        temp=mul_matric(temp, temp, mod);
    }
    return res;
}
ll gcd(ll n,ll m)
{
	if(m==0)
		return n;
	return gcd(m,n%m);
}
int main()
{
    ll n,m;
    cin>>n>>m;
    n=gcd(n,m);
    if(n==1||n==2)
    {
        cout<<1;
        return 0;
    }
    matric p;
    p.a[1][1]=1;
    p.a[1][2]=1;
    p.a[2][1]=1;
    p.a[2][2]=0;
    matric ans;
    ans=Pow_matric(p, n-2, 100000000);
    matric f;
    f.a[1][1]=1;
    f.a[2][1]=1;
    ans=mul_matric(ans, f, 100000000);
    cout<<ans.a[1][1];
    return 0;
}
