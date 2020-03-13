//
//  main.cpp
//  编辑距离
//
//  Created by 高飞 on 2018/9/15.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n,m;
char a[5010],b[5010];
int f[3005][3005];
int main()
{
    scanf("%s",a+1);
    scanf("%s",b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    for(int i=0;i<=n;i++)
        f[i][0]=i;
    for(int i=0;i<=m;i++)
        f[0][i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                f[i][j]=min(min(f[i][j-1]+1,f[i-1][j]+1),f[i-1][j-1]);
            else
                f[i][j]=min(min(f[i][j-1]+1,f[i-1][j]+1),f[i-1][j-1]+1);
        }
    printf("%d",f[n][m]);
    return 0;
}
