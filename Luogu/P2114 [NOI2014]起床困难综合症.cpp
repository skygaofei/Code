//
//  起床困难综合征.cpp
//  10.5晚上作业
//
//  Created by 高飞 on 2018/10/5.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#define maxn 100005
using namespace std;
int a[maxn],ans,n,m,op[maxn];
bool flag;
char s[10];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        if(s[0]=='A')
            op[i]=1;
        if(s[0]=='O')
            op[i]=2;
        if(s[0]=='X')
            op[i]=3;
        scanf("%d",&a[i]);
    }
    flag=1;
    for(int i=30;i>=0;i--)
    {
        int tmp1=(1<<i),tmp0=0;
        for(int j=1;j<=n;j++)
        {
            if(op[j]==1)
                tmp1&=a[j],tmp0&=a[j];
            if(op[j]==2)
                tmp1|=a[j],tmp0|=a[j];
            if(op[j]==3)
                tmp1^=a[j],tmp0^=a[j];
        }
        if((1<<i)<0)
        {
            ans|=tmp0;
            continue;
        }
        if(flag&&!(m&(1<<i)))
        {
            ans|=tmp0;
            continue;
        }
        if((tmp0&(1<<i))||((tmp1&(1<<i))&&(!flag||(m&(1<<i)))))
            ans|=(1<<i);
        if((m&(1<<i))&&(tmp0&(1<<i))>=(tmp1&(1<<i)))
            flag=0;
    }
    printf("%d",ans);
    return 0;
}
