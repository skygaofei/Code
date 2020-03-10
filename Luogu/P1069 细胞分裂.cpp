//
//  main.cpp
//  细胞分裂
//
//  Created by 高飞 on 2018/10/1.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 30005
using namespace std;
int n,m1,m2,k;
int prime[maxn];
bool flag_all,flag_now;
int all_prime;
int prime_bow[maxn],prime_cell[maxn],temp_ans,minn=0x3f3f3f3f;
bool is_prime(int x)
{
    if(x==1||x==0)
        return false;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return false;
    return true;
}
inline void Init()
{
    k=1;
    temp_ans=0;
    flag_now=true;
}
int main()
{
    scanf("%d",&n);
    scanf("%d%d",&m1,&m2);
    for(int i=2;i<=maxn;i++)
        if(is_prime(i))
        {
            all_prime++;
            prime[all_prime]=i;
        }
    k=1;
    while(m1!=1)
    {
        if(m1%prime[k]==0)
        {
            while(!(m1%prime[k]))
            {
                prime_bow[k]+=m2;
                m1=m1/prime[k];
            }
        }
        k++;
    }
    int temp;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        Init();
        memset(prime_cell,0,sizeof(prime_cell));
        while(k<=all_prime)
        {
            if(temp%prime[k]==0)
            {
                while(temp%prime[k]==0)
                {
                    prime_cell[k]++;
                    temp=temp/prime[k];
                }
            }
            k++;
        }
        for(int j=1;j<=all_prime;j++)
        {
            if(prime_bow[j]!=0&&prime_cell[j]==0)
                flag_now=false;
            if(prime_bow[j]!=0&&prime_cell[j]!=0)
            {
                if(prime_bow[j]%prime_cell[j]==0)
                    temp_ans=max(temp_ans,prime_bow[j]/prime_cell[j]);
                else
                    temp_ans=max(temp_ans,prime_bow[j]/prime_cell[j]+1);
                
            }
        }
        if(flag_now)
        {
            flag_all=true;
            minn=min(minn,temp_ans);
        }
    }
    if(flag_all)
        printf("%d",minn);
    else
        printf("-1");
    return 0;
}
