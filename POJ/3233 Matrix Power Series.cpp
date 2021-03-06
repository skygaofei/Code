//
//  POJ 3233 Matirx Power Series.cpp
//  Algorithm
//
//  Created by skygao on 2020/1/1.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define ll long long
using namespace std;
int mod;
namespace Matrix_Calculation
{
    int n;
    class Matrix
    {
    public:
        long long a[31][31];
        Matrix operator *(const Matrix&b)
        {
            Matrix res;
            for(re int i=1;i<=n;i++)
                for(re int j=1;j<=n;j++)
                {
                    res.a[i][j]=0;
                    for(re int p=0;p<=n;p++)
                    {
                        res.a[i][j]+=this->a[i][p]*b.a[p][j];
                        res.a[i][j]%=mod;
                    }
                }
            return res;
        }
        Matrix operator +(const Matrix&b)
        {
            Matrix res;
            for(re int i=1;i<=n;++i)
                for(re int j=1;j<=n;++j)
                    res.a[i][j]=(this->a[i][j]+b.a[i][j])%mod;
            return res;
        }
        Matrix unit()
        {
            Matrix ans;
            for(re int i=1;i<=n;i++)
                for(re int j=1;j<=n;j++)
                {
                    if(i==j)
                        ans.a[i][j]=1;
                    else
                        ans.a[i][j]=0;
                }
            return ans;
        }
        Matrix quickpow(Matrix a,ll b)
        {
            Matrix res;
            res=res.unit();
            while(b)
            {
                if(b&1)
                    res=res*a;
                a=a*a;
                b>>=1;
            }
            return res;
        }
    };
    ostream& operator<<(ostream &out,const Matrix& x)
    {
        for(re int i=1;i<=n;++i)
        {
            for(re int j=1;j<=n;++j)
                printf("%lld ",x.a[i][j]);
            printf("\n");
        }
        return out;
    }
}
using namespace Matrix_Calculation;
Matrix solve(Matrix x,int k)
{
    if(k==1)
        return x;
    Matrix ans;
    ans=ans.unit();
    ans=ans+ans.quickpow(x, k>>1);
    ans=ans*solve(x, k>>1);
    if(k&1)
        ans=ans+ans.quickpow(x,k);
    return ans;
}
int main()
{
    Matrix a;
    int k;
    scanf("%d%d%d",&n,&k,&mod);
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=n;++j)
            scanf("%lld",&a.a[i][j]);
    cout<<solve(a,k);
    return 0;
}