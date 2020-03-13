//
//  main.cpp
//  语句解析
//
//  Created by 高飞 on 2018/8/8.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<char,int> m;
int main()
{
    m['a']=0;
    m['b']=0;
    m['c']=0;
    string a;
    cin>>a;
    for(int i=0;i<a.length();i+=5)
    {
        if(a[i+3]>='1'&&a[i+3]<='9')
            m[a[i]]=(int)(a[i+3]-'0');
        else
            m[a[i]]=m[a[i+3]];
    }
    for(char i='a';i<='c';i++)
        cout<<m[i]<<' ';
    return 0;
}
