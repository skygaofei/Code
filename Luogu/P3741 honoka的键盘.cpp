//
//  main.cpp
//  键盘
//
//  Created by 高飞 on 2018/8/7.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    string a;
    cin>>a;
    cin>>a;
    int ans=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='V'&&a[i+1]=='K')
        {
            ans++;
            a[i]='X';
            a[i+1]='X';
        }
    }
    for(int i=0;i<a.length();i++)
        if(a[i]!='X'&&a[i]==a[i+1])
        {
            ans++;
            break;
        }
    printf("%d",ans);
    return 0;
}
