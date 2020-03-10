//
//  main.cpp
//  悲剧文本
//
//  Created by 高飞 on 2018/11/24.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <iterator>
using namespace std;
list<char> l;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    string s;char c;
    list<char>::iterator k=l.begin();
    while(cin>>s)
    {
        l.clear();
        l.resize(0);
        k=l.begin();
        for(int i=0;i<s.length();i++)
        {
            c=s[i];
            if(c==']')
                k=l.end();
            else if(c=='[')
                k=l.begin();
            else
                l.insert(k,c);
        }
        for(k=l.begin();k!=l.end();k++)
            cout<<*k;
        cout<<endl;
    }
    return 0;
}
