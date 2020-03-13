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
#include <vector>
#define re register
#define ll long long
using namespace std;
string s,a;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,x,y;
    cin>>n;
    cin>>s;
    int type;
    for(re int i=1;i<=n;++i)
    {
        cin>>type;
        switch(type)
        {
            case 1:
                cin>>a;
                s+=a,cout<<s<<endl;
                break;
            case 2:
                cin>>x>>y;
                s=s.substr(x,y),cout<<s<<endl;
                break;
            case 3:
                cin>>x>>a;
                s.insert(x,a),cout<<s<<endl;
                break;
            case 4:
                cin>>a;
                if(s.find(a)<s.size())
                    cout<<s.find(a)<<endl;
                else
                    cout<<-1<<endl;
                break;
        }
    }
    return 0;
}
