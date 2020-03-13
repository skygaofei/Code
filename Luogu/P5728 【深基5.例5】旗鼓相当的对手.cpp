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
#define re register
#define ll long long
using namespace std;
struct student
{
    int ch,ma,en,sum;
}stu[1005];
int ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d%d%d",&stu[i].ch,&stu[i].ma,&stu[i].en),stu[i].sum=stu[i].ch+stu[i].ma+stu[i].en;
    for(re int i=1;i<n;++i)
        for(re int j=i+1;j<=n;++j)
        {
            int t1=abs(stu[i].ch-stu[j].ch);
            int t2=abs(stu[i].ma-stu[j].ma);
            int t3=abs(stu[i].en-stu[j].en);
            int t4=abs(stu[i].sum-stu[j].sum);
            if(t1<=5&&t2<=5&&t3<=5&&t4<=10)
                ans++;
        }
    printf("%d",ans);
    return 0;
}
