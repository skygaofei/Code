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
map<string,int> mp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t,type,score,k=0;
    string name;
    cin>>t;
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>name>>score;
            if(mp[name]==0)
                k++;
            mp[name]=score;
            printf("OK\n");
        }
        else if(type==2)
        {
            cin>>name;
            if(mp[name]==0)
                printf("Not found\n");
            else
                printf("%d\n",mp[name]);
        }
        else if(type==3)
        {
            cin>>name;
            if(mp[name]==0)
                printf("Not found\n");
            else
                mp[name]=0,printf("Deleted successfully\n"),k--;
        }
        else if(type==4)
            printf("%d\n",k);
    }
    return 0;
}
