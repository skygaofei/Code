//
//  深基.cpp
//  Algorithm
//
//  Created by skygao on 2020/1/30.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#define re register
#define ll long long
using namespace std;
bool is_prime[100005];
void prime(int n)
{
    is_prime[1]=false;
    for(int i=2;i<=n;i++)
        is_prime[i]=true;
    for(int i=2;i*i<=n;i++)
        if(is_prime[i])
            for(int j=i*i;j<=n;j+=i)
                is_prime[j]=false;
}
int a[101];
int main()
{
    prime(100000);
    int n;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(re int i=1;i<=n;++i)
        if(is_prime[a[i]])
            printf("%d ",a[i]);
    return 0;
}
