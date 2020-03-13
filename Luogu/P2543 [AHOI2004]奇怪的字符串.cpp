//
//  P2543 [AHOI2004]奇怪的字符串.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/3/8.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
using namespace std;
char a[10005],b[10005];
int dp[10001][10001];
int main()
{
    scanf("%s%s",a,b);
    int lena=strlen(a),lenb=strlen(b);
    for(re int i=1;i<=lena;++i)
        for(re int j=1;j<=lenb;++j)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    printf("%d",dp[lena][lenb]);
    return 0;
}
