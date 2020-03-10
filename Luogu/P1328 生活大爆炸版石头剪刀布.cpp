//
//  main.cpp
//  刷题专用
//
//  Created by 高飞 on 2018/10/20.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int n,a,b;
int s1[205],s2[205];
int ans1,ans2;
int score[10][10]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<a;i++)
        scanf("%d",&s1[i]);
    for(int i=0;i<b;i++)
        scanf("%d",&s2[i]);
    for(int i=0;i<n;i++)
    {
        ans1+=score[s1[i%a]][s2[i%b]];
        ans2+=score[s2[i%b]][s1[i%a]];
    }
    printf("%d %d",ans1,ans2);
    return 0;
}
