//
//  矩阵模板.cpp
//  11.28
//
//  Created by skygao on 2019/12/28.
//  Copyright © 2019 skygao. All rights reserved.
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
namespace Matrix_Calculation
{
    #define mod 1000000007
    int n;
    class Matrix
    {
    public:
        long long a[110][110];
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
int main()
{
    Matrix a,c;
    ll k;
    scanf("%d%lld",&n,&k);
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=n;++j)
            scanf("%lld",&a.a[i][j]);
    c=c.quickpow(a,k);
    cout<<c;
    return 0;
}
